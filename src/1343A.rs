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
    let t = buffer.trim().parse().unwrap();
    for _ in 0..t {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let n: u32 = buffer.trim().parse().unwrap();

        let mut base: u32 = 4;
        while n % (base - 1) != 0 {
            base *= 2;
        }
        writeln!(stdout, "{}", n / (base - 1)).unwrap();
    }
}
