use std::io::{self, BufRead, BufReader, BufWriter, Write};

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
        let (n, k) = (buffer[0], buffer[1]);
        if n % 2 != k % 2 || n < k * k {
            writeln!(stdout, "NO").unwrap();
        } else {
            writeln!(stdout, "YES").unwrap();
        }
    }
}
