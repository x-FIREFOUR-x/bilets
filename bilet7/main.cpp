#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    cout << "input size matrix (m): " ;
    int m;          // size matrix
    cin >> m ;

    int** A = create_matrix(m);                                 // create matrix
    print_matrix (A, m);                                        // print matrix
    int line, column;           // index line and column than locate min element
    int min_el = search_min (A, m, line, column);               // search min elem in up and down triangles

    int k ;         // index line and column than crossroads
    cout << "Input k: " ;
    cin >> k;
    move_matrix(A, m, line, column, k);                         // move line and column matrix's,
                                                                    // than min element locate in crossroads k-line and k-column
    print_matrix (A, m);                                        // print matrix

    string* S = create_mat_string (A, m);                       // 3. create matrix string symbol, whose cods = element matrix A   (late)
                                                                // 4. association in tokens (word) in quiet line where cods sorted by growth
    print_mat_str (S, m);                                       // print matrix(string) this symbol

    return 0;
}
