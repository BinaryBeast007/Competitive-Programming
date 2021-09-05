# *Sieve of Eratosthenes*
**Sieve of Eratosthenes :**  
Sieve of Eratosthenes is an algorithm for finding all the prime numbers in a segment [1;n] using O(nloglogn) operations.  

**Sieve of Eratosthenes Algorithm:**  

- Create an array of size n+1  
- Mark all numbers as prime  
- Start from the smallest prime number 2 and mark all it's multiples as composite  
-  For next prime numbers do the same, mark all it's multiples as composite  
- To find all the prime numbers until n, it will be enough just to perform these operations till the root of n  

**Time Complexity: O(nloglogn)**  

**Segmented Sieve :**  
Sometimes we need to find all prime numbers in a range [L, R] of small size (e.g. R−L+1≈1e7), where R can be very large (e.g. 1e12).  
To solve such a problem, we can use the idea of the Segmented sieve. We pre-generate all prime numbers up to √R, and use those primes to mark all composite numbers in the segment [L, R].  

**Segmented Sieve Algorithm:**  

- Generate all prime numbers up to √R and store them in an array or vector  
-  Use those primes to mark all composite numbers in the segment [L, R]  

**Time complexity : O((R−L+1)loglog( R )+√Rloglog√R)**  
