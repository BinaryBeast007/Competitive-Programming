# ***Fibonacci***

The Fibonacci Sequence is the series of numbers:  
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... ... ...  

The next number is found by adding up the two numbers before it:  
-   the 2 is found by adding the two numbers before it (1+1),  
-   the 3 is found by adding the two numbers before it (1+2),  
-   the 5 is (2+3),  
-   and so on!  

nth fibonacci number,  **f(n) = f(n-1) + f(n-2)**  

**Recursive solution:**  
Time Complexity: O(2^n)  
Space Complexity: O(n)  
````cpp
int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}
````  

**Memoization:** Top Down  
Store the results to avoid the redundant recursive calls.  
Time Complexity: O(n)  
Space Complexity: O(n)  

````cpp
int fib(int n) {
    if(n <= 1) {
        return n;
    }
    if(arr[n] != -1) {
        return arr[n];
    }
    return arr[n] = fib(n-1) + fib(n-2);
}
````  

**Tabulation:** Bottom Up  
We can get rid of all the recursive calls.  
Time Complexity: O(n)  
Space Complexity: O(n)  

````cpp
int fib(int n) {
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=n; i++) {
        arr[i] = arr[i-1] + arr[i-2]; 
    }
    return arr[n];
}
````
