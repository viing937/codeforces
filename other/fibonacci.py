import random
import numpy as np
import tensorflow as tf
import tensorflow.contrib.layers as layers

INPUT_SIZE = 32
RNN_HIDDEN = 16
OUTPUT_SIZE = 32
LEARNING_RATE = 0.01
TINY = 1e-6

USE_LSTM = True

# DATASET GENERATION
def encode_decimal(n, n_bits = INPUT_SIZE):
    n = bin(n)[2:]
    n = [0] * (n_bits-len(n)) + [int(i) for i in n]
    return n

def decode_bits(n, n_bits = INPUT_SIZE):
    pass

def gen_data(m, slen = 2):
    l = [0] * (m+1)
    for i in range(slen):
        l[i] = int(random.random()*8)
    for i in range(slen, m+1):
        l[i] = sum(l[i-slen:i])
    l = list(map(encode_decimal, l))
    x = np.array(l[:m]).reshape(m, 1, INPUT_SIZE)
    y = np.array(l[1:]).reshape(m, 1, OUTPUT_SIZE)
    return x, y

# GRAPH DEFINITION
inputs  = tf.placeholder(tf.float32, (None, None, INPUT_SIZE))  # (time, batch, in)
outputs = tf.placeholder(tf.float32, (None, None, OUTPUT_SIZE)) # (time, batch, out)

if USE_LSTM:
    cell = tf.nn.rnn_cell.BasicLSTMCell(RNN_HIDDEN, state_is_tuple = True)
else:
    cell = tf.nn.rnn_cell.BasicRNNCell(RNN_HIDDEN)

batch_size = tf.shape(inputs)[1]
initial_state = cell.zero_state(batch_size, tf.float32)

rnn_outputs, rnn_states = tf.nn.dynamic_rnn(cell, inputs, initial_state = initial_state,
                                                          time_major = True)

final_projection = lambda x: layers.linear(x, num_outputs = OUTPUT_SIZE,
                                              activation_fn = tf.nn.sigmoid)
predicted_outputs = tf.map_fn(final_projection, rnn_outputs)

error = -( outputs * tf.log(predicted_outputs + TINY) +
           (1.0 - outputs) * tf.log(1.0 - predicted_outputs + TINY) )
error = tf.reduce_mean(error)

train_fn = tf.train.AdamOptimizer(learning_rate = LEARNING_RATE).minimize(error)
accuracy = tf.reduce_mean(tf.cast(tf.abs(outputs - predicted_outputs) < 0.5, tf.float32))

# TRAIN LOOP
SEQLENGTH = 20
ITERATIONS_PER_EPOCH = 100
BATCH_SIZE = 1

valid_x, valid_y = gen_data(SEQLENGTH)

session = tf.Session()

session.run(tf.global_variables_initializer())
for epoch in range(300):
    epoch_error = 0
    for _ in range(ITERATIONS_PER_EPOCH):
        x, y = gen_data(SEQLENGTH)
        epoch_error += session.run([error, train_fn], {
            inputs: x,
            outputs: y,
        })[0]
    epoch_error /= ITERATIONS_PER_EPOCH
    valid_accuracy = session.run(accuracy, {
        inputs:  valid_x,
        outputs: valid_y,
    })
    print("Epoch %d, train error: %.2f, valid accuracy: %.1f %%" %
          (epoch, epoch_error, valid_accuracy * 100.0))
