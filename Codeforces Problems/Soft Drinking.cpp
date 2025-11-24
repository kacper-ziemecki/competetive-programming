#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	cout << (k*l)/(nl*n) << " " << (c*d) << " " << p/(np*n) << endl;
	cout << min((k*l)/(nl*n), min((c*d), p/(np*n))) << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("input.txt", "r", stdin);
	solve();	
} 