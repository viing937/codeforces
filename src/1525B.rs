use std::{
    io::{self, BufRead},
    usize,
};

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
        let n: usize = buffer.trim().parse().unwrap();

        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let arr: Vec<usize> = buffer
            .trim()
            .split(" ")
            .map(|x| x.parse().unwrap())
            .collect();

        let mut is_sorted = true;
        for (i, &val) in arr.iter().enumerate() {
            if i + 1 != val {
                is_sorted = false;
                break;
            }
        }
        if is_sorted {
            writeln!(stdout, "{}", 0).unwrap();
        } else if arr[0] == 1 || arr[n - 1] == n {
            writeln!(stdout, "{}", 1).unwrap();
        } else if arr[0] == n && arr[n - 1] == 1 {
            writeln!(stdout, "{}", 3).unwrap();
        } else {
            writeln!(stdout, "{}", 2).unwrap();
        }
    }
}
