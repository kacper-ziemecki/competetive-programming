#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

void solve()
{
  ll n,k;
  cin >> n >> k;
  string text;
  cin >> text;
  vector<ll> list;
  for(ll i = 0; i < n; i++){
    if(text[i] == '.') list.push_back(i);
  }
  for(ll i = 1; i < list.size(); i++){
    if(list[i] - list[i-1] > k){
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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