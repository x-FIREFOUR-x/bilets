#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
#include "head.h"
using namespace std;
int** create_matrix(int k)
{
    int** R = new int* [k];
    for (int i = 0; i <k; i++)
        R[i] = new int [k];
    for (int i = 0; i <k; i++)
    {
        for (int j = 0; j <k; j++)
        {
            R[i][j] = rand() %1801 - 900 ;
        }
    }

    return R;
}
void print_matrix(int** R, int k, int n)
{
    cout << endl << "Matrix R:" << endl;
    for (int i = 0; i <k; i++)
    {
        for (int j = 0; j <n; j++)
        {
            cout << setw(4) << R[i][j] << " " ;
        }
        cout << endl;
    }
}

int search_special (int** R, int k, int& column)
{
    int special;
    int number_special = 0;
    for (int i = k - 1; i >=0; i--)
    {
        if ( i != 2 )
        {
           for (int j = 1; j < k - 1; j++)
            {
                if (  R[i][j] > R[i][j-1] && R[i][j] < R[i][j+1] )
                    {
                        special = R[i][j];
                        column = j;
                        number_special++;
                       // cout << endl << special << " " << i << " " << j << endl;
                    }
            }
        }
        else
        {
            int max_el = R[i][0] ;
            int index = 0;
            for (int j = 0; j < k; j++)
            {
                if (max_el < R[i][j])
                {
                    max_el = R[i][j];
                    index = j;
                }

            }
            special = max_el;
            column = index ;
            number_special ++;
        }

    }
    if (number_special > 1)
    {
        special = R[1][1];
        column = 1;
    }

    cout << endl  << " special: " << special << endl << "index column special element's: "<< column << endl;

    return special;
}

int** create_D (int** R, int k, int& n, int column)
{
    n = k + 1;
    int** D = new int* [k];
    for (int i = 0; i <k; i++)
        D[i] = new int [n];

    for (int i =0; i < k; i++)
    {
        for (int j =0; j <= column; j++)
        {
            D[i][j] = R[i][j];
        }

        D[i][column+1] = 0;

        //int t = column + 1;
        for (int h =column+2; h < n; h++)
        {
            D[i][h] = R[i][h - 1];
            //t++;
        }
    }

    return D;
}

string* create_array_str ( int** D, int k , int n)
{
    string* V = new string [k];

    for (int i =0; i < k; i++)
    {
        for (int j =0; j < n; j++)
        {
            V[i] += to_string(D[i][j]) + " " ;
        }
    }

    return V;
}

void print_array (string* V, int k)
{
    cout << endl << "Array string V: " << endl;
     for (int i =0; i < k; i++)
        cout << V[i] << endl;
}

string* transform_V (int** D, int k, int n)
{

    string* V = new string [k];

    for (int i =0; i < k; i++)
    {
        V[i] = "(" ;
        for (int j =0; j < n; j++)
        {
            if (D[i][j] < 0)
            {
                V[i] += to_string(D[i][j]) + " " ;
            }
        }
        if (V[i].length() > 2)
            V[i].pop_back();
        V[i] += ")" ;
        V[i] += "(" ;

         for (int j =0; j < n; j++)
        {
            if (D[i][j] == 0)
            {
                V[i] += to_string(D[i][j]) + " " ;
            }
        }
        V[i].pop_back();
        V[i] += ")" ;
        V[i] += "(" ;

         for (int j =0; j < n; j++)
        {
            if (D[i][j] > 0)
            {
                V[i] += to_string(D[i][j]) + " " ;
            }
        }
        V[i].pop_back();
        V[i] += ")" ;
    }

    return V;
}
