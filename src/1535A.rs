use std::{
    cmp::{max, min},
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let t: i32 = read_one(&mut stdin);
    for _ in 0..t {
        let s: Vec<i32> = read_line(&mut stdin, " ");
        if min(s[0], s[1]) > max(s[2], s[3]) {
            writeln!(stdout, "NO").unwrap();
        } else if max(s[0], s[1]) < min(s[2], s[3]) {
            writeln!(stdout, "NO").unwrap();
        } else {
            writeln!(stdout, "YES").unwrap();
        }
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
