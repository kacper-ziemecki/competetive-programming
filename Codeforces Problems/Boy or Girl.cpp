#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	unordered_map<char, bool> list;
	for(auto el : text) list[el] = true;
	if(list.size()&1){
		cout << "IGNORE HIM!\n";
	}
	else{
		cout << "CHAT WITH HER!\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 