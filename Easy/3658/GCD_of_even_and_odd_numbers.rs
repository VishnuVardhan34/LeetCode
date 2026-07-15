impl Solution {
    fn gcd(mut a: i32, mut b: i32) -> i32 {
        while b > 0 {
            let t = a;
            a = b;
            b = t % b;
        }
        a
    }

    pub fn gcd_of_odd_even_sums(n: i32) -> i32 {
        let sO = n * n;
        let sE = n * (n + 1);

        Self::gcd(sO, sE)
    }
}

// Actually the logic is simple the sum of both sumEven and sumOdd is n itself.
/*
impl solution {
    fn gcd_of_odd_even_sums(n: i32) -> i32 {
        n
    }
}*/
