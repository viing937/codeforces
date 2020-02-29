package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scan(&t)
	for tc := 0; tc < t; tc++ {
		var a, b, c int
		fmt.Scan(&a, &b, &c)
		rls := solve(a, b, c)
		fmt.Println(rls)
	}
}

func solve(a, b, c int) int {
	arr := []int{a, b, c}
	sort.Sort(sort.Reverse(sort.IntSlice(arr)))
	rls := 0
	for i := 0; i < 3; i++ {
		if arr[i] > 0 {
			rls += 1
			arr[i] -= 1
		}
	}
	for i := 0; i < 3; i++ {
		for j := i + 1; j < 3; j++ {
			if arr[i] > 0 && arr[j] > 0 {
				rls += 1
				arr[i] -= 1
				arr[j] -= 1
			}
		}
	}
	if arr[0] > 0 && arr[1] > 0 && arr[2] > 0 {
		rls += 1
	}
	return rls
}
