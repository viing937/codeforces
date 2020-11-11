package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scan(&t)
	for tt := 0; tt < t; tt++ {
		var n, x int
		fmt.Scan(&n, &x)
		a := make([]int, n)
		b := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&a[i])
		}
		for i := 0; i < n; i++ {
			fmt.Scan(&b[i])
		}
		if check(a, b, x) {
			fmt.Println("Yes")
		} else {
			fmt.Println("No")
		}
	}
}

func check(a, b []int, x int) bool {
	n := len(a)
	a = sort.IntSlice(a)
	b = sort.IntSlice(b)
	for i := 0; i < n; i++ {
		j := n - i - 1
		if a[i]+b[j] > x {
			return false
		}
	}
	return true
}
