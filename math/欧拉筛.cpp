#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
void euler_Prime(int n){
    vector<int> v(n + 1);
    for (int i = 2; i < n; i++){
        if (!v[i]){
            v[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size(); j++){
            if(i * prime[j] >= n) break;
            v[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}