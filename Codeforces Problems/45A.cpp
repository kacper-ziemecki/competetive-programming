#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define ld long double

ll converter(string text){
  if(text == "January"){
    return 1;
  }
  if(text == "February"){
    return 2;
  }
  if(text == "March"){
    return 3;
  }
  if(text == "April"){
    return 4;
  }
  if(text == "May"){
    return 5;
  }
  if(text == "June"){
    return 6;
  }
  if(text == "July"){
    return 7;
  }
  if(text == "August"){
    return 8;
  }
  if(text == "September"){
    return 9;
  }
  if(text == "October"){
    return 10;
  }
  if(text == "November"){
    return 11;
  }
  if(text == "December"){
    return 12;
  }
}

string deconvert(ll number){
  if(number == 1){
    return "January";
  }
  if(number == 2){
    return "February";
  }
  if(number == 3){
    return "March";
  }
  if(number == 4){
    return "April";
  }
  if(number == 5){
    return "May";
  }
  if(number == 6){
    return "June";
  }
  if(number == 7){
    return "July";
  }
  if(number == 8){
    return "August";
  }
  if(number == 9){
    return "September";
  }
  if(number == 10){
    return "October";
  }
  if(number == 11){
    return "November";
  }
  if(number == 12){
    return "December";
  }
}

void solve()
{
  string text;
  ll n;
  cin >> text >> n;
  ll number = converter(text);
  number += n;
  number %= 12;
  if(number == 0) number = 12;
  cout << deconvert(number) << endl;
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