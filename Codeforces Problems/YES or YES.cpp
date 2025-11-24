#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string s;
	cin >> s;
	for(auto &el : s) el = tolower(el);
	if(s != "yes"){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
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