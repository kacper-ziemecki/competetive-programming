#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(ll n)
{
  ll right = 11, left = 0, tmp = n;
  string text;
  bool first = true;
  while(true){
    if(!first) cin >> tmp;
    first = false;
    cin.ignore();
    getline(cin, text);
    if(text == "too high"){
      right = min(tmp, right);
    }
    else if(text == "too low"){
      left = max(left,tmp);
    }
    else{
      // cout << "right on: " << tmp << endl;
      if(tmp < right && tmp > left){
        cout << "Stan may be honest\n";
        return;
      }
      else{
        cout << "Stan is dishonest\n";
        return;
      }
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

// #ifndef ONLINE_JUDGE
//   freopen("../../input.txt", "r", stdin);
// #endif

  ll n;
  while(true){
    cin >> n;
    if(n == 0) break;
    solve(n);
  }
  
}