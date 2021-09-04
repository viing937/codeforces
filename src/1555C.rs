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
        let m: usize = read_one(&mut stdin);
        let mut a = vec![vec![0i64; 0]; 2];
        a[0] = read_line(&mut stdin, " ");
        a[1] = read_line(&mut stdin, " ");

        for i in 0..2 {
            for j in 1..m {
                a[i][j] += a[i][j - 1];
            }
        }

        let mut rslt = i64::MAX;
        for p in 0..m {
            let v1 = seg_acc(&a, 0, p + 1, m);
            let v2 = seg_acc(&a, 1, 0, p);
            let t = max(v1, v2);
            rslt = min(rslt, t);
        }
        writeln!(stdout, "{}", rslt).unwrap();
    }
}

fn seg_acc(a: &Vec<Vec<i64>>, i: usize, l: usize, r: usize) -> i64 {
    if l >= r {
        0
    } else if l == 0 {
        a[i][r - 1]
    } else {
        a[i][r - 1] - a[i][l - 1]
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
