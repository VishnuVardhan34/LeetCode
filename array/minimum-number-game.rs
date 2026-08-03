impl Solution {
    pub fn number_game(nums: Vec<i32>) -> Vec<i32> {
        let mut sorted = nums.clone();
        sorted.sort();
        // Now we are ensuring that we are not overflowing the bounds if the array is odd;
        let end = if sorted.len() == 0 { 0 } else { sorted.len() - 1 };
        // Swapping the pairs to get the output
        for i in (0..end).step_by(2) {
            sorted.swap(i,i+1);
        }
        sorted
    }
}