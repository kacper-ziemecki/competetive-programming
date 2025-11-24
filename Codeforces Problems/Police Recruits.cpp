#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int res = 0, temp, sum = 0;
	for(int i = 0; i < n; i++){
		cin >> temp;
		sum += temp;
		if(sum < 0){
			sum = 0;
			res++;
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