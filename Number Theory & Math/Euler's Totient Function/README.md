
# *Euler's totient function*

Euler's totient function, also known as phi-function ϕ(n), counts the number of integers between 1 and n inclusive, which are coprime to n. Two numbers are coprime if their greatest common divisor equals 1 (1 is considered to be coprime to any number).  

Example:  
````
ϕ(9) = [1, 2, 4, 5, 7, 8] = 6  
````
If a and b are relatively prime, then:  
````
ϕ(ab) =  ϕ(a) *  ϕ(b), where gcd(a, b) = 1  
````
Prime factors of n,  
n = p<sub>1</sub><sup>a</sup> * p<sub>2</sub><sup>b</sup> * ... ... ... * p<sub>k</sub><sup>x</sup>  
ϕ(n) = ϕ(p<sub>1</sub><sup>a</sup> * p<sub>2</sub><sup>b</sup> * ... ... ... * p<sub>k</sub><sup>x</sup>)  
ϕ(n) = ϕ(p<sub>1</sub><sup>a</sup>) ϕ(p<sub>2</sub><sup>b</sup>) ... ... ... ϕ(p<sub>x</sub><sup>k</sup>)  
  
ϕ(p<sup>a</sup>), where p is a prime  number  
ϕ(p<sup>a</sup>) = p<sup>a</sup> - (total elements not co-prime to p<sup>a</sup> or multiples of p)  
multiples of p are : 1p, 2p, 3p, ... ... ..., p<sup>a-1</sup>, p<sup>a</sup>  

ϕ(p<sup>a</sup>) = p<sup>a</sup> - p<sup>a-1</sup>  
ϕ(p<sup>a</sup>) = p<sup>a</sup> ( 1 - 1/p)  
ϕ(n) = ϕ(p<sub>1</sub><sup>a</sup>) ϕ(p<sub>2</sub><sup>b</sup>) ... ... ... ϕ(p<sub>x</sub><sup>k</sup>)  
ϕ(n) = p<sub>1</sub><sup>a</sup> ( 1 - 1/p<sub>1</sub>)  * p<sub>2</sub><sup>b</sup> ( 1 - 1/p<sub>2</sub>) * ... ... ... * p<sub>x</sub><sup>k</sup> ( 1 - 1/p<sub>x</sub>)  
ϕ(n) = p<sub>1</sub><sup>a</sup>  * p<sub>2</sub><sup>b</sup> * ... ... ... * p<sub>x</sub><sup>k</sup>  * ( 1 - 1/p<sub>1</sub>) * ( 1 - 1/p<sub>2</sub>) * ... ... ... * ( 1 - 1/p<sub>x</sub>)  
ϕ(n) = n  * ( 1 - 1/p<sub>1</sub>) * ( 1 - 1/p<sub>2</sub>) * ... ... ... * ( 1 - 1/p<sub>x</sub>)  

### Euler's totient function  
ϕ(n) = n  * ( 1 - 1/p<sub>1</sub>) * ( 1 - 1/p<sub>2</sub>) * ( 1 - 1/p<sub>x</sub>)  

***Code***  
If we need all all the totient of all numbers between 1 and n, we can use the same idea as the Sieve of Eratosthenes.  
````cpp
void eulerPhi(int n) {
    int phi[n+1];
    for(int i=0; i<=n; i++) {
        phi[i] = i;
    }
    for(int i=2; i<=n; i++) {
        if(phi[i] == i) { 
            // if i is prime
            // ith phi will be i-1 
            // multiply all the multiples of i with (1-1/i)
            phi[i] = i-1;
            for(int j=2*i; j<=n; j+=i) {
                phi[j] = (phi[j]*(i-1))/i;
            }
        } 
    }
    for(int i=1; i<=n; i++) {
        cout << "Euler totient phi for " << i << " is = " << phi[i] << "\n";
    }
}
````  

**Time Complexity : O(nloglogn)**
