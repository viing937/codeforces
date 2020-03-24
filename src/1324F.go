package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(r, &n)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(r, &a[i])
	}
	g := make([][]int, n+1)
	for i := 0; i < n-1; i++ {
		var u, v int
		fmt.Fscan(r, &u, &v)
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}
	rls := solve(n, a, g)
	fmt.Println(strings.Trim(fmt.Sprint(rls), "[]"))
}

func solve(n int, a []int, g [][]int) []int {
	for i := range a {
		if a[i] == 0 {
			a[i] = -1
		}
	}

	dp := make([]int, n+1)

	var dfs func(v, f int) int
	dfs = func(v, f int) int {
		dp[v] = a[v]
		for _, child := range g[v] {
			if child == f {
				continue
			}
			s := dfs(child, v)
			if s > 0 {
				dp[v] += s
			}
		}
		return dp[v]
	}
	dfs(1, 0)

	var calcu func(v, f int)
	calcu = func(v, f int) {
		if dp[v] > 0 {
			dp[v] = max(dp[v], dp[f])
		} else {
			dp[v] = max(dp[v], dp[v]+dp[f])
		}
		for _, child := range g[v] {
			if child == f {
				continue
			}
			calcu(child, v)
		}
	}
	calcu(1, 0)
	return dp[1:]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
