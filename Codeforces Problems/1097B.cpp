#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


bool subsolve(vector<ll> list, ll index, ll n, ll suma){
  if(index == n && suma%360 == 0) return true;
  if(index == n) return false;

  if(subsolve(list, index+1, n, suma+list[index])){
    return true;
  }
  if(subsolve(list, index+1, n, suma-list[index])){
    return true;
  }
  return false;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  cout << (subsolve(list, 0, n, 0) ? "YES\n" : "NO\n" );
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