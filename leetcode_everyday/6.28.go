package main

import (
	"fmt"
	"math"
)

//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。
//如果不存在符合条件的连续子数组，返回 0。
// 示例：
// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的连续子数组。 注意是连续子数组，要连续！！
func main() {
	fmt.Print(minSubArrayLen(213, []int{12, 28, 83, 4, 25, 26, 25, 2, 25, 25, 25, 12}))
}

func minSubArrayLen(s int, nums []int) int {
	ans := math.MaxInt32
	if len(nums) == 0 {
		return 0
	}
	for i := 0; i < len(nums); i++ {
		sum := 0
		for j := i; j < len(nums); j++ {
			sum += nums[j]
			if sum >= s {
				ans = min(j-i+1, ans)
				break
			}
		}
	}
	if ans == math.MaxInt32 {
		return 0
	}
	return ans
}

func Min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

//-----------------------------------------双指针法------------------------------------------
func minSubArrayLen2(s int, nums []int) int {
	n := len(nums)
	if n == 0 {
		return 0
	}
	ans := math.MaxInt32
	start, end := 0, 0
	sum := 0
	for end < n {
		sum += nums[end]
		for sum >= s {
			ans = min(ans, end-start+1)
			sum -= nums[start]
			start++
		}
		end++
	}
	if ans == math.MaxInt32 {
		return 0
	}
	return ans
}

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}
