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

    return 0;
}
