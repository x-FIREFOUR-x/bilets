#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
using namespace std;
int** create_matrix (int n)
{
    int** Q = new int* [n];
    for (int i = 0; i < n; i++)
        Q[i] = new int [n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Q[i][j] = rand()%10001 -1000 ;
        }
    }

    return Q;
}
void print_matrix (int** Q, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(5) << Q[i][j] << " ";
        }
        cout << endl;
    }
}

int  search_special (int** Q, int n)
{
    int special;
    bool is_special = false;
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 1; j < n-1; j++)
        {
            if (i >= j && i+j >= n - 1 && Q[i][j] > Q[i][j-1] && Q[i][j] < Q[i][j+1])
            {
                special =  Q[i][j];
                is_special = true;
                break;
            }
        }
        if (is_special)
                break;
    }

    if (is_special)
        cout << endl << "Special element: " << special << endl;
    else
        cout << endl << "!Matrix have not special element!" << endl;


    return special;
}

string* create_string_matrix (int** Q, int n)
{
    string* S = new string [n-1];
    cout << endl << "String matrix:" << endl;

     for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << Q[i][j] * Q[i+1][j] << " ";
            string s = to_string(Q[i][j] * Q[i+1][j]);
            int len_word = s.length();

            for (int t = 1; t < len_word; t++)
            {
                for (int k = 0; k < t; k++)
                {
                    if (s[t] == s[k])
                    {
                       s.replace(t, 1, "*");
                    }
                }
            }



            /*string str = to_string(Q[i][j] * Q[i+1][j]);
            int len*/

            S[i] += s + " ";

        }
        cout << endl;
    }

    return S;
}

 void print_str_matrix (string* S, int m)
 {
     cout << endl << "String matrix:" << endl;
     for (int i =0; i < m; i++)
        cout << S[i] << endl;
 }
