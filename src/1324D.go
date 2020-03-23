package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	var n int
	fmt.Fscan(r, &n)
	topics := make([][]int, n)
	for i := 0; i < n; i++ {
		topics[i] = make([]int, 2)
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &topics[i][0])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &topics[i][1])
	}
	rls := solve(topics)
	fmt.Println(rls)
}

func solve(topics [][]int) int64 {
	n := len(topics)
	sort.Slice(topics, func(i, j int) bool {
		v1 := topics[i][0] - topics[i][1]
		v2 := topics[j][0] - topics[j][1]
		return v1 < v2
	})
	rls := int64(0)
	for i := n - 1; i > 0; i-- {
		idx := sort.Search(i, func(j int) bool {
			return topics[j][0]-topics[j][1] > topics[i][1]-topics[i][0]
		})
		rls += int64(i - idx)
	}
	return rls
}
