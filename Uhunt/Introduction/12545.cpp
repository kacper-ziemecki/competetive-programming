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
  string a,b;
  cin >> a >> b;
  ll one1 = 0, one2 = 0, ones, res=0;
  for(ll i = 0; i < a.size(); i++){
    if(a[i] == '1') one1++;
    if(b[i] == '1') one2++;
  }

  ones = one2-one1;
  if(ones < 0){
    cout << -1;
    return;
  }

  for(ll i = 0; i < a.size(); i++){
    if(a[i] != '?') continue;
    if(a[i] == '?' && b[i] == '1' && ones > 0){
      a[i] = '1';
      res++;
      ones--;
    }
    else{
      a[i] = '0';
      res++;
    }
  }
  for(ll i = 0; i < a.size(); i++){
    if(a[i] == '0' && b[i] == '1' && ones > 0){
      a[i] = '1';
      res++;
      ones--;
    }
  }
  ll temp = 0;
  for(ll i = 0; i < a.size(); i++){
    if(a[i] != b[i]) temp++;
  }
  res += temp/2;
  // cout << a << endl;
  cout << res;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif
  
  ll t;
  cin >> t;
  for(ll i = 1; i<= t; i++){
    cout << "Case " << i << ": ";
    solve();
    cout << endl;
  }
}