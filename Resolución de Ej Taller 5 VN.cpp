/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdio.h>
#include <iostream>
using namespace std;

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