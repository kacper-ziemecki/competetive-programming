#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<ull> divi{4};

void solve()
{
  ull n;
  cin >> n;
  while(divi.back()-1 < n){
    divi.push_back(divi.back()*2);
  }
  // for(auto el : divi) cout << el << endl;
  for(auto el : divi){
    // dbg(el);
    if(n % (el - 1) == 0){
      cout << n / (el - 1) << endl;
      return;
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
#endif

  ll t;
  cin >> t;
  while(t--) solve();
  
}