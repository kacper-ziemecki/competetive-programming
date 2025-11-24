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
  ll n = s.size();
  for(ll i = n-1; i >= 0; i--){
    for(ll j = i-1; j >= 0; j--){
      for(ll k = j-1; k >= 0; k--){
        ll num1 = (s[k]-'0')*100 + (s[j]-'0')*10 + (s[i]-'0');
        if(num1%8==0){
          cout << "YES\n";
          cout << s.substr(0, k) << s[k] << s[j] << s[i] << endl;
          return;
        }
      }
      ll num2 = (s[j]-'0')*10 + (s[i]-'0');
      if(num2%8==0 && s[j] != '0'){
          cout << "YES\n";
          cout << s[j] << s[i] << endl;
          return;
      }
    }
    ll num3 = (s[i]-'0');
    if(num3%8==0){
      cout << "YES\n";
      cout << s[i] << endl;
      return;
    }
  }
  cout << "NO\n";
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