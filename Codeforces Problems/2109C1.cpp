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

ll plusik = 1e18+1;
ll liczba;

void solve(){
  ll n,a;
  bool flag = false;
  cin >> n;
  cout << "digit" << endl; cin >> a;
  cout << "digit" << endl;  cin >> a;
  cout << "div " << 2 << endl;
  cin >> a;
  if(a){
    vector<ll> lista = {2,4,6};
    for(auto el : lista){
      cout << "add " << plusik-el << endl;
      cin >> a;
      if(a){
        flag = true;
        liczba = el;
        // dbg(el);
        break;
      }
    }
    if(!flag){
      liczba = 8;
      cout << "add " << n-8 << endl;
      cin >> a;
      cout << "!" << endl;
      cin >> a;
      return;
      // nie ustawiamy na plusik
    }
  } else{
    cout << "div 3" << endl;
    cin >> a;
    if(a){
      cout << "add " << plusik-3 << endl;
      cin >> a;
      if(a){
        liczba = 3;
      } else{
        liczba = 9;
        cout << "add " << n-9 << endl;
        cin >> a;
        cout << "!" << endl;
        cin >> a;
        return;
        // nie ustawiamy na plusik
      }
    } else{
      vector<ll> lista = {1,5};
      for(auto el : lista){
        cout << "add " << plusik-el << endl;
        cin >> a;
        if(a){
          flag = true;
          liczba = el;
          break;
        }
      }
      if(!flag){
        liczba = 7;
        cout << "add " << n-7 << endl;
        cin >> a;
        cout << "!" << endl;
        cin >> a;
        return;
        // nie ustawiamy na plusik
      }
    }
  }
  cout << "add " << n-plusik << endl;
  cin >> a;
  cout << "!" << endl;
  cin >> a;
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