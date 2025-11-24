#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string a;
	cin >> a;
	string res;
	for(int i = 0; i < a.size(); i++){
		if(i+1 < a.size() && a[i] == '-' && a[i+1] == '-'){
			res += '2';
			i++;
		}
		else if(i+1 < a.size() && a[i] == '-' && a[i+1] == '.'){
			res += '1';
			i++;
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