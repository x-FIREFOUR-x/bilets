
#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int** create_matrix (int n)
{
    int** R = new int* [n];
    for (int i = 0; i < n; i++)
        R[i] = new int [n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            R[i][j] = rand () % 19999 - 9999 ;
        }
    }


    return R;
}
void print_matrix(int** R, int n, int m)
{
    cout << endl << "Matrix R: " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(5) << R[i][j] << " " ;
        }
        cout << endl;
    }
}

bool  search_special (int** R, int n , int& special)
{
    //int special ;
    bool is_special = false;

    for (int i = n - 1; i >= 0 ; i--)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if ( (i <= j) && (i + j >= n - 1) && (R[j][i] > R[j - 1][i]) && (R[j][i] < R[j + 1][i]))
            {
               special = R[j][i] ;
               is_special = true;
               break;
            }
        }
        if (is_special)
        {
            break;
        }

    }
    if (is_special)
    {
        cout << endl << "special: " << special << endl;
        return is_special ;
    }

    else
    {
        cout << endl << "This matrix have not special element!" << endl;
        special = 20000;
        return is_special;
    }


}

int** duplicated(int** R, int n, int& m, int special, bool is_special)
{
    if (is_special)
    {
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (R[j][i] == special)
                {
                    m++;
                    break;
                }
            }
        }

        int** A = new int* [n] ;
        for (int i = 0; i < n ; i++)
            A[i] = new int [m];

        int t = 0;
        bool dup = false;
        for (int i = 0; i < m; i++)
        {
            for (int j =0; j < n; j++)
            {
                if (R[j][i] == special)
                {
                   dup = true;
                }
                A[j][t] = R[j][i];
            }
            t++;
            if (dup)
            {
                for (int j =0; j < n; j++)
                {
                    A[j][t] = R[j][i];
                }
                dup = false;
                t++;
            }
        }

        return A;

    }
    else
    {
        return R;
    }

}

 string* create_P (int** A, int n, int m)
 {
     string* P = new string [n-1];

     for (int i = 0; i < n -1; i++)
     {
         for (int j = 0; j < m ; j++)
         {
             P[i] += to_string(A[i][j] + A[i+1][j]) + ";" ;
         }
         P[i].pop_back();
     }

     return P;
 }
void print_array (string* P, int n)
{
    cout << endl << "array strings P: " << endl;

     for (int i = 0; i < n -1; i++)
     {
         cout << P[i] << endl;
     }
}

string*  duplicated (int** A, int n , int m)
{
    int** D = new int* [n - 1];
    for (int i =0; i < n ; i++)
        D[i] = new int [m];

    for (int i = 0; i < n - 1; i++)
     {
         for (int j = 0; j < m ; j++)
         {
             D[i][j] = A[i][j] + A[i+1][j];
         }
     }

    string* P = new string [n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m ; j++)
        {
            if (D[i][j] > 0)
            {
               P[i] += to_string(D[i][j]) + ";" + to_string(D[i][j]) + ";" ;
            }
            else
            {
                P[i] += to_string(D[i][j]) + ";";
            }
        }
         P[i].pop_back();
    }

    return P;
}
