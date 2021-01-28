//求和不为0 的子数组个数

package main

import (
	"fmt"
)

func main() {
	// n := 0
	// fmt.Scan(&n)
	// arr := make([]int, 0)
	// for i := 0; i < n; i++ {
	// 	t := 0
	// 	fmt.Scan(&t)
	// 	arr = append(arr, t)
	// }
	arr := []int{1, 0, -2}
	countOfNonZero(arr)
}

func countOfNonZero(a []int) int {

	len := len(a)
	dp := make([][]int, len)
	for i := 0; i < len; i++ {
		dp[i] = make([]int, len)
		dp[i][i] = a[i]
	}
	for i := 0; i < len; i++ {
		for j := i + 1; j < len; j++ {
			dp[i][j] = dp[i][j-1] + a[j]
		}
	}
	count := 0
	for i := 0; i < len; i++ {
		for j := 0; j < len; j++ {
			fmt.Printf("dp[%d][%d]=%d ", i, j, dp[i][j])
			if dp[i][j] != 0 {
				count += 1
			}
		}
	}
	return count
}
