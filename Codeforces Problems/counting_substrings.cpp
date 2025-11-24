#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

void counting_sort(vector<ll>& suffix_array, vector<ll>& c){
  ll n = suffix_array.size();
  vector<ll> cnt(n), pos(n), new_suffix_array(n);
  for(auto el: c) cnt[el]++;
  pos[0]=0;
  for(ll i = 1; i < n; i++) pos[i] = pos[i-1] + cnt[i-1];
  for(auto el : suffix_array){
    new_suffix_array[pos[c[el]]] = el;
    pos[c[el]]++;
  }
  suffix_array = new_suffix_array;
}

vector<ll> build_suffix_array(string s){
  ll n = s.size();
  vector<pair<char, ll>> a(n);
  vector<ll> suffix_array(n), c(n);
  for(ll i = 0; i < n; i++) a[i] = {s[i], i};
  sort(a.begin(), a.end());
  for(ll i = 0; i < n; i++) suffix_array[i] = a[i].second;
  c[suffix_array[0]] = 0;
  for(ll i = 1; i < n; i++){
    if(a[i-1].first == a[i].first){
      c[suffix_array[i]] = c[suffix_array[i-1]];
    } else{
      c[suffix_array[i]] = c[suffix_array[i-1]]+1;
    }
  }
  ll k = 0;
  while((1 << k) < n){
    for(ll i = 0; i < n; i++) suffix_array[i] = (suffix_array[i] - (1<<k) + n) % n;
    counting_sort(suffix_array, c);
    vector<ll> new_c(n);
    new_c[suffix_array[0]] = 0;
    for(ll i = 1; i < n; i++){
      pair<ll,ll> cur = {c[suffix_array[i]], c[(suffix_array[i]+(1<<k))%n]};
      pair<ll,ll> prev = {c[suffix_array[i-1]], c[(suffix_array[i-1]+(1<<k))%n]};
      if(cur == prev){
        new_c[suffix_array[i]] = new_c[suffix_array[i-1]];
      } else{
        new_c[suffix_array[i]] = new_c[suffix_array[i-1]]+1;
      }
    }
    c = new_c;
    k++;
  }
  return suffix_array;
}

bool check1(vector<ll>& suffix_array, ll mid, string& x, string& s){
  bool res=true;
  for(ll i = suffix_array[mid]; i-suffix_array[mid] < x.size(); i++){
    if(i < s.size() && x[i-suffix_array[mid]] < s[i]) return true;
    if(i >= s.size() || x[i-suffix_array[mid]] > s[i]) return false;
  }
  // dbg(suffix_array[mid], mid,x,s,res);
  return res;
}

ll lower_bound(vector<ll>& suffix_array, string& s, string& x){
  // dbg(x);
  ll n = s.size();
  ll l = 0, r = n-1;
  while(l < r){
    ll mid = (l+r)/2;
    if(check1(suffix_array,mid,x,s)) r = mid;
    else l = mid+1;
  }
  // dbg(l,s,x);
  for(ll i = 0; i < x.size(); i++){
    if(i+suffix_array[l] >= n || x[i] != s[i+suffix_array[l]]) return n+2;
  }
  return l;
}

bool check2(vector<ll>& suffix_array, ll mid, string& x, string& s){
  bool res=true;
  for(ll i = suffix_array[mid]; i-suffix_array[mid] < x.size(); i++){
    if(i < s.size() && x[i-suffix_array[mid]] > s[i]) return true;
    if(i >= s.size() || x[i-suffix_array[mid]] < s[i]) return false;
  }
  // dbg(suffix_array[mid], mid,x,s,res);
  return res;
}

ll upper_bound(vector<ll>& suffix_array, string& s, string& x){
  // dbg(x);
  ll n = s.size();
  ll l = 0, r = n-1;
  while(l < r){
    ll mid = (l+r+1)/2;
    if(check2(suffix_array,mid,x,s)) l = mid;
    else r = mid-1;
  }
  // dbg(l,s,x);
  for(ll i = 0; i < x.size(); i++){
    if(i+suffix_array[l] >= n || x[i] != s[i+suffix_array[l]]) return -1;
  }
  return l;
}
void solve()
{
  string s;
  cin >> s;
  s += '$';
  vector<ll> suffix_array = build_suffix_array(s);
  // for(auto el : suffix_array) cout << el << " ";
  // cout << endl;
  ll m;
  string x;
  cin >> m;
  for(ll i = 0; i < m; i++){
    cin >> x;
    ll lower = lower_bound(suffix_array,s,x);
    ll upper = upper_bound(suffix_array,s,x);
    // dbg(lower, upper);
    cout << max(0ll, upper-lower+1) << endl;
  }
}
  

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
#endif

  solve();
}