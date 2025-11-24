#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int res = 0;
	while(n-5 >= 0){
		n -= 5;
		res++;
	}
	while(n-4 >= 0){
		n -=4;
		res++;
	}
	while(n-3 >= 0){
		n -= 3;
		res++;
	}
	while(n-2 >= 0){
		n -= 2;
		res++;
	}
	while(n-1 >= 0){
		n -= 1;
		res++;
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 