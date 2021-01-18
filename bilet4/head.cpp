#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
using namespace std;
float** create_matrix(int n)
{
    float** H = new float*[n];
    for(int i =0; i < n; i++)
        H[i] = new float [n];

    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            H[i][j] = (rand()%993 + 8) + (float)(rand()%100)/100;
        }
    }
    return H;
}

void print_matrix (float** H, int m, int n)
{
    cout << "matrix:" << endl;
    for(int i =0; i < m; i++)
    {
        for(int j =0; j < n; j++)
        {
           cout << fixed << setw(10) << H[i][j] << " " ;
        }
        cout << endl;
    }

}

float  search_min (float** H, int n, int& line)
{
    float min_el = H[1][0];

    for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
          if (i > j && min_el > H[i][j])
          {
              min_el = H[i][j];
              line = i ;
          }
        }

    }

   cout << endl << "min element down main diagonal: " << min_el << endl << " index line min element: " << line + 1 << endl ;
   return min_el;
}

float** create_matrix_D(float** H, int& m, int n, int line)
{

    if (line != m-1)
    {
        m++;
        float** D = new float*[m];
            for(int i =0; i < m; i++)
            D[i] = new float [n];

        for(int i =0; i <= line; i++)
        {
            for(int j =0; j < n; j++)
            {
                D[i][j] = H[i][j];

            }
        }
        for (int j =0; j < n; j++)
            D[line + 1][j] = 0;

        int k = line +1;
        for(int i = line+2; i < m; i++)
        {

            for(int j =0; j < n; j++)
            {
                D[i][j] = H[k][j];

            }
            k++;
        }

        return D;
    }
    else
    {
        float** D = new float*[m];
            for(int i =0; i < m; i++)
            D[i] = new float [n];

            //cout << m ;
        for(int i =0; i < m; i++)
        {
            for(int j =0; j < n; j++)
            {
                D[i][j] = H[i][j];

            }
        }

        return D;
    }


}

string* transform_matrix (float** D, int m, int n)
{
    string* R = new string [m];

    for(int i =0; i < m; i++)
    {
        for(int j =0; j < n; j++)
        {
            int numb = (int) D[i][j];
            int a = 0;
            int b = 0;
            if (numb == 8)
            {
                a = 1;
                b = 1;
            }
            else
            {
                switch (numb % 10)
                {
                case 0 : b = numb / 5 ; a = 0; break;
                case 5 : b = numb / 5 ; a = 0; break;
                case 1 : a = 7; b = (numb - 21) / 5; break;
                case 2 : a = 4; b = (numb - 12) / 5; break;
                case 3 : a = 1; b = (numb - 3) / 5; break;
                case 4 : a = 8; b = (numb - 24) / 5; break;
                case 6 : a = 2; b = (numb - 6) / 5; break;
                case 7 : a = 9; b = (numb - 27) / 5; break;
                case 8 : a = 6; b = (numb - 18) / 5; break;
                case 9 : a = 3; b = (numb - 9) / 5; break;
                }
            }
            R[i] = R[i] + "3" + "*" + to_string(a) + "+" + "5" + "*" + to_string(b) + " " ;
        }
    }
    return R;
}
void print_array (string* R, int m)
{
    cout << endl << "Array string R: " << endl;
    for(int i =0; i < m; i++)
        cout << R[i] << endl;
}

string*  sort_lek (float** D, int m, int n)
{
    string** R = new string* [m];
    for (int i =0; i <m; i++)
        R[i] = new string [n];

    for(int i =0; i < m; i++)
    {
        for(int j =0; j < n; j++)
        {
            int numb = (int) D[i][j];
            int a = 0;
            int b = 0;
            if (numb == 8)
            {
                a = 1;
                b = 1;
            }
            else
            {
                switch (numb % 10)
                {
                case 0 : b = numb / 5 ; a = 0; break;
                case 5 : b = numb / 5 ;a = 0; break;
                case 1 : a = 7; b = (numb - 21) / 5; break;
                case 2 : a = 4; b = (numb - 12) / 5; break;
                case 3 : a = 1; b = (numb - 3) / 5; break;
                case 4 : a = 8; b = (numb - 24) / 5; break;
                case 6 : a = 2; b = (numb - 6) / 5; break;
                case 7 : a = 9; b = (numb - 27) / 5; break;
                case 8 : a = 6; b = (numb - 18) / 5; break;
                case 9 : a = 3; b = (numb - 9) / 5; break;

                }
            }
            R[i][j] = "3*" + to_string(a) + "+5*" + to_string(b);
        }
    }

    for (int i =0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            if (R[i][j] > R[i][k])
                {
                    string box = R[i][j];
                    R[i][j] = R[i][k];
                    R[i][k] = box;
                }
        }
    }
    string* G = new string [m];
    for (int i =0; i < m; i++)
    {
        for (int j =0; j < n; j++)
        {
            G[i] += R[i][j] + " " ;
        }
    }
    return G;
}
