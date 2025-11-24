#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	string text;
	cin >> text;
	for(auto &el : text) el = tolower(el);
	vector<bool> list('z'-'a'+1, false);
	for(auto el : text) list.at(el - 'a') = true;
	for(auto el : list){
		if(!el){
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
	// freopen("input.txt", "r", stdin);
	solve();	
} 