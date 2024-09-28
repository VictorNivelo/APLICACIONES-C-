/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define ZERO 0.000001;

// INICIO MODELO
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

class Triangulo
{
private:
    /* data */
    Punto A;
    Punto B;
    Punto C;

public:
    Triangulo(Punto punto1, Punto punto2, Punto punto3)
    {
        A = punto1;
        B = punto2;
        C = punto3;
    }

    // getters --> acceder (leer) los atributos
    // seeters --> fijar nuevos valores a los atributos
    Punto getA()
    {
        return A;
    }

    void setA(Punto nuevoValor)
    {
        A = nuevoValor;
    }

    Punto getB()
    {
        return B;
    }

    Punto getC()
    {
        return C;
    }

    int getLadoAB()
    {
        int distancia = A.distancia(B);
        return distancia;
    }

    int getLadoBC()
    {
        int distancia = B.distancia(C);
        return distancia;
    }

    int getLadoCA()
    {
        int distancia = C.distancia(A);
        return distancia;
    }

    int perimetro()
    {
        int p = getLadoAB() + getLadoBC() + getLadoCA();
        return p;
    }

    string toString()
    {
        return "A" + A.toString() + "--> B" + B.toString() + "--> C" + C.toString();
    }
};

// FIN MODELO

// VISTA

Triangulo ingresarTringulo();
Punto ingresarPunto(string mensaje);

int main(int argc, char const *argv[])
{
    system("@cls||clear");
    Triangulo triangulo = ingresarTringulo();

    // Punto modificadoA = Punto(10,7);
    // triangulo.setA(modificadoA);

    int perimetro = triangulo.perimetro();

    cout << endl
         << endl;
    cout << "Ud. ingreso el triangulo cuyos puntos son: " << endl;
    cout << triangulo.toString() << endl;
    cout << "A: " << triangulo.getA().toString() << endl;
    cout << "B: " << triangulo.getB().toString() << endl;
    cout << "C: " << triangulo.getC().toString() << endl;
    cout << "Lado AB: " << triangulo.getLadoAB() << endl;
    cout << "Lado BC: " << triangulo.getLadoBC() << endl;
    cout << "Lado CA: " << triangulo.getLadoCA() << endl;
    cout << "Perimetro del triangulo: " << perimetro << endl;
    return 0;
}

// CONTROLADOR
Triangulo ingresarTringulo()
{
    cout << "======================================================" << endl;
    cout << "INGRESE LOS PUNTOS DEL TRIANGULO EN EL PLANO CARTESIANO" << endl;
    Punto puntoA = ingresarPunto("A");
    Punto puntoB = ingresarPunto("B");
    Punto puntoC = ingresarPunto("C");
    Triangulo t = Triangulo(puntoA, puntoB, puntoC);
    return t;
}

Punto ingresarPunto(string mensaje)
{
    int x, y;
    cout << "Ingresando el punto " << mensaje << endl;
    cout << "Coordenadas (x,y): \n";
    scanf("%d,%d", &x, &y);
    // Instanciar la clase Punto
    Punto punto = Punto(x, y);
    return punto;
}
