use std::{
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let _: i32 = read_one(&mut stdin);
    let s: String = read_one(&mut stdin);
    let mut s: Vec<_> = s.chars().rev().collect();

    let n = s.len();
    let mut dp: Vec<i64> = vec![1; n * 2 + 1];
    for i in (0..n).rev() {
        dp[i] = calculate(&s, &dp, i);
    }
    let q: usize = read_one(&mut stdin);
    for _ in 0..q {
        let qs: String = read_one(&mut stdin);
        let qs: Vec<&str> = qs.split(" ").collect();
        let mut p: usize = n - qs[0].parse::<usize>().unwrap();
        let c: char = qs[1].chars().nth(0).unwrap();

        s[p] = c;
        while p > 0 {
            dp[p] = calculate(&s, &dp, p);
            p = (p - 1) / 2;
        }
        dp[0] = calculate(&s, &dp, 0);
        writeln!(stdout, "{}", dp[0]).unwrap();
    }
}

fn calculate(s: &Vec<char>, dp: &Vec<i64>, i: usize) -> i64 {
    let p0 = i * 2 + 2;
    let p1 = i * 2 + 1;
    if s[i] == '0' {
        return dp[p0];
    } else if s[i] == '1' {
        return dp[p1];
    } else {
        return dp[p0] + dp[p1];
    }
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
