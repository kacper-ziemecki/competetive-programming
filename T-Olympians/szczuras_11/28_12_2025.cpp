#include <bits/stdc++.h>
using namespace std;

int n,k;
const int maxn = 1e5+1;
int tablica[maxn], tablica2[maxn];
int main()
{
    cin >> n >> k;
    for(int i = 0 ; i< n; i++) cin >> tablica[i];
    for(int i = 0; i < k; i++) cin >> tablica2[i];

    for(int i = 0; i < k; i++)
    {
        int lewo = 0;
        int prawo = n-1;
        int srodek;
        while(lewo < prawo)
        { 
            srodek = (lewo+prawo+1)/2; 
            if(tablica[srodek] <= tablica2[i]){
              lewo = srodek;
            } else{
              prawo = srodek-1;
            }
        }
        if(tablica[lewo] <= tablica2[i]){
          cout << lewo+1 << endl;
        } else{
          cout << 0 << endl;
        }
    }

    return 0;
}