package main

// func main() {
// 	nums := []int{6, 4, 2, 5, 3, 1}
// 	fmt.Println(nums)
// 	res := insertion_sort(nums)
// 	fmt.Println(res)
// }

func insertion_sort(nums []int) []int {
	if len(nums) <= 1 {
		return nums
	}

	for i := 1; i < len(nums); i++ {
		value := nums[i]
		var j int = i - 1

		//查到插入位置
		for ; j >= 0; j-- {
			if value < nums[j] {
				nums[j+1] = nums[j]
			} else {
				break
			}
		}

		//插入对应位置
		nums[j+1] = value
	}

	return nums
}
