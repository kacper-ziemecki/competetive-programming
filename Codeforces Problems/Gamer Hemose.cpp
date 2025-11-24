#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

void solve(){
	ll n,H,jeden=INT_MIN,dwa=INT_MAX,a,res=0;
	cin >> n >> H;
	for(int i = 0; i < n; i++){
		cin >> a;
		if(a > jeden){
			dwa = jeden;
			jeden = a;
		}
		else if(a > dwa){
			dwa = a;
		}
	}
	res = H / (jeden + dwa);
	H -= res * (jeden + dwa);
	res *= 2;
	if(H > 0){
		H -= jeden;
		res++;
	}
	if(H > 0){
		H -= dwa;
		res++;
	}
	cout << res << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	//freopen("input.txt", "r", stdin);
	ll t;
	cin >> t;
	while(t--) solve();	
} 