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
  ll n;
  cin >> n;
  vector<string> one(n, " "), two(n, " "), three(n, " ");
  for(auto &el : one) cin >> el;
  for(auto &el : two) cin >> el;
  for(auto &el : three) cin >> el;
  map<string, ll> m;
  for(auto el : one) m[el]++;
  for(auto el : two) m[el]++;
  for(auto el : three) m[el]++;

  ll a=0, b=0, c=0;
  for(auto el : one){
    if(m[el] == 1){
      a += 3;
    } else if(m[el] == 2){
      a += 1;
    }
  }
  for(auto el : two){
    if(m[el] == 1){
      b += 3;
    } else if(m[el] == 2){
      b += 1;
    }
  }
  for(auto el : three){
    if(m[el] == 1){
      c += 3;
    } else if(m[el] == 2){
      c += 1;
    }
  }
  cout << a << " " << b << " " << c << endl;
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