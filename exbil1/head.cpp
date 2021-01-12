#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int create_R(int** R, int n, int m)
{
    for (int i = 0; i < n; i++)
        R[i] = new int [m];


    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            R[i][j] = rand()%19999 - 9999;
            //R[i][j] = rand()%31 - 15;
            cout << fixed << setw(5) << R[i][j];
        }
        cout << endl;
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ( j >= i && i + j >= (n + m)/2 - 1 )
            cout << fixed << setw(5) << R[i][j];
        }
        cout << endl;
    }*/

    //bool specialExist = false;
    int special;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = m -1; j >= 0; j--)
        {
            if (j >= i && i + j >= (n + m)/2 - 1  && R[i][j] > R[i - 1][j] && R[i][j] < R[i + 1][j] )
            {
                special = R[i][j];
                cout << "special: " << special << endl;
                return special;
            }
        }


    }
    return 10000;
}

int** create_A (int ** R, int special, int n, int &m)
{

    int col = m;
    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if ( R[j][i] == special )
            {
                col++;
                break;
            }
        }

    }

    int** A = new int* [n];
    for (int i =0; i < col ; i++)
    {
        A[i] = new int [col];
    }

    int shift = 0;
    for (int i = 0; i < col; i++)
    {
        bool specialExist = false;
        for (int j = 0; j < n; j++)
        {
           A[j][i] = R[j][i - shift];
           if ( R[j][i - shift] == special)
            {
                specialExist = true;
            }
        }

        if (specialExist) {
            shift++;
            i++;
            for (int k = 0; k < n; k++) {
                A[k][i] = R[k][i - shift];
            }
        }

    }




    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < col; j++)
        {

            cout << fixed << setw(5) << A[i][j];
        }
        cout << endl;
    }
    m = col;
    return A;
}

int** create_A (int ** R, int n, int m)
{
    int** A = new int* [n];
    for (int i =0; i < m ; i++)
    {
        A[i] = new int [m];
    }

    cout << endl << "Matrix A: " << endl;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            A[i][j] = R[i][j];
            cout << fixed << setw(5) << A[i][j];
        }
        cout << endl;
    }

}

string* create_P (int** A, int n, int m)
{
    string* P = new string [m -1] ;
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n -1)
            {
                P[i] += to_string(A[j][i] + A[j][i+1] ) + ";" ;
            }
            else
                P[i] += to_string(A[j][i] + A[j][i+1] ) ;
        }
    }
    cout << endl << "P: " << endl;
    for (int i = 0; i < m - 1; i++)
        cout << P[i] << endl;

    return P;

}

string* double_P (int** A, int n, int m)
{
    string* P_d = new string [m -1];
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            P_d[i] += to_string(A[j][i] + A[j][i+1] ) + ";" ;
            if (A[j][i] + A[j][i+1] > 0)
            {
                P_d[i] += "[" + to_string(A[j][i] + A[j][i+1] ) + "]" + ";" ;
            }

        }
        P_d[i] = P_d[i].substr(0, P_d[i].length() - 1);
    }
    cout << endl << "P(double): " << endl;
    for (int i = 0; i < m - 1; i++)
        cout << P_d[i] << endl;

    return P_d;

}
