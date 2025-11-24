#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b;
	cin >> a >> b;
	bool flag = true;
	for(int i = a+1; i < b; i++){
		flag = true;
		for(int j = 2; j * j <= i; j++){
			if(i % j == 0) flag = false;
		}
		if(flag){
			cout << "NO\n";
			return;
		}
	}
	flag = true;
	for(int i = 2; i * i <= b; i++){
		if(b % i == 0) flag = false;
	}
	if(!flag){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 