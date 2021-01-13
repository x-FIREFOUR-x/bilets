#include <iostream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
#include "head.h"
using namespace std;
int** create_G (int m)
{
    int** G = new int* [m];
    for(int i =0; i <m; i++)
        G[i] = new int [m];

    for(int i =0; i < m; i++)
    {
        for(int j =0; j < m; j++)
        {
            G[i][j] = rand()% 1001 ;
            cout << fixed << setw(4) << G[i][j] << " ";
        }
        cout << endl;
    }

     return G ;
}
int search_min (int** G, int m, int & index_min)
{
    int min_el = G[0][0];
    index_min = 0;

    for(int i =0; i < m; i++)
    {
        for(int j =0; j < m; j++)
        {
            if (i + j <= m - 1 && min_el > G[i][j])
            {
                min_el = G[i][j];
                index_min = j;
            }
        }
    }
    cout << "Min elemt, than locate up no main diagonal: " << min_el ;
    return min_el;
}

 int** delete_column (int** G, int m, int& m_col, int index_min)
 {
     if (index_min != m-1)
     {
        for(int i = index_min + 1; i < m -1 ; i++)
        {
            for(int j =0; j < m ; j++)
            {
                G[j][i] = G[j][i+1];
            }
        }

        int** G_new = new int* [m];
        for(int i =0; i <m; i++)
            G_new[i] = new int [m-1];


        for(int i =0; i < m; i++)
        {
            for(int j =0; j < m-1; j++)
            {
                G_new[i][j] = G[i][j];
            }
        }

        for(int i =0; i <m; i++)
           delete[]G[i];
        delete[]G;

        m_col--;
        return G_new;
     }
     else
        return G;


 }

void  print_matrix_G(int** G, int m, int m_col)
 {
      cout << endl << "matrix G: " << endl;
     for(int i =0; i < m; i++)
    {
        for(int j =0; j < m_col; j++)
        {
            cout << fixed << setw(4) << G[i][j] << " ";
        }
        cout << endl;
    }
 }

  string * decimal_to_binary (int** G, int m, int n)
  {
      string* A = new string[n];

      for(int i =0; i < n; i++)
    {
        int pos = 0;
        for(int j =0; j < m; j++)
        {
            int decimal_number = G[j][i];
            while(decimal_number != 0)
            {
                int binary_symbol = decimal_number - (decimal_number/ 2 * 2);
                decimal_number = decimal_number / 2;
                string s = to_string(binary_symbol);
                A[i].insert(pos,s) ;
            }

            A[i] += " ";
            pos = A[i].length();
        }

    }
    return A;
  }

  void print_string_matrix (string* A, int n)
  {
       cout << endl << "matrix G translate to binary system (string massif): " << endl;
     for(int i =0; i < n; i++)
    {
        cout <<  A[i] << endl;
    }
  }

  void duplication_element (string* A, int n, int m)
  {
    cout << endl << "elements than duplicated: ";
    for (int i =0 ; i < n; i++)       // #Search of array elements
    {

        int start = 0;                // the beginning of the word in which we count 1
        int len = A[i].length();      // length all string (element massif)
        int last = A[i].find(" ");    // the end of the word in which we count 1
        int max_number_1 = 0;         // the number of the largest number 1
        int first_pos_max = 0;        //  the beginning of the word in which the max 1
        int last_pos_max = last;      //  the end of the word in which the max 1

        int index_elements_which_double =0;   // index word which the max 1


        for (int j =0; j < m; j++)    //  #Search word in string (element in massif)
        {
            string s = A[i].substr(start, last-start );
            int numb_1 =0;                  // the number 1 in search word

            for (int k = 0; k < last-start ; k++ )  // #Search char in word
            {
                if (s[k] == '1')
                {
                    numb_1++ ;
                }
            }

            if (numb_1 > max_number_1)      // check if the word has the max 1
            {
                max_number_1 = numb_1 ;
                first_pos_max = start;
                last_pos_max = last;
                index_elements_which_double = j + 1;
            }

            start = last + 1;                                           // highlight the beginning and end of the next word
            string str = A[i].substr(start, len - start );
            if (j != m-1 )
                last = str.find(" ") + start;
            else
                last = len -1;                                          //


        }

        string select_word_duplicate = A[i].substr(first_pos_max, last_pos_max - first_pos_max );   //
        select_word_duplicate = " " + select_word_duplicate + " ";                                          // duplicated word with max 1
        A[i]. insert(first_pos_max, select_word_duplicate);                                         //

        cout << index_elements_which_double << " " ;

    }
    cout << endl;
  }
