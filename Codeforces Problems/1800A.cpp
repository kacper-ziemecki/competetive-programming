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
  string text;
  cin >> text;
  for(auto &el : text){
    el = tolower(el);
  }
  string tmp = "meow";
  ll j = 0;
  ll cnt = 0;
  for(ll i = 0; i < n; i++){
    if(text[i] == tmp[j]){
      cnt++;
    }
    else if(text[i] != tmp[j] && cnt > 0 && j < tmp.size()-1 && text[i] == tmp[j+1]){
      j++;
      cnt=1;
    }
    else{
      cout << "NO\n";
      return;
    }
  }
  if(j != tmp.size()-1){
    cout << "NO\n";
    return;
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