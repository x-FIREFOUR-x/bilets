#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
float** create_matrix(int);
float search_special (float**, int, int&, int&);
void move_special(float**, int, int, int);
void print_matrix(float**, int);
float** create_matrix_pair (float**, int);
string* create_matrix_string (float**, int, int);
