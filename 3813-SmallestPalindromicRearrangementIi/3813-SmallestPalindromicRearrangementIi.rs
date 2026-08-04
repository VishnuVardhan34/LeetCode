// Last updated: 8/4/2026, 12:22:09 PM
impl Solution {
    pub fn smallest_palindrome(s: String, k: i32) -> String {
        let mut counts = [0; 26];
        for b in s.bytes() {
            counts[(b - b'a') as usize] += 1;
        }
        
        let mut left_counts = [0; 26];
        let mut mid_char = None;
        let mut left_len = 0;
        
        // Populate the frequency map for the left half of the palindrome
        for i in 0..26 {
            if counts[i] % 2 != 0 {
                mid_char = Some((b'a' + i as u8) as char);
            }
            left_counts[i] = counts[i] / 2;
            left_len += left_counts[i];
        }
        
        // We only care about permutation counts up to k.
        // Capping it at `k + 1` prevents any integer overflow risks and speeds up the calculation.
        let limit = (k as u64) + 1;
        
        // Helper function to calculate the number of unique permutations of a multiset
        fn calc_perms(counts: &[usize; 26], limit: u64) -> u64 {
            let mut ans = 1u64;
            let mut n = 0;
            for &c in counts.iter() {
                for i in 1..=c {
                    n += 1;
                    // (ans * n) / i computes the next incremental binomial coefficient combination
                    ans = (ans * n as u64) / i as u64;
                    if ans >= limit {
                        return limit;
                    }
                }
            }
            ans
        }
        
        let mut k_u64 = (k - 1) as u64; // Convert to 0-indexed for easier math
        
        // If there are fewer valid permutations than `k`, return an empty string
        let total_perms = calc_perms(&left_counts, limit);
        if k_u64 >= total_perms {
            return String::new();
        }
        
        let mut left_str = String::with_capacity(left_len);
        
        // Greedily find the k-th permutation
        for _ in 0..left_len {
            for c in 0..26 {
                if left_counts[c] > 0 {
                    // Test putting character `c` at the current position
                    left_counts[c] -= 1;
                    let perms = calc_perms(&left_counts, limit);
                    
                    if k_u64 < perms {
                        // This character belongs at the current position
                        left_str.push((b'a' + c as u8) as char);
                        break;
                    } else {
                        // Otherwise, skip all `perms` combinations starting with this character
                        k_u64 -= perms;
                        // Backtrack and restore the count to try the next character lexicographically
                        left_counts[c] += 1;
                    }
                }
            }
        }
        
        // Construct the full palindromic string
        let mut right_str = left_str.clone();
        if let Some(m) = mid_char {
            left_str.push(m);
        }
        
        for c in right_str.chars().rev() {
            left_str.push(c);
        }
        
        left_str
    }
}