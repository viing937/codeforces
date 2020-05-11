use std::io;
use std::io::BufRead;
use std::io::BufReader;
use std::io::BufWriter;
use std::io::Write;

fn main() {
    let mut stdin = BufReader::new(io::stdin());
    let mut stdout = BufWriter::new(io::stdout());
    let mut buffer = String::new();

    stdin.read_line(&mut buffer).unwrap();
    let t = buffer.trim().parse().unwrap();
    for _ in 0..t {
        buffer.clear();
        stdin.read_line(&mut buffer).unwrap();
        let mut n: i32 = buffer.trim().parse().unwrap();

        let mut base: i32 = 1;
        let mut ans: Vec<i32> = Vec::new();

        while n != 0 {
            if n % 10 > 0 {
                ans.push(n % 10 * base);
            }
            n /= 10;
            base *= 10;
        }

        let ans: Vec<String> = ans.iter().map(|x| x.to_string()).collect();
        writeln!(stdout, "{}", ans.len()).unwrap();
        writeln!(stdout, "{}", ans.join(" ")).unwrap();
    }
}
