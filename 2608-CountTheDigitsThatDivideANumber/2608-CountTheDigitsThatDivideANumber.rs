// Last updated: 8/4/2026, 12:23:00 PM
impl Solution {
    pub fn count_digits(num: i32) -> i32 {
        if num == 0 {
            return 1;
        }

        let original = num;
        let mut n = num;
        let mut count = 0;

        while n > 0 {
            let digit = n%10;
            if original%digit == 0 {
                count +=1;
            }
            n/=10;
        }
        return count;
    }
}