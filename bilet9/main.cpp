#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    int k;          // size matrix R
    cout << "input size matrix k: " ;
    cin >> k;

    int** R = create_matrix(k);                                     // create matrix R
    print_matrix(R, k, k);                                          // print matrix R
    int column;      // index column where located special element
    int special = search_special (R, k, column);                    // search special            (done 23 min, late send)

    int n;      // number columns in matrix D
    int** D = create_D (R, k, n, column);                           // create matrix D add column 0 after column where locate special element
    print_matrix(D, k, n);                                          // print matrix D

    string* V = create_array_str (D, k , n);                        // crate array strings V
    print_array (V, k);                                             // print array strings V

    V = transform_V (D, k, n);                                      // transform array V in sorting type (-)(0)(+)
    print_array (V, k);                                             // print array V

    return 0;
}
