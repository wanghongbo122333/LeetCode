package main

import (
	"fmt"
	"sort"
)

/*你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。
你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。
返回的长度需要从小到大排列。

示例：

输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
提示：

0 < shorter <= longer
0 <= k <= 100000*/

func main() {
	fmt.Println(divingBoard(1, 2, 3))
}

func divingBoard(shorter int, longer int, k int) []int {
	if k == 0 {
		return nil
	}
	var m map[int]int = make(map[int]int)
	var res []int = make([]int, 0)
	for i := 0; i <= k; i++ {
		tmp := i*shorter + (k-i)*longer
		m[tmp] = 1
	}
	for k, _ := range m {
		res = append(res, k)
	}
	sort.Ints(res)
	return res
}

func divingBoard(shorter int, longer int, k int) []int {
	//k=0 nil
	if k == 0 {
		return nil
	}
	if shorter == longer {
		return []int{longer * k}
	}
	// var res []int = make([]int, 0)
	res := make([]int, k+1)
	shortest := k * shorter
	dis := longer - shorter
	for i := 0; i <= k; i++ {
		res[i] = shortest + dis*i
	}
	return res
}
