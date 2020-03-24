package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	var n, h, l, r int
	fmt.Fscan(reader, &n, &h, &l, &r)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &a[i])
	}
	rls := solve(h, l, r, a)
	fmt.Println(rls)
}

func solve(h, l, r int, a []int) int {
	n := len(a)
	dp := make(map[int]int)
	dp[0] = 0
	for i := 0; i < n; i++ {
		newdp := make(map[int]int)
		for k, v := range dp {
			k1 := (k + a[i]) % h
			k2 := (k + a[i] - 1) % h
			if newdp[k1] <= v {
				newdp[k1] = v
			}
			if newdp[k2] <= v {
				newdp[k2] = v
			}
		}
		dp = newdp
		for k, v := range dp {
			if k >= l && k <= r {
				dp[k] = v + 1
			}
		}
	}
	rls := 0
	for _, v := range dp {
		if rls < v {
			rls = v
		}
	}
	return rls
}
