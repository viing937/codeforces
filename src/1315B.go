package main

import "fmt"

func solve(a, b, p int64, s string) int {
	n := len(s)
	dp := make([]int64, n)
	dp[n-1] = 0
	if s[n-2] == 'A' {
		dp[n-2] = a
	} else {
		dp[n-2] = b
	}
	for i := n - 3; i >= 0; i-- {
		if s[i] == s[i+1] {
			dp[i] = dp[i+1]
		} else if s[i] == 'A' {
			dp[i] = dp[i+1] + a
		} else {
			dp[i] = dp[i+1] + b
		}
	}
	for i := 0; i < n; i++ {
		if dp[i] <= int64(p) {
			return i + 1
		}
	}
	return n
}

func main() {
	var t int
	fmt.Scan(&t)
	for tc := 0; tc < t; tc++ {
		var a, b, p int64
		var s string
		fmt.Scan(&a, &b, &p, &s)
		rls := solve(a, b, p, s)
		fmt.Println(rls)
	}
}
