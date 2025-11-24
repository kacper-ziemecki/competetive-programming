#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string napis;
	cin >> napis;
	sort(napis.rbegin(), napis.rend());
	cout << napis[0];
	for(int i = 1; i < napis.length(); i++){
		if(napis[i] == napis[0]){
			cout << napis[0];
		}
		else {
			cout << endl;
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	//freopen("input.txt", "r", stdin);
	solve();	
} 