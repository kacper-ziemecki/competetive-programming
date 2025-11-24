#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pb push_back
#define hs unsigned long long
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

const hs primes[2] = {5586985605742039601,6889537187409766193};
// const hs modulo[2] = {421734293,680641817};
const int maxn = 5e5+1;
hs pref_hash1[2][maxn], pref_hash2[2][maxn];
hs prime_powers[2][maxn];
int n;
string s1,s2;

void calc_pref_hash(string s, hs pref_hash[2][maxn]){
  pref_hash[0][0] = s[0];
  pref_hash[1][0] = s[0];
  for(int i = 1; i < n; i++){
    pref_hash[0][i] = pref_hash[0][i-1]*primes[0] + s[i];
    pref_hash[1][i] = pref_hash[1][i-1]*primes[1] + s[i];
    // dbg(s[i],pref_hash[0][i], pref_hash[1][i]);
  }
  // cout << "----------------\n";
}

hs get_hash(int l, int r, int k, hs pref_hash[2][maxn]){
  hs hash = pref_hash[k][r];
  // dbg(pref_hash[k][r]);
  if(l > 0){
    // dbg(pref_hash[k][l-1]);
    // dbg(prime_powers[k][r-l+1]);
    hash = hash - pref_hash[k][l-1]*prime_powers[k][r-l+1];
  }
  return hash;
}

bool check(int length, int i){
  //  s1                s2
  // [i-length...i] == [i+1 ... i+1+length]
  hs hash1[2] = {get_hash(i-length,i,0,pref_hash1),
                 get_hash(i-length,i,1,pref_hash1)};
  hs hash2[2] = {get_hash((n-1)-(i+1)-length,(n-1)-(i+1),0,pref_hash2),
                 get_hash((n-1)-(i+1)-length,(n-1)-(i+1),1,pref_hash2)};
  // dbg(i-length, i);
  // dbg((n-1)-(i+1)-length, (n-1)-(i+1));
  // dbg(hash1[0], hash1[1]);
  // dbg(hash2[0], hash2[1]);
  if((hash1[0] == hash2[0]) && (hash1[1] == hash2[1])) return true;
  return false;
}
void solve(){
  cin >> n;
  cin >> s1;
  s2 = s1;
  reverse(s2.begin(), s2.end());
  for(int i = 0; i < n; i++){
    s2[i] = (s2[i] == '1' ? '0' : '1');
  }
  // dbg(s1,s2);
  prime_powers[0][0] = prime_powers[1][0] = 1;
  for(int i = 1; i <= n; i++){
    prime_powers[0][i] = prime_powers[0][i-1]*primes[0];
    prime_powers[1][i] = prime_powers[1][i-1]*primes[1];
    // dbg(prime_powers[0][i], prime_powers[1][i]);
  }
  calc_pref_hash(s1, pref_hash1);
  calc_pref_hash(s2, pref_hash2);
  // dbg(s1[0], s1[1]);
  // dbg(s2[4], s2[5]);
  // dbg(get_hash(0,1,1,pref_hash1));
  // dbg(get_hash(4,5,1,pref_hash2));
  long long res = 0;
  for(int i = 0; i+1 < n; i++){
    if(s1[i] == s1[i+1]) continue;
    long long l = 0, r = min(i, (n-1)-(i+1));
    while(l < r){
      int mid = (l+r+1)/2;
      if(check(mid, i)) l = mid;
      else r = mid-1;
    }
    res += l+1;
  }
  cout << res << endl;
} 
 
int main()
{
 
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
 

  freopen("../in.in", "r", stdin);
  freopen("../out.out", "w", stdout);
  
  solve();

}