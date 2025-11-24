#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double



void solve()
{
  string one, two;
  cin >> one >> two;

  ll first, second;
  if(one[0] == '0'){
    first = (one[1] - '0');
  }
  else{
    first = (one[0] - '0') * 10 + (one[1] - '0');
  }

  if(two[0] == '0'){
    second = (two[1] - '0');
  }
  else{
    second = (two[0] - '0') * 10 + (two[1] - '0');
  }


  ll third, fourth;
  if(one[3] == '0'){
    third = (one[4] - '0');
  }
  else{
    third = (one[3] - '0') * 10 + (one[4] - '0');
  }

  if(two[3] == '0'){
    fourth = (two[4] - '0');
  }
  else{
    fourth = (two[3] - '0') * 10 + (two[4] - '0');
  }

  ll number1, number2;
  number1 = first * 60 + third;
  number2 = second * 60 + fourth;

  ll res = number1 - number2;
  if(res < 0){
    res += 24 * 60;
  }
  string res1, res2;
  res1 = to_string(res/60);
  res2 = to_string((res - (res/60)*60));
  if(res1.size() < 2) res1 = '0' + res1;
  if(res2.size() < 2) res2 = '0' + res2;
  cout << res1 << ":" << res2 << endl;
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