#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,k;
vector<int> a;

bool good(double x){
  int s = 0;
  for(int i = 0; i < n; i++){
    s += floor(a[i]/x);
  }
  return s >= k;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
#endif

  cin >> n >> k;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  double l = 0;
  double r = 1e8;

  for(int t = 0; t < 100; t++){
    double m = (l+r)/2;
    if(good(m)){
      l = m;
    } else{
      r = m;
    }
  }
  cout << setprecision(20) << l << endl;
}