use std::io;
use std::io::BufRead;
use std::io::BufReader;
use std::io::BufWriter;
use std::io::Write;

const MOD: u64 = 998244353;

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let mut buffer = String::new();
    stdin.read_line(&mut buffer).unwrap();
    let n: usize = buffer.trim().parse().unwrap();
    if n == 1 {
        writeln!(stdout, "10").unwrap();
    } else if n == 2 {
        writeln!(stdout, "180 10").unwrap();
    } else {
        let mut rls: Vec<u64> = vec![0; n];
        rls[0] = 10;
        rls[1] = 180;
        let mut base: u64 = 10;
        for i in 2..rls.len() {
            rls[i] = ((rls[i - 1] * 10) % MOD + (81 * base) % MOD) % MOD;
            base = (base * 10) % MOD;
        }
        let rls: Vec<String> = rls.iter().rev().map(|x| x.to_string()).collect();
        writeln!(stdout, "{}", rls.join(" ")).unwrap();
    }
}
