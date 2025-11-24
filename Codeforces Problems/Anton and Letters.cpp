#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	getline(cin, text);
	set<char> list;
	for(auto el : text){
		if(el != ',' && el != ' ' && el!= '{' && el != '}') list.emplace(el);
	}
	cout << list.size() << endl;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 