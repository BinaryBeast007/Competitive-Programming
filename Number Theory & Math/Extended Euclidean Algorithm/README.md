# *Extended Euclidean Algorithm*

A **linear Diophantine equation** equates to a constant sum of two or more monomials, each of degree one.  
**ax + by = c**  
There exist a solution if gcd(a, b) divides c.

**Intuition:**  
gcd(a, b) divides a & ax  
gcd(a, b) divides b & bx  
ax + bx divisible by gcd(a, b) which is c  

**Extended Euclidean Algorithm**  
ax + by = gcd(a, b)   -------- (i)  
We know from Euclidean Algorithm,  
gcd(a, b) = gcd(b, a%b)  
from (i) we get,  
gcd(b, a%b) = bx<sub>1</sub> + (a%b)y<sub>1</sub>  -------- (ii)  
We can write,  
a%b = a - (a/b) *b 

From the above equations we get,  
from (i) & (ii)  
ax+by = bx<sub>1</sub> + (a%b)y<sub>1</sub>  
replacing the value of (a%b)   
ax + by = bx<sub>1</sub> + (a - (a/b) * b)y<sub>1</sub>  
ax + by = bx<sub>1</sub> + ay<sub>1</sub> - (a/b) * by<sub>1</sub>  
ax + by = ay<sub>1</sub> + bx<sub>1</sub>  - (a/b) * by<sub>1</sub>  
ax + by = ay<sub>1</sub> + b(x<sub>1</sub> - (a/b) * y<sub>1</sub>)  

Comparing the coefficients of a and b we get,  
x = y<sub>1</sub>  
y = x<sub>1</sub> - (a/b) * y<sub>1</sub>  

A structure of triplet to hold the x, y and gcd of the equation 
```cpp
struct Triplet {
    int x, y, gcd;
};
```
Base case if ```b == 0``` the equation ````ax + by = gcd(a, b)```` becomes ````ax = a```` or ````x = 1```` and ````gcd = a````  
```cpp
if(b == 0) {
    Triplet ans;
    ans.gcd = a;
    ans.x = 1;
    ans.y = 0;
    return ans;
}
```
Recursive call to find the gcd and the value of x & y  
x = y<sub>1</sub>  
y = x<sub>1</sub> - (a/b) * y<sub>1</sub> 

```cpp
Triplet smallAns = extendedEuclid(b, a%b);
Triplet ans;
ans.gcd = smallAns.gcd;
ans.x = smallAns.y;
ans.y = smallAns.x - (a/b) * smallAns.y;
return ans;
```
