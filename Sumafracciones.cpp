/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <conio.h>
void main()
{
    int n, i, k = 1;
    float s, a, b, nume = 1, deno;
    cout << "Ingresar limite:";
    cin >> n;
    cout << endl;
    cout << "ingresar primer numero:";
    cin >> a;
    cout << "ingresar segundo numero:";
    cin >> b;
    cout << endl;
    s = 0;
    for (i = 0; i < n; i++)
    {
        deno = a + (k * b);
        cout << nume * nume << "/" << deno * deno << endl;
        nume = nume + 1;
        s = s + (nume / deno);
        k = k + 1;
    }
    cout << "la suma es:" << s;
    getch();
}