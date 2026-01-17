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

  // int : -2000000000 .... 2000000000
  // long long: -1000000000000000000 ... 1000000000000000000

  // 15 = 01010101010100101
  // 11241242 = 010101010010101010010101001

  // 213 = 2 * 100 + 1 * 10 + 3 
  //     = 2 * 10**2 + 1 * 10*1 + 3 * 10**0
  // 5421 = 5 * 1000 + 4 * 100 + 2 * 10 + 1
  //      = 5 * 10**3 + 4 * 10**2 + 2 * 10**1 + 1 * 10**0
  // //konwersja z systemu binarnego do systemu dziesietnego (normalnego)
  // 101 => 1 * 4 + 0 * 2 + 1 * 1 = 
  //     =  1 * 2*2 + 0 * 2 + 1 =
  //     = 1 * 2**2 + 0 * 2**1 + 1 * 2**0
  //     = 4 + 0 + 1
  //     = 5
  // 10110 => 1*16 + 0*8 + 1*4 + 1*2 + 0*1 = 22

  // 101110 =>1*32 + 0*16 + 1*8 + 1*4 + 1*2 + 0*1 = 46

  // [0101010100100101010101001011
  //  0101010101010100101010100101
  //  0101010101010010101010100101
  //  0101111011011010111011001111]

  // int za = 15; // ok
  // int y = 100000000000000000000;

  // cout << za << endl;
  // cout << y << endl;

  int x = 5; // system dziesietny
  int z = 0b101; // system dwójkowy / binarny
  cout << x << " to jest to samo co: " << z << endl;
  int y = 12; // 0b1100
  1100 | 0101 = 1101
  10110101 | 10011010 = 10111111
  // bitowe lub |
  // 1 1 -> 1
  // 1 0 -> 1
  // 0 1 -> 1
  // 0 0 -> 0
  cout << "bitowe lub pomiedzy x a y: " << (x|y) << endl;
  1100 & 0101 = 0100
  110101 & 10011010 = 10010000
  // bitowe i &
  // 1 1 -> 1
  // 1 0 -> 0
  // 0 1 -> 0
  // 0 0 -> 0
  cout << "bitowe i pomiedzy x a y: " << (x&y) << endl;
  // szift w prawo (>>)
  // 110101100 >> 1 => 011010110
  // 110101100 >> 5 => 000001101
  // szift w lewo (<<)
  // 110101100 << 1 => 101011000

  int a = 0b1010101111010101;

  // 1 w systemie binarnym -> 0000000000000001
  // mozemy sobie sziftowac ta jedynke
  // np.
  // 1 << 2 => 0b00000000000100
  // 1 << 5 => 0b00000000100000
  // 1 << 10 => 0b0010000000000

  // bitowa negacja
  // ~
  ~0101010101010101010 = 10101010101010101
  int x = 5; // co w notacji bitowej to : 101
  // to wtedy negacja bitowa tej zmiennej to: 1111111111010

  // jak chcemy sprawdzic czy bit jest ustawiony
  //a & (1 << 5) != 0 to znaczy, że bit jest ustawiony

  int spr = 0b0101011101;
  cout << spr & (1 << 2) << endl;

  0b0101011101 &
  0b0000000100
  _____________
    0000000100

  // spr & (1 << 2) == 0 to bit nie jest ustawiony
  // spr & (1 << 2) != 0 to bit jest ustawiony

  // inna metoda sprawdzenia czy bit jest ustawiony na pozycji nr 3

  // (spr>>2) & 1 == 0 to bit nie jest ustawiony
  // (spr>>2) & 1 != 0 to bit jest ustawiony

  // __int128_t ciekawostka

  __builtin_popcount(n) ==> ile bitow jest ustawionych w zmiennej n 

  //ZADANIA:
  //1) https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation
  //2) https://leetcode.com/problems/reverse-bits/description/?envType=problem-list-v2&envId=bit-manipulation
  //3) https://leetcode.com/problems/counting-bits/description/
  //4) https://leetcode.com/problems/sum-of-two-integers/description/
  //5) https://leetcode.com/problems/bitwise-and-of-numbers-range/description/

  //ZADANIA XOR:
  //1) https://leetcode.com/problems/single-number/description/
  //2) https://leetcode.com/problems/missing-number/description/
  //3) https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

  //CODEFORCES:
  //1) https://codeforces.com/contest/1527/problem/A (rating: 800)
  //2) https://codeforces.com/contest/579/problem/A (rating: 1000)
  //3) https://codeforces.com/contest/467/problem/B (rating: 1100)
  //4) https://codeforces.com/contest/1514/problem/B (rating: 1200)
  //5) https://codeforces.com/contest/1420/problem/B (rating: 1200)
  //6) https://codeforces.com/contest/878/problem/A (rating: 1600)
  //7) https://codeforces.com/contest/1151/problem/B (rating: 1600)
  //8) https://codeforces.com/contest/1368/problem/D (rating: 1700)
  //9) https://codeforces.com/contest/276/problem/D (rating: 1700)
  //10) https://codeforces.com/contest/1556/problem/D (rating: 1800)

  //UHUNT:
  //...
}