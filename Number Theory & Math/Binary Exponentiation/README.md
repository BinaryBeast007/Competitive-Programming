

# Binary Exponentiation
Binary exponentiation (also known as exponentiation by squaring) is a trick that allows to calculate a^n using only O(log n) multiplications (instead of O(n) multiplications required by the naive approach).  

## Explanation

Calculate 2 <sup>13</sup>  
2 <sup>13</sup>  
= 2 * ( 2 <sup>12</sup> )   
= 2 * ( 2 <sup>2 <sup>6</sup></sup> )  
= 2 * ( 4 <sup>6</sup> )  
= 2 * ( 16 <sup>3</sup> )  
= 2 * 16 * ( 16 <sup>2</sup> )  
=  2 * 16 * ( 256 <sup>1</sup> )  
= 2 * 16 *  256 * ( 256 <sup>0</sup> )  
= 2 * 16 *  256 * 1  
= 8192

**Steps**

-   initially result = 1
-   if the base is odd multiply the result with base
-   square the base and half the power
-   if the base is 0 return the result
