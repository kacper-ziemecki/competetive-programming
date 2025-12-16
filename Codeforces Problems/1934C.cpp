#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
#define pb push_back
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(){
  int n,m;
  cin >> n >> m;
  int a,b,c,d;
  cout << "? 1 1" << endl;
  cin >> a;
<<<<<<< HEAD
  cout << "? " << min(n,1+a) << ' ' << max(1,1+a-n+1) << endl;
  cin >> b;
  cout << "? " << max(1,1+a-m+1) << ' ' << min(m,1+a) << endl;
  cin >>c;
  if(b&1){
    cout << "! " << max(1,1+a-m+1)+c/2 << ' ' << min(m,1+a)-c/2 << endl;
  } else{
    cout << "? " << min(n,1+a)-b/2 << ' ' << max(1,1+a-n+1)+b/2 << endl;
    cin >> d;
    if(d == 0){
      cout << "! " << min(n,1+a)-b/2 << ' ' << max(1,1+a-n+1)+b/2 << endl;
    } else{
      cout << "! " << max(1,1+a-m+1)+c/2 << ' ' << min(m,1+a)-c/2 << endl;
    }
=======
  cout << "? 1 " << m << endl;
  cin >> b;
  cout << "? " << n << " 1" << endl;
  cin >> d;
  cout << "? " << n << ' ' << m << endl;
  cin >> c;
  if(a+b-m+1 % 2 == 0 && a-(a+b-m+1)/2 >= 0 && b-(a+b-m+1)/2 >= 0){
    // dbg(1);
    cout << "! " << 1+(a+b-m+1)/2 << ' ' << 1+a-(a+b-m+1)/2 << endl;
  } else if(b+c-n+1 % 2 == 0 && b-(b+c-n+1)/2 >= 0 && c-(b+c-n+1)/2 >= 0){
    // dbg(2);
    cout << "! " << 1+b-(b+c-n+1)/2 << ' ' << 1+(b+c-n+1)/2 << endl;
  } else if(c+d-m+1 % 2 == 0 && c-(c+d-m+1)/2 >= 0 && d-(c+d-m+1)/2 >= 0){
    // dbg(3);
    cout << "! " << n-(c+d-m+1)/2 << ' ' << 1+d-(c+d-m+1)/2 << endl;
  } else{
    // dbg(4);
    cout << "! " << 1+a-(a+d-n+1)/2 << ' ' << 1+(a+d-n+1)/2 << endl;
>>>>>>> 259e0c613432dd285b014a91bdaa64e3492743cf
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

  int t;
  cin >> t;
  while(t--)
  solve();
}