#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	n *= 2;
	vector<bool> test(n, false);
	ll temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(!test[temp-1]){
			test[temp-1] = true;
			cout << temp << " ";
		}
	}
	cout << endl;
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