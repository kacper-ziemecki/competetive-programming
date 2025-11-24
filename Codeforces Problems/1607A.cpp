#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string one, two;
	cin >> one >> two;
	ll res = -1;
	ll temp = 0;
	for(auto el : two){
		ll index = 0;
		for(int i = 0; i < 26; i++){
			if(el == one[i]){
				index = i;
				break;
			}
		}
		if(res == -1){
			temp = index;
			res = 0;
		}
		res += abs(temp - index);
		temp = index;
	}	
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 