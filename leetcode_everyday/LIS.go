package main

import (
	"LeetCode/util"
	"fmt"
)

func main() {
	fmt.Println(LIS([]int{1, 6, 3, 4}))
}

//最长递增子序列
func LIS(nums []int) int {
	//dp[i] 为考虑前 ii 个元素，以第 ii 个数字结尾的最长上升子序列的长度
	//dp[i]=max(dp[j])+1,其中0≤j<i且num[j]<num[i]
	//IS length=max(dp[i]),其中0≤i<n
	dp := make([]int, len(nums))
	dp[0] = 1
	maxAns := 1
	for i := 1; i < len(nums); i++ {
		maxval := 0
		for j := 0; j < i; j++ {
			if nums[i] > nums[j] {
				maxval = util.Max(dp[j], maxval)
			}
		}
		dp[i] = maxval + 1
		maxAns = util.Max(maxAns, dp[i])
	}
	return maxAns
}
