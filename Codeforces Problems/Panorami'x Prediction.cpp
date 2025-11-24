#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


bool isprime(int n){
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return false;
	}
	return true;
}
void solve(){
	int a,b;
	cin >> a >> b;
	for(int i = a+1; i <= b; i++){
		if(isprime(i) && i != b){
			cout << "NO\n";
			return;
		}
		else if(isprime(i) && i == b){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();	
} 
