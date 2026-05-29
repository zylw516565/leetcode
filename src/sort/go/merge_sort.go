package main

import (
	"fmt"
)

func main() {
	nums := []int{6, 4, 2, 5, 3, 1}
	fmt.Println(nums)
	merge_sort(nums)
	fmt.Println(nums)
}

func merge_sort(nums []int) {
	if len(nums) < 2 {
		return
	}

	left := 0
	right := len(nums) - 1

	merge_sort_c(nums, left, right)
}

func merge_sort_c(nums []int, left, right int) {
	if left >= right {
		return
	}

	mid := (left + right) / 2
	merge_sort_c(nums, left, mid)
	merge_sort_c(nums, mid+1, right)

	merge(nums, left, right)
}

func merge(nums []int, left, right int) {
	i := left
	mid := (left + right) / 2
	j := mid + 1

	var tmps []int
	for i <= mid && j <= right {
		if nums[i] <= nums[j] {
			tmps = append(tmps, nums[i])
			i++
		} else {
			tmps = append(tmps, nums[j])
			j++
		}
	}

	for ; i <= mid; i++ {
		tmps = append(tmps, nums[i])
	}

	for ; j <= right; j++ {
		tmps = append(tmps, nums[j])
	}

	i = left
	k := 0
	for i <= right {
		nums[i] = tmps[k]
		i++
		k++
	}
}
