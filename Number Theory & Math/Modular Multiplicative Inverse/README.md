# *Modular Multiplicative Inverse*

The **multiplicative inverse** of a number is defined as a number which when multiplied by the original number gives the product as 1. It is denoted by 1/x or x<sup>-1</sup>.  
  
A is given, find the value of B.  
````
A * B = 1  
B = ?  
B = 1/A = A^-1  
A * 1/A = 1  
````  

**Modular Multiplicative Inverse**  
Given two integers ‘A’ and ‘m’, find modular multiplicative inverse of ‘A’ under modulo ‘m’.
The modular multiplicative inverse is an integer ‘B’ such that.   
````
A B ≅ 1 (mod m)  
````
Example:

````
(A * B) mod m = 1  
(A * B) % m = 1  
  
Given, A = 5, m = 17  
find the value of B  
  
(5 * 1) % 17 = 5  
(5 * 2) % 17 = 10  
(5 * 3) % 17 = 15  
(5 * 4) % 17 = 3  
(5 * 5) % 17 = 8  
(5 * 6) % 17 = 13  
(5 * 7) % 17 = 1  

Answer: B = 17  
````

Calculating the answer using extended euclidean algorithm,

````
A B ≅ 1 (mod m)  
(A * B - 1) mod m = 0  
(A * B - 1) = mq [multiple of m, here q is a integer]  
AB - mq = 1  
(A * B) + m (-q) = 1  
AB + mQ = 1  
  
From extended euclidean algorithm,  
ax + by = c  
ax + by = gcd(a, b)  

here, AB + mQ = 1  
gcd(A, m) = 1  
B will exist if gcd(A, m) = 1  
A & m should be co-primes  

AB + mQ = gcd(A, m)  
We can calculate it by using extended euclidean algorithm.
````

