use std::{
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let t: i32 = read_one(&mut stdin);
    for _ in 0..t {
        let n: usize = read_one(&mut stdin);
        let a: Vec<i32> = read_line(&mut stdin, " ");
        let mut cnt: Vec<i32> = vec![0; n];
        for i in 0..n {
            for j in 0..n {
                if i == j {
                    continue;
                }
                if gcd(a[i], 2 * a[j]) > 1 {
                    cnt[i] += 1;
                }
            }
        }
        let mut cnt: Vec<(usize, i32)> = cnt.iter().enumerate().map(|x| (x.0, *x.1)).collect();
        let mut rls: i32 = 0;
        while cnt.len() > 0 {
            cnt.sort_by_key(|x| x.1);
            let last = cnt.pop().unwrap();
            rls += last.1;
            for item in cnt.iter_mut() {
                if gcd(a[item.0], 2 * a[last.0]) > 1 {
                    item.1 -= 1;
                }
            }
        }
        writeln!(stdout, "{}", rls).unwrap();
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if a == 0 {
        b
    } else {
        gcd(b % a, a)
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
