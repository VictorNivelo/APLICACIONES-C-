/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;

int main()
{
        string v_original[5];
        string v_aux[5];
        string v_final[5];
        string num;

        int cont, i, j = 0, k, z = 0;
        printf("=======================================================\n");
        printf("Programa para determinar si los nombres son homonimos\n");
        printf("=======================================================\n");
        for (i = 0; i < 5; i++)
        {
                cout << "Introduce los nombres y apellidos: ";
                getline(cin, v_original[i]);
        }

        for (i = 0; i < 5; i++)
        {
                cont = 0;
                num = v_original[i]; // a
                v_aux[j] = num;      // a
                j++;                 // 1
                for (k = 0; k < 5; k++)
                {
                        if (v_aux[k] == num)
                        {
                                cont++;
                        }
                }

                if (cont != 1)
                {
                        v_final[z] = num;
                        z++;
                }
        }

        printf("=======================================================\n");
        cout << "Los homonimos son: \n";
        for (i = 0; i < z; i++)
        {
                cout << v_final[i] << endl;
        }
        printf("=======================================================\n");
        printf("Autor: Victor David Nivelo Yaguana  TP   1A\n");
        printf("=======================================================\n");
}
