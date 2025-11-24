#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

vector<ll> arr1 = {1, 0, -1, 0}, arr2 = {0, 1, 0, -1};


void solve(){
	ll n,m;
	cin >> n >> m;
	unordered_map<ll, ll> list;
	ll a,b;
	for(ll i = 0; i < m; i++){
		cin >> a >> b;
		list[a]++;
		list[b]++;
	}
	vector<ll> res;
	for(auto el : list){
		if(el.second > 1) res.push_back(el.second);
	}
	sort(res.begin(), res.end());
	if(res[0] != res[1]){
		cout << res[0] << " " << res[1]-1 << endl;
	}
	else if(res[res.size()-1] != res[res.size()-2]){
		cout << res[res.size() - 1] << " " << res[res.size() - 2]-1 << endl;
	}
	else{
		cout << res[0] << " " << res[0] - 1 << endl;
	}
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