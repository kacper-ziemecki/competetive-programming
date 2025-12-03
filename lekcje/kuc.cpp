#include <bits/stdc++.h>
#include "ckuclib.h"
using namespace std;
// #define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve(){
  int n,e,one,two,three;
  n = dajn();
  e = daje();
  vector<int> koszt(n+1), energia(n+1); // zamienic na long long
  koszt[0] = 0;
  energia[0] = e;
  koszt[1] = jedno(1);
  energia[1] = e+1;
  for(int i = 2; i <= n; i++){
    one = jedno(i);
    two = dwa(i);
    three = polowa(i);
    

  }
}

int main()
{

//   ios_base::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}