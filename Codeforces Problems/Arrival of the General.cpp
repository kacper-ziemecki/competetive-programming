#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	int n;
	cin >> n;
	vector<int> list(n, 0);
	for(auto &el : list) cin >> el;
	pair<int,int> maks = {0, INT_MIN}, minimum = {0, INT_MAX};
	for(int i = 0; i < n; i++){
		if(list[i] > maks.second){
			maks.second = list[i];
			maks.first = i;
		}
		if(list[i] <= minimum.second){
			minimum.second = list[i];
			minimum.first = i;
		}
	}
	if(minimum.first > maks.first){
		cout << n-1-minimum.first + maks.first << endl;
	}
	else{
		cout << n-1-minimum.first + maks.first - 1 << endl;
	}

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	// freopen("input.txt", "r", stdin);
	solve();	
} 