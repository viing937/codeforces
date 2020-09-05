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
	for i := 0; i < t; i++ {
		var n, k int
		fmt.Fscan(r, &n, &k)
		var rls int
		if n < k {
			rls = k - n
		} else if (n-k)%2 > 0 {
			rls = 1
		} else {
			rls = 0
		}
		fmt.Println(rls)
	}
}
