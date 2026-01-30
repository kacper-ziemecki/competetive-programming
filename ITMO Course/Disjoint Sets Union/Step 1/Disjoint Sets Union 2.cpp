#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


vector<ll> p(3*1e5+1, 0), _size(3*1e5+1, 1), smin(3*1e5+1, 0), smax(3*1e5+1, 0);

ll _get(ll a){
  return p[a] = (p[a] == a ? a : _get(p[a]));
}

void _union(ll a, ll b){
  a = _get(a);
  b = _get(b);
  if(a == b) return;
  if(_size[a] > _size[b]){
  	p[b] = a;
  	smin[a] = min(smin[b], smin[a]);
  	smax[a] = max(smax[b], smax[a]);
  	_size[a] += _size[b];
  }
  else{
  	p[a] = b;
  	smin[b] = min(smin[b], smin[a]);
  	smax[b] = max(smax[b], smax[a]);
  	_size[b] += _size[a];
  }
}

void solve()
{
	ll n,m;
	cin >> n >> m;
	for(int i = 0; i <= n; i++){
		p[i] = i;
		smin[i] = i;
		smax[i] = i;
	}
	for(int i = 0; i < m; i++){
		string text;
		cin >> text;
		ll a,b;
		if(text == "union"){
			cin >> a >> b;
			_union(a,b);
		}
		else{
			cin >> a;
			ll temp = _get(a);
			cout << smin[temp] << " " << smax[temp] << " " << _size[temp] << endl;
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