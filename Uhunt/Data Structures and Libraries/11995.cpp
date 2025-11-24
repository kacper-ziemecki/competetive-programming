#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
#define ull unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void solve(ll n)
{
  vector<bool> res{true, true, true};
  stack<ll> s;
  queue<ll> q;
  priority_queue<ll> pq;
  ll a,b;
  for(ll i = 0; i < n; i++){
    cin >> a >> b;
    if(a == 1){ 
      s.push(b);
      q.push(b);
      pq.push(b);
    }
    else{
      if(s.empty()){
        res = {false, false, false};
        continue;
      }
      if(s.top() != b) res[0] = false;
      if(q.front() != b) res[1] = false;
      if(pq.top() != b) res[2] = false;
      s.pop();
      q.pop();
      pq.pop();
    }
  }
  ll cnt = 0;
  for(auto el : res) if(el) cnt++;
  if(cnt == 0){
    cout << "impossible\n";
  }
  else if(cnt > 1){
    cout << "not sure\n";
  }
  else if(res[0]){
    cout << "stack\n";
  }
  else if(res[1]){
    cout << "queue\n";
  }
  else if(res[2]){
    cout << "priority queue\n";
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
  while(cin >> n) solve(n);  
}