#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b;
	cin >> a >> b;
	for(int i = 1; i <= 10; i++){
		if(a*i%10 == b || a*i%10 == 0){
			cout << i << endl;
			return;
		}
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 