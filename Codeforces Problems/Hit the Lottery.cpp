#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	cnt += n/100;
	n -= n/100 * 100;
	cnt += n/20;
	n -= n/20 * 20;
	cnt += n/10;
	n -= n/10 * 10;
	cnt += n/5;
	n -= n/5 * 5;
	cnt += n;
	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 