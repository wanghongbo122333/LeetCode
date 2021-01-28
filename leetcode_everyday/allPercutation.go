package main

import (
	"fmt"
)

func main() {
	// fmt.Printf("%d", int('b'-'a'))
	percutation([]rune{'a', 'b', 'c'}, 0, 3)
}
func percutation(ch []rune, k, m int) {
	if k == m {
		for _, k := range ch {
			fmt.Printf("%c ", k)
		}
		fmt.Println()
	} else {
		for i := k; i < m; i++ {
			swap(ch, k, i)
			percutation(ch, k+1, m)
			swap(ch, k, i)
		}
	}
}
func swap(ch []rune, k, i int) {
	ch[k], ch[i] = ch[i], ch[k]
}
