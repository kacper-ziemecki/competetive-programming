#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		if(i&1){
			if(i == n-1){
				cout << "I love it ";
			}
			else{
				cout << "I love that ";
			}
		}
		else{
			if(i == n-1){
				cout << "I hate it ";
			}
			else{
				cout << "I hate that ";
			}
		}
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 