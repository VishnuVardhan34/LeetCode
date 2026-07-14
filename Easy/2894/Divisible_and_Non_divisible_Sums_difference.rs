impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut nd = 0; // variable for non-divisible
        let mut d = 0; // variable for divisible
        for i in 1..=n {
            if i % m == 0 {
                d += i;
            }
            else {
                nd += i;
            }
        }
        (nd-d)
    }
}