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
