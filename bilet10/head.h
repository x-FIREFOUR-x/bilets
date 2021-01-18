#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;
int** create_matrix (int n);
void print_matrix(int** R, int n, int);
bool  search_special (int** R, int n, int&);
int** duplicated(int** R, int n, int& m, int special, bool is_special);
 string* create_P (int** A, int n, int m);
 string*  duplicated (int** A, int n , int m);
void print_array (string* P, int n);


