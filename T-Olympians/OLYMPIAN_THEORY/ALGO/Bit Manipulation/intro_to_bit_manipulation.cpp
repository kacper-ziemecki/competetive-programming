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


int main()
{

  // int - 2*10^9 - 32bit [010101010101...01010]
  // long long - 10^18 - 64bit [010001011010110101011...01111010101]

  int x = 5; // system dziesietny
  int z = 0b101; // system dwójkowy / binarny
  cout << x << " to jest to samo co: " << z << endl;
  int y = 12; // 0b1100
  // bitowe lub |
  // 1 1 -> 1
  // 1 0 -> 1
  // 0 1 -> 1
  // 0 0 -> 0
  cout << "bitowe lub pomiedzy x a y: " << (x|y) << endl;
  // bitowe i &
  // 1 1 -> 1
  // 1 0 -> 0
  // 0 1 -> 0
  // 0 0 -> 0
  cout << "bitowe i pomiedzy x a y: " << (x&y) << endl;
  // szift w prawo (>>)
  // 110101100 >> 1 => 011010110
  // szift w lewo (<<)
  // 110101100 << 1 => 101011000

  int a = 0b1010101111010101;

  // 1 w systemie binarnym -> 0000000000000001
  // mozemy sobie sziftowac ta jedynke
  // np.
  // 1 << 5 => 0b00000000100000

  // jak chcemy sprawdzic czy bit jest ustawiony
  //a & (1 << 5) != 0 to znaczy, że bit jest ustawiony

  // __int128_t ciekawostka

  //ZADANIA:
  //1) https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation
  //2) https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation
}