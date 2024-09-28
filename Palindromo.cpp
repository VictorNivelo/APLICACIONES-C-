/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
	char cadena1[50], cadena2[50];
	int log1, log2, a = 0, b = 0, c, pal = 0;
	printf("Introduce una frase o palabra:\n");
	scanf("%[^\n]", cadena1);

	log1 = strlen(cadena1);

	for (a = 0; a <= log1; a = a + 0)
	{

		if (cadena1[a] == ' ')
		{
			a++;
		}

		if (cadena1[a] != ' ')
		{
			cadena2[b] = cadena1[a];
			a++;
			b++;
		}
	}
	log2 = strlen(cadena2);

	for (c = 0; c <= log2; c++)
	{
		if (cadena2[log2 - c - 1] == cadena2[c])
		{
			pal++;
		}
	}

	if (pal == log2)
	{
		printf("Es palindromo\n");
	}
	else
	{
		printf("No es palindromo\n");
	}
	system("pause");
}