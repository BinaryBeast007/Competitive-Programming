/**Trial Division for integer factorization
 * Time Complexity : O(√n) 
 */
#include<bits/stdc++.h>
using namespace std;

vector<long long> trial_division(long long n) {
    vector<long long> factorization;
    for(long long i=2; i*i <= n; i++) {
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
    vector<long long> factors = trial_division(n);

    for(auto &i : factors) cout << i << " ";

    return 0;
}
