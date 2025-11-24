#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,k;
	cin >> n >> k;
	int time = 4*60 - k;
	int res = 0;
	for(int i = 1; i <= n; i++){
		if(time - i*5 >= 0){
			time -= i*5;
			res++;
		}
		else{
			break;
		}
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