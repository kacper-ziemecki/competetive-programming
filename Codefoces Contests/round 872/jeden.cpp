#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

bool palindrome(string text, ll i, ll j){
	for(ll x = i; x < j; x++){
		if(x < text.size() && j-(x-i) >= 0 && j-(x-i) < text.size() && text[x] != text[j-(x-i)]) return false;
	}
	return true;
}

void solve(){
	string text;
	cin >> text;
	ll res = -1;
	for(ll i = 0; i < text.size() - 1; i++){
		for(ll j = i+1; j < text.size() - 1; j++){
			if(!palindrome(text, i, j)){
				res = max(res, j-i+1);
				//cout << i << " " << j << endl;
			}
		}
	}
	cout << res << endl;
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