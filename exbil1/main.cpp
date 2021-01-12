#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "head.h"
#include <ctime>
using namespace std;
int main ()
{
    srand(time(0));
    int n, m;
    cin >> n >> m ;
    int ** R = new int* [n];
    int mCopy = m;
    int**A;

    int special = create_R (R, n, m);
    if (special != 10000)
    {
        A = create_A (R, special,n, m);
    }
    else
    {
        A = create_A (R, n, m);
    }
    string* P = create_P (A, n, m);

    string* P_d = double_P (A, n, m);

}
