#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	string text;
	cin >> text;
	int a=0,b=0;
	for(auto el : text){
		if(el == 'A') a++;
		if(el == 'D') b++;
	}
	cout << (a > b ? "Anton\n" : (a == b ? "Friendship\n" : "Danik\n"));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 