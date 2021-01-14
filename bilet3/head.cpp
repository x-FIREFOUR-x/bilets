#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
#include <cmath>
using namespace std;
float** create_matrix(int n)
{
    float **A = new float*[n];
    for(int i =0; i < n; i++)
        A[i] = new float [n];


   for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            A[i][j] = (rand()%201 - 100) + ( (float)(rand()% 100000)/ 100000 );
        }
    }

    return A;
}

void print_matrix(float** A, int n)
{
    cout << "matrix:" << endl;
     for(int i =0; i < n; i++)
    {
        for(int j =0; j < n; j++)
        {
            cout << fixed << setw(3+8) << A[i][j] << " " ;
        }
        cout << endl;
    }
}
float search_special (float** A, int n, int& line, int& column)
{
    float special;
    bool special_search = false;
    for(int i =0; i < n; i++)
    {
        for(int j =1; j < n - 1; j++)
        {
            if (A[j][i] > abs(A[j-1][i] + A[j+1][i]))
            {
                special = A[j][i];
                special_search = true;
                line = j;
                column = i;
                break;

            }
        }
        if (special_search)
            break;

    }
    cout << endl << " special element: " << special << endl <<endl ;

    return special;
}

void move_special(float** A, int n, int line, int column)
{

    int midle = n / 2;
    float * box = A[line];
    A[line] = A[midle];
    A[midle] = box;

    float* ptr_box = new float [n];
    for (int i =0; i <n; i++)
        ptr_box[i] = A[i][column];

    for(int i =0; i < n; i++)
    {
        A[i][column] = A[i][midle];
        A[i][midle] = ptr_box[i];
    }
    delete[]ptr_box;
}

float** create_matrix_pair (float** A, int n)
{

    int m = n / 2 + 1;

    float **B = new float*[m];
    for(int i =0; i < m; i++)
        B[i] = new float [n];

    for (int i =0; i < n; i++)
    {
        int k = 0;
        for (int j = 0; j < n; j = j+2 )
        {
            B[k][i] = A[j][i];
             k++;
        }

    }

    for (int i =0; i < m; i++)
    {
        for (int j =0; j < n ; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (B[i][j] < B[i][k])
                {
                    float box = B[i][j];
                    B[i][j] =  B[i][k];
                    B[i][k] = box;
                }
            }
        }
    }

    return B;
}

string* create_matrix_string (float** B, int n, int m)
{
    string* C = new string [m];

    cout << endl << "matrix string:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j =0; j < n; j++)
        {
            string s = to_string(B[i][j]);
            cout << s << " ";
            int pos_point = s.find(".");
            int pos_last = s.length() - 1;
            if (pos_last -  pos_point > 4)
            {
                string rest = s.substr(pos_point +5, 1);
                //string fourth = s.substr(pos_point + 4, 1)
                if (rest[0] < 52)
                {
                    s.erase(pos_point + 5, pos_last-pos_point-4);
                    C[i] += s + " " ;
                }
                else
                {
                    string four = s.substr(pos_point+1, 4);
                     int four_symbol = stoi(four) ;
                     four_symbol++;
                     C[i] += s.substr(0,pos_point +1) + to_string(four_symbol) + " " ;
                }

            }
            else
            {
                C[i] += s + " " ;
            }
        }
        cout << endl;
    }
    cout << endl << "matrix string rounded:" << endl;
    for (int i = 0; i < m; i++)
        cout << C[i] << endl;

    return C;
}



//
/*string* create_matrix_string (float** B, int n, int m)        // slices up to four characters after point
{
    string* C = new string [m];

    cout << endl << "matrix string:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j =0; j < n; j++)
        {
            string s = to_string(B[i][j]);
            cout << s << " ";
            int pos_point = s.find(".");
            int pos_last = s.length() - 1;
            if (pos_last -  pos_point > 4)
            {
                s = s.erase(pos_point+5,pos_last - pos_point - 4 );
                C[i] += s + " " ;
            }
            else
            {
                C[i] += s + " " ;
            }
        }
        cout << endl;
    }
    cout << endl << "matrix string rounded:" << endl;
    for (int i = 0; i < m; i++)
        cout << C[i] << endl;

    return C;
}*/
