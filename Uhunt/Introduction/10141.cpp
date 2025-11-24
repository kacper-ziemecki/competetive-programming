#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


void solve(double a, double b)
{
  string temp;
  double n;
  double q;
  cin.ignore();
  for(ll i = 0; i < a; i++) getline(cin, temp);
  map<double, vector<pair<double, string>>, greater<double>> mapa;
  for(ll i = 0; i < b; i++){
    getline(cin, temp);
    cin >> q >> n;
    mapa[n/a].push_back({q, temp});
    //cout << n/a << " -> " << q << ", " << temp << endl; 
    cin.ignore();
    for(ll j = 0; j < n; j++) getline(cin, temp);
  }
  for(auto el : mapa){
    sort(el.second.begin(), el.second.end());
    //cout << el.first << ":\n";
    cout << el.second[0].second << endl;
    return;
    // for(auto subel : el.second){
    //   cout << subel.first << " " << subel.second << endl;
    //   //cout << subel.second << endl;
    //   //return;
    // }
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
  
  double a,b;
  ll counter = 0;
  while(true){
    counter++;
    cin >> a >> b;
    if(a == 0 && b == 0) break;
    if(counter > 1) cout << endl;
    cout << "RFP #" << counter << endl;
    solve(a,b);
  }
}