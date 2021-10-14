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

**Linear Sieve :**  
It can be analyzed that the *Sieve of Eratosthenes* runs in *O(nloglogn)* complexity (with the  [Euler–Mascheroni constant](https://en.wikipedia.org/wiki/Euler%E2%80%93Mascheroni_constant), i.e.  ![](https://espresso.codeforces.com/0b3a627a122ad6f08c15f0a85399ee2829d7d7a6.png)). Let us take a minute to consider the bottleneck of such sieve. While we do need to cross out each composite once, in practice we run the inner loop for a composite multiple times due to the fact that it has multiple factors. Thus, if we can establish a unique representation for each composite and pick them out only once, our algorithm will be somewhat better. Actually it is possible to do so. Note that every composite  _q_  must have at least one prime factor, so we can pick the smallest prime factor  _p_, and let the rest of the part be  _i_, i.e.  _q_ = _ip_. Since  _p_  is the smallest prime factor, we have  _i_ ≥ _p_, and no prime less than  _p_  can divide  _i_. Now let us take a look at the code we have a moment ago. When we loop for every  _i_, all primes not exceeding  _i_  is already recorded in the container  `prime`. Therefore, if we only loop for all elements in  `prime`  in the inner loop, breaking out when the element divides  _i_, we can pick out each composite exactly once.

```cpp
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
```

As is shown in the code, the statement  `if (i % prime[j] == 0) break;`  terminates the loop when  _p_  divides  _i_. From the analysis above, we can see that the inner loop is executed only once for each composite. Hence, the code above performs in  _O_(_n_)  complexity, resulting in its name — the 'linear' sieve. [[source](https://codeforces.com/blog/entry/54090)]  

