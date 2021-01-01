use std::io::{self, BufRead};

use io::{BufReader, BufWriter, Write};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());
    let mut buffer = String::new();

    stdin.read_line(&mut buffer).unwrap();
    let t: i32 = buffer.trim().parse().unwrap();
    writeln!(stdout, "{}", t).unwrap();
}
