package main

import (
	"fmt"
)

func main() {
	fmt.Println(RecursionLCS("abcde", "abd", 4, 2))
}

//if a[i]==b[j] dp[i][j]=1+dp[i-1][j-1]
//else dp[i][j]=max{dp[i-1][j],dp[i][j-1]}
func LCS(a, b string) int {
	la := len(a)
	lb := len(b)
	dp := make([][]int, la+1)
	for i := 0; i < la+1; i++ {
		dp[i] = make([]int, lb+1)
	}
	for i := 1; i <= la; i++ {
		for j := 1; j <= lb; j++ {
			if a[i-1] == b[j-1] {
				dp[i][j] = 1 + dp[i-1][j-1]
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}
	return dp[la][lb]
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

//递归方法
func RecursionLCS(a, b string, i, j int) int {
	if i < 0 || j < 0 {
		return 0
	}

	if a[i] == b[j] {
		return 1 + RecursionLCS(a, b, i-1, j-1)
	} else {
		return max(RecursionLCS(a, b, i-1, j), RecursionLCS(a, b, i, j-1))
	}
}
