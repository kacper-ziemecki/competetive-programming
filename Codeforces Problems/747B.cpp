#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double


void solve()
{
  ll n;
  cin >> n;
  string text;
  cin >> text;
  ll cntA = 0, cntC = 0, cntG = 0, cntT = 0, cnt0 = 0;
  for(auto el : text){
    if(el == 'A') cntA++;
    if(el == 'C') cntC++;
    if(el == 'G') cntG++;
    if(el == 'T') cntT++;
    if(el == '?') cnt0++;
  }
  vector<ll> list = {cntA, cntC, cntG, cntT};
  sort(list.begin(), list.end());
  ll first = 0, second = 0, third = 0, fourth = 0;

  first += list.back() - cntA;
  second += list.back() - cntC;
  third += list.back() - cntG;
  fourth += list.back() - cntT;
  ll suma = first + second + third + fourth;

  if(suma > cnt0 || (cnt0-suma)%4 != 0){
    cout << "===\n";
    return;
  }

  first += (cnt0-suma)/4;
  second += (cnt0-suma)/4;
  third += (cnt0-suma)/4;
  fourth += (cnt0-suma)/4;

  ll i = 0;
  for(;;i++){
    if(text[i] == '?' && (--first >= 0)){
      text[i] = 'A';
    }
    if(first <= 0) break;
  }
  for(;;i++){
    if(text[i] == '?' && (--second >= 0)){
      text[i] = 'C';
    }
    if(second <= 0) break;
  }
  for(;;i++){
    if(text[i] == '?' && (--third >= 0)){
      text[i] = 'G';
    }
    if(third <= 0) break;
  }
  for(;;i++){
    if(text[i] == '?' && (--fourth >= 0)){
      text[i] = 'T';
    }
    if(fourth <= 0) break;
  }
  cout << text << endl;
}

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifndef ONLINE_JUDGE
  freopen("../../input.txt", "r", stdin);
  freopen("../../output.txt", "w", stdout);
#endif

  solve();
}