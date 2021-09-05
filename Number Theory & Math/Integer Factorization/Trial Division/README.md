# *Trial Division*
This is the most basic algorithm to find a prime factorization.  
**Algorithm:**  

- Divide it by each possible divisor d  
- Start from smallest prime number 2 till √n  
- If n is divisible then store the divisor in a vector and divide n by it and continue the step  

We remove the factor from the number, and repeat the process. If we cannot find any divisor in the range [2; √n], then the number itself has to be prime.

**Time Complexity: O(√n)**  
