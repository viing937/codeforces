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
        let n: usize = buffer.trim().parse().unwrap();

        let mut m = vec![false; n + 1];
        let mut f = vec![false; n + 1];
        for i in 1..n + 1 {
            let mut buffer = String::new();
            stdin.read_line(&mut buffer).unwrap();
            let g: Vec<usize> = buffer
                .trim()
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();
            for &j in g.iter().skip(1) {
                if m[j] == false {
                    f[i] = true;
                    m[j] = true;
                    break;
                }
            }
        }
        if f.iter().skip(1).filter(|&x| *x).count() == n {
            writeln!(stdout, "OPTIMAL").unwrap();
        } else {
            let f = f.iter().skip(1).position(|&x| x == false).unwrap();
            let m = m.iter().skip(1).position(|&x| x == false).unwrap();
            writeln!(stdout, "IMPROVE").unwrap();
            writeln!(stdout, "{} {}", f + 1, m + 1).unwrap();
        }
    }
}
