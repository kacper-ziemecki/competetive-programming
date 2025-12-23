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


void solve(){
  ll n,x,y;
  cin >> n >> x >> y;
  string s;
  cin >> s;
  vector<ll> p(n);
  for(auto &el : p) cin >> el;
  vector<ll> a(n), b(n);
  ll suma1 = 0, suma2 = 0, totalSuma = 0;
  bool jestZero = false, jestJeden = false;
  for(ll i = 0; i < n; i++){

    totalSuma += p[i];

    if(s[i] == '1') jestJeden = true;
    else jestZero = true;

    if(s[i] == '0'){
      a[i] = p[i];
      suma1 += p[i];
    } else{
      b[i] = p[i];
      suma2 += p[i];
    }
  }
  if(totalSuma > x+y){
    cout << "NO\n"; 
    return;
  }
  if((x >= suma1) && (y >= suma2) && jestZero && jestJeden){
    cout << "YES\n";
    return;
  }
  // dbg(suma1,suma2);
  // for(auto el : a) cout << el << ' ';
  // cout << endl;
  // for(auto el : b) cout << el << ' ';
  // cout << endl;
  // cout << "--------------\n";

  if(x < suma1){ // pierwszy ma za duzo
    for(ll i = 0; i < n; i++){
      if(s[i] == '0'){
        ll odejmowanie = min(suma1-x,(a[i]+1)/2-1);
        a[i] -= odejmowanie;
        b[i] += odejmowanie;
        suma1 -= odejmowanie;
        suma2 += odejmowanie;
      }
    }
  } 
  if(y < suma2){ // drugi ma za duzo
    for(ll i = 0; i < n; i++){
      if(s[i] == '1'){
        ll odejmowanie = min(suma2-y,(b[i]+1)/2-1);
        b[i] -= odejmowanie;
        a[i] += odejmowanie;
        suma2 -= odejmowanie;
        suma1 += odejmowanie;
      }
    }
  }

  if((x > suma1) || (y > suma2)){ // w jakims za malo
    if(jestZero && (x > suma1)){ // ten pierwszy musi byc gdzies wiekszy niz ten drugi
      for(ll i = 0; i < n; i++){
        if(s[i] == '0'){
          a[i] += (x-suma1);
          suma1 = x;
          break;
        }
      }
    }
    if(jestJeden && (y > suma2)){ // ten drugi musi byc gdzies wiekszy niz ten pierwszy
      for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
          b[i] += (y-suma2);
          suma2 = y;
          break;
        }
      }
    }

    if(x > suma1){ // nie ma zadnych pul gdzie mozemy zwiekszyc suma1 
      for(ll i = 0; i < n; i++){
        ll dodanie = min(x-suma1, b[i]-1-a[i]);
        a[i] += dodanie;
        suma1 += dodanie;
      }
    } 
    if(y > suma2){ // nie ma zadnych pul gdzie mozemy zwiekszyc suma2
      for(ll i = 0; i < n; i++){
        ll dodanie = min(y-suma2, a[i]-1-b[i]);
        b[i] += dodanie;
        suma2 += dodanie;
      }
    }
  }

  // for(auto el : a) cout << el << ' ';
  // cout << endl;
  // for(auto el : b) cout << el << ' ';
  // cout << endl;

  if(x == suma1 && y == suma2){
    cout << "YES\n";
  } else{
    cout << "NO\n";
  }
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

  int t;
  cin >> t;
  while(t--)
  solve();
}