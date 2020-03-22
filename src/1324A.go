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
		var n int
		fmt.Fscan(r, &n)
		a := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Fscan(r, &a[i])
		}
		rls := solve(a)
		if rls {
			fmt.Println("YES")
		} else {
			fmt.Println("NO")
		}
	}
}

func solve(a []int) bool {
	odd, even := 0, 0
	for _, v := range a {
		if v%2 > 0 {
			odd++
		} else {
			even++
		}
	}
	return odd == 0 || even == 0
}
