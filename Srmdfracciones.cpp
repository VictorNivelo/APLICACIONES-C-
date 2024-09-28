/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

class Srmdfracciones
{
private:
    int numerador;
    int denominador;
    int entero;

    int minimocomundenominador(Srmdfracciones fraccion)
    {
        int mumerodenominador;
        if (denominador == fraccion.denominador)
        {
            mumerodenominador = denominador;
        }
        else
        {
            mumerodenominador = denominador * fraccion.denominador;
        }
        return mumerodenominador;
    }

public:
    Srmdfracciones(int numevalor = 1, int denovalor = 1, int enterovalor = 0)
    {
        entero = enterovalor;
        numerador = numevalor;
        denominador = denovalor;
    }

    Srmdfracciones sumar(Srmdfracciones sumando)
    {
        int minimodenominador = minimocomundenominador(sumando);
        int numeronuevo = (numerador * sumando.denominador) + (sumando.numerador * denominador);
        Srmdfracciones respuesta = Srmdfracciones(numeronuevo, minimodenominador);
        respuesta.simplificar();
        return respuesta;
    }

    Srmdfracciones restar(Srmdfracciones restando)
    {
        int minimodenominador = minimocomundenominador(restando);
        int numeronuevo = (numerador * restando.denominador) + (restando.numerador * denominador);
        Srmdfracciones respuesta = Srmdfracciones(numeronuevo, minimodenominador);
        respuesta.simplificar();
        return respuesta;
    }

    Srmdfracciones multiplicar(Srmdfracciones multiplicar)
    {
        int minimodenominador = minimocomundenominador(multiplicar);
        int numeronuevo = (numerador * multiplicar.denominador) + (multiplicar.numerador * denominador);
        Srmdfracciones respuesta = Srmdfracciones(numeronuevo, minimodenominador);
        respuesta.simplificar();
        return respuesta;
    }

    Srmdfracciones dividir(Srmdfracciones dividir)
    {
        int minimodenominador = minimocomundenominador(dividir);
        int numeronuevo = (numerador * dividir.denominador) + (dividir.numerador * denominador);
        Srmdfracciones respuesta = Srmdfracciones(numeronuevo, minimodenominador);
        respuesta.simplificar();
        return respuesta;
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
    Srmdfracciones simplificarnuevafracion()
    {
        Srmdfracciones copia = Srmdfracciones(numerador, denominador, entero);
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
    toString toString()
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
        int numeradoraux = numerador;
        if (entero != 0)
        {
            numeradoraux = (entero * denominador) + numerador;
        }
        return (float)numeradoraux / (float)denominador;
    }
    Srmdfracciones convertirafraccionmixta()
    {
        int Enteraparte = entero;
        int resto = numerador;
        if (Enteraparte == 0)
        {
            Enteraparte = numerador / denominador;
            resto = numerador % denominador;
        }
        Srmdfracciones copia = Srmdfracciones(resto, denominador, Enteraparte);
        return copia;
    }
};

class Calculadorafraccion
{
private:
    Srmdfracciones fraccion1;
    Srmdfracciones fraccion2;
    Srmdfracciones fraccion3;
    Srmdfracciones fraccion4;

public:
    Calculadorafraccion(Srmdfracciones f1, Srmdfracciones f2, Srmdfracciones f3, Srmdfracciones f4)
    {
        fraccion1 = f1;
        fraccion2 = f2;
        fraccion3 = f3;
        fraccion4 = f4;
    }
    Srmdfracciones sumar()
    {
        Srmdfracciones rta1 = fraccion1.sumar(fraccion2);
        Srmdfracciones rta2 = rta1.sumar(fraccion3);
        Srmdfracciones rta = rta2.sumar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Srmdfracciones restar()
    {
        Srmdfracciones rta1 = fraccion1.restar(fraccion2);
        Srmdfracciones rta2 = rta1.restar(fraccion3);
        Srmdfracciones rta = rta2.restar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Srmdfracciones multiplicar()
    {
        Srmdfracciones rta1 = fraccion1.multiplicar(fraccion2);
        Srmdfracciones rta2 = rta1.multiplicar(fraccion3);
        Srmdfracciones rta = rta2.multiplicar(fraccion4);
        rta.simplificar();
        return rta;
    }

    Srmdfracciones dividir()
    {
        Srmdfracciones rta1 = fraccion1.dividir(fraccion2);
        Srmdfracciones rta2 = rta1.dividir(fraccion3);
        Srmdfracciones rta = rta2.dividir(fraccion4);
        rta.simplificar();
        return rta;
    }
}

int
main(int argc, char const *argv[])
{
    cout << "======================================================" << endl;
    cout << "INGRESE LOS PUNTOS DEL TRIANGULO EN EL PLANO CARTESIANO" << endl;
    Srmdfracciones fraccion1 = fraccion("%d,%d,%d,%d,&fraccion1");
    Srmdfracciones fraccion2 = fraccion("%d,%d,%d,%d,&fraccion2");
    Srmdfracciones fraccion3 = fraccion("%d,%d,%d,%d,&fraccion3");
    Srmdfracciones fraccion4 = fraccion("%d,%d,%d,%d,&fraccion4");
    Calculadorafraccion cf = fraccion(fraccion1, fraccion2, fraccion3, fraccion4);
    Srmdfracciones rta = cf.sumar();
    cout << "======================================================" << endl;

    Srmdfracciones fracionmixta = rta.convertirafraccionmixta()
    {
        cout << fraccion1.toString() << " => " << fraccion1.aRepresentacionNumerica() << endl;
        cout << fraccion2.toString() << " => " << fraccion2.aRepresentacionNumerica() << endl;
        cout << fraccion3.toString() << " => " << fraccion3.aRepresentacionNumerica() << endl;
        cout << fraccion4.toString() << " => " << fraccion4.aRepresentacionNumerica() << endl;
        cout << rta.toString() << " => " << rta.aRepresentacionNumerica() << endl;
        cout << fracionmixta.toString() << " => " << fracionmixta.aRepresentacionNumerica() << endl;

        return 0;
    };
}
