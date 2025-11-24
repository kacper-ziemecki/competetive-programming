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
  string n;
  cin >> n;
  unsigned long long number = stoull(n);
  map<int, bool> mapa;
  for(int i = 1; i < 10; i++){
    if(number % i == 0){
      mapa[i] = true;
    }
  }
  int res = 0, tmp = 0;
  for(auto el : n){
    if(mapa[stoi(string(1, el))]){
      tmp++;
      cout << 1;
    }
    else{
      tmp=0;
      cout << 0;
    }
    res = max(res, tmp);
  }
  cout << endl;
  cout << res << endl;
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