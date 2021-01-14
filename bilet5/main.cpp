#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    int k, m;               // size matrix
    cout << "input size matrix (k,m): " ;
    cin >> k >> m ;

    long**Q = create_matrix_Q(k,m);                                     // create matrix Q size k * m
    cout << endl << "Matrix Q: " << endl;
    print_matrix(Q, k, m);                                              // print matrix Q
    int line, column;       // index line and column special element
    long special = search_special(Q, k, m, line, column);               // search special element

    move_matrix (Q, k, m, line, column);                                // move line and column matrix than special locate in left and down in matrix
    cout << endl << "Matrix Q: " << endl;
    print_matrix(Q, k, m);                                              // print move matrix

    string* Z = create_Z(Q,k,m);                                        // create matrix Z, which have pair elements matrix Q and print matrix Z
                                                                        // and add elements matrix Z fractional part
    print_string_mas (Z, k);                                            // print matrix string Z with fractional part



    return 0;
}
