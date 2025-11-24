#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	if(text.size() % 2 != 0){
		cout << "NO\n";
		return;
	}
	for(int i = 0; i < text.size()/2; i++){
		if(text[i] != text[i + text.size()/2]){
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
	int t;
	cin >> t;
	while(t--) solve();	
} 