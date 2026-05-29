package main

/*
a[5] 1 1 1 1 1 6
a[4] 2 2 2 2 6 1
a[3] 3 3 3 6 2 2
a[2] 6 6 6 3 3 3
a[1] 5 5 5 5 5 5
a[0] 4 4 4 4 4 4
***************>>
*/

// func main() {
// 	nums := []int{6, 4, 2, 5, 3, 1}
// 	fmt.Println(nums)
// 	res := bubbleSort(nums)
// 	fmt.Println(res)

// 	nums2 := []int{6, 8, 7, 4, 2, 5, 3, 1}
// 	fmt.Println(nums2)
// 	res = bubble_sort_optimized(nums2)
// 	fmt.Println(res)
// }

func bubbleSort(nums []int) []int {
	for i := len(nums) - 1; i > 0; i-- {
		for j := 0; j < i; j++ {
			if nums[i] < nums[j] {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
	}

	return nums
}

func bubble_sort_optimized(nums []int) []int {
	for i := len(nums) - 1; i > 0; i-- {
		is_swap := false
		for j := 0; j <= i-1; j++ {
			if nums[j] > nums[j+1] {
				nums[j], nums[j+1] = nums[j+1], nums[j]
				is_swap = true
			}
		}

		if !is_swap {
			break
		}
	}

	return nums
}
