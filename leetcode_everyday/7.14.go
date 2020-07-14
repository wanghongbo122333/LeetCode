package main

import (
	"fmt"
	"math"
	"learngo/util"
)

/*给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。



例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

func main()  {
	fmt.Println(minimumTotal([][]int{{2},{3,4},{6,5,7},{4,1,8,3}}))
}

func minimumTotal(tra [][]int) int {
	//dp[i][j]表示从顶点到达tra[i][j]的最短路径
	//dp[i][j]=min{dp[i-1][j],dp[i-1][j-1]}+tra[i][j]
	n:=len(tra)
	dp:=make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i]=make([]int, len(tra[i]))
	}
	dp[0][0]=tra[0][0]
	for i := 1; i < n; i++ {
		//特殊处理最左侧列：只能每列都选左边的数字下来
		dp[i][0]=dp[i-1][0]+tra[i][0]
		for j := 1; j < i; j++ {//注意此处j限制条件j<i，因为dp[i][j>i]处是不可达的
			dp[i][j]=util.Min(dp[i-1][j-1],dp[i-1][j])+tra[i][j]
		}
		//特殊处理dp[i][i] 每次都向右下走
		dp[i][i]=dp[i-1][i-1]+tra[i][i]
	}
	minV:=math.MaxInt32
	for i := 0; i < len(tra[n-1]); i++ {
		minV=util.Min(minV,dp[n-1][i])
	}
	return minV
}