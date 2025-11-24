#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string one, two, three;
	cin >> one >> two >> three;
	vector<int> list('z'-'a' + 1, 0);
	for(auto el : one) list[el - 'A']++;
	for(auto el : two) list[el - 'A']++;
	for(auto el : three) list[el - 'A']--;
	for(auto el : list){
		if(el != 0){
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
	solve();	
} 