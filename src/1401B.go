package main

import (
	"bufio"
	"fmt"
	"os"
)

func min(x, y int64) int64 {
	if x < y {
		return x
	} else {
		return y
	}
}

func main() {
	r := bufio.NewReader(os.Stdin)
	var t int
	fmt.Fscan(r, &t)
	for tc := 0; tc < t; tc++ {
		var x1, y1, z1 int64
		fmt.Fscan(r, &x1, &y1, &z1)
		var x2, y2, z2 int64
		fmt.Fscan(r, &x2, &y2, &z2)

		tmp := min(z1, y2)
		z1, y2 = z1-tmp, y2-tmp
		rls := 2 * tmp

		tmp = min(x1+z1, z2)
		rls -= 2 * (z2 - tmp)
		fmt.Println(rls)
	}
}
