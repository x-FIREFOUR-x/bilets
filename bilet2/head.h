#include <iostream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
using namespace std;
int** create_G (int);
int search_min (int**, int, int&);
int** delete_column (int**, int, int&, int);
void print_matrix_G (int**, int, int);
string * decimal_to_binary (int**, int, int);
void print_string_matrix (string*, int);
void duplication_element (string*, int, int);

