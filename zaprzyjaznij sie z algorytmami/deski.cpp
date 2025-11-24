#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n, m, res = INT_MIN;
	cin >> n >> m;
	vector<pair<ll,ll>> jeden(n, {0,0}), dwa(n, {0,0});
	vector<ll> trzy(n, 0);
	for(auto &el : jeden) cin >> el.first >> el.second;
	for(auto &el : dwa) cin >> el.first;
	for(int i = 0; i < n; i++) dwa[i].second = i;
	sort(dwa.begin(), dwa.end());
	for(int i = 0; i < n; i++){
		trzy[i] = dwa[i].first;
	}
	ll uno,dos,temp;
	for(auto el : jeden){
		uno = lower_bound(trzy.begin(), trzy.end(), el.first) - trzy.begin();
		dos = upper_bound(trzy.begin(), trzy.end(), el.second) - 1 - trzy.begin();
		temp = INT_MAX;
		for(int i = uno; i <= dos; i++){
			temp = min(temp, dwa[i].second + 1);
		}
		res = max(res, temp);
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin); 
	solve();	
} 