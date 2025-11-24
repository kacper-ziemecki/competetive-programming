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
  string s;
  cin >> s;
  ll n = s.size();
  vector<char> prawo(n), lewo(n);
  prawo[n-1] = s[n-1];
  lewo[0] = s[0];
  for(ll i = 1; i < n; i++){
    if(s[i] == '.') lewo[i] = lewo[i-1];
    else lewo[i] = s[i];

    if(s[n-i-1] == '.') prawo[n-i-1] = prawo[n-i];
    else prawo[n-i-1] = s[n-i-1];
  }
  // for(auto el : lewo) cout << el;
  // cout << endl;
  // for(auto el : prawo) cout << el;
  // cout << endl;
  ll one=0,two=0;
  for(ll i = 0; i < n; i++){
    if(lewo[i] == 'A' && prawo[i] == 'A') one++;
    if(lewo[i] == 'B' && prawo[i] == 'B') two++;
  }
  cout << one << " " << two << endl;
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