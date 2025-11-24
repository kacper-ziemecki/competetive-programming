#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve()
{
  string one, two;
  cin >> one >> two;
  map<char, int> mapa;
  for(auto el : one){
    mapa[el] = 1;
  }
  ll incorrect = 0, correct = 0;
  for(auto el : two){
    if(mapa[el] == 1){
      mapa[el] = 2;
      correct++;
    }
    else if(!mapa[el]){
      mapa[el] == 3;
      incorrect++;
    }

    if(correct >= mapa.size()){
      cout << "You win.\n";
      return;
    }
    if(incorrect >= 7){
      cout << "You lose.\n";
      return;
    }
  }

  cout << "You chickened out.\n";
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
    if(n == -1) break;
    cout << "Round " << n << endl;
    solve();
  }
  
}