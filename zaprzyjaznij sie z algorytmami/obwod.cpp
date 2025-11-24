#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,res=INT_MAX;
	cin >> n;
	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			res = min(res, 2*i + 2*(n/i));
		}
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