/**
 * @file OperacionesConFracciones.c++
 * @author Iván Alejandro González Ortega
 * @brief Operaciones básicas con 4 fracciones ingresadas por el usuario
 * @version 0.1
 * @date 2022-01-23
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define DEFAULT_CONSOLE_COLOR "\033[0m"
#define NEGRITA "\033[1m"
#define COLOR_LETRA_NEGRO "\033[30m"
#define COLOR_LETRA_GRIS_OSCURO "\033[90m"
#define COLOR_LETRA_ROJO "\033[31m"
#define COLOR_LETRA_CELESTE "\033[94m"
#define COLOR_LETRA_MAGENTA_CLARO "\033[95m"
#define COLOR_LETRA_CYAN "\033[36m"

class Fraccion
{
private:
    int numerador;
    int denominador;
    int entero;

    int minimoComunDenominador(Fraccion fraccion)
    {
        int mndenominador;
        if (denominador == fraccion.denominador)
        {
            mndenominador = denominador;
        }
        else
        {
            mndenominador = denominador * fraccion.denominador;
        }
        return mndenominador;
    }

public:
    Fraccion(int valorNum = 1, int valorDenom = 1, int valorEntero = 0)
    {
        entero = valorEntero;
        numerador = valorNum;
        denominador = valorDenom;
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
        int nuevoNum = (numerador * restando.denominador) - (restando.numerador * denominador);
        Fraccion rta = Fraccion(nuevoNum, mcDenominador);
        rta.simplificar();
        return rta;
    }

    Fraccion multiplicar(Fraccion multiplicando)
    {
        int nuevoNum = numerador * multiplicando.numerador;
        int nuevoDeno = denominador * multiplicando.denominador;
        Fraccion rta = Fraccion(nuevoNum, nuevoDeno);
        rta.simplificar();
        return rta;
    }

    Fraccion dividir(Fraccion dividiendo)
    {
        int nuevoNum = numerador * dividiendo.denominador;
        int nuevoDeno = denominador * dividiendo.numerador;
        Fraccion rta = Fraccion(nuevoNum, nuevoDeno);
        rta.simplificar();
        return rta;
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

    Fraccion simplificarANuevaFraccion()
    {
        Fraccion copia = Fraccion(numerador, denominador, entero);
        copia.simplificar();
        return copia;
    }

    int getNumerador()
    {
        return numerador;
    }

    void setNumerador(int nuevoValor)
    {
        numerador = nuevoValor;
    }

    int getDenominador()
    {
        return denominador;
    }

    void setDenominador(int nuevoValor)
    {
        denominador = nuevoValor;
    }

    string toString()
    {
        string resultado = "";
        if (entero != 0)
        {
            resultado = resultado + to_string(entero);
        }
        resultado = resultado + "[" + to_string(numerador) + " / " + to_string(denominador) + "]";
        return resultado;
    }

    float aRepresentacionNumerica()
    {
        int auxNumerador = numerador;
        if (entero != 0)
        {
            auxNumerador = (entero * denominador) + numerador;
        }
        return (float)auxNumerador / (float)denominador;
    }

    Fraccion convertirAFraccionMixta()
    {
        int parteEntera = entero;
        int resto = numerador;
        if (parteEntera == 0)
        {
            parteEntera = numerador / denominador;
            resto = numerador % denominador;
        }
        Fraccion copia = Fraccion(resto, denominador, parteEntera);
        return copia;
    }
};

class CalculadoraFraccion
{
private:
    Fraccion fraccion1;
    Fraccion fraccion2;
    Fraccion fraccion3;
    Fraccion fraccion4;

public:
    CalculadoraFraccion(Fraccion f1, Fraccion f2, Fraccion f3, Fraccion f4)
    {
        fraccion1 = f1;
        fraccion2 = f2;
        fraccion3 = f3;
        fraccion4 = f4;
    }

    Fraccion sumar()
    {
        Fraccion rta1 = fraccion1.sumar(fraccion2);
        Fraccion rta2 = rta1.sumar(fraccion3);
        Fraccion rta = rta2.sumar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Fraccion restar()
    {
        Fraccion rta1 = fraccion1.restar(fraccion2);
        Fraccion rta2 = rta1.restar(fraccion3);
        Fraccion rta = rta2.restar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Fraccion multiplicar()
    {
        Fraccion rta1 = fraccion1.multiplicar(fraccion2);
        Fraccion rta2 = rta1.multiplicar(fraccion3);
        Fraccion rta = rta2.multiplicar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Fraccion dividir()
    {
        Fraccion rta1 = fraccion1.dividir(fraccion2);
        Fraccion rta2 = rta1.dividir(fraccion3);
        Fraccion rta = rta2.dividir(fraccion4);
        rta.simplificar();
        return rta;
    }
};

Fraccion ingresarFraccion(string mensaje);

int main(int argc, char const *argv[])
{
    system("@cls||clear");
    Fraccion fraccion1 = ingresarFraccion("1");
    Fraccion fraccion2 = ingresarFraccion("2");
    Fraccion fraccion3 = ingresarFraccion("3");
    Fraccion fraccion4 = ingresarFraccion("4");
    system("@cls||clear");

    CalculadoraFraccion cf = CalculadoraFraccion(fraccion1, fraccion2, fraccion3, fraccion4);
    Fraccion rtaSuma = cf.sumar();
    Fraccion fracionMixtaSuma = rtaSuma.convertirAFraccionMixta();

    Fraccion rtaResta = cf.restar();
    Fraccion fraccionMixtaResta = rtaResta.convertirAFraccionMixta();

    Fraccion rtaMultiplicacion = cf.multiplicar();
    Fraccion fraccionMixtaMultiplicacion = rtaMultiplicacion.convertirAFraccionMixta();

    Fraccion rtaDivision = cf.dividir();
    Fraccion fraccionMixtaDivision = rtaDivision.convertirAFraccionMixta();

    cout << COLOR_LETRA_NEGRO << NEGRITA;
    cout << "****************************************************************************" << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "============================================================================" << endl;
    cout << COLOR_LETRA_ROJO;
    cout << "\t\t\tFracciones Ingresadas" << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << COLOR_LETRA_MAGENTA_CLARO;
    cout << "Primera fraccion: " << fraccion1.toString() << " => Respresentacion Decimal =>  " << fraccion1.aRepresentacionNumerica() << endl;
    cout << "Segunda fraccion: " << fraccion2.toString() << " => Respresentacion Decimal => " << fraccion2.aRepresentacionNumerica() << endl;
    cout << "Tercera fraccion: " << fraccion3.toString() << " => Representacion Decimal => " << fraccion3.aRepresentacionNumerica() << endl;
    cout << "Cuarta fraccion: " << fraccion4.toString() << " => Representacion Decimal => " << fraccion4.aRepresentacionNumerica() << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "============================================================================" << endl;
    cout << COLOR_LETRA_CELESTE;
    cout << "Suma de las Fracciones => " << rtaSuma.toString() << endl;
    cout << "Representacion decimal => " << rtaSuma.aRepresentacionNumerica() << endl;
    cout << "Representacin Mixta => " << fracionMixtaSuma.toString() << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "============================================================================" << endl;
    cout << COLOR_LETRA_CYAN;
    cout << "Resta de las Fracciones => " << rtaResta.toString() << endl;
    cout << "Representacion decimal => " << rtaResta.aRepresentacionNumerica() << endl;
    cout << "Representacion Mixta => " << fraccionMixtaResta.toString() << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "============================================================================" << endl;
    cout << COLOR_LETRA_CELESTE;
    cout << "Multiplicacion de las Fracciones => " << rtaMultiplicacion.toString() << endl;
    cout << "Representacion decimal => " << rtaMultiplicacion.aRepresentacionNumerica() << endl;
    cout << "Representacion Mixta => " << fraccionMixtaMultiplicacion.toString() << endl;
    cout << COLOR_LETRA_GRIS_OSCURO;
    cout << "============================================================================" << endl;
    cout << COLOR_LETRA_CYAN;
    cout << "Division de las Fracciones => " << rtaDivision.toString() << endl;
    cout << "Representacion decimal => " << rtaDivision.aRepresentacionNumerica() << endl;
    cout << "Representacion Mixta => " << fraccionMixtaDivision.toString() << endl;
    cout << COLOR_LETRA_NEGRO;
    cout << "****************************************************************************" << endl;
    cout << COLOR_LETRA_ROJO;
    cout << "\t\tGracias por usar nuestro programa!" << endl;
    cout << "\t\tAutor: Ivan Alejandro Gonzalez Ortega" << endl;
    cout << COLOR_LETRA_NEGRO;
    cout << "****************************************************************************" << endl;
    return 0;
}

Fraccion ingresarFraccion(string mensaje)
{
    int num, den;
    cout << "Ingrese la fraccion " << mensaje << "en la forma (#/#): ";
    scanf("%d/%d", &num, &den);
    Fraccion fraccion = Fraccion(num, den);
    return fraccion;
}