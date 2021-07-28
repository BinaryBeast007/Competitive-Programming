/**Euclidean algorithm for computing the greatest common divisor
 * Time Complexity : O(log min(a,b))  
 */
#include<bits/stdc++.h>
using namespace std;

// recursive
int gcd (int a, int b) {
    if(b == 0) {
        return a;
    }else {
        return gcd(b, a%b);
    }
}
// recursive using the ternary operator
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
// iterative
int gcd (int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
// lcm (a, b) = (a*b) / gcd(a, b)
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {

    return 0;
}
