#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,res=0;
	cin >> n;
	int a,b,c;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c;
		if((a == 1 && b == 1) || (b == 1 && c == 1) || (a == 1 && c == 1)){
			res++;
		}
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 