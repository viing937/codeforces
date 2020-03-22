package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var n, m int
	fmt.Fscan(r, &n, &m)

	g := make([][]int, n+1)
	rg := make([][]int, n+1)
	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(r, &u, &v)
		g[u] = append(g[u], v)
		rg[v] = append(rg[v], u)
	}
	var k int
	fmt.Fscan(r, &k)
	p := make([]int, k)
	for i := 0; i < k; i++ {
		fmt.Fscan(r, &p[i])
	}
	min, max := solve(g, rg, p)
	fmt.Println(min, max)
}

func solve(g, rg [][]int, p []int) (int, int) {
	k := len(p)
	d := dijkstra(rg, p[k-1])
	var min, max int
	for i := 0; i < k-1; i++ {
		if d[p[i]] != d[p[i+1]]+1 {
			min++
		}
		for _, v := range g[p[i]] {
			if v != p[i+1] && d[p[i]] == d[v]+1 {
				max++
				break
			}
		}
	}
	return min, max
}

func dijkstra(g [][]int, src int) []int {
	n := len(g)
	d := make([]int, n)
	for i := 0; i < n; i++ {
		d[i] = -1
	}
	d[src] = 0
	q := []int{src}
	for len(q) > 0 {
		cur := q[0]
		q = q[1:]
		for _, v := range g[cur] {
			if d[v] == -1 {
				d[v] = d[cur] + 1
				q = append(q, v)
			}
		}
	}
	return d
}
