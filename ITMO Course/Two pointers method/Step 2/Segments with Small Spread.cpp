#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

struct s{
	vector<ll> s,smin = {LONG_LONG_MAX},smax = {LONG_LONG_MIN};
	void add(ll x){
		s.push_back(x);
		smin.push_back(min(smin.back(), x));
		smax.push_back(max(smax.back(), x));
	}
	ll remove(){
		ll res = s.back();
		s.pop_back();
		smin.pop_back();
		smax.pop_back();
		return res;
	}
	ll maks(){
		return smax.back();
	}
	ll mn(){
		return smin.back();
	}
	bool empty(){
		return s.empty();
	}
	ll size(){
		return s.size();
	}
};

void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> list(n, 0);
	for(auto &el : list) cin >> el;
	s s1,s2;
	ll l = 0, res = 0;
	for(ll r = 0; r < n; r++){
		s2.add(list[r]);
		while(max(s1.maks(), s2.maks()) - min(s1.mn(), s2.mn()) > m){
			if(s1.empty()){
				while(s2.size() != 0){
					s1.add(s2.remove());
				}
			}
			s1.remove();
			l++;
		}
		res += r - l + 1;
	}
	cout << res << endl;
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