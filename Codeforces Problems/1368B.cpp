#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)



void solve()
{
  ll n;
  cin >> n;
  vector<ll> list(10, 1);
  string napis="codeforces";
  ll i = 0, res = 1;
  while(res < n){
    res/= list[i];
    list[i]++;
    res *= list[i];
    i = (i+1)%10;
  }
  for(ll i = 0; i < 10; i++){
    cout << string(list[i], napis[i]);
  }
  cout << endl;
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}