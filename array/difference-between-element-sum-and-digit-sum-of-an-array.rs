impl Solution {
    pub fn difference_of_sum(nums: Vec<i32>) -> i32 {
        let element_sum: i32 = nums.iter().sum();
        let mut digit_sum = 0;
        for &num in &nums {
            let mut n = num;
            while n > 0 {
                digit_sum += n % 10;
                n /= 10;
            }
        }
        return (element_sum - digit_sum).abs();
    }
}