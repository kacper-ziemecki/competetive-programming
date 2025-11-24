#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n;
	cin >> n;
	pair<ll, ll> minimum = {0, INT_MAX}, maks = {0, INT_MIN};
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp < minimum.second){
			minimum.second = temp;
			minimum.first = i;
		}
		if(temp > maks.second){
			maks.second = temp;
			maks.first = i;
		}
	}
	if(minimum.first < maks.first){
		cout << min(minimum.first + 1 + (n - maks.first), min(maks.first + 1, n - minimum.first)) << endl;
	}
	else{
		cout << min(maks.first + 1 + (n - minimum.first), min(minimum.first + 1, n - maks.first)) << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 