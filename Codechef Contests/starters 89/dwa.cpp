#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	ll one = 0, two = 0;
	ll temp;
	for(ll i = 1; i <= n; i++){
		cin >> temp;
		if(temp == -1){
			one += i;
		}
		else{
			two += i;
		}
	}
	cout << abs(one - two) << endl;
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