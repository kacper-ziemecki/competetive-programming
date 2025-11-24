#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	ll res = 0;
	string temp;
	for(int i = 0;i < n; i++){
		cin >> temp;
		if(temp == "Tetrahedron") res += 4;
		if(temp == "Cube") res += 6;
		if(temp == "Octahedron") res += 8;
		if(temp == "Dodecahedron") res += 12;
		if(temp == "Icosahedron") res += 20;
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