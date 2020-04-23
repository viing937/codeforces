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
    let t: usize = buffer.trim().parse().unwrap();
    for _ in 0..t {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let n: usize = buffer.trim().parse().unwrap();

        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let p: Vec<usize> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();

        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let c: Vec<usize> = buffer
            .trim()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap() - 1)
            .collect();
        let rls = solve(n, &p, &c);
        writeln!(stdout, "{}", rls).unwrap();
    }
}

fn solve(n: usize, p: &Vec<usize>, c: &Vec<usize>) -> usize {
    let mut visited = vec![false; n];
    let mut rls = n;
    for i in 0..n {
        if visited[i] {
            continue;
        }

        let mut cycle: Vec<usize> = Vec::new();
        let mut v = i;
        while !visited[v] {
            visited[v] = true;
            cycle.push(v);
            v = p[v];
        }

        for k in 0..cycle.len() {
            let k = k + 1;
            if cycle.len() % k != 0 {
                continue;
            }

            for s in 0..k {
                let mut eq = true;
                for pos in (s..cycle.len() - k).step_by(k) {
                    if c[cycle[pos]] != c[cycle[pos + k]] {
                        eq = false;
                    }
                }
                if eq {
                    rls = cmp::min(rls, k);
                    break;
                }
            }
        }
    }
    return rls;
}
