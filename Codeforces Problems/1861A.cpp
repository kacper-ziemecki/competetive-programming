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
  vector<bool> prime(100, true);
  prime[0] = false;
  prime[1] = false;
  for(ll i = 2; i*i < 100; i++){
    if(!prime[i]) continue;
    for(ll j = i*i; j < 100; j+=i){
      prime[j] = false;
    }
  }
  for(ll i = 0; i < s.size(); i++){
    for(ll j = i+1; j < s.size(); j++){
      if((s[i]-'0') != 0 && prime[(s[i]-'0')*10 + (s[j]-'0')]){
        cout << (s[i]-'0')*10 + (s[j]-'0') << endl;
        return;
      }
    }
  }
  cout << -1 << endl;
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