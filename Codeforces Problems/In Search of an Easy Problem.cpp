#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,temp;
	bool res = true;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 1) res = false;
	}

	cout << (res ? "EASY\n" : "HARD\n");
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 