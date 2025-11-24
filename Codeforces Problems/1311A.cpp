#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b;
	cin >> a >> b;
	if(a == b){
		cout << 0 << endl;
	}
	else if(a < b && (b-a)&1){
		cout << 1 << endl;
	}
	else if(a > b && !((a-b)&1)){
		cout << 1 << endl;
	}
	else{
		cout << 2 << endl;
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