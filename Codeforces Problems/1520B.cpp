#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int res = 0;
	for(int i = 1; i < 10; i++){
		int temp = 0;
		for(int j = 1; j <= 9; j++){
			temp *= 10;
			temp += i;
			if(temp <= n) res++;
			if(temp > n) break;
		}
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 