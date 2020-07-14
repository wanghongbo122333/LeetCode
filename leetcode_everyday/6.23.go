package main

import (
	"container/list"
	"fmt"
	"math"
	"math/big"
	"strconv"
)

func addBinary(a string, b string) string {
	x := binary2int(a)
	y := binary2int(b)
	fmt.Print(x, y)
	return strconv.FormatInt(int64(x+y), 2)
}
func addBinary2(a string, b string) string {
	ai, _ := new(big.Int).SetString(a, 2)
	bi, _ := new(big.Int).SetString(b, 2)

	ai.Add(ai, bi)
	return ai.Text(2)

}
func main() {
	fmt.Print(addBinary2("1001", "1001"))
}

//二进制转int
func binary2int(s string) int {
	sum := 0
	var stnum, conum float64 = 0, 2
	stack := list.New()
	for _, c := range s {
		stack.PushBack(c)
	}

	for e := stack.Back(); e != nil; e = e.Prev() {
		v := e.Value.(int32)
		sum += int(v-48) * int(math.Pow(conum, stnum))
		stnum++
	}
	return sum

}
