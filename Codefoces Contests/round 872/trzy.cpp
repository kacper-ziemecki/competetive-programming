#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long


long long minimum(long long a, long long b){
	if(a <= b) return a;
	return b;
}
long long maximum(long long a, long long b){
	if(a>=b) return a;
	return b;
}

void solve(){
	ll n, m;
	cin >> n >> m;
	set<ll> list = {};
	ll cnt1=0,cnt2=0;
	ll temp;
	for(ll i = 0; i < n; i++){
		cin >> temp;
		if(temp > 0) list.emplace(temp);
		if(temp == -1) cnt1++;
		if(temp == -2) cnt2++;
	}
	vector<ll> temporary = {};
	for(long long el : list) temporary.push_back(el);
	sort(temporary.begin(), temporary.end());
	ll temporarySize = temporary.size();
	if(temporarySize == 0){
		cout << maximum(cnt1, cnt2) << endl;
	}
	else if(!(cnt1 || cnt2)){
		cout << temporarySize << endl;
	}
	else{
		ll i = -1;
		ll res = 0;

		res = maximum(res, minimum(m, cnt1+temporarySize));
		res = maximum(res, minimum(m, cnt2+temporarySize));

		for(long long el : temporary){
			i++;

			ll left = minimum(cnt1+i, el-1);
			ll right = minimum(cnt2+(temporarySize-i-1), m-el);
			res = minimum(m, maximum(res, left+1+right));

		}
		cout << res << endl;
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