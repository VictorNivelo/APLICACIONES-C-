/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <math.h>
using namespace std;

class Fraccion
{
private:
    int numerador;
    int denominador;
    int entero;
    int fraccion1, fraccion2, fraccion3, fraccion4;

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
    int multiplicacionNumerador(Fraccion fraccion)
    {
        int mpNumerador;
        numerador.fraccion1 *numerador.fraccion2 *numerador.fraccion3 *numerador.fraccion4;
        return mpNumerador;
    }
    int multiplicacionDenominador(Fraccion fraccion)
    {
        int mpDenominador;
        denominador.fraccion1 *denominador.fraccion2 *denominador.fraccion3 *denominador.fraccion4;
        return mpDenominador;
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
        int nuevoNum = (numerador * restando.denominador) + (restando.numerador * denominador);
        Fraccion rtaresta = Fraccion(nuevoNum, mcDenominador);
        rtaresta.simplificar();
        return rtaresta;
    }
    Fraccion multiplicar(Fraccion multiplicando)
    {
        int mpNumerador = multiplicacionNumerador(multiplicando);
        int nuevoNum = (numerador * multiplicando.numerador);
        int nuevoNUm = (denominador * multiplicando.denominador);
        Fraccion rtamultiplicar = Fraccion(nuevoNum, mpNumerador);
        rtamultiplicar.simplificar();
        return rtamultiplicar;
    }
    Fraccion dividir(Fraccion dividiendo)
    {
        int int
            Fraccion rtadividir = Fraccion(nuevoNum, )
                                      rtadividir.simplificar();
        return rtadividir;
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
        Fraccion rta3 = rta2.restar(fraccion4);
        rtaresta.simplificar();
        return rta;
    }

    Fraccion multiplicar()
    {
        Fraccion rta1 = fraccion1.multiplicar(fraccion2);
        Fraccion rta2 = rta1.multiplicar(fraccion3);
        Fraccion rta3 = rta2.multiplicar(fraccion4);
        rtamultiplicar.simplificar();
        return rtamultiplicar;
    }

    Fraccion dividir()
    {
        Fraccion rta1 = fraccion1.dividir(fraccion2);
        Fraccion rta2 = rta1.dividir(fraccion3);
        Fraccion rta3 = rta2.dividir(fraccion4);
        rtadividir.simplificar();
        return rtadividir;
    }
};

int main(int argc, char const *argv[])
{
    Fraccion fraccion1 = Fraccion("%d, %d");
    Fraccion fraccion2 = Fraccion("%d, %d");
    Fraccion fraccion3 = Fraccion("%d, %d");
    Fraccion fraccion4 = Fraccion("%d, %d");

    // Fraccion rta1 = fraccion1.sumar(fraccion2);
    // Fraccion rta = rta1.sumar(fraccion3);
    // Fraccion rta = fraccion1.sumar(fraccion2).sumar(fraccion3);
    CalculadoraFraccion cf = CalculadoraFraccion(fraccion1, fraccion2, fraccion3, fraccion4);
    Fraccion rta = cf.sumar();

    Fraccion fracionMixta = rta.convertirAFraccionMixta();

    cout << fraccion1.toString() << " => " << fraccion1.aRepresentacionNumerica() << endl;
    cout << fraccion2.toString() << " => " << fraccion2.aRepresentacionNumerica() << endl;
    cout << fraccion3.toString() << " => " << fraccion3.aRepresentacionNumerica() << endl;
    cout << rta.toString() << " => " << rta.aRepresentacionNumerica() << endl;
    cout << fracionMixta.toString() << " => " << fracionMixta.aRepresentacionNumerica() << endl;

    return 0;
}
#include 4t.
ninclude - rtdib.h.NnrIu % ^co.h ^

    usng nwpace sd;
nt n()
{

    float nldlnZdZ

        cou c "Favor tngre5ar rtador l

        cin nl;

    cout c "Fauor ingrar deninador t
        cin dl;
    EOU cc "avor ngrar nad 2: '
        EOU cc "avor ngrar nad 2: '
        cin n2;
    dz
        cou c wFavor ingresar deninador z
            cin dz;

    ir dt.L = B,

       cou.

               .

           c((nl / dl) + (n2 / d2))

               els

           cou ta ldosi
           - ntre EO no.'void

             gstcrl()
