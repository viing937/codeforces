package main

import (
	"fmt"
	"strings"
)

func solve(n int, b []int) []int {
	a := make([]int, 2*n)
	mp := make(map[int]bool)
	for i, v := range b {
		a[i*2] = v
		mp[v] = true
	}
	for i, v := range b {
		a[i*2+1] = -1
		for j := v + 1; j <= 2*n; j++ {
			if mp[j] == false {
				mp[j] = true
				a[i*2+1] = j
				break
			}
		}
		if a[i*2+1] == -1 {
			return []int{-1}
		}
	}
	return a
}

func main() {
	var t int
	fmt.Scan(&t)
	for tc := 0; tc < t; tc++ {
		var n int
		fmt.Scan(&n)
		b := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&b[i])
		}
		a := solve(n, b)
		fmt.Println(strings.Trim(fmt.Sprint(a), "[]"))
	}
}
