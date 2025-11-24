#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

void subsolve(ll index, vector<ll> list, ll temp, ll suma, ll &res){
  if(!((suma - temp)&1)) res++;
  if(index >= list.size()) return;

  subsolve(index+1, list, temp+list[index], suma, res);
  subsolve(index+1, list, temp, suma, res);
}

void solve()
{
  ll n, suma = 0;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list){
    cin >> el;
    suma += el;
  }
  ll res = 0;
  subsolve(0, list, 0, suma, res);
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

  solve();
}