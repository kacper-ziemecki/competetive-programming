#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	vector<int> list = {a,b,c,d};
	sort(list.begin(), list.end());
	for(int i = 0; i < 4; i++){
		if(list[i] == a){
			cout << 3-i << endl;
			return;
		}
	}
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