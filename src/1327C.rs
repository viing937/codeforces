use std::io::{self, BufRead, BufReader, BufWriter, Write};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let mut buffer = String::new();
    stdin.read_line(&mut buffer).unwrap();
    let buffer: Vec<i32> = buffer
        .trim()
        .split_ascii_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    let (n, m, k) = (buffer[0], buffer[1], buffer[2]);
    for _ in 0..k {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
    }
    for _ in 0..k {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
    }

    let mut rls: Vec<String> = Vec::new();

    for _ in 1..n {
        rls.push("D".to_string());
    }
    for _ in 1..m {
        rls.push("L".to_string());
    }

    for i in 0..n {
        if i % 2 == 0 {
            for _ in 1..m {
                rls.push("R".to_string());
            }
        } else {
            for _ in 1..m {
                rls.push("L".to_string());
            }
        }
        rls.push("U".to_string());
    }
    rls.pop();

    writeln!(stdout, "{}", rls.len()).unwrap();
    writeln!(stdout, "{}", rls.join("")).unwrap();
}
