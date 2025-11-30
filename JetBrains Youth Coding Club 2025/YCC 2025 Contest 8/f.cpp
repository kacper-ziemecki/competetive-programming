#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


int n,res=INT_MIN;
string s;
const int maxn = 201;
int times[maxn];

int to_time(string s){
  int a = (s[0] - '0')*10;
  int b = s[1] - '0';
  int c = (s[3] - '0')*10;
  int d = s[4] - '0';
  int res = (a+b)*60 + (c+d);
  return res;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> s;
    times[i] = to_time(s);
    // dbg(times[i]);
  }
  sort(times, times+n);
  for(int i = 0; i < n; i++){
    times[i+n] = times[i]+(24*60);
  }
  for(int i = 0; i < 2*n-1; i++){
    res = max(res, times[i+1]-times[i]);
  }
  res--;
  if(res/60 < 10) cout << 0;
  cout << res/60;
  res -= (res/60)*60;
  cout << ":";
  if(res < 10) cout << 0;
  cout << res << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../in.in", "r", stdin);
  freopen("../../out.out", "w", stdout);
#endif

  solve();
}