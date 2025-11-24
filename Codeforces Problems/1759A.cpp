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
  if(s == "e" || s == "s" || s == "Y"){
    cout << "YES\n";
    return;
  }
  if(s[0] == 's'){
    s = s.substr(1, s.size()-1);
  } else if(s.size() >= 2 && s.substr(0, 2) == "es"){
    s = s.substr(2, s.size()-2);
  }

  if(s.size() >= 1 && s.back() == 'Y'){
    s = s.substr(0, s.size()-1);
  } else if(s.size() >= 2 && s.substr(s.size()-2, 2) == "Ye"){
    s = s.substr(0, s.size()-2);
  }
  if(s.size()%3 != 0){
    cout << "NO\n";
    return;
  }
  for(ll i = 2; i < s.size(); i+=3){
    if(s.substr(i-2, 3) != "Yes"){
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