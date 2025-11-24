#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)


bool comparing(pair<ll, pair<ll, ll>> one, pair<ll, pair<ll, ll>> two){
  if(one.first == two.first){
    return one.second.first >= two.second.first;
  }
  return one.first >= two.first;
}

void solve()
{
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, decltype(&comparing) > pq(comparing);
  string tmp;
  ll a,b,k;
  while(true){
    cin >> tmp;
    if(tmp == "#") break;
    cin >> a >> b;
    pq.push({b, {b, a}});
  }
  cin >> k;
  for(ll i = 0; i < k; i++){
    pair<ll, pair<ll, ll>> temp = pq.top();
    cout << temp.second.second << endl;
    pq.pop();
    temp.first += temp.second.first;
    pq.push(temp);
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

  solve();
  
}