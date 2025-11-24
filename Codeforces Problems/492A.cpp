#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	ll temp = 0;
	for(int i = 1;; i++){
		temp += i;
		if(n - temp < 0){
			cout << i-1 << endl;
			return;
		}
		n -= temp;
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 