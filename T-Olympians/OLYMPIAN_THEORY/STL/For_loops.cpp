#include <bits/stdc++.h>
using namespace std;


int main()
{

  // for([co robimy na poczotku - tak jakby przed for-loopem];
  //     [jaki warunek stawiamy zeby for-loop dzialal];
  //     [co robimy pod koniec kazdego wykonania for-loopa]){

  //   [kod wewnatrz for-loopa]
  // }

  // przyklad
  // for(int i = 0; i < 10; i++){
  //   ...
  // }

  // to jest to samo co to:
  // int i = 0;
  // for( ;i < 10; i++){
  //   ...
  // }

  // to jest to samo co to:
  // int i = 0;
  // for( ;i < 10; ){
  //   [kod wewnatrz for-loopa]
  //   i++;
  // }


  // TRZEBA WIEDZIEĆ OPERACJE BREAK
  // to jest to samo co to:
  // int i = 0;
  // for( ; ; ){
  //  if(i < 10){
  //    [kod wewnatrz for-loopa]
  //  } 
  //  else{
  //    break;
  //  }
  //  i++;
  // }

  //operacja continue
  for(int i = 0; i <= 10; i++){
    if(i%2 == 0) continue;
    cout << i << ' ';
    //<- tutaj przechodzi continue
  }
  cout << endl;

  for(int i = 5; i <= 20; i++){
    if(i%2 == 1){
      continue;
    } else{
      cout << i << ' ';
    }
    //<- tutaj przechodzi continue
  }
  cout << endl;
  // wszystkie -> "0 1 2 3 4 5 6 7 8 9 10"
  // tylko nieparzyste -> "1 3 5 7 9"

  for(int i = 0; i <= 10; i++){
    if(i > 5){ // tego nie chce wyswietlic
      cout << "continue ";
      continue;
    } else{ // inaczej chce wyswietlic
      cout << i << ' '; 
    }
    //<- tutaj przechodzi continue
  }
  cout << endl;
  // wszystkie -> "0 1 2 3 4 5 6 7 8 9 10"
  // mniejsze niz 6 -> "0 1 2 3 4 5"

  for(int i = 0; i <= 10; i++){
    if(i > 5){
      cout << "break ";
      break;
    }
    cout << i << ' ';
  }
  // <- tutaj przechodzi break

  // ZADANIA 1D:
  //1. wyswietl liczby od 1 do 10
  //1.1 wyswietl liczby od 5 do 20
  //2. wyswietl liczby od 100 do 150
  //3. wyswietl liczby od 1 do 10 - tylko parzyste
  // - modulo
  // - bez if
  //3.1 wyswietl liczby od 5 do 20 - tylko parzyste
  // - continue



  // omowienie zachowania for loop 1D

  for(int i = 0; i < 10; i++){
    cout << i << ' ';
  }

  // output
  // 0 1 2 3 4 5 6 7 8 9

  //przykladowe uruchomienie for-loopa
  //1) uruchamiamy kod z pierwszej czesci for-loopa
  // int i = 0;
  //2) sprawdzamy warunek z drugiej czesci for-loopa
  // czy (i < 10) -> TAK/NIE
  //   | TAK
  //  \/
  //3) jezeli warunek jest spelniony to uruchamiamy kod wewnatrz for-loopa
  // cout << i << ' '; -> to co jest w środku pętli
  //4) ururachamiamy kod z trzeciej czesci for-loopa
  // i++
  // i powracamy do kroku drugiego...


  // omowienie zachowania for-loopa 2D
  // for(int i = 0; i < 10; i++){
    // for(int j = 0; j < 10; j++){     // kod, ktory mamy w srodku
      // cout << i << ',' << j << endl; // zewnetrznego for-loopa
    // }                                // i zachowuje sie tak samo
  // }

  // for(int i = 0; i < 10; i++){
    // [jakis kod wewnatrz for-loopa]
  // }

  // output:
  // 0,0
  //1) uruchamiamy kod w pierwszej czesci for loopa
  // int i = 0;
  //2) sprawdzamy warunek 
  // i < 10 --> TAK/NIE
  //3) uruchamiamy kod wewnatrz for-loopa
    // for(int j = 0; j < 10; j++){
    //   cout << i << ',' << j << endl;
    // }
    //4) uruchamiamy kod w pierwszej czesci for loopa
    // int j = 0;
    //5) sprawdzamy warunek <------------------------------|
    // j < 10                                              |
    //6) uruchamiamy kod wewnatrz for-loopa                |    
    // cout << i << ',' << j << endl; --> 0,0 na poczotku  |
    //7) uruchamiamy kod z trzeciej czesci for-loopa       |
    // j++                                                 |
    //8) powracamy do kroku 5 -----------------------------|
  //9) uruchamiamay kod z trzeciej czesci for-loopa
  // i++
  //10) powracamy do kroku 2





  //ZADANIA 2D:
  //4.1 wyswietl pionową linie z kropek o dlugosci 5
  //.
  //.
  //.
  //.
  //.
  //4.2 wyswietl poziomą linię z kropek o dlugosci 8
  //........
  //4.3 wyswietl kwadrat z kropek 5x5
  // .....
  // .....
  // .....
  // .....
  // .....
  // - jedna petla for 
  // - dwie petle for
  //5. wyswietl trapez z kropek 5x5
  // .....
  //  .....
  //   .....
  //    .....
  //     .....
  // - jedna petla for
  // - dwie petle for
  //6. wyswietl trójkąt z kropek 5x5
  //.
  //..
  //...
  //....
  //.....

  //7. wyswietle trójkąt z kropek 5x5
  //.....
  //....
  //...
  //..
  //.
  
  //8. wyswietl trapez z kropek 5x5
  //    .....
  //   .....
  //  .....
  // .....
  //.....
  // ciekawostka, można to rozwiązać za pomocą jednego for loopa oraz instrukcji
  // s.substr(1, s.size()-1);

  //10. wyswietl piramidę z gwiazdek o wysokości 5
  //    *
  //   ***
  //  *****
  // *******
  //*********

  //11. wyswietl romb z kropek o szerokości 5
  //   .
  //  ...
  // .....
  //  ...
  //   .

  //12. wyswietl szachownicę 5x5 z znaków # i .
  //#.#.#
  //.#.#.
  //#.#.#
  //.#.#.
  //#.#.#
  //  |
  // \/
  //.....
  //.....
  //.....
  //.....
  //.....
  //  |
  // \/
  // zauwazylem, że jezeli i+j jest parzyste to # inaczej .
  cout << endl << endl;
  cout << "jak podejsc do rozwiązywania zadan\n";
  for(int i = 0; i < 5; i++){
    cout << '.' << endl;
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      cout << '.';
    }
    cout << endl;
  }
  
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if((i+j) % 2 == 0){
        cout << '#';
      } else{
        cout << '.';
      }
    }
    cout << endl;
  }

  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    //rozwiazywanie pojedynczego zadania
  }

  int t;
  cin >> t;
  while(t--){
    //rozwiazwyanie pojedynczego zadania
  }
}