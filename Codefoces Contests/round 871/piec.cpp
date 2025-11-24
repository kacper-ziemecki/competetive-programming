#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<ll> arr1 = {1, 0, -1, 0}, arr2 = {0, 1, 0, -1};

ll dfs(ll i, ll j, vector<vector<ll>> &list, ll n, ll m, ll res = 0){
	if(list[i][j] == 0) return res;

	res += list[i][j];
	list[i][j] = 0;

	for(ll x = 0; x < 4; x++){
		if(i + arr1[x] >= 0 && i + arr1[x] < n && j + arr2[x] >= 0 && j + arr2[x] < m){
				res = max(res, dfs(i + arr1[x], j + arr2[x], list, n, m, res));
		}
	}
	return res;
}
void solve(){
	ll n,m;
	cin >> n >> m;
	vector<vector<ll>> list(n, vector<ll>(m, 0));
	for(auto &sub : list){
		for(auto &el : sub){
			cin >> el;
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(list[i][j]){
				ans = max(ans, dfs(i, j, list, n, m));
			}
		}
	}
	cout << ans << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 