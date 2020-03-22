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
	m := make(map[int]int)
	for i, v := range a {
		idx, ok := m[v]
		if ok {
			if idx+1 != i {
				return true
			}
		} else {
			m[v] = i
		}
	}
	return false
}
