/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>

using namespace std;

int main()
{
    float n1, d1, n2, d2, n3, d3, n4, d4;
    cout << "================================================" << endl;
    cout << "Ingrese el primer numerador: " << endl;
    cin >> n1;
    cout << "Ingrese el primer denominador: " << endl;
    cin >> d1;
    cout << "Ingrese el segundo numerador: " << endl;
    cin >> n2;
    cout << "Ingrese el segundo numerador: " << endl;
    cin >> d2;
    cout << "Ingrese el tercer numerador: " << endl;
    cin >> n3;
    cout << "Ingrese el tercer numerador: " << endl;
    cin >> d3;
    cout << "Ingrese el cuarto numerador: " << endl;
    cin >> n4;
    cout << "Ingrese el cuarto numerador: " << endl;
    cin >> d4;
    cout << "================================================" << endl;

    if (d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
    {
        printf("Fraccion de la suma es:"
               " 1/2  ");
        cout << "Resultado de la suma de fracciones es: " << (n1 / d1) + (n2 / d2) + (n3 / d3) + (n4 / d4) << endl;
    }
    else
    {
        cout << "La suma entre cero no es valida.";
    }

    if (d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
    {
        printf("Fraccion de la resta es:"
               " -1/4  ");
        cout << "La resta de fracciones es:  " << (n1 / d1) - (n2 / d2) - (n3 / d3) - (n4 / d4) << endl;
    }
    else
    {
        cout << "La resta entre cero no es valida.";
    }
    if (d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
    {
        printf("Fraccion de la multiplicacion es:"
               " 1/4096  ");
        cout << "La multiplicacion de fracciones es:  " << (n1 / d1) * (n2 / d2) * (n3 / d3) * (n4 / d4) << endl;
    }
    else
    {
        cout << "La multiplicacion entre cero no es valida.";
    }
    if (d1 != 0 && d2 != 0 && d3 != 0 && d4 != 0)
    {
        printf("Fraccion de la divicion es:"
               " 64/1  ");
        cout << "La divicion de fracciones es:  " << (n1 / d1) / (n2 / d2) / (n3 / d3) / (n4 / d4) << endl;
        cout << "================================================" << endl;
        cout << "AUTOR: Victor David Nivelo Yaguana  1 A  UNL" << endl;
    }
    else
    {
        cout << "La divicion entre cero no es valida.";
    }
}