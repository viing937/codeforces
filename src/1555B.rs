use std::{
    cmp::max,
    cmp::min,
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let t: i32 = read_one(&mut stdin);
    for _ in 0..t {
        let v: Vec<i64> = read_line(&mut stdin, " ");
        let (max_w, max_h) = (v[0], v[1]);

        let v: Vec<i64> = read_line(&mut stdin, " ");
        let (x1, y1, x2, y2) = (v[0], v[1], v[2], v[3]);

        let v: Vec<i64> = read_line(&mut stdin, " ");
        let (w, h) = (v[0], v[1]);

        let mut rslt: i64 = i64::MAX;

        let dx: i64 = max(0, w - x1);
        if x2 + dx <= max_w {
            rslt = min(rslt, dx);
        }
        let dy: i64 = max(0, h - y1);
        if y2 + dy <= max_h {
            rslt = min(rslt, dy);
        }

        let dx: i64 = max(0, x2 + w - max_w);
        if x1 - dx >= 0 {
            rslt = min(rslt, dx);
        }
        let dy: i64 = max(0, y2 + h - max_h);
        if y1 - dy >= 0 {
            rslt = min(rslt, dy);
        }

        if rslt == i64::MAX {
            rslt = -1;
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
