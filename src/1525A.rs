use std::io::{self, BufRead};

use io::{BufReader, BufWriter, Write};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());
    let mut buffer = String::new();

    stdin.read_line(&mut buffer).unwrap();
    let t: i32 = buffer.trim().parse().unwrap();
    for _ in 0..t {
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let k: i32 = buffer.trim().parse().unwrap();
        writeln!(stdout, "{}", 100 / gcd(k, 100)).unwrap();
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if a % b == 0 {
        return b;
    }
    return gcd(b, a % b);
}
