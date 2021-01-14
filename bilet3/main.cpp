#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cout << "input size matrix(n): ";
    cin >> n;
    int line = 0, column = 0;

    if (n%2 == 1)
    {
        float** A = create_matrix(n);                           // create matrix
        print_matrix(A, n);                                     // print matrix
        float special = search_special (A, n, line, column);    // search in matrix special element

        move_special(A, n, line, column);                       // move line and column than special locate in center     (late, zatypuv)
        print_matrix(A, n);                                     // print matrix                                           (late)

        float** B = create_matrix_pair (A, n);                  // create matrix pair column and sorting     (late)
        int m = n / 2 + 1;                               // number line in matrix B
        string* C = create_matrix_string (B, n, m);             // create and print matrix string C than cope matrix B ; round numbers in string matrix
                                                                //(3 late, 4: 50/50)

    }
    else
    {
        cout << "eror input azygous size matrix!" << endl;
    }

    return 0;
}
