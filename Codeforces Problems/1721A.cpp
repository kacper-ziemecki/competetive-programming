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
  set<char> l;
  for(auto el : a) l.emplace(el);
  for(auto el : b) l.emplace(el);
  if(l.size() == 3){
    cout << 2 << endl;
  } else if(l.size() == 2){
    cout << 1 << endl;
  } else if(l.size() == 4){
    cout << 3 << endl;
  } else{
    cout << 0 << endl;
  }
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