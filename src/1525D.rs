use std::{
    cmp::min,
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let _: usize = read_one(&mut stdin);
    let a: Vec<usize> = read_line(&mut stdin, " ");

    let x: Vec<i32> = a
        .iter()
        .enumerate()
        .filter(|t| *t.1 == 1)
        .map(|t| t.0 as i32)
        .collect();
    let y: Vec<i32> = a
        .iter()
        .enumerate()
        .filter(|t| *t.1 == 0)
        .map(|t| t.0 as i32)
        .collect();

    let m = x.len();
    let n = y.len();
    let mut dp = vec![vec![i32::MAX; n + 1]; m + 1];
    for i in 0..n + 1 {
        dp[0][i] = 0;
    }
    for i in 1..m + 1 {
        for j in i..n + 1 {
            dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + (x[i - 1] - y[j - 1]).abs())
        }
    }
    writeln!(stdout, "{}", dp[m][n]).unwrap();
}

fn read_one<R, T>(r: &mut R) -> T
where
    R: BufRead,
    T: FromStr,
    <T as FromStr>::Err: Debug,
{
    read_line(r, "\n").remove(0)
}

fn read_line<R, T>(r: &mut R, sep: &str) -> Vec<T>
where
    R: BufRead,
    T: FromStr,
    <T as FromStr>::Err: Debug,
{
    let mut buf = String::new();
    r.read_line(&mut buf).unwrap();
    buf.trim().split(sep).map(|x| x.parse().unwrap()).collect()
}
