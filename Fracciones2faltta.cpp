/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    int ingresardatos();
    {

        int n1, n2, n3, n4, d1, d2, d3, d4;

        cout << "======================================================" << endl;
        cout << "INGRESAR DATOS" << endl;
        cout << "Introduce el valor de el primer numerador:  " << endl;
        cin >> n1;
        cout << "Introduce el valor de el primer denominadordor:  " << endl;
        cin >> d1;
        cout << "Introduce el valor de el segundo numerador:  " << endl;
        cin >> n2;
        cout << "Introduce el valor de el segundo denominadordor:  " << endl;
        cin >> d2;
        cout << "Introduce el valor de el tercer numerador:  " << endl;
        cin >> n3;
        cout << "Introduce el valor de el tercer denominadordor:  " << endl;
        cin >> d3;
        cout << "Introduce el valor de el cuarto numerador:  " << endl;
        cin >> n4;
        cout << "Introduce el valor de el cuarto denominadordor:  " << endl;
        cin >> d4;
        cout << "======================================================" << endl;
        cout << "======================================================" << endl;
        cout << "Las fracciones son las siguientes:" << endl;
        cout << "Fraccion 1: " << n1 << "/" << d1 << endl;
        cout << "Fraccion 2: " << n2 << "/" << d2 << endl;
        cout << "Fraccion 3: " << n3 << "/" << d3 << endl;
        cout << "Fraccion 4: " << n4 << "/" << d4 << endl;
        cout << "======================================================" << endl;
    }
}