package main

import (
	"fmt"
	"strings"
)

func main() {
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var s string
		fmt.Scan(&s)
		s = strings.Trim(s, "0")
		fmt.Println(strings.Count(s, "0"))
	}
}
