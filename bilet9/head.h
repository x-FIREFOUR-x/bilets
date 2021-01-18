#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <ctime>
#include <cmath>
using namespace std;
int** create_matrix(int k);
void print_matrix(int** R, int k, int);
int search_special (int** R, int k, int&);
int** create_D (int** R, int k, int& , int column);
string* create_array_str ( int** D, int k , int n);
void print_array (string* V, int k);
string* transform_V (int** D, int k, int n);
