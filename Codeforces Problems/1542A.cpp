#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	n*= 2;
	ll temp, even = 0, odd = 0;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp&1) odd++;
		else even++;
	}
	if(even == odd){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while(t--) solve();	
} 