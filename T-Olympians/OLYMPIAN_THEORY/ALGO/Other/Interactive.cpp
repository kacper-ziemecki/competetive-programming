#include <bits/stdc++.h>
using namespace std;
// #define endl "\n"
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int main()
{
//1...n
int n;
string x;
cin >> n;
// ok
// nie 
for(int i = 1; i <= n; i++){
  cout << "? " << i << endl;
  cin >> x;
  if(x == "ok") break;
  // cout << "? " << i << "\n" << flush;
}
// n = 10, x = 7
// nie nie nie nie nie nie ok nie nie nie
// wyszukiwanie binarne mozemy uzyc jak stworzymy sobie w wyszukiwaniu
// binarnym taki warunek, ze z tej plazczyzny mozemy stworzyc dwa ciagi
// 1 2 2 3 7 9 9 9 
// if(element >= 7)
// 0 0 0 0 1 1 1 1
// if(element <= 7)
// 1 1 1 1 1 0 0 0
// if(element < 7)
// 1 1 1 1 0 0 0 0
}