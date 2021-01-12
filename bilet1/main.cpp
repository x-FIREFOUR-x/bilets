#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "head.h"
#include <ctime>
#include <ctype.h>
using namespace std;
int main()
{
    srand(time(0));
    cout << "input size matrix:" ;
    int n, m; //  size matrix
    cin >> n >> m;

    int** A = create(n,m);          // створюєм матрицю
    float* M = average (A, n, m);   // створюєм матрицю середніх значень сум в рядку матриці A
    input_matrix_average (M, n);    // виводим матрицю середніх

    sorting (A, M, n, m) ;          // сортуєм матрицю А за значеннями матриці M
    input_sort_A (A, n ,m);         // виводим відсортовану матрицю А

    string* H = hexta (A, n , m);   // створюєм матрицю H переведенням в 16-ву матриці A  (не встиг)
    input_hexta_matrix (H, n);      // виведення матриці H          (не встиг)


    delete_cifry (H,n);             // видаляю в матриці H цифри
    input_hexta_matrix (H, n);      // виведення матриці H


    return 0;
}
