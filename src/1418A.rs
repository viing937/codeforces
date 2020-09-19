use std::io;
use std::io::BufRead;
use std::io::BufReader;
use std::io::BufWriter;
use std::io::Write;

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());
    let mut buffer = String::new();

    stdin.read_line(&mut buffer).unwrap();
    let t: i32 = buffer.trim().parse().unwrap();
    for _ in 0..t {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();

        let buffer: Vec<u64> = buffer
            .split_whitespace()
            .map(|x| x.trim().parse().unwrap())
            .collect();
        let (x, y, k) = (buffer[0], buffer[1], buffer[2]);
        let trade_1 = (k - 1 + y * k - 1) / (x - 1) + 1;
        let trade_2 = k;
        writeln!(stdout, "{}", trade_1 + trade_2).unwrap();
    }
}
