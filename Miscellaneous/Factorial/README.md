# *Factorial Facts*  

In mathematics, the factorial of a non-negative integer n, denoted by n!, is the product of all positive integers less than or equal to n. The factorial of n also equals the product of n with the next smaller factorial: For example, The value of 0! is 1, according to the convention for an empty product.  

### Number of Digits of Factorial  

Given an integer **N**, find number of digits in **N!**.  
For example, for N = 3, number of digits in N! = 3! = 3×2×1 = 6 is 1. 
For N = 5, number of digits in 5! = 120 is 3.  

A naive solution would be to calculate the n! first and then calculate the number of digits present in it. However as the value for n! can be very large, it would become cumbersome to store them in a variable (Unless you’re working in python!) .  
A better solution would be to use the useful property of logarithms to calculate the required answer. Logarithm of a number is connected to its number of digits, which might not be apparent. What is logarithm? Logarithm of a number  x, in base  b, is a real number  y  such that  x=b<sup>y</sup>. For example:  

log<sub>10</sub>1234 = 3.0913151597 and 10<sup>3.0913151597</sup> = 1234  

In logarithms, the base of the number is important. Since we want the number of digits of  N!  in decimal, we will work with base  10.
````
We know,
log(a*b) = log(a) + log(b)

Therefore
log( n! ) = log(1*2*3 ....... * n) 
          = log(1) + log(2) + ........ +log(n)

log10(1) = 0  
log10(10) = 1  
log10(100) = 2  
log10(1000) = 3  
log10(10000) = 4

Now, observe that the floor value of log base 
10 increased by 1, of any number, gives the
number of digits present in that number.
````
**Time Complexity: O(N)**
````cpp
const double eps = 1e-9;

int factorialDigit (int n) {
    double x = 0;
    for(int i = 1; i <= n; i++) {
        x += log10(i);
    }
    int res = x + 1 + eps;
    return res;
}
````

However that solution would not be able to handle cases where n >10^6. We improve our solution.  
We can use **Kamenetsky’s formula** to find our answer !
````
It approximates the number of digits in a factorial by :
f(x) = log10( ((n / e) ^ n) * sqrt(2 * pi * n))

Thus, we can pretty easily use the property of logarithms to,
f(x) = n * log10(( n / e)) + log10(2 * pi * n) / 2 
````  

````cpp
long long factorialDigit(int n) {
    // Kamenetsky formula to calculate the number of digits  
    double x = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0));  

    return floor(x) + 1;  
}  
````

### Digits of  N!  in Different Base  

Now what if we want to find how many digits N! has if we convert N! to some other base.  
For example, how many digits 3! has in the binary number system with base 2? We know that (6)10=(110)2. So 3! has 3 digits in base 2 number system.  
Can we use logarithms to solve this problem too? Yes.  

**number of digits of x in base B = ⌊ log<sub>B</sub> ( x ) ⌋ + 1**  

All we need to do is change the base of our log and it will find the number of digits in that base.
But, how do we change base in our code? We can only use log with base 2 and 10 in C++. Fear not, we can use the following law to change base of logartihm from B to C.  
**log<sub>B</sub> ( x ) = log<sub>C</sub> ( x ) / log<sub>C</sub> (B)**  

So in C++, we will use C=2 or C=10 to find value of log<sub>B </sub>( x ).  

````cpp
const double eps = 1e-9;

int factorialDigit (int n, int base) {
    double x = 0;
    for (int i = 1; i <= n; i++) {
        x += log10 ( i ) / log10(base); // Base Conversion
    }
    int res = x + 1 + eps;
    return res;
}

````

---  

### Prime Factorization of Factorial  

Given a positive integer N, find the prime factorization of N!.  
For example, 5! = 5 × 4 × 3 × 2 × 1 = 120 = 2<sup>3</sup> × 3 × 5.  

There can not be any prime greater than N that can divide N!  
N! = N × (N − 1) × (N − 2) × (N − 3) × … × 3 × 2 × 1  
6! = 6 × 5 × 4 × 3 × 2 × 1 = (2 × 3) × 5 × 2<sup>2</sup> × 3 × 2 = 2<sup>4</sup> × 3<sup>2</sup> × 5  

If prime p<sub>1</sub> occurs a<sub>1</sub> times, p<sub>2</sub> occurs a<sub>2</sub> times...  p<sub>x</sub> occurs a<sub>x</sub> times, then N! = p<sub>1</sub><sup>a<sub>1</sub></sup> ×p<sub>2</sub><sup>a<sub>2</sub></sup> × ... × p<sub>x</sub><sup>a<sub>x</sub></sup>.  
For a given prime p, N! will have p<sup>x</sup> as its prime factor where,  
x = (N / p) + (N / p<sub>2</sub>) + (N / p<sub>3</sub>) + ... Until it becomes 0.  

````cpp
const int MAXN = 10000000;
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
    is_composite[0] = is_composite[1] = true;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}
long long factorialPrimePower (long long n, long long p) {
    long long freq = 0;
    long long x = n;
    while (x / p) {
        freq += x / p;
        x = x / p;
    }
    return freq;
}
void factorialFactorize (int n) {
    for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
        int freq = factorialPrimePower(n, prime[i]);
        cout << prime[i] << "^" << freq << " ";
    }
}
````

---  
### Number of Trailing Zeroes of Factorial  

Given a positive integer N, find the number of trailing zero N! has. For example, 5! = 120 has 1 trailing zero and 10! = 3628800 has 2.  

A number x, with y trailing zeroes at its end, can be write as x = z × 10<sup>y</sup>  
For every factor of 10, x gets a trailing zero. Prime factorization of 10 is 10 = 2 × 5. So we need to find out how many 2s and 5s  N! has.  

````cpp
long long factorialPrimePower (long long n, long long p) {
    long long freq = 0;
    long long x = n;
    while (x / p) {
        freq += x / p;
        x = x / p;
    }
    return freq;
}
int trailingZeroes(int n) {
    int numOfTwos = factorialPrimePower(n, 2);
    int numOfFives = factorialPrimePower(n, 5);
    int numOfZeros = min(numOfTwos, numOfFives);

    return numOfZeros;
}
````

### Trailing Zeroes in Different Base  

For a number in base B, if we multiply it by B it gets a trailing zero at its end. So all we need to do is find out how many B does N! has. For base 16, we need to find out how many times 16 = 2^4 occurs in N!.  
