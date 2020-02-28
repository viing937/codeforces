package main

import "fmt"

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var a, b, x, y int
		fmt.Scan(&a, &b, &x, &y)
		rls := 0
		rls = max(rls, a*y)
		rls = max(rls, a*(b-y-1))
		rls = max(rls, b*x)
		rls = max(rls, b*(a-x-1))
		fmt.Println(rls)
	}
}
