#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,k,res=0;
	cin >> n >> k;
	vector<int> list(n,0);
	for(auto &el : list) cin >> el;
	for(int i = 0; i < n; i++){
		if(list[i] >= list[k-1] && list[i] > 0){
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