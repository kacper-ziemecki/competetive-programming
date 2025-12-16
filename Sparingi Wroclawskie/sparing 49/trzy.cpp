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

ll n,k;
ll suma=0;
ll dwojki=0;

bool helper(ll x, ll gracz, ll ruchy_przed){
  // dbg(x,gracz);
  if(x <= 0 || !(x&1)) return true;
  if(gracz == 0){
    for(ll i = x-1; i >= max({0ll,x-k,x-ruchy_przed}); i--){
      if(!helper(i,1,x-i)){
        return true;
      }
    }
  } else{
    for(ll i = x-1; i >= max(0ll,x-ruchy_przed); i--){
      if(!helper(i,0,x-i)){
        return true;
      }
    }
  }
  return false;
}

bool koniec(vector<ll> &lista){
  for(auto el : lista){
    if(el > 0) return false;
  }
  return true;
}

bool brute(vector<ll> &lista, ll k, ll prev = LLONG_MAX, bool pierwszy = true){
  // dbg(pierwszy);
  if(!(suma&1)) return true;
  if(koniec(lista)) return true;
  for(auto &el : lista){
    for(int i = (pierwszy ? min({k,prev,el}) : min(el,prev)); i > 0; i-=2){
      el -= i;
      suma -= i;
      // dbg(i);
      if(!brute(lista,k,i,!pierwszy)){
        el += i;
        suma += i;
        return true;
      }
      el += i;
      suma += i;
    }
  }
  return false;
}

void solve(){
  cin >> n >> k;
  vector<ll> lista(n);
  for(auto &el : lista){
    cin >> el;
    suma += el;
    dwojki += el/2;
  }
  if(k == 1){
    cout << (suma&1 ? "NIE\n" : "TAK\n");
  } else if((suma-1)&1){ // mozna zrobic -1 i sie wygrywa
    cout << "TAK\n";
  } 
  else if(k == 2 || k == 3){
    if(dwojki&1) cout << "TAK\n";
    else cout << "NIE\n";
  } 
  else{
    if(n == 1){
        if(dwojki&1) cout << "TAK\n";
        cout << (helper(lista[0],0,LLONG_MAX) ? "TAK\n" : "NIE\n");
    }else{
      // brut forceeeeeeeeee (may the force be with you)
      cout << (brute(lista, k) ? "TAK\n" : "NIE\n");
    }
  }
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