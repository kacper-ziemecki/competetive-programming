#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string one, two;
	cin >> one >> two;
	for(int i = 0; i < n; i++){
		if((one[i] == two[i]) || (one[i] == 'G' && two[i] == 'B') || (one[i] == 'B' && two[i] == 'G')){
			continue;
		}
		else{
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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