#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string text;
	cin >> text;
	ll res = 0, temp = 0;
	for(auto el : text){
		if(el == 'x'){
			temp++;
		}
		else{
			res += max(0ll, temp - 2);
			temp = 0;
		}
	}
	res += max(0ll, temp - 2);
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 