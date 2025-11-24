#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,h;
	cin >> n >> h;
	int temp, res = 0;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp > h) res++;
		res++;
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 