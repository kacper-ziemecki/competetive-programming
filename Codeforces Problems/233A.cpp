#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	if(n&1){
		cout << -1 << endl;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(i&1){
				cout << i+1 << " ";
			}
			else{
				cout << i-1 << " ";
			}
		}
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 