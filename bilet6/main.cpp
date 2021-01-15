#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    int n;      // size matrix
    cout << "input n size matrix: " ;
    cin >> n ;

    int** Q = create_matrix (n);                                // create matrix Q
    cout << "matrix Q:" << endl;
    int line ;
    print_matrix (Q, n, n);                                     // print matrix Q
    int m = n;              // size line in matrix
    int special = search_special (Q, m, n, line);                   // search special element in zone matrix /\ (down triangle) start


    int** A = add_line(Q, m, n, line );                         // add line where locate special element in end matrix
    print_matrix (A, m, n);

    string* S = create_string_matrix (A, m ,n);                 // create matrix string
    print_str_matrix(S, m);                                     //print matrix string

    return 0;
}
