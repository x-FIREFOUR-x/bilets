#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
int** create_matrix (int);
void print_matrix (int**, int);
int search_min (int** A, int m, int&, int&);
void move_matrix (int**, int, int, int, int);
string* create_mat_string (int**, int);
void print_mat_str (string* S, int m);
