#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  ll n,v,k = 0;
  cin >> n >> v;
  ll i = 0;
  ll res = 0;
  if(v >= n){
    cout << n-1 << endl;
    return;
  }
  n--;
  while(n - k > 0){
    i++;
    res += i*(v-k);
    k = v;
    k--;
    n--;
  }
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