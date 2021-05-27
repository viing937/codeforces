use std::{
    fmt::Debug,
    io::{self, BufRead, BufReader, BufWriter, Write},
    str::FromStr,
};

#[derive(Clone)]
struct Robot(usize, i32, char);

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());

    let t: i32 = read_one(&mut stdin);
    for _ in 0..t {
        let buf: Vec<i32> = read_line(&mut stdin, " ");
        let n: usize = buf[0] as usize;
        let m = buf[1];

        let x: Vec<i32> = read_line(&mut stdin, " ");
        let d: Vec<char> = read_line(&mut stdin, " ");

        let mut r: Vec<Robot> = (0..n)
            .into_iter()
            .map(|i| Robot(i, x[i].clone(), d[i].clone()))
            .collect();
        r.sort_by_key(|x| x.1);

        let mut rls: Vec<i32> = vec![-1; n];
        solve(&r, &mut rls, m, 0);
        solve(&r, &mut rls, m, 1);

        let rls: Vec<String> = rls.iter().map(|x| x.to_string()).collect();
        writeln!(stdout, "{}", rls.join(" ")).unwrap();
    }
}

fn solve(r: &Vec<Robot>, rls: &mut Vec<i32>, m: i32, odd: i32) {
    let mut left: Vec<Robot> = Vec::new();
    let mut right: Vec<Robot> = Vec::new();
    for robot in r.iter() {
        if robot.1 % 2 == odd {
            continue;
        }
        if robot.2 == 'L' {
            if right.len() > 0 {
                let robot_ = right.pop().unwrap();
                let t = (robot.1 - robot_.1) / 2;
                rls[robot_.0] = t;
                rls[robot.0] = t;
            } else {
                left.push(robot.to_owned());
            }
        } else {
            right.push(robot.to_owned());
        }
    }
    while right.len() >= 2 {
        let a = right.pop().unwrap();
        let b = right.pop().unwrap();
        let t = (a.1 - b.1) / 2 + m - a.1;
        rls[a.0] = t;
        rls[b.0] = t;
    }
    left.reverse();
    while left.len() >= 2 {
        let a = left.pop().unwrap();
        let b = left.pop().unwrap();
        let t = (b.1 - a.1) / 2 + a.1;
        rls[a.0] = t;
        rls[b.0] = t;
    }
    if right.len() > 0 && left.len() > 0 {
        let a = right.pop().unwrap();
        let b = left.pop().unwrap();
        let t = ((m - a.1) + b.1 + m) / 2;
        rls[a.0] = t;
        rls[b.0] = t;
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
