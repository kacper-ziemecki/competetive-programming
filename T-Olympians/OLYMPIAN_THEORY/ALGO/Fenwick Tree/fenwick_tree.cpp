#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

struct Fenwick{
  vector<int> f;
  int ss;
  Fenwick(int n){
    ss = n+1;
    f.assign(ss,0);
  }
  void add(int i, int v){
    while(i < ss){
      f[i] += v;
      i += (i&(-i));
    }
  }
  int pref(int i){
    int suma = 0;
    while(i){
      suma += f[i];
      i -= (i&(-i));
    }
    return suma;
  }
  int suma(int l, int r){
    return pref(r) - pref(l-1);
  }
};

void solve(){
  Fenwick fen(5);
  fen.add(1,6);
  fen.add(2,7);
  cout << fen.suma(1,2) << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}