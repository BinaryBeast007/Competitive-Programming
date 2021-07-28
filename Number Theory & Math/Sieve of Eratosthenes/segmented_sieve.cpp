// Segmented Sieve
// Time complexity : O((R−L+1)loglog(R)+√Rloglog√R)

#include<bits/stdc++.h>
using namespace std;

vector<bool> segmentedSieve(long long L, long long R) {
    // generate all primes up to sqrt(R)
    long long lim = sqrt(R);
    vector<bool> mark(lim+1, true);
    for(long long i=2; i*i<=lim; i++) {
        if(mark[i]) {
            for(long long j=i*i; j<=lim; j+=i) {
                mark[j] = false;
            }
        }
    }
    // store all the primes
    vector<long long> primes;
    for(long long i=2; i<=lim; i++) {
        if(mark[i]) {
            primes.emplace_back(i);
        }
    }
    // mark all the multiples of primes as composite
    vector<bool> isPrime(R-L+1, true);
    for (long long i : primes) {
        long long start = max(i * i, (L + i - 1) / i * i);
        for (long long j = start; j <= R; j += i) {
            isPrime[j - L] = false;
        }
    }
    if (L == 1) {
        isPrime[0] = false;
    }
    return isPrime;
}

int main() {
    long long L = 1, R = 10;
    vector<bool> isPrime = segmentedSieve(L, R);

    for(int i=0; i<isPrime.size(); i++) {
        if(isPrime[i]){
            cout << i+L << "\n";
        }
    }

    return 0;
}
