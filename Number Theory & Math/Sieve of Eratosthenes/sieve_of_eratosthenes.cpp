/**Sieve of Eratosthenes
 * Time Complexity : O(NloglogN)  
 * Space Complexity : O(N)
 */
#include<bits/stdc++.h>
using namespace std;

#define N 100000
vector<bool> isPrime(N+1, true); // mark all as prime
void sieve() {
    isPrime[0] = isPrime[1] = false; // 0 & 1 is not prime
    // mark all the multiples of primes as composite
    for(int i=2; i*i<=N; i++) {
        if(isPrime[i]) {
            for(int j=i*i; j<=N; j+=i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve();

    int checkPrime = 97;
    if(isPrime[checkPrime]) {
        cout << "Prime\n";
    }else {
        cout << "Not Prime\n";
    }

    return 0;
}
