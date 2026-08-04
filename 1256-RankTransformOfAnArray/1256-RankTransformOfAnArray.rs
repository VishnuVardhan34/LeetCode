// Last updated: 8/4/2026, 12:23:40 PM
use std::collections::HashMap;
impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        let mut sorted = arr.clone();
        sorted.sort();

        let mut rank = HashMap::new();
        let mut r = 1;

        for &x in &sorted {
            if !rank.contains_key(&x) {
                rank.insert(x, r);
                r+=1;
            }
        }
        arr.iter().map(|x| rank[x]).collect()
    }
}