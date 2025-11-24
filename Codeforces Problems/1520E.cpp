#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll cntr=0,cntl=0,sumr=0,suml=0;
  for(ll i = n-1; i >= 0; i--){
    sumr += cntr;
    if(s[i]=='*') cntr++;
  }
  ll res = LLONG_MAX;
  for(ll i = 0; i < n; i++){
    if(s[i]=='*') cntr--;
    sumr -= cntr;

    suml += cntl;
    if(s[i]=='*') cntl++;

    if(cntl==0){
      sumr += cntr;
      ll cur1 = sumr-(cntr*(cntr-1))/2;
      sumr -= cntr;
      res = min(res, cur1);
    } else{
      ll cur1 = sumr-(cntr*(cntr-1))/2;
      ll cur2 = suml-(cntl*(cntl-1))/2;
      res = min(res, cur1+cur2);
    }
  }
  cout << res << endl;
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

  ll t;
  cin >> t;
  while(t--)
  solve();  
  
} 