# *Wheel Factorization*

This is an optimization of the trial division. The idea is the following. Once we know that the number is not divisible by 2, we don't need to check every other even number. This leaves us with only 50% of the numbers to check. After checking 2, we can simply start with 3 and skip every other number.  

---  

This method can be extended. If the number is not divisible by 3, we can also ignore all other multiples of 3 in the future computations. So we only need to check the numbers 5,7,11,13,17,19,23,…. We can observe a pattern of these remaining numbers. We need to check all numbers with d mod 6 = 1 and d mod 6 = 5. So this leaves us with only 33.3% percent of the numbers to check. We can implement this by checking the primes 2 and 3 first, and then start checking with 5 and alternatively skip 1 or 3 numbers.  

We can extend this even further. Here is an implementation for the prime number 2, 3 and 5. It's convenient to use an array to store how much we have to skip.  
````cpp
vector<long long> trial_division3(long long n) {
    vector<long long> factorization;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}
````

If we extend this further with more primes, we can even reach better percentages. However, also the skip lists will get a lot bigger.  

**Time Complexity: O(√n)**  
