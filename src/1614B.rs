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
        let ai: Vec<i64> = read_line(&mut stdin, " ");
        let mut ai: Vec<(usize, i64)> = ai.into_iter().enumerate().map(|x| (x.0 + 1, x.1)).collect();

        ai.sort_by(|a, b| b.1.cmp(&a.1));

        let mut xi: Vec<i64> = vec![0; n + 1];
        let mut sum_dis: i64 = 0;
        let mut cnt: i64 = 0;
        for (idx, a) in ai.into_iter() {
            sum_dis += 2 * a * (cnt / 2 + 1);
            if cnt % 2 == 0 {
                xi[idx] = cnt / 2 + 1;
            } else {
                xi[idx] = -(cnt / 2 + 1);
            }
            cnt += 1;
        }
        writeln!(stdout, "{}", sum_dis).unwrap();
        writeln!(
            stdout,
            "{}",
            xi.into_iter()
                .map(|x| x.to_string())
                .collect::<Vec<String>>()
                .join(" ")
        )
        .unwrap();
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
