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

const int maxLiczba = 2*1005;
int dp[maxLiczba][maxLiczba];
bool sciany[maxLiczba][maxLiczba];
int dirx[] = {0,1,0,-1}, diry[] = {-1,0,1,0};
pair<int,int> srodek = {1000, 1000}; // nie ma minusowych indeksow to shift o 1000
ll n,s;
ll even=0,odd=0,x,y;
bool in_bounds(pair<int,int> &a){
  if(a.first >= 0 && a.first < maxLiczba && a.second >= 0 && a.second < maxLiczba) return true;
  return false;
}

void solve(){
  cin >> n >> s;
  even = 1+((s/2) * (2*8 + ((s/2)-1)*8)/2);
  odd = (s+1)/2 * (2*4+((s+1)/2-1)*8)/2;
  for(ll i = 0; i < n; i++){
    cin >> x >> y;
    // dbg(x,y);
    sciany[srodek.first+x][srodek.second+y] = true;
    if((abs(x)+abs(y)) & 1) odd--;
    else even--;
  }
  if(n == 0 || n == 1){
    cout << even << ' ' << odd << endl;
  } else{
    even = 0;
    odd = 0;
    for(int i = 0; i < maxLiczba; i++){
      for(int j = 0; j < maxLiczba; j++) dp[i][j] = -1;
    }
    queue<pair<int,int>> q;
    q.push(srodek);
    dp[srodek.first][srodek.second] = 0;
    while(!q.empty()){
      pair<int,int> cur = q.front(); q.pop();
      for(int i = 0; i < 4; i++){
        pair<int,int> next = {cur.first+dirx[i], cur.second+diry[i]};
        if(in_bounds(next) && (dp[next.first][next.second] == -1) && (sciany[next.first][next.second] == false)){
          q.push(next);
          dp[next.first][next.second] = dp[cur.first][cur.second]+1;
        }
      }
    }
    // for(auto el : sciany){
    //   cout << el.first << ' ' << el.second << endl;
    // }
    // dbg(dp[srodek.first+1][srodek.second]);
    for(int i = 0; i < maxLiczba; i++){
      for(int j = 0; j < maxLiczba; j++){
        if((dp[i][j] <= s) && (dp[i][j]&1) && (dp[i][j] != -1)){
          // dbg("odd",i-srodek.first,j-srodek.second, dp[i][j]);
          odd++;
        } else if((dp[i][j] <= s) && !(dp[i][j]&1) && (dp[i][j] != -1)){
          // dbg("even",i-srodek.first,j-srodek.second, dp[i][j]);
          even++;
        }
      }
    }
    //------------------------boki-----------------
    for(int i = 0; i < maxLiczba; i++){
      if(dp[0][i] == -1) continue;
      ll ilosc_elementow = max(0ll, s-dp[0][i]);
      if(dp[0][i]&1){
        even += (ilosc_elementow+1)/2;
        odd += ilosc_elementow/2;
      } else{
        even += ilosc_elementow/2;
        odd += (ilosc_elementow+1)/2;
      }
    }
    for(int i = 0; i < maxLiczba; i++){
      if(dp[i][maxLiczba-1] == -1) continue;
      ll ilosc_elementow = max(0ll, s-dp[i][maxLiczba-1]);
      if(dp[i][maxLiczba-1]&1){
        even += (ilosc_elementow+1)/2;
        odd += ilosc_elementow/2;
      } else{
        even += ilosc_elementow/2;
        odd += (ilosc_elementow+1)/2;
      }
    }
    for(int i = 0; i < maxLiczba; i++){
      if(dp[maxLiczba-1][i] == -1) continue;
      ll ilosc_elementow = max(0ll, s-dp[maxLiczba-1][i]);
      if(dp[maxLiczba-1][i]&1){
        even += (ilosc_elementow+1)/2;
        odd += ilosc_elementow/2;
      } else{
        even += ilosc_elementow/2;
        odd += (ilosc_elementow+1)/2;
      }
    }
    for(int i = 0; i < maxLiczba; i++){
      if(dp[i][0] == -1) continue;
      ll ilosc_elementow = max(0ll, s-dp[i][0]);
      if(dp[i][0]&1){
        even += (ilosc_elementow+1)/2;
        odd += ilosc_elementow/2;
      } else{
        even += ilosc_elementow/2;
        odd += (ilosc_elementow+1)/2;
      }
    }
    //---------------------------rogi------------
    ll ilosc_elementow,jeden,dwa;

    if(dp[0][0] != -1){
      ilosc_elementow = max(0ll, s-dp[0][0]);
      jeden = (ilosc_elementow/2) * (2*1+(ilosc_elementow/2-1)*2)/2;
      dwa = (ilosc_elementow-1)/2 * (2*2+((ilosc_elementow-1)/2-1)*2)/2;
      if(dp[0][0]&1){
        odd += jeden;
        even += dwa;
      } else{
        odd += dwa;
        even += jeden;
      }
    } 
    if(dp[0][maxLiczba-1] != -1){
      ilosc_elementow = max(0ll, s-dp[0][maxLiczba-1]);
      jeden = (ilosc_elementow/2) * (2*1+(ilosc_elementow/2-1)*2)/2;
      dwa = (ilosc_elementow-1)/2 * (2*2+((ilosc_elementow-1)/2-1)*2)/2;
      if(dp[0][maxLiczba-1]&1){
        odd += jeden;
        even += dwa;
      } else{
        odd += dwa;
        even += jeden;
      }
    }
    if(dp[maxLiczba-1][maxLiczba-1] != -1){
      ilosc_elementow = max(0ll, s-dp[maxLiczba-1][maxLiczba-1]);
      jeden = (ilosc_elementow/2) * (2*1+(ilosc_elementow/2-1)*2)/2;
      dwa = (ilosc_elementow-1)/2 * (2*2+((ilosc_elementow-1)/2-1)*2)/2;
      if(dp[maxLiczba-1][maxLiczba-1]&1){
        odd += jeden;
        even += dwa;
      } else{
        odd += dwa;
        even += jeden
      }
    mentow-1)/2-1)*2)/2;
      if(dp[maxLiczba-1][0]&1){
        odd += jeden;
        even += dwa;
      } else{
        odd += dwa;
        even += jeden;
      }
    }
    // dbg(even,odd);
    // dbg(97993-(even-odd));
    cout << even << ' ' << odd << endl;
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