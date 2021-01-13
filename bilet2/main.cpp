#include <iostream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
#include "head.h"
#include <ctime>
using namespace std;
int main ()
{
    srand(time(0));
    int m;            // size square matrix G
    cout << "input size matrix:" ;
    cin >> m;

    int index_min;   // index column than is min element

    int** G = create_G (m);                         //create square matrix G
    int min_el = search_min (G, m, index_min);     // search min element up side (no main) diagonal


    int n = m;    // number column in new matrix G_new

    int** G_new = delete_column (G, m, n, index_min);       // delete column in matrix G and create new matrix G_new    (late)
    print_matrix_G (G_new, m, n);                           // print new matrix G_new                                   (late)


    string * matrix_string = decimal_to_binary (G_new, m, n);      // create matrix string than locate element matrix G translate to binary system
    print_string_matrix (matrix_string, n);                        // print massif string with binary numbers

    duplication_element (matrix_string, n, m);                     // duplication word with max number 1                            (late)
    print_string_matrix (matrix_string, n);                        // print massif string with binary numbers (already duplicated)  (late)

    return 0;
}
