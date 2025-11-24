#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n, 0), b(n, 0);
	for(auto &el : a) cin >> el;
	for(auto &el : b) cin >> el;
	vector<ll> res(n, 0);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll j = 0;
	for(ll i = 0; i < n; i++){
		while(j < n && a[j] <= b[i]){
			j++;
		}
		res[i] = n-j;
	}
	j = 0;
	ll ans = 1;
	for(ll i = n-1; i >= 0; i--){
		res[i] -= j;
		res[i] = max(0ll, res[i]);
		j++;
		ans *= res[i];
		ans %= 1000000007;
		if(res[i] == 0) break;
	}
	ans %= 1000000007;
	cout << ans << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 