use std::cmp;
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

        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let a: Vec<i64> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse().unwrap())
            .collect();

        let mut pos: Vec<i64> = Vec::new();
        let mut neg: Vec<i64> = Vec::new();
        for ai in a {
            if pos.len() == 0 {
                if ai > 0 {
                    pos.push(ai);
                }
            } else {
                if pos.last().unwrap() ^ ai >= 0 {
                    let last = pos.pop().unwrap();
                    pos.push(cmp::max(last, ai));
                } else {
                    pos.push(ai);
                }
            }

            if neg.len() == 0 {
                if ai < 0 {
                    neg.push(ai);
                }
            } else {
                if neg.last().unwrap() ^ ai >= 0 {
                    let last = neg.pop().unwrap();
                    neg.push(cmp::max(last, ai));
                } else {
                    neg.push(ai);
                }
            }
        }

        if pos.len() > neg.len() {
            writeln!(stdout, "{}", pos.iter().sum::<i64>()).unwrap();
        } else if neg.len() > pos.len() {
            writeln!(stdout, "{}", neg.iter().sum::<i64>()).unwrap();
        } else {
            let rls = cmp::max(pos.iter().sum::<i64>(), neg.iter().sum::<i64>());
            writeln!(stdout, "{}", rls).unwrap();
        }
    }
}
