#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string one,two,res = "";
	cin >> one >> two;
	for(int i = 0; i < one.size(); i++){
		if(one[i] != two[i]){
			res += '1';
		}
		else{
			res += '0';
		}
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 