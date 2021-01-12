#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "head.h"
#include <cctype>
using namespace std;
int** create (int n, int m)
{
    int** A = new int* [n];
    for (int i =0; i < n; i++)
        A[i] = new int [m];

    for (int i =0; i < n; i++)
    {
        for (int j =0; j < m; j++)
        {
            A[i][j] = rand()%101;
            cout << fixed << setw(3) << A[i][j] << " " ;
        }
        cout << endl;
    }

    return A;
}
float*  average (int ** A, int n, int m)
{
    float* M = new float [n];

     for (int i =0; i < n; i++)
    {
       int max_el = A[i][0];
        int index = 0;

        for (int j = 0; j < m; j++)
        {
           if (max_el < A[i][j])
           {
               max_el = A[i][j];
               index = j;
           }
        }

        int suma = 0;
        for (int j = 0; j <= index; j++)
        {
            suma += A[i][j];
        }

        M[i] = (float) (suma) / (index+1);
    }

    return M;
}

void input_matrix_average (float* M, int n)
{
    cout << endl << "Matrix average radkiv:" << endl;

    for (int i = 0; i < n ; i++)
        cout << fixed << setw(3) << M[i] << " " ;
}

void sorting (int** A, float* M, int n, int m)
{
    for (int i = 0; i < n; i++ )
    {
        for (int j = i+1; j < n ; j++)
        {
            if (M[i] > M[j])
            {
             float box =  M[i];
             M[i] = M[j];
             M[j] = box;

             int * b = A[i];
             A[i] = A[j];
             A[j] = b;
            }
        }
    }
}

void input_sort_A (int** A, int n, int m)
{

    cout << endl << endl << "sorting matrix A:" << endl;
    for (int i =0; i < n; i++)
    {
        for (int j =0; j < m; j++)
        {
            cout << fixed << setw(3) << A[i][j] << " " ;
        }
        cout << endl;
    }
}

string* hexta (int** A, int n , int m)
{
    string* H = new string [n];

    for (int i =0; i < n; i++)
    {
        int pos = 0;
        for (int j =0; j < m; j++)
        {
            int cila = A[i][j];

            while(cila > 15)
            {
              int ekv = cila - (cila / 16 * 16);
              cila = cila / 16 ;

              if (ekv < 10)
              {
                  string e = to_string(ekv);
                  H[i] = H[i].insert(pos, e);
              }
              else
              {    switch(ekv)
                  {
                      case 10 : H[i] = H[i].insert(pos, "A"); break;
                      case 11 : H[i] = H[i].insert(pos, "B"); break;
                      case 12 : H[i] = H[i].insert(pos, "C"); break;
                      case 13 : H[i] = H[i].insert(pos, "D"); break;
                      case 14 : H[i] = H[i].insert(pos, "E"); break;
                      case 15 : H[i] = H[i].insert(pos, "F"); break;
                  }
              }
            }

            if (cila < 10)
              {
                  string e = to_string(cila);
                  H[i] = H[i].insert(pos, e);
              }
              else
              {    switch(cila)
                  {
                      case 10 : H[i] = H[i].insert(pos, "A"); break;
                      case 11 : H[i] = H[i].insert(pos, "B"); break;
                      case 12 : H[i] = H[i].insert(pos, "C"); break;
                      case 13 : H[i] = H[i].insert(pos, "D"); break;
                      case 14 : H[i] = H[i].insert(pos, "E"); break;
                      case 15 : H[i] = H[i].insert(pos, "F"); break;
                  }
              }

                  H[i] += " ";
                pos = H[i].length();
        }

    }

    return H;
}

void input_hexta_matrix (string* H, int n)
{
    cout << endl << "Matrix 16:" << endl;

    for (int i = 0; i < n ; i++)
        cout <<  H[i] << endl ;
}

void delete_cifry (string* H, int n)
{
    for (int i =0; i < n; i++)
    {
        int len = H[i].length();
        int j = 0;

        while (j < len)
            {
                int sumvol = (int) H[i][j];
                if ( sumvol > 47 && sumvol < 58 )
                {
                    H[i] = H[i].erase(j, 1);
                    len--;
                }
                else
                    j++;
            }
    }

}

