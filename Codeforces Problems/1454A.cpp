#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	if(!(n&1)){
		for(int i = n; i > 0; i--){
			cout << i << " ";
		}
		cout << endl;
	}
	else{
		for(int i = n; i > 0; i--){
			if(i == n/2 + 1){
				cout << 1 << " ";
			}
			else if(i == 1){
				cout << n/2 + 1<< " ";
			}
			else{
				cout << i << " ";
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
	int t;
	cin >> t;
	while(t--) solve();	
} 