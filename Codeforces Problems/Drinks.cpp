#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long double n;
	cin >> n;
	long double sum=0,temp;
	for(long double i = 0; i < n; i++){
		cin >> temp;
		sum += temp;
	}
	cout << fixed;
	cout << sum/n << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 