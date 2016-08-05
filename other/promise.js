'use strict';
var util = require('util'),
    EventEmitter = require('events').EventEmitter;


// Promise
var Promise = function () {
    EventEmitter.call(this);
}
util.inherits(Promise, EventEmitter);

Promise.prototype.then = function (fulfilledHandler, errorHandler, progressHandler) {
    if (typeof fulfilledHandler === 'function') {
        this.once('success', fulfilledHandler);
    }
    if (typeof errorHandler === 'function') {
        this.once('error', errorHandler);
    }
    if (typeof progressHandler === 'function') {
        this.on('progress', progressHandler);
    }
    return this;
}

// Deferred
var Deferred = function () {
    this.state = 'unfulfilled';
    this.promise = new Promise();
}

Deferred.prototype.resolve = function (obj) {
    this.state = 'fulfilled';
    this.promise.emit('success', obj);
}

Deferred.prototype.reject = function (err) {
    this.state = 'failed';
    this.promise.emit('error', err);
}

Deferred.prototype.progress = function (data) {
    this.promise.emit('progress', data);
}


// demo
var emitter = new EventEmitter();
var fun = function (num) {
    if (num < 0) {
        emitter.emit('error', 'The number is negative');
        return;
    }
    for (var i = 0; i < 10; i++) {
        num += 1;
        emitter.emit('progress', 'The number increases by 1, now is ' + num);
    }
    emitter.emit('success', 'The number increases by 100, ' + num);
};

/*
emitter.on('success', function (rlt) {
    console.log(rlt);
});

emitter.on('error', function (err) {
    console.log(err);
});

emitter.on('progress', function (msg) {
    console.log(msg);
});
*/

var promisify = function (res) {
    var deferred = new Deferred();
    res.on('success', function (rlt) {
        deferred.resolve(rlt);
    });

    res.on('error', function (err) {
        deferred.reject(err);
    });

    res.on('progress', function (msg) {
        deferred.progress(msg);
    });
    return deferred.promise;
};

promisify(emitter).then(function (rlt) {
    console.log(rlt);
}, function (err) {
    console.log(err);
}, function (msg) {
    console.log(msg);
});

fun(20);
