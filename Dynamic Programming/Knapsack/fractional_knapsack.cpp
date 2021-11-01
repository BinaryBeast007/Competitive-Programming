#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    double ratio1 = (double) a.first / (double) a.second;
    double ratio2 = (double) b.first / (double) b.second;
    return ratio1 > ratio1;
}
double fractionalKnapsack(int W, vector<pair<int, int>>& v) {
    sort(v.begin(), v.end(), comp);
    int currWeight = 0;
    double finalValue = 0.0;

    for(int i=0; i<v.size(); i++) {
        if(currWeight + v[i].second <= W) {
            currWeight += v[i].second;
            finalValue += v[i].first;
        }else {
            int remain = W - currWeight;
            finalValue += v[i].first * ((double) remain / (double) v[i].second);
        }
    }
    return finalValue;
} 

int main() {
    // vector<pair<value, weight>>
    vector<pair<int, int>> v = { {60, 10}, {100, 20}, {120, 30} };
    int n = v.size(); // number of items
    int W = 50; // Weight of knapsack

    cout << "Maximum Value = " << fractionalKnapsack(W, v) << "\n";

    return 0;
}
