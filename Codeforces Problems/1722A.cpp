#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	string text;
	cin >> text;
	unordered_map<char, bool> test;
	for(auto el : string("Timur")){
		test[el] = true;
	}
	for(auto el : text){
		if(!test[el]){
			cout << "NO\n";
			return;
		}
		else{
			test[el] = false;
		}
	}
	for(auto el : test){
		if(el.second == true){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 