#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5;
bool isPrime[MAXN];	//根据isPrime[i]判断i+a是不是质数，isPrime[i-a]=true 表示i是素数（下标偏移了a）
bool isSqrtPrime[MAXN];	//根据isSqrtPrime[i]判断i是不是质数
vector<int> prime;
//对区间[a,b)内的整数执行筛法 
void SegmentSieve(ll a, ll b)	//对区间[a,b)进行筛选 
{
	for (ll i = 0; i * i < b; i++) //初始化[2,sqrt(b))的全为质数
		isSqrtPrime[i] = true;
	for (ll i = 0; i < b - a; i++) //初始化偏移后的[a,b)全为质数
		isPrime[i] = true;

	for (ll i = 2; i * i < b; i++) //埃氏筛选
	{ 
		if (isSqrtPrime[i]) {
			for (ll j = 2 * i; j  <= sqrt(b); j += i)//筛选上限变为sqrt(b)
				isSqrtPrime[j] = false;
			//筛除[a,b)里的非素数
			//(a+i-1)/i 得到最接近（a/i）这个数，也即（a的i倍数)，最低是2LL是表示最低2倍
			for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i)
				isPrime[j - a] = false;
		}
	}
    for (ll i = a; i < b; i++){
        if (isPrime[i - a]) prime.push_back(i);
    }
}


typedef long long ll;
const int MAXN = 1e6 + 5;
vector<int> primes;
void segment_sieve(ll a, ll b) {
    vector<bool> is_prime_small(sqrt(b) + 1, true); // 筛[2, sqrt(b)]
    vector<bool> is_prime(b - a, true);              // 筛[a, b)

    if (a == 1) is_prime[0] = false;

    for (ll p = 2; p * p < b; p++) {
        if (is_prime_small[p]) {
            // 筛小素数
            for (ll j = p * p; j * j < b; j += p) 
                is_prime_small[j] = false;
            // 筛大区间
            ll start = max(p * p, (a + p - 1) / p * p);
            for (ll j = start; j < b; j += p) 
                is_prime[j - a] = false;
        }
    }

    for (ll i = a; i < b; i++) 
        if (is_prime[i - a]) primes.push_back(i);
}
int main(){
    segment_sieve(1000000000, 1001000000);
    for (auto v : primes){
        cout << v << " ";
    }
    return 0;
}



int main(){
    SegmentSieve(100, 10000);
    for (auto v : prime){
        cout << v << " ";
    }
    return 0;
}