package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(r, &n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &b[i])
	}
	rls := solve(n, b)
	fmt.Println(rls)
}

func solve(n int, b []int) int64 {
	mp := make(map[int]int64)
	for i := 0; i < n; i++ {
		mp[b[i]-i] += int64(b[i])
	}
	rls := int64(0)
	for _, v := range mp {
		if rls < v {
			rls = v
		}
	}
	return rls
}
