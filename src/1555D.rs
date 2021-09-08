use std::{
    cmp::min,
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let v: Vec<usize> = read_line(&mut stdin, " ");
    let (n, m) = (v[0], v[1]);
    let s: String = read_one(&mut stdin);
    let s = s.as_bytes();

    let permu = vec![
        "abc".as_bytes(),
        "acb".as_bytes(),
        "bac".as_bytes(),
        "bca".as_bytes(),
        "cab".as_bytes(),
        "cba".as_bytes(),
    ];
    let mut dp = vec![vec![0i64; n + 1]; 6];
    for i in 0..6 {
        for j in 0..n {
            dp[i][j + 1] = dp[i][j];
            if s[j] != permu[i][j % 3] {
                dp[i][j + 1] += 1;
            }
        }
    }
    for _ in 0..m {
        let v: Vec<usize> = read_line(&mut stdin, " ");
        let (l, r) = (v[0], v[1]);
        let mut rslt = i64::MAX;
        for i in 0..6 {
            rslt = min(rslt, dp[i][r] - dp[i][l - 1]);
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
