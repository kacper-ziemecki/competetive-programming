#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,res=0;
	cin >> n;
	vector<ll> jeden(n, 0),dwa = {1};
	for(auto &el : jeden) cin >> el;
	for(int i = 1; i < n; i++){
		if(jeden[i] == jeden[i-1]){
			dwa[dwa.size() - 1]++;
		}
		else{
			dwa.push_back(1);
		}
	}
	for(int i = 1; i < dwa.size(); i++){
		res = max(res, min(dwa[i-1], dwa[i]));
	}
	cout << 2 * res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	//freopen("input.txt", "r", stdin);
	solve();	
} 