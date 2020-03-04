package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	r := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&r[i])
	}
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	rls := solve(n, r, b)
	fmt.Println(rls)
}

func solve(n int, r, b []int) int {
	nr, nb := 0, 0
	for i := 0; i < n; i++ {
		if r[i] == 1 && b[i] == 0 {
			nr += 1
		}
		if r[i] == 0 && b[i] == 1 {
			nb += 1
		}
	}
	var rls int
	if nr == 0 {
		rls = -1
	} else {
		rls = nb/nr + 1
	}
	return rls
}
