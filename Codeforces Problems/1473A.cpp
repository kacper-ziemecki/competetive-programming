#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,d;
	cin >> n >> d;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	sort(list.begin(), list.end());	
	if(list[n-1] <= d){
		cout << "YES\n";
	}
	else if(list[0] + list[1] <= d){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 