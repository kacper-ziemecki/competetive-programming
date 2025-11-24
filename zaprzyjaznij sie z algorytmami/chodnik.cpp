#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	long long unsigned int n, a, suma1 = 0, suma2;
	cin >> n;
	for(long long unsigned int i = 1; i < n; i++){
		cin >> a;
		suma1 += a;
	}  
	suma2 = n * (n + 1) / 2;
	cout << suma2 - suma1 << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	solve();
	
} 