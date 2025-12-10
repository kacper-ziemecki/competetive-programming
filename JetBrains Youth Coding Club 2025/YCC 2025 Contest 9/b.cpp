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

int string_to_int(string s){
  int res = (s[0]-'0')*60*10 + (s[1]-'0')*60 + (s[3]-'0') * 10 + (s[4]-'0');
  return res;
}

string int_to_string(int n){
  int hours = 0;
  while(n-60 >= 0){
    hours++;
    n -= 60;
  }
  if(hours == 24) hours=0;
  int minutes = n;
  string res = (hours < 10 ? '0'+to_string(hours) : to_string(hours)) + ':' +(minutes < 10 ? '0'+to_string(minutes) : to_string(minutes));
  return res;
}

bool is_palindrome(string s){
  return (s[0] == s[4] && s[1] == s[3]);
}

void solve(){
  string s;
  cin >> s;
  int res=0;
  while(!is_palindrome(s)){
    int num = string_to_int(s);
    num++;
    res++;
    s = int_to_string(num);
  }
  cout << res << endl;
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

  solve();
}