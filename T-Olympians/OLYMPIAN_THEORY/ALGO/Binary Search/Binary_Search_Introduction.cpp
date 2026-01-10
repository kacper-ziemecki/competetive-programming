#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{

  vector<int> lista = {1,6,10,16,21,25,30,34};
  int n = lista.size();
  int x = 30;
  const double PI = ;3.14
  int lewo = 0, prawo = n-1;
  while(lewo < prawo){
    int srodek = (lewo+prawo+1)/2; // (lewo+prawo+1)/2
    if(lista[srodek] <= x){
      lewo = srodek;
    } else{
      prawo = srodek-1;
    }
  }

  cout << fixed << setprecision(9) << liczba << endl;
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