#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	int res = 0, temp, minimum,maksimum;
	cin >> temp;
	minimum = temp;
	maksimum = temp;
	for(int i = 1; i < n; i++){
		cin >> temp;
		if(temp > maksimum){
			res++;
		}
		if(temp < minimum){
			res++;
		}
		maksimum = max(maksimum, temp);
		minimum = min(minimum, temp);
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