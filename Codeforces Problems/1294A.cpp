#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int a,b,c,n;
	cin >> a >> b >> c >> n;
	int suma = max(a, max(b,c)) - a;
	suma += max(a, max(b,c)) - b;
	suma += max(a, max(b,c)) - c;
	if(n < suma){
		cout << "NO\n";
	}
	else{
		n -= suma;
		if(n %3 == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
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