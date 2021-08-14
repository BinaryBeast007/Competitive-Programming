/**Prime Factorization using Sieve
 * Time Complexity : for precomputation O(nloglog n) & to get factors O(log n)
 */
#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000001
int spf[MAXN];
// Time Complexity : O(nloglog n)
void sieve() {
    spf[1] = 1;
    // marking smallest prime factor for every
    // odd number to be itself and for even number is 2
    for(int i=2; i<=MAXN; i++) {
        if(i%2 == 0) spf[i] = 2;
        else spf[i] = i;
    }
    for(int i=3; i*i<=MAXN; i+=2) {
        if(spf[i] == i) { // checking if i is prime
            for(int j=i*i; j<=MAXN; j+=i) { // marking SPF for all numbers divisible by i
                if(spf[j] == j) {
                    spf[j] = i; // marking spf[j] if it is not previously marked
                }
            }
        }
    }
}
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x) {
    vector<int> factorization;
    while (x != 1) {
        factorization.push_back(spf[x]);
        x /= spf[x];
    }
    return factorization;
}

int main() {
    sieve();

    int n = 100;
    vector<int> factors = getFactorization(n);
    for(auto &i : factors) cout << i << " ";

    return 0;
}
