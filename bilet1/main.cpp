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

    int** A = create(n,m);          // �������� �������
    float* M = average (A, n, m);   // �������� ������� ������� ������� ��� � ����� ������� A
    input_matrix_average (M, n);    // ������� ������� �������

    sorting (A, M, n, m) ;          // ������ ������� � �� ���������� ������� M
    input_sort_A (A, n ,m);         // ������� ����������� ������� �

    string* H = hexta (A, n , m);   // �������� ������� H ������������ � 16-�� ������� A  (�� �����)
    input_hexta_matrix (H, n);      // ��������� ������� H          (�� �����)


    delete_cifry (H,n);             // ������� � ������� H �����
    input_hexta_matrix (H, n);      // ��������� ������� H


    return 0;
}
