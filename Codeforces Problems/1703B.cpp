#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	string text;
	cin >> text;
	vector<bool> test(26, false);
	ll res = 0;
	for(auto &el : text){
		el = tolower(el);
		if(!test[el - 'a']){
			res+=2;
		}
		else{
			res++;
		}
		test[el - 'a'] = true;
	}
	cout << res << endl;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 