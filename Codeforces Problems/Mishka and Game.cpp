#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int one = 0, two = 0;
	int t1,t2;
	for(int i = 0; i < n; i++){
		cin >> t1 >> t2;
		if(t1 > t2){
			one++;
		}
		if(t2 > t1){
			two++;
		}
	}
	if(one > two){
		cout << "Mishka\n";
	}
	else if(one < two){
		cout << "Chris\n";
	}
	else {
		cout << "Friendship is magic!^^\n";
	}
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 