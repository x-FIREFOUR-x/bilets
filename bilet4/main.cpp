#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
#include "head.h"
using namespace std;
int main()
{
    srand(time(0));
    cout << "input size squre matrix(n): " ;
    int n;          // size matrix H
    cin >> n ;

    float** H = create_matrix(n);                       // create matrix H float number size n
    print_matrix (H, n, n);                             // print matrix H
    int line;               // index line than located min element
    float min_el = search_min (H,n, line);              // search min element down main diagonal in matrix H

    int m = n;          // m - number line in matrix D
    float** D = create_matrix_D(H, m, n, line);         // create matrix D copy matrix H + line '0' after line than locate min element (late 50/50)
    cout << endl ;
    print_matrix (D, m, n);

    string* R = transform_matrix (D, m, n);             // transform number matrix's D to number kind 3a + 5b in array string R (late)
    print_array (R, m);                                 // print array string R

    R = sort_lek (D, m, n);                             // sort type numbers(word) 3a+5b in lines lexicographically in array string R
    print_array (R, m);                                 // print array R

    return 0;
}
