use std::{
    cmp::max,
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let t: i32 = read_one(&mut stdin);
    for _ in 0..t {
        let s: String = read_one(&mut stdin);
        let len = s.len();
        let mut dp = vec![vec![0; len + 1]; 2];
        let mut rslt: i64 = 0;
        for (i, ch) in s.chars().enumerate() {
            if ch == '?' {
                dp[0][i + 1] = dp[1][i] + 1;
                dp[1][i + 1] = dp[0][i] + 1;
            } else if ch == '1' {
                dp[1][i + 1] = dp[0][i] + 1;
            } else if ch == '0' {
                dp[0][i + 1] = dp[1][i] + 1;
            }
            rslt += max(dp[0][i + 1], dp[1][i + 1]);
        }
        writeln!(stdout, "{}", rslt).unwrap();
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
