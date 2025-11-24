#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void change(string& s, ll idx){
  reverse(s.begin(), s.begin()+idx+1);
  for(ll i = 0; i <= idx; i++){
    if(s[i] == '0') s[i] = '1';
    else s[i] = '0';
  }
}

void solve(){
  ll n;
  cin >> n;
  string a,b;
  cin >> a >> b;
  vector<ll> res;
  for(ll i = n-1; i >= 0; i--){
    if(a[i] == b[i]) continue;
    if(a[0] == b[i]){
      change(a, 0);
      res.push_back(0);
      change(a, i);
      res.push_back(i);
    } else{
      change(a, i);
      res.push_back(i);
    }
  }
  cout << res.size() << " ";
  for(auto el : res) cout << el+1 << " ";
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
  
  ll t;
  cin >> t;
  while(t--)
  solve();
  
}