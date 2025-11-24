#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	if(text.size() <= 10){
		cout << text << endl;
		return;
	}
	cout << text[0] << text.size() - 2 << text[text.size() - 1] << endl;
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