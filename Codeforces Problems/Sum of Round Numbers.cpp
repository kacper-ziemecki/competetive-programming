#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int temp = 1;
	vector<int> res;
	while(n){
		if(n%10 != 0){
			temp *= n%10;
			res.push_back(temp);
			temp /= n%10;
		}
		n /= 10;
		temp *= 10;
	}
	cout << res.size() << endl;
	for(auto el : res) cout << el << " ";
	cout << endl;
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