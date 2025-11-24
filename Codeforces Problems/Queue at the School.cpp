#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n,t;
	cin >> n >> t;
	string text;
	cin >> text;
	for(int i = 0; i < t; i++){
		for(int j = 0; j < n-1; j++){
			if(text[j] == 'B' && text[j+1] == 'G'){
				text[j] = 'G';
				text[j+1] = 'B';
				j++;
			}
		}
	}
	cout << text<< endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 