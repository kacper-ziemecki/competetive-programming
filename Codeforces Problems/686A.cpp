#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,x;
	cin >> n >> x;
	vector<pair<char, ll>> list(n, {' ', 0});
	for(auto &el : list) cin >> el.first >> el.second;

	ll one = 0;
	for(auto el : list){
		if(el.first == '-'){
			if(x < el.second){
				one++;
			}
			else{
				x -= el.second;
			}
		}
		else{
			x += el.second;
		}
	}
	cout << x << " " << one << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 