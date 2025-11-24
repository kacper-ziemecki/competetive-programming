#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b,c,d,e;
	cin >>a >> b >> c >> d >> e;
	vector<bool> res(e+1, false);
	for(int i = a; i <= e; i += a){
		res[i] = true;
	}
	for(int i = b; i <= e; i += b){
		res[i] = true;
	}
	for(int i = c; i <= e; i += c){
		res[i] = true;
	}
	for(int i = d; i <= e; i += d){
		res[i] = true;
	}
	ll ans = 0;
	for(int i = 1; i <= e; i++) if(res[i]) ans++;
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 