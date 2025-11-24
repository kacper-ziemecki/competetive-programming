#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve()
{
	ll n;
	cin >> n;
	vector<ll> one(n, 0ll), two{};
	for(auto &el : one) cin >> el;
	for(ll i = 1; i < n-1; i++){
		if(one[i] > one[i-1] && one[i] > one[i+1]) two.push_back(i);
	}
	for(ll i = two.size(); i >= 1; i--){
		ll pominiete = 0, last = two[0];
		for(ll j = 1; j < two.size(); j++){
			if(two[j] - last < i){
				pominiete++;
			}
			else{
				last = two[j];
			}
		}
		if(two.size() - pominiete >= i){
			cout << i << endl;
			return;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// #ifndef ONLINE_JUDGE
	// 	freopen("../../input.txt", "r", stdin);
	// 	freopen("../../output.txt", "w", stdout);
	// #endif
	
	solve();
	
}