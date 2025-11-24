#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	ll one = 0, two = 0;
	ll temp = 1;
	for(int i = 1; i < n; i++){
		temp *= 2;
		if(i<n/2) one += temp;
		else two += temp;
	}
	one += temp * 2;
	cout << abs(two - one) << endl;
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