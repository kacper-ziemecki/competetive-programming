#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string text;
	cin >> text;
	sort(text.begin(), text.end());
	if(n >= 3 && text[0] == text[n-1]){
		if(n&1){
			cout << 2 << endl;
		}
		else{
			cout << 1 << endl;
		}
		return;
	}
	unordered_map<char, ll> list;
	for(auto el : text){
		list[el]++;
	}
	ll cnt = 0;
	for(auto el : list){
		if(el.second&1) cnt++;
	}
	if(cnt > 1){
		cout << 0 << endl;
		return;
	}
	cout << 1 << endl;
	return;
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