#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  ll n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> a,b;
  for(ll i = 0; i < n; i++){
    if(i&1) b.push_back(s[i]);
    else a.push_back(s[i]);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for(ll i = 0; i < a.size(); i++){
    if(a[i] != b[i]){
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
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif


  ll t;
  cin >> t;
  while(t--)
  solve();
  
  
}