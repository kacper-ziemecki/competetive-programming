#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	int n;
	cin >> n;
	string jeden,dwa;
	cin >> jeden >> dwa;
	int one=0,two=0;
	for(auto el : jeden){
		if(el == '1') one++;
	}
	for(auto el : dwa){
		if(el == '1') two++;
	}
	if(one == two){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
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
