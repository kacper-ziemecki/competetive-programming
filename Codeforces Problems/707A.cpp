#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,m;
	cin >> n >> m;
	char temp;
	bool flag = true;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> temp;
			if(temp != 'W' && temp != 'B' && temp != 'G') flag = false;
		}
	}
	if(flag){
		cout << "#Black&White\n";
	}
	else{
		cout << "#Color\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	// freopen("input.txt", "r", stdin);
	solve();	
} 