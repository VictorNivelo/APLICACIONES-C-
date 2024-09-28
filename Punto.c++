/**
 * @file Punto.c++
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 * Distancia entre Dos puntos en un plano cartesiano
 */

#include <math.h>
#include <iostream>
using namespace std;

#define ZERO 0.000001;

class Punto
{

private:
    // Atributos --> Describir característica
    int x;
    int y;

public:
    // Construir objetos
    Punto(int valorX = 0, int valorY = 0)
    {
        // cout << "Construyendo objeto" << endl;
        x = valorX;
        y = valorY;
    }
    /*
    // Destructor
    ~Punto(){
        cout << "Destruyendo objeto" << endl;
    }
    */
    // Métodos ---> Comportamiento
    float distancia(Punto puntoFinal)
    {
        float distanciaPotencia = pow(puntoFinal.y - y, 2) + pow(puntoFinal.x - x, 2);
        return sqrt(distanciaPotencia);
    }

    float pendiente(Punto puntoFinal)
    {
        int numerador = puntoFinal.y - y;
        int denominador = puntoFinal.x - x;
        float m = ZERO;
        if (denominador != 0)
        {
            m = (float)numerador / (float)denominador;
        }
        return m;
    }

    float anguloInclinacion(Punto puntoFinal)
    {
        float valorPendiente = pendiente(puntoFinal);
        float angulo = atanf(valorPendiente * 180 / M_PI);
        return angulo;
    }

    string toString()
    {
        return "[" + to_string(x) + ", " + to_string(y) + "]";
    }
};

Punto ingresarPunto(string mensaje);

int main(int argc, char const *argv[])
{
    // Punto puntoA = Punto(5,3);
    // Punto puntoB = Punto (-8, 5);
    Punto puntoA = ingresarPunto("A");
    Punto puntoB = ingresarPunto("B");
    cout << "Punto A" << puntoA.toString() << endl;
    cout << "Punto B" << puntoB.toString() << endl;
    // cin
    float distanciaEntrePuntosAB = puntoA.distancia(puntoB);
    float pendienteEntrePuntosAB = puntoA.pendiente(puntoB);
    cout << "La distancia (A-B): " << puntoA.toString() << " --> " << puntoB.toString() << " = " << distanciaEntrePuntosAB << endl;
    cout << "La pendiente (A-B): " << puntoA.toString() << " --> " << puntoB.toString() << " = " << pendienteEntrePuntosAB << endl;

    cout << "======================================================" << endl;
    cout << "La distancia (B-A): " << puntoB.toString() << " --> " << puntoA.toString() << " = " << puntoB.distancia(puntoA) << endl;
    cout << "La pendiente (B-A): " << puntoB.toString() << " --> " << puntoA.toString() << " = " << puntoB.pendiente(puntoA) << endl;

    return 0;
}

Punto ingresarPunto(string mensaje)
{
    int x, y;
    cout << "Ingresando el punto " << mensaje << endl;
    cout << "Coordenadas (x,y): \n";
    cin >> x >> y;
    // Instanciar la clase Punto
    Punto punto = Punto(x, y);
    return punto;
}
