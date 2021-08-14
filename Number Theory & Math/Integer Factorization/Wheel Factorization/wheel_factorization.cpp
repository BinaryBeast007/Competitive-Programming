// Wheel factorization for integer factorization [optimization of the trial division]
#include<bits/stdc++.h>
using namespace std;

vector<long long> wheel_factorization(long long n) {
    vector<long long> factorization;
    while (n % 2 == 0) {
        factorization.push_back(2);
        n /= 2;
    }
    for(long long i=3; i*i <= n; i+=2) {
        while(n%i == 0) {
            factorization.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factorization.push_back(n);
    return factorization;
}

int main() {
    long long n = 100;
    vector<long long> factors = wheel_factorization(n);

    for(auto &i : factors) cout << i << " ";

    return 0;
}
