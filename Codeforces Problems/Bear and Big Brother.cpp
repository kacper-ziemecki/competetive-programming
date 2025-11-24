#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b;
	cin >> a >> b;
	for(int i = 0;;i++){
		if(a > b){
			cout << i << endl;
			return;
		}
		a *= 3;
		b *= 2;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 