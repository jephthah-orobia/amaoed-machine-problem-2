/* ****************************************************************
 * @author: Jephthah M. Orobia
 * @app name: Seat Keeper
 * @app desc: This app reserves seat.
 *            This app is a partial requirement for Com Prog 1
 *            "Machine Problem 2"
 * ****************************************************************/

#include <cstdio>
#include <cstdlib>
#include <limits>
#include <iostream>
#include "_pause.h"

using namespace std;

int main()
{
  int seats[5][7], n;

  for (int s = 0; s < 35; s++)
  {
    seats[s / 7][s % 7] = s + 1;
  }

  while (true)
  {

    for (int row = 0; row < 5; row++)
    {
      for (int col = 0; col < 7; col++)
      {
        if(n > 0 && row == (n-1)/7 && col == (n - 1) % 7)
          cout<<"\033[32m";
        else if(seats[row][col]==0) cout << "\033[31m";
        cout << seats[row][col] << "\033[0m\t";
      }
      cout << endl;
    }

    cout << endl
         << "Enter seat number to reserve: ";
    cin >> n;
    system("clear");
    cout << endl;
    if (!cin.fail() && n > 0 && n < 36)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      int r = (n - 1) / 7, c = (n - 1) % 7;
      if (seats[r][c] == 0)
      {
        cout << "\033[31m<< Seat #" << n << " is taken >>\033[0m";
        n=0;
      }
      else
      {
        seats[r][c] = 0;
        cout << "\033[32m<< Seat #" << n << " is successfully reserved. >>\033[0m";
      }
    }
    else
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "\033[47m\033[31m!!! Invalid seat number. Try again. !!!\033[0m";
      n=0;
    }

    cout << endl
         << endl;
  }

  _pause();
  return EXIT_SUCCESS;
}
