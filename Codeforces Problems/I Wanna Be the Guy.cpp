#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	scanf("%lld", &n);
	vector<bool> list(n+1, false);
	ll temp;
	while(scanf("%lld", &temp) != EOF){
		list[temp] = true;
	}
	for(auto el : list) cout << el;
	for(ll i = 1; i <= n; i++){
		if(!list[i]){
			cout << "Oh, my keyboard!\n";
			return;
		}
	}
	cout << "I become the guy.\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	solve();	
} 