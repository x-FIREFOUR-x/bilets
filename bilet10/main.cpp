#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <ctime>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cout << "inpu size matrix n: " ;
    cin >> n;
    int** R = create_matrix (n);                            // create square matrix R
    print_matrix(R, n, n);                                  // print matrix R
    int special;
    bool is_special = search_special (R, n, special);       // search special element

    int m = n;
    int** A = duplicated(R, n, m, special, is_special);     // create matrix A, duplicated column where locate element == special
    print_matrix(A, n, m);                                  // print matrix A

    cout << endl << n << endl ;
    string* P = create_P (A, n, m);                         // create matrix strings P to sum element column matrix A
    print_array (P, n);                                     // print array strings P

    P = duplicated (A, n , m);                              // duplicated elements > 0 array's P
    print_array (P, n);                                     // print array P

    return 0;
}
