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
  string s;
  cin >> s;
  char el = 'a';
  ll x = -1;
  for(ll i = 0; i < s.size(); i++){
    if(s[i] == el){
      x = i;
      break;
    }
  }
  if(x == -1){
    cout << "NO\n";
    return;
  }
  el++;
  ll left = x-1, right = x+1;
  while(left >= 0 || right < s.size()){
    if(left >= 0 && el == s[left]){
      left--;
    } else if(right < s.size() && el == s[right]){
      right++;
    } else{
      cout << "NO\n";
      return;
    }
    el++;
    if(el > 'z'){
      cout << "YES\n";
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
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  ll t;
  cin >> t;
  while(t--)
  solve();
  
}