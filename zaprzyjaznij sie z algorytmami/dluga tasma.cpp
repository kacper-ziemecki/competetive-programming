#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,a,res=INT_MAX;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		res = min(res, a);
	}
	cout << res << ".00" << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 