#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b;
	cin >> a >> b;
	int temp;
	int res = 0;
	for(int i = 0; i < a; i++){
		cin >> temp;
		if(temp + b <=5)res++;
	}
	cout << res/3 << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 