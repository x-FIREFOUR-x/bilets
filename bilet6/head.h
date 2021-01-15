#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <ctime>
using namespace std;
int** create_matrix (int);
void print_matrix (int**, int, int);
int  search_special (int**, int&, int, int&);
int** add_line(int**, int, int, int);
string* create_string_matrix (int**, int, int);
void print_str_matrix (string*, int);
