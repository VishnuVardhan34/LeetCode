// Last updated: 8/4/2026, 12:22:29 PM
impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        let a = nums[0];
        let b = nums[1];
        let c = nums[2];

        if a + b <= c || a + c <= b || b + c <= a {
            return "none".to_string();
        }

        if a == b && b == c {
            return "equilateral".to_string();
        }

        if a == b || a == c || b == c {
            return "isosceles".to_string();
        }

        "scalene".to_string()
    }
}