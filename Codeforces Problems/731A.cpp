#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	char temp = 'a';
	ll res = 0;
	for(auto el : text){
		if(temp <= el){
			res += min(temp + ('z' - el + 1) - 'a', el - temp );
		}
		else{
			res += min(temp - el , ('z' - temp  - 'a') + el + 1);
		}
		temp = el;
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 