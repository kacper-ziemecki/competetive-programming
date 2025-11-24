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
 vector<ll> one,two;
 for(ll i = 0; i < s.size()-1; i++){
  if(s[i] == 'A' && s[i+1] == 'B'){
    if(!two.empty() && two[0] < i-1){
      cout << "YES\n"; return;
    }
    one.push_back(i);
  }
  if(s[i] == 'B' && s[i+1] == 'A'){
    if(!one.empty() && one[0] < i-1){
      cout << "YES\n"; return;
    }
    two.push_back(i);
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