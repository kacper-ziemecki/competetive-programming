#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	vector<bool> lista(2*n + 1, true);
	vector<pair<ll, ll>> ans;
	ll last = -1;
	for(ll i = 2; i <= 2*n; i++){
		for(ll j = i; j <= 2*n; j += i){
			if(lista[j] && last == -1){
				lista[j] = false;
				last = j;
			}
			else if(lista[j] && last != -1){
				lista[j] = false;
				ans.push_back({last, j});
				last = -1;
			}
		}	
		if(last != -1){
			lista[last] = true;
			last = -1;
		}
	}
	
	ll res = 0;
	for(ll i = 1; i <= 2*n; i++){
		if(lista[i]){
			lista[i] = false;
			for(ll j = i+1; j <= 2*n; j++){
				if(lista[j]){
					lista[j] = false;
					ans.push_back({i, j});
					res++;
					break;
				}
			}
		}
	}
	cout << res << endl;
	for(auto el : ans){
		cout << el.first << " " << el.second << endl;
	}
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