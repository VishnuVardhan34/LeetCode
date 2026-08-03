impl Solution {
    pub fn subsequence_pair_count(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        const MAX: usize = 200;

        fn gcd(mut a: usize, mut b: usize) -> usize {
            while b != 0 {
                let t = a % b;
                a = b;
                b = t;
            }
            a
        }

        let mut dp = vec![vec![0_i64; MAX + 1]; MAX + 1];
        dp[0][0] = 1;

        for &x in &nums {
            let x = x as usize;
            let mut ndp = vec![vec![0_i64; MAX + 1]; MAX + 1];

            for g1 in 0..=MAX {
                for g2 in 0..=MAX {
                    let cur = dp[g1][g2];
                    if cur == 0 {
                        continue;
                    }

                    // Option 1: ignore
                    ndp[g1][g2] = (ndp[g1][g2] + cur) % MOD;

                    // Option 2: put into seq1
                    let ng1 = if g1 == 0 { x } else { gcd(g1, x) };
                    ndp[ng1][g2] = (ndp[ng1][g2] + cur) % MOD;

                    // Option 3: put into seq2
                    let ng2 = if g2 == 0 { x } else { gcd(g2, x) };
                    ndp[g1][ng2] = (ndp[g1][ng2] + cur) % MOD;
                }
            }

            dp = ndp;
        }

        let mut ans = 0_i64;
        for g in 1..=MAX {
            ans = (ans + dp[g][g]) % MOD;
        }

        ans as i32
    }
}