package util

import "sort"

func Min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func quickSort(arr []int) []int {
	return _quickSort(arr, 0, len(arr)-1)
}

func _quickSort(arr []int, left, right int) []int {
	if left < right {
		partitionIndex := partition(arr, left, right)
		_quickSort(arr, left, partitionIndex-1)
		_quickSort(arr, partitionIndex+1, right)
	}
	return arr
}

func partition(arr []int, left, right int) int {
	pivot := left
	index := pivot + 1

	for i := index; i <= right; i++ {
		if arr[i] < arr[pivot] {
			swap(arr, i, index)
			index += 1
		}
	}
	swap(arr, pivot, index-1)
	return index - 1
}

func swap(arr []int, i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

//Reverse
//链表节点
type ListNode struct {
	Val  int
	Next *ListNode
}

//反转链表的实现
func reversrList(head *ListNode) *ListNode {
	cur := head
	var pre *ListNode = nil
	for cur != nil {
		pre, cur, cur.Next = cur, cur.Next, pre //这句话最重要
	}
	return pre
}

func maxEnvelopes(envelopes [][]int) int {

	if len(envelopes) <= 1 {
		return len(envelopes)
	}

	sort.Slice(envelopes, func(i, j int) bool {

		return envelopes[i][0] < envelopes[j][0]

	})

	// fmt.Println(envelopes)

	dp := make([]int, len(envelopes)) //表示第几个信封里面最多套了多少个
	dp[0] = 1                         //

	maxEvs := 1
	for i, ev := range envelopes {

		if i == 0 {
			continue
		}

		tmpEvs := 0
		for j := i - 1; j >= 0; j-- {
			//如果ev 可以装下 第 j 个信封
			if ev[0] > envelopes[j][0] && ev[1] > envelopes[j][1] && dp[j] > tmpEvs {
				tmpEvs = dp[j]
			}
		}

		dp[i] = tmpEvs + 1
		if dp[i] > maxEvs {
			maxEvs = dp[i]
		}
	}

	return maxEvs

}
