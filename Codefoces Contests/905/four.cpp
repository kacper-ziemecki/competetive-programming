#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool same(pair<ll, ll> one, pair<ll, ll> two){
  if(one.first == -two.second && one.second == -two.first){
    return true;
  }
  return false;
}

void solve()
{
  ll q;
  cin >> q;
  char op;
  ll a,b;
  map<pair<ll, ll>, ll> one, two;
  for(ll i = 0; i < q; i++){
    cin >> op >> a >> b;
    if(op == '+'){
      one[{b, a}]++;
      two[{-a, -b}]++;
    } else{
      if(one[{b,a}] == 1) one.erase({b,a});
      else one[{b,a}]--;

      if(two[{-a, -b}] == 1) two.erase({-a, -b});
      else two[{-a, -b}]--;
    }
    if(one.empty()){
      cout << "NO\n";
      continue;
    }
    if(same((*one.begin()).first, (*two.begin()).first)){
      cout << "NO\n";
      continue;
    }
    if((*one.begin()).first.first < -((*two.begin()).first.first)){
      cout << "YES\n";
    } else{
      cout << "NO\n";
    }
  }
}
int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}