#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

struct s{
	vector<ll> s,sgcd;
	void add(ll x){
		s.push_back(x);
		if(sgcd.empty()){
			sgcd.push_back(x);
		}
		else{
			sgcd.push_back(__gcd(sgcd.back(), x));
		}
	}
	ll remove(){
		ll res = s.back();
		s.pop_back();
		sgcd.pop_back();
		return res;
	}
	ll cd(){
		if(sgcd.empty()) return 0;
		return sgcd.back();
	}
	bool empty(){
		return s.empty();
	}
	ll size(){
		return s.size();
	}
	void printGcd(){
		for(auto el : sgcd) cout << el << " ";
		cout << endl;
	}
};

void solve()
{
	ll n;
	cin >> n;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	s s1,s2;
	ll l = 0, res = LONG_LONG_MAX;
	for(ll r = 0; r < n; r++){
		if(list[r] == 1){
			cout << 1 << endl;
			return;
		}
		s2.add(list[r]);
		// s1.printGcd();
		// s2.printGcd();
		while(__gcd(s1.cd(), s2.cd()) == 1 && l < r){
			if(s1.empty()){
				while(s2.size() != 0){
					s1.add(s2.remove());
				}
			}
			s1.remove();
			l++;
		}
		// cout << l << " " << r << endl;
		if(l > 0) res = min(res, r - l + 2);
	}
	if(res == LONG_LONG_MAX){
		cout << -1 << endl;
	}
	else{
		cout << res << endl;
	}
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../../../input.txt", "r", stdin);
  freopen("../../../../output.txt", "w", stdout);
#endif

  solve();
}