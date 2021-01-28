package main

import (
	"fmt"
	"strconv"
)

func main() {
	// fmt.Printf("%d", int('b'-'a'))
	fmt.Println(addStrings("1237", "123"))
}

func addStrings(num1 string, num2 string) string {
	l1 := len(num1)
	l2 := len(num2)
	idx1 := l1 - 1
	idx2 := l2 - 1
	carry := 0
	res := ""
	for {
		sum := 0
		if idx1 >= 0 || idx2 >= 0 {
			if idx1 >= 0 {
				sum += int(num1[idx1] - '0')
				idx1 -= 1
			}
			if idx2 >= 0 {
				sum += int(num1[idx2] - '0')
				idx2 -= 1
			}
			sum += carry
			carry = sum / 10
			sum = sum % 10
			res = strconv.Itoa(sum) + res
		} else {
			break
		}
	}
	if carry != 0 {
		res = strconv.Itoa(carry) + res
	}

	return res

}
