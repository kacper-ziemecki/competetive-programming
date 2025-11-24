#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll a,b,c,temp=0;
	cin >> a >> b >> c;
	int i = 0;
	while(c){
		i++;
		c--;
		temp+= i*a;
	}
	cout << max(0ll, temp - b) << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 