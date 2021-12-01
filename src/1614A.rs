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
        let v: Vec<i32> = read_line(&mut stdin, " ");
        let (_, l, r, mut k) = (v[0], v[1], v[2], v[3]);

        let a: Vec<i32> = read_line(&mut stdin, " ");
        let mut a: Vec<i32> = a.into_iter().filter(|&x| x >= l && x <= r).collect();
        a.sort();

        let mut rls = 0;
        for item in a.into_iter() {
            if k < item {
                break;
            } else {
                rls += 1;
                k -= item;
            }
        }
        writeln!(stdout, "{}", rls).unwrap();
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
