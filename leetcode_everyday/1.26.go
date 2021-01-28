package main

import "fmt"

func numEquivDominoPairs(dominoes [][]int) int {
	var cnt int
	cnt = 0
	for i := 0; i < len(dominoes); i++ {
		for j := i + 1; j < len(dominoes); j++ {
			if dominoes[i][0] == dominoes[j][0] && dominoes[i][1] == dominoes[j][1] || dominoes[i][0] == dominoes[j][1] && dominoes[i][1] == dominoes[j][0] {
				cnt = cnt + 1
			}
		}
	}
	return cnt
}

func main() {
	arr:=[][]int{{1,2},{2,1},{3,4},{4,3}}
	fmt.Println(numEquivDominoPairs(arr))
}