/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>

using namespace std;

class Fraccion
{
private:
    int n1, d1, n2, d2, n3, d3, n4, d4;
    int numerador;
    int denominador;
    int entero;

    int minimocomundenominador(Fraccion fraccion)
    {
        int mcd;
        if (denominador == fraccion.denominador)
        {
            mcd = denominador;
        }
        else
        {
            mcd = denominador * fraccion.denominador;
        }
        return mcd;
    }

public:
    fraccion(int valorNumerador = 1, int valorDenominador = 1, int valorEntero = 0)
    {
        entero = valorEntero;
        numerador = valorNumerador;
        denominador = valorDenominador;
    }

    fraccion(int valorn1 = 0, int valord1 = 0, int valorn2 = 0, int valord2 = 0, int valorn3 = 0, int valord3 = 0, int valorn4 = 0, int valord4 = 0)
    {
        n1 = valorn1;
        d1 = valord1;
        n2 = valorn1;
        d2 = valord2;
        n3 = valorn3;
        d3 = valord3;
        n4 = valorn4;
        d4 = valord4;
    }
    int main(int argc, char const *argv[])
    {
        cout << "======================================================" << endl;
        cout << "Ingrese el primer numerador " << endl;
        cin >> n1;
        cout << "Ingrese el primer denominador " << endl;
        cin >> d1;
        cout << "Ingrese el segundo numerador " << endl;
        cin >> n2;
        cout << "Ingrese el segundo numerador " << endl;
        cin >> d2;
        cout << "Ingrese el tercer numerador " << endl;
        cin >> n3;
        cout << "Ingrese el tercer numerador " << endl;
        cin >> d3;
        cout << "Ingrese el cuarto numerador " << endl;
        cin >> n4;
        cout << "Ingrese el cuarto numerador " << endl;
        cin >> d4;
        cout << "======================================================" << endl;
    }
    int minimoComunDenominador(Fraccion fraccion)
    {
        int mcDenominador;
        if (denominador == fraccion.denominador)
        {
            mcDenominador = denominador;
        }
        else
        {
            mcDenominador = denominador * fraccion.denominador;
        }
        return mcDenominador;
    }

    Fraccion sumar(Fraccion sumando)
    {
        int mcDenominador = minimoComunDenominador(sumando);
        int nuevoNum = (numerador * sumando.denominador) + (sumando.numerador * denominador);
        Fraccion rta = Fraccion(nuevoNum, mcDenominador);
        rta.simplificar();
        return rta;
    }
    Fraccion restar(Fraccion restando)
    {
        int mcDenominador = minimoComunDenominador(restando);
        int nuevoNum = (numerador * restando.denominador) + (restando.numerador * denominador);
        Fraccion rtaresta = Fraccion(nuevoNum, mcDenominador);
        rtaresta.simplificar();
        return rtaresta;
    }
    void simplificar()
    {
        int menor = abs(numerador);
        if (menor > abs(denominador))
        {
            menor = abs(denominador);
        }
        for (int i = menor; i >= 2; i--)
        {
            if ((numerador % i == 0) && (denominador % i == 0))
            {
                numerador = numerador / i;
                denominador = denominador / i;
            }
        }
    }
};