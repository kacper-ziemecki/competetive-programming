#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


void solve(){
	int n,a,res=0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a&1)res++;
	}
	if(res&1 && n > 1){
		cout<< 2 << endl;
	}
	else{
		cout << 1 << endl;
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
