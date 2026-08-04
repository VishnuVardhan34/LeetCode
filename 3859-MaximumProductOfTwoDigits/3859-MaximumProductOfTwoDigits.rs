// Last updated: 8/4/2026, 12:21:56 PM
impl Solution {
    pub fn max_product(n: i32) -> i32 {
        let mut n = n; // Shadow the immutable 'n' with a mutable 'n'
        
        let mut max1 = 0;
        let mut max2 = 0;

        while n > 0 {
            let digit = n % 10;
            
            if digit > max1 {
                max2 = max1;
                max1 = digit;
            } else if digit > max2 {
                max2 = digit;
            }
            
            n /= 10;
        }

        max1 * max2
    }
}