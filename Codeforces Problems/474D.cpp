#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve(ll k, vector<ll> &prefix)
{
  ll a,b;
  cin >> a >> b;
  ll res = prefix[b] - (a - 1 > 0 ? prefix[a-1] : 0);
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  ll t,k;
  cin >> t >> k;

  vector<ll> lista(1e5+1, 1);
  for(ll i = 1; i <= 1e5+1; i++){
    if(i >= k){
      lista[i] = lista[i-1] + lista[i-k];
    }
    else{
      lista[i] = lista[i-1];
    }
    lista[i] %= 1000000007;
  }
  vector<ll> prefix(1e5+1, 1);
  prefix[1] = lista[1];
  for(ll i = 2; i < 1e5+1; i++){
    prefix[i] = prefix[i-1] + lista[i];
    prefix[i] %= 1000000007;
  }

  while(t--) solve(k, prefix);
}