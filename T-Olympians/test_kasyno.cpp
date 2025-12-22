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

int rnd(int a, int b){return rand()%(b-a+1) + a;}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll pieniodze = 1<<12;
  ll mn = LLONG_MAX;
  ll mx = LLONG_MIN;
  ll max_bet = 0;
  random_device rd;  // a seed source for the random number engine
  mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
  uniform_int_distribution<int> wygrana(0, 100);
  bool flag = false;
  for(ll dzien = 1; dzien < 365*10; dzien++){
    if(flag) break;
    for(ll bet = 0; bet < 9; bet++){
      if(pieniodze < 0){
        dbg(dzien, (double)dzien/365);
        double safety = (dzien-1)*0.1;
        dbg(safety);
        cout << "zrobilem kupe\n";
        flag = true;
        break;
      }
      max_bet = max(max_bet, bet);
      // dbg(1<<bet, wygrana(gen));
      if(wygrana(gen) < 50){
        pieniodze -= 1<<bet;
        mn = min(mn, pieniodze);
        mx = max(mx, pieniodze);
      } else{
        pieniodze += (1<<bet);
        mn = min(mn, pieniodze);
        mx = max(mx, pieniodze);
        break;
      }
    }
    if(dzien % (ll)1e6 == 0) dbg(dzien, pieniodze);
  }
  ll zysk = pieniodze - (1<<12);
  dbg(mn,mx);
  dbg(1<<max_bet);
  dbg(1<<12, pieniodze);
  dbg(zysk);
}