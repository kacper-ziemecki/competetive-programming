#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c;
	cin >> a >> b >> c;
	ll res = 0;
	ll iter = 0;
	bool flag = true;
	if(a > b){
		flag = false;
		iter = 1;
	}

	while(a <= c || b <= c){
		iter++;
		if(iter&1){
			a += b;
		}
		else{
			b += a;
		}
	}
	if(flag) cout << iter-1 << endl;
	else cout << iter-2 << endl;
}  

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 