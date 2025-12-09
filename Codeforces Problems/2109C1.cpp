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

<<<<<<< HEAD
ll liczba;
=======
ll plusik = 1e18+1;
>>>>>>> e370b23cb76b6cd10a1064f45236c4bb9f73fff5

void solve(){
  ll n,a;
  bool flag = false;
  cin >> n;
  cout << "digit" << endl; cin >> a;
  cout << "digit" << endl;  cin >> a;
<<<<<<< HEAD
  cout << "div " << 2 << endl; cin >> a;
  if(a){
    vector<ll> lista = {8,6,4};
    for(auto el : lista){
      cout << "add " << -el+1 << endl; cin >> a;
      if(a){
        flag = true;
        break;
      }
    }
    if(!flag){
      cout << "add " << -1 << endl; cin >> a;
      cout << "!" << endl; cin >> a;
      return;
      // nie ustawiamy na plusik
    }
  } else{
    cout << "div 3" << endl; cin >> a;
    if(a){
      cout << "add " << plusik-3 << endl; cin >> a;
      if(a){
        liczba = 3;
      } else{
        cout << "add " << n-9 << endl; cin >> a;
        cout << "!" << endl; cin >> a;
        return;
        // nie ustawiamy na plusik
      }
    } else{
      vector<ll> lista = {1,5};
      for(auto el : lista){
        cout << "add " << plusik-el << endl; cin >> a;
        if(a){
          flag = true;
          liczba = el;
          break;
        }
      }
      if(!flag){
        liczba = 7;
        cout << "add " << n-7 << endl; cin >> a;
        cout << "!" << endl; cin >> a;
        return;
        // nie ustawiamy na plusik
      }
    }
  }
  // dbg(n, plusik);
  cout << "add " << n-plusik << endl; cin >> a;
=======
  // 1 2 3 4 5 6 7 8 9
  cout << "add " << -8 << endl; cin >> a;
  // 1 2 3 4 5
  cout << "add " << -4 << endl; cin >> a;
  // 1 2 3
  cout << "add " << -2 << endl; cin >> a;
  // 1 2
  cout << "add " << -1 << endl; cin >> a;
  // 1 
  cout << "add " << n-1 << endl; cin >> a;
  // n 
>>>>>>> e370b23cb76b6cd10a1064f45236c4bb9f73fff5
  cout << "!" << endl; cin >> a;
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