#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
#include "head.h"
using namespace std;
int** create_matrix (int m)
{
    int** A = new int* [m];
    for (int i = 0; i < m; i++)
        A[i] = new int [m];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            A[i][j] = rand()%224 +33;
        }
    }

    return A;
}
void print_matrix (int** A, int m)
{
    cout  << "Matrix: " << endl;
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(5) << A[i][j] << " ";
        }
        cout << endl;
    }
}

int search_min (int** A, int m, int& line, int& column)
{
    int min_el = A[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ( (i <= j && j + i <= m-1 && min_el > A[i][j]) || (i >= j && j + i >= m-1 && min_el > A[i][j]) )
            {
                min_el = A[i][j];
                line = i;
                column = j;
            }
        }
    }

    cout << endl << "min element: " << min_el << endl;
    return min_el;
}

void move_matrix (int** A, int m, int line, int column, int k)
{
    cout << endl << "index: " << line << " " << column << endl ;
    int* box = A[k];
    A[k] = A[line];
    A[line] = box;

    int* ptr_box = new int [m];
    for (int i = 0; i < m; i++)
    {
        ptr_box[i] = A[i][k];
    }
    for (int i = 0; i < m; i++)
    {
        A[i][k] = A[i][column];
    }
    for (int i = 0; i < m; i++)
    {
        A[i][column] =  ptr_box[i];
    }
}

string* create_mat_string (int** A, int m)
{
    string* S = new string [m];

    cout << endl << "Matrix (string) symbol-cod:" << endl;   // 3. create matrix string symbol, whose cods = element matrix A   (late)
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != m-1)
            {
                char symbol = A[i][j];
                cout << symbol << "," ;
            }
            else
            {
                char symbol = A[i][j];
                cout << symbol;
            }

        }
        cout << endl;
    }

    for (int i = 0; i < m; i++)             // 4. association in tokens (word) in quiet line where cods sorted by growth
    {
        bool is_sort = true;
        for (int j = 0; j < m-1; j++)
        {
            if (A[i][j] > A[i][j+1])
            {
                is_sort = false;
            }
        }
        if (is_sort == false)
            for (int j = 0; j < m; j++)
            {
                char symbol = A[i][j];
                S[i] += symbol;
                S[i] += "," ;
            }
        else
            for (int j = 0; j < m; j++)
            {
                char symbol = A[i][j];
                S[i] += symbol;
            }
        if (is_sort != true)
            S[i].erase(m*2 -1,1);
    }

    return S;
}

void print_mat_str (string* S, int m)
{
    cout << endl << "Matrix (string) symbol-cod (association in tokens): " << endl;
    for (int i =0; i< m; i++)
    {
        cout << S[i] << endl;
    }
}

/*string* create_mat_string (int** A, int m)
{
    string* S = new string [m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char symbol = A[i][j];
            S[i] += symbol;
            S[i] += "," ;

        }
    }

    return S;
}*/
