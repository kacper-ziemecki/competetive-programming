#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

ll _get(ll a, vector<ll> &p){
  return p[a] = (p[a] == a ? a : _get(p[a], p));
}

void _union(ll a, ll b, vector<ll> &p, vector<ll> &r){
  a = _get(a, p);
  b = _get(b, p);
  if(r[a] == r[b]) r[a]++;
  if(r[a] > r[b]) p[b] = a;
  else p[a] = b;
}

void solve()
{
	ll n,m;
	cin >> n >> m;
	vector<ll> p(n+1, 0), r(n+1, 1);
	for(int i = 0; i <= n; i++){
		p[i] = i;
	}
	for(int i = 0; i < m; i++){
		string text;
		cin >> text;
		ll a,b;
		cin >> a >> b;
		if(text == "union"){
			_union(a,b, p, r);
		}
		else if(_get(a,p) == _get(b,p)){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
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