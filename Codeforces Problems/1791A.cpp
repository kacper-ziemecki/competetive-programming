#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	char a;
	cin >> a;
	string text = "codeforces";
	for(auto el : text){
		if(el == a){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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