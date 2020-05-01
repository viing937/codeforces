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
        let n: usize = buffer.trim().parse().unwrap();

        if n / 2 % 2 > 0 {
            writeln!(stdout, "NO").unwrap();
        } else {
            let mut a = vec![0; n];
            for i in (0..n / 2).step_by(2) {
                a[i] = i * 6 + 2;
                a[i + 1] = i * 6 + 4;
                a[n / 2 + i] = i * 6 + 1;
                a[n / 2 + i + 1] = i * 6 + 5;
            }
            let a: Vec<String> = a.iter().map(|x| x.to_string()).collect();
            writeln!(stdout, "YES").unwrap();
            writeln!(stdout, "{}", a.join(" ")).unwrap();
        }
    }
}
