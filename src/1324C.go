package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(r, &t)
	for tc := 0; tc < t; tc++ {
		var s string
		fmt.Fscan(r, &s)
		rls := solve(s)
		fmt.Println(rls)
	}
}

func solve(s string) int {
	s = "R" + s + "R"
	cur, rls := 0, 0
	for i, ch := range s {
		if ch == 'R' {
			if i-cur > rls {
				rls = i - cur
			}
			cur = i
		}
	}
	return rls
}
