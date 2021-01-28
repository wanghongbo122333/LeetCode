package main

import (
	"fmt"
	// "strconv"
	"time"
)

func main() {
	// line:=""
	// fmt.Scan(&line)
	// str:=string(line)
	// idx:=0
	// for {
	// 	// fmt.Print(str[idx:idx+1])
	// 	nn,_:=strconv.Atoi(str[idx:idx+1])
	// 	fmt.Print(nn)
	// 	idx+=1
	// 	if idx==len(str) {
	// 		break
	// 	}
	// }

	open := true

	go func() {
		for {
			if open {
				fmt.Print("a")
			}
		}
		time.Sleep(100 * time.Millisecond)
		fmt.Print("b")
	}()

	time.Sleep(200 * time.Millisecond)
	open = false
	fmt.Print("b")
	time.Sleep(200 * time.Millisecond)
	fmt.Print("c")
}
