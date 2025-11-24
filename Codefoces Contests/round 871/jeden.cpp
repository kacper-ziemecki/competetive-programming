#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text, wzor = "codeforces";
	cin >> text;
	int res = 0;
	for(int i = 0; i < wzor.size(); i++){
		if(text[i] != wzor[i]) res++;
	}
	cout << res << endl;
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