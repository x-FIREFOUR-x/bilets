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
    print_matrix (Q, n);                                        // print matrix Q
    int special = search_special (Q,n);                         // search special element in zone matrix /\ (down triangle) start

    // i don't understand two task

    string* S = create_string_matrix (Q, n);                    // create matrix string
    print_str_matrix(S, n-1);                                   //print matrix string

    return 0;
}
