use std::vec::Vec;

fn eratosthenes(max: usize) -> Vec<usize> {
    let mut primes = Vec::new();
    // create a vector of size max + 1, all of value true
    let mut is_prime = vec![true; max + 1];

    is_prime[0] = false;
    is_prime[1] = false;

    for i in 2 .. max + 1 {
        if is_prime[i] {
            primes.push(i);

            let mut j = i + i;

            while j < max + 1 {
                is_prime[j] = false;
                j += i;
            }
        }
    }

    return primes;
}

#[test]
fn test_eratosthenes() {
    assert_eq!(eratosthenes(18), [2, 3, 5, 7, 11, 13, 17]);
}
