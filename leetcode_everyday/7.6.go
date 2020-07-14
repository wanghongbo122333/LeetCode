package main

import "fmt"

func main() {
	var array = [][]int{{0, 0}, {1, 1}, {0, 0}}
	// {0, 1, 0},
	// {0, 0, 0}}
	fmt.Print(uniquePathsWithObstacles(array))
}

func uniquePathsWithObstacles(array [][]int) int {
	m := len(array)
	n := len(array[0])

	dp := make([][]int, m)
	// 终点同一行列只有1种走法
	if array[0][0] == 1 || array[m-1][n-1] == 1 {
		return 0
	}
	for i := 0; i < m; i++ {
		dp[i] = make([]int, n)
		if i == 0 {
			dp[i][0] = 1
		} else {
			if i > 0 && array[i][0] == 0 {
				dp[i][0] = dp[i-1][0]
			} else {
				dp[i][0] = 0
			}
		}

	}
	for j := 0; j < n; j++ {
		if j == 0 {
			dp[0][j] = 1
		} else {
			if array[0][j] == 0 && j > 0 {
				dp[0][j] = dp[0][j-1]
			} else {
				dp[0][j] = 0
			}
		}

	}

	// f[m][n]=f[m-1][n]+f[m][n-1]  array[m][n]有障碍物则f[m][n]为0
	for i := 1; i < m; i++ {
		for j := 1; j < n; j++ {
			if array[i][j] == 1 {
				dp[i][j] = 0
			} else {
				dp[i][j] = dp[i-1][j] + dp[i][j-1]
			}
		}
	}
	// 打印结果矩阵
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			fmt.Printf("%d ", dp[i][j])
		}
		fmt.Println()
	}
	return dp[m-1][n-1]
}
