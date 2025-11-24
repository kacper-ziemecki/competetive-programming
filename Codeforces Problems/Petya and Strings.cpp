#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string one, two;
	cin >> one >> two;
	for(auto &el : one){
		el = tolower(el);
	}
	for(auto &el : two){
		el = tolower(el);
	}
	for(int i = 0; i < one.size(); i++){
		if(one[i] > two[i]){
			cout << 1 << endl;
			return;
		}
		else if(one[i] < two[i]){
			cout << -1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 