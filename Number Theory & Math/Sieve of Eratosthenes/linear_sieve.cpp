#include<bits/stdc++.h>
using namespace std;

#define MAXN 10000000
std::vector <int> prime;
bool is_composite[MAXN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
    is_composite[0] = is_composite[1] = true;
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
			is_composite[i * prime[j]] = true;
			if (i % prime[j] == 0) break;
		}
	}
}

int main() {
    sieve(MAXN);
    
    return 0;
}
