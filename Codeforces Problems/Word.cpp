#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	string text;
	cin >> text;
	int a=0,b=0;
	for(auto el : text){
		if(el != tolower(el)){
			b++;
		}
		else{
			a++;
		}
	}
	if(a >= b){
		for(auto &el : text){
			el = tolower(el);
		}
	}
	else{
		for(auto &el : text){
			el = toupper(el);
		}
	}
	cout << text << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 