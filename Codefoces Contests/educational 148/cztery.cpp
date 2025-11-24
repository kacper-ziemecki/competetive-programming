#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	ll n,q;
	cin >> n >> q;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	sort(list.begin(), list.end());
	int question;
	for(int i = 0; i < q; i++){
		cin >> question;
		ll minimum = INT_MAX;
		for(int j = 0; j < n; j++){
			minimum = min(minimum, list[j] + max(question - j, 0));
		}
		if(question > n){
			if((question - n) % 2 != 0){
				minimum = min(minimum, list[n-1]);
			}
		}
		cout << minimum << " ";
	}
	cout << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	solve();	
} 