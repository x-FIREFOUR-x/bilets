#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>

using namespace std;
float** create_matrix(int);
void print_matrix (float**, int, int);
float search_min (float**, int, int&);
float** create_matrix_D(float**, int&, int, int);
string* transform_matrix (float**, int, int);
void print_array (string*, int);
string* sort_lek (float**, int, int);
