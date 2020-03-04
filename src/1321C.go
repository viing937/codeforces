package main

import "fmt"

func main() {
	var n int
	var s string
	fmt.Scan(&n, &s)
	rls := solve(n, s)
	fmt.Println(rls)
}

func solve(n int, s string) int {
	chs := []rune(s)
	for ch := 'z'; ch > 'a'; ch-- {
		for i := 1; i < len(chs); i++ {
			for i < len(chs) && chs[i] == ch && chs[i-1] == ch-1 {
				chs = append(chs[:i], chs[i+1:]...)
			}
		}
		for i := len(chs) - 2; i >= 0; i-- {
			if i+1 < len(chs) && chs[i] == ch && chs[i+1] == ch-1 {
				chs = append(chs[:i], chs[i+1:]...)
			}
		}
	}
	return len(s) - len(chs)
}
