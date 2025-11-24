#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n,k,res=INT_MAX;
  cin >> n >> k;
  vector<ll> list(n, 0);
  for(auto &el : list) cin >> el;
  if(k == 2){
    for(auto el : list){
      if(el == 0) res = min(res, 2ll);
      res = min(res, (el%2));
    }
  }
  if(k == 3){
    for(auto el : list){
      if(el == 0) res = min(res, 3ll);
      res = min(res, (el%3 == 0 ? 0 : 3 - (el%3)));
    }
  }
  if(k == 5){
    for(auto el : list){
      if(el == 0) res = min(res, 5ll);
      res = min(res, (el%5 == 0 ? 0 : 5 - (el%5)));
    }
  }
  if(k == 4){
    ll liczba1 = 0, liczba2 = 0, liczba4 = 0, liczba0 = 0;
    ll minimum = INT_MAX;
    for(auto el : list){
      if(el%2 == 1) liczba1++;
      if(el%2 == 0) liczba2++;
      if(el%4 == 0) liczba4++;
      if(el == 0) liczba0++;

      if(el == 0) minimum = min(minimum, 4ll);
      minimum = min(minimum, (el%4 == 0 ? 0 : 4 - (el%4)));
    }
    if(liczba4 >= 1 || liczba2 >= 2) res = 0;
    else if(liczba2 == 1 && liczba1 >= 1) res = 1;
    else if(liczba1 >= 2) res = 2;
    else if(liczba0 >= 1) res = 4;
    res = min(res, minimum);
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

  ll t;
  cin >> t;
  while(t--) solve();
}