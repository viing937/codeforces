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
    let t: i32 = buffer.trim().parse().unwrap();
    for _ in 0..t {
        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();

        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let a: Vec<i32> = buffer
            .split_whitespace()
            .map(|x| x.trim().parse().unwrap())
            .collect();

        let mut buffer = String::new();
        stdin.read_line(&mut buffer).unwrap();
        let l: Vec<i32> = buffer
            .split_whitespace()
            .map(|x| x.trim().parse().unwrap())
            .collect();

        let rls: Vec<String> = solve(&a, &l).iter().map(|x| x.to_string()).collect();
        writeln!(stdout, "{}", rls.join(" ")).unwrap();
    }
}

fn solve(a: &Vec<i32>, l: &Vec<i32>) -> Vec<i32> {
    let mut unlocks: Vec<i32> = Vec::new();
    for (idx, num) in a.iter().enumerate() {
        if l[idx] == 0 {
            unlocks.push(*num);
        }
    }
    unlocks.sort();
    let mut rls = a.clone();
    for idx in 0..rls.len() {
        if l[idx] == 0 {
            rls[idx] = unlocks.pop().unwrap();
        }
    }
    return rls;
}
