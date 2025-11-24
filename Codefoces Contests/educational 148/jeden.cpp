#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	string text;
	cin >> text;
	for(int i = 1; i < text.size()/2; i++){
		if(text[i] != text[i-1]){
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