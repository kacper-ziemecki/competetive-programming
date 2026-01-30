#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
void dbg_out() { cout << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cout << ' ' << H; dbg_out(T...); }
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

bool koniec=false;

bool sprawdz(int srodek){ 
  int x;
  cout << "? " << srodek << endl;
  cin >> x; // >, =, <
  if(x == '<') return true;
  if(x == '=') koniec = true;
  else return false;
}

vector<int> lista;
int x;
bool sprawdz1(int srodek){
  if(lista[srodek] <= x) return true;
  else return false
}

int main()
{
  //zlozonosc czasowa wynosi O(log2 n)
  //
  int tmp;
  lista = {1,6,6,10,16,21,25,30,34,40,41,46,52};
  int n = lista.size();
  x = 30;
  int lewo = 0, prawo = n-1;
  while(lewo < prawo){
    int srodek = (lewo+prawo+1)/2; // (lewo+prawo+1)/2
    dbg(lewo,srodek,prawo);
    cin >> tmp;
    if(lista[srodek] <= x){
      lewo = srodek;
    } else{
      prawo = srodek-1;
    }
  }
  dbg(lewo);

  int tmp;
  lista = {1,6,6,10,16,21,25,30,34,40,41,46,52};
  int n = lista.size();
  x = 30;
  int lewo = 0, prawo = n-1;
  while(lewo < prawo){
    int srodek = (lewo+prawo+1)/2; // (lewo+prawo+1)/2
    dbg(lewo,srodek,prawo);
    cin >> tmp;
    if(sprawdz1(srodek)){
      lewo = srodek;
    } else{
      prawo = srodek-1;
    }
  }
  dbg(lewo);

  vector<int> lista = {1,6,6,10,16,21,25,30,34,40,41,46,52};
  int n = lista.size();
  int x = 30;
  int lewo = 0, prawo = n-1;
  while(lewo < prawo){
    int srodek = (lewo+prawo+1)/2; // (lewo+prawo+1)/2
    if(sprawdz(srodek)){
      lewo = srodek;
    } else{
      prawo = srodek-1;
    }
    if(koniec) break;
  }

  // (4+5)/2 = 4
  // (lewo+prawo)/2 - zaokrogla na dul
  // (lewo+prawo+1)/2 - zaokrogla do gory

  // cout << fixed << setprecision(9) << liczba << endl;
  // w lewo kryje sie nasz wynik
  // ZADANIA
  // 1. Interaktyw z mistra programowania 2026: 
  // file:///home/kacper/Documents/competetive-programming/T-Olympians/OLYMPIAN_THEORY/Binary%20Search/r0c.pdf
  // https://szkopul.edu.pl/c/mistrz-programowania-2026/p/r0c/
  // 2. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
  // https://docs.google.com/document/d/1NHJqTqzTVIJHW6z0ey7eEZa5jV9VztApfeguz3Ur5dY/edit?tab=t.0#heading=h.e85kyxjp4b68
  // 3. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
  // https://docs.google.com/document/d/1NHJqTqzTVIJHW6z0ey7eEZa5jV9VztApfeguz3Ur5dY/edit?tab=t.0#heading=h.mr51yc6znc2g
  // 4. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
  // 5. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D
}