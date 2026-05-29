package main

//递推公式
//quick_sort(p...r) = quick_sort(p...q-1) + quick_sort(q+1...r)

// func main() {
// 	nums := []int{6, 4, 2, 5, 3, 1}
// 	fmt.Println(nums)
// 	quick_sort(nums)
// 	fmt.Println(nums)
// }

func quick_sort(nums []int) {
	if len(nums) < 2 {
		return
	}

	left := 0
	right := len(nums) - 1

	quick_sort_c(nums, left, right)
}

func quick_sort_c(nums []int, left, right int) {
	if left >= right {
		return
	}

	mid := partition(nums, left, right)
	quick_sort_c(nums, left, mid-1)
	quick_sort_c(nums, mid+1, right)
}

func partition(nums []int, left, right int) int {
	pivot := nums[right]
	i := left
	j := left

	for i < right && j < right {
		if nums[j] < pivot {
			nums[i], nums[j] = nums[j], nums[i]
			i++
			j++
		} else {
			j++
		}
	}

	nums[i], nums[right] = nums[right], nums[i]
	return i
}
