package main

import "fmt"

func main() {
	var t int
	fmt.Scan(&t)
	for tc := 0; tc < t; tc++ {
		var n, x, y int64
		fmt.Scan(&n, &x, &y)
		best, worst := solve(n, x, y)
		fmt.Println(best, worst)
	}
}

func solve(n, x, y int64) (best, worst int64) {
	if x > y {
		x, y = y, x
	}

	best = x - (n - y - 1)
	if best < 1 {
		best = 1
	} else if best > n {
		best = n
	}
	worst = y + x - 1
	if worst < 1 {
		worst = 1
	} else if worst > n {
		worst = n
	}
	return best, worst
}
