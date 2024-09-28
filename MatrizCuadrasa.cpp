/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>

#define limite 50

int main()
{
    int palabra_inicial, palabra_final;
    char palabra[limite], caracter;
    int i;

    printf("Introduzca la palabra: ");
    scanf("%c", &caracter);
    i = 0;
    while (i < limite, caracter != '.')
    {
        palabra[i] = caracter;
        i++;
        scanf("%c", &caracter);
    }
    palabra_inicial = 0;
    palabra_final = -1;

    while (palabra_inicial < palabra_final, palabra[palabra_inicial] == palabra[palabra_final])
    {
        palabra_inicial++;
        palabra_final--;
    }
    if (palabra_inicial >= palabra_final)
    {
        printf("La palabra es polindrama\n");
    }
    else
    {
        printf("La palabra no es polindroma\n");
    }
    return 0;
}