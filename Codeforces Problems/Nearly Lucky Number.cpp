#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,res=0;
	cin >> n;
	while(n){
		if(n%10 == 7 || n%10 == 4) res++;
		n /= 10;
	}
	if(res == 0){
		cout << "NO\n";
		return;
	}
	while(res){
		if(res%10 != 7 && res%10 != 4){
			cout << "NO\n";
			return;
		}
		res /= 10;
	}
	cout << "YES\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 