#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include "head.h"
using namespace std;
long** create_matrix_Q (int k, int m)
{
    long** Q = new long* [k];
    for (int i =0; i < k ; i++)
        Q[i] = new long [m];

    for (int i =0; i < k ; i++)
    {
        for (int j =0; j < m ; j++)
        {
          Q[i][j] = rand()%100001;
        }
    }

    return Q;
}
void print_matrix (long** Q, int k, int m)
{
    for (int i =0; i < k ; i++)
    {
        for (int j =0; j < m ; j++)
        {
          cout << fixed << setw(6) << Q[i][j] << " " ;
        }
        cout << endl;
    }
}

long  search_special(long** Q, int k, int m, int& line, int& column)
{
    long special;
    bool is_special = false;
    for (int i =0; i < k ; i++)
    {
        long sum = 0;
        for (int j = 0; j < m ; j++)
        {
          sum += Q[i][j];
        }

       for (int j = 0; j < m ; j++)
        {
          if (Q[i][j] > sum - Q[i][j])
          {
              special = Q[i][j];
              is_special = true;
              line = i;
              column = j;
              break;
          }
        }

        if(is_special)
            break;
    }
    if (is_special)
    {
        cout << endl << "special: " << special << endl;
    }
    else
    {
        cout << endl << "!This matrix haven't special! " << endl;
    }

    return special;
}

 void move_matrix (long** Q, int k, int m, int line, int column)
 {
     long* box = Q[k-1];
     Q[k-1] = Q[line];
     Q[line] = box;

     long* ptr_box = new long [k];
     for (int i =0; i < k; i++)
        ptr_box[i] = Q[i][0];

     for (int i =0; i < k; i++)
        Q[i][0] = Q[i][column];

    for (int i =0; i < k; i++)
        Q[i][column] = ptr_box[i];


 }

 string* create_Z(long** Q, int k, int m)
 {
     string* Z = new string [k];
     cout << endl << "matrix strings Z pair numbers: " << endl;

     for (int i =0; i < k ; i++ )
     {
         for (int j =0 ; j < m ; j++)
         {
             if ( Q[i][j]%2 == 0)
             {
                 Z[i] +=  to_string(Q[i][j]) ;
                 cout << Q[i][j] << " " ;

                 long p = Q[i][j];
                 int len = (to_string(Q[i][j])).length();
                 int max_digit = 0;
                 for (int t =0; t < len; t++)
                 {
                     int digit = p % 10;
                     if (digit > max_digit)
                     {
                         max_digit = digit;
                     }
                     p = p / 10;
                 }
                Z[i] += "." + to_string(max_digit) + " ";
             }
         }
         cout << endl;
     }

     return Z;
 }

 void print_string_mas (string* Z, int k)
 {
     cout << endl << "Matrix strings Z pair numbers + fractional part: " << endl;
     for (int i =0; i < k; i++)
        cout << Z[i] << endl;
 }
