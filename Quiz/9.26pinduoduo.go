package main

import "fmt"

func main() {
	K := 0
	fmt.Scan(&K)
	for i := 0; i < K; i++ {
		n, k := 0, 0
		fmt.Scan(&n, &k)
		a := make([]int, n) //n个人的能力值

		for j := 0; j < n; j++ {
			fmt.Scan(&a[i])
		}
		m := make([][]int, n) //n-1个互斥关系  0行0列为空
		for i := 0; i < n; i++ {
			m[i] = make([]int, n)
		}
		for i := 0; i < n-1; i++ {
			x, y := 0, 0
			fmt.Scan(&x, &y)
			m[x][y] = 1
			m[y][x] = 1
		}
		for i := 0; i < count; i++ {

		}
	}
}
