#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int n,ans,lg,p=1,i=0,block;
string napis;
bool a,b;

bool zapytaj(string s){
  cout << "? " << s << endl;
  cin >> ans;
  return ans;
}

void solve(){
  cin >> n;
  while(napis.size() < n){
    a = zapytaj(napis+'1');

    if(a) napis = napis+'1';
    else napis = napis+'0';
  }
  int lewo = 0, prawo = n;
  while(lewo < prawo){
    int mid = (lewo+prawo+1)/2;
    if(zapytaj(napis.substr(0, mid))) lewo = mid;
    else prawo = mid-1;
  }
  napis = napis.substr(0, lewo);
  while(napis.size() < n){
    // cout << "koniec\n";
    a = zapytaj('0'+napis);
    if(a) napis = '0'+napis;
    else napis = '1'+napis;
  }
  cout << "! " << napis << endl;
}

int main()
{

  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);
 
// #ifndef ONLINE_JUDGE
//   freopen("../../in.in", "r", stdin);
//   freopen("../../out.out", "w", stdout);
// #endif

  solve();
}