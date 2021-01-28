package main

import (
	"fmt"
)

func main() {
	n := 0
	fmt.Scan(&n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		temp := 0
		fmt.Scan(&temp)
		arr[i] = temp
	}
	for _, v := range arr {
		fmt.Println(deal(v))
	}
}

func deal(N int) int {
	count := 1
	for i := 2; N > i; {
		if N%i == 0 {
			N = N / i
			count += 1
		} else {
			i++
		}
	}
	return count
}
