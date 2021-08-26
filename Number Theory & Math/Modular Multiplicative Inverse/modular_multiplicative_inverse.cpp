#include<bits/stdc++.h>
using namespace std;

struct Triplet {
    int x, y, gcd;
};
Triplet extendedEuclid(int a, int b) {
    if(b == 0) {
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }
    Triplet smallAns = extendedEuclid(b, a%b);
    Triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b) * smallAns.y;
    return ans;
}
int modularMultiplicativeInverse(int a, int m) {
    Triplet ans = extendedEuclid(a, m);
    if (ans.gcd != 1) {
		cout << "Inverse doesn't exist\n";
        return 0;
    }
    return ans.x;
}

int main() {
    int a = 11, m = 13;
    int ans = modularMultiplicativeInverse(a, m);
    cout << "Answer: " << ans << '\n';
    
    return 0;
}
