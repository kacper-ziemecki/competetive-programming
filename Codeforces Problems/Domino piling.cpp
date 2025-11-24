#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	if(!(n&1) && !(m&1)){
		cout << n * m/2 << endl;
	}
	else if(((n&1) && !(m&1)) || (!(n&1) && (m&1))){
		cout << (m * n)/2 << endl;
	}
	else{
		cout << (n*(m-1))/2 + (n-1)/2 << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 