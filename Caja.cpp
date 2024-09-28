/*
 * @author Victor Nivelo
 * @brief
 * @version 0.1
 * @copyright Copyright (c) 2021
 */

#include <iostream>
#include <math.h>
using namespace std;

class caja
{
private:
   float largo;
   float ancho;
   float altura;

public:
   caja(float valorLargo = 1, float valorAncho = 1, float valorAltura = 1)
   {
      largo = valorLargo;
      ancho = valorAncho;
      altura = valorAltura;
   }

   caja Volumen(caja volumenCaja)
   {
      float cajaVolumen = ((largo * ancho) * altura);
      caja RespuestaVolumen = caja(cajaVolumen);
      return RespuestaVolumen;
   }

   caja areaTotalcaja(caja areaCaja)
   {
      float cajaArea = ((2 * (largo * ancho)) + (2 * (largo * ancho)) + (2 * (largo * ancho)));
      caja areaTotalcaja = caja(cajaArea);
      return areaTotalcaja;
   }

   caja Perimetro(caja perimetroCaja)
   {
      float cajaPerimetro = (ancho * altura) * 2;
      caja RespuestaPerimetroCaja = caja(cajaPerimetro);
      return RespuestaPerimetroCaja;
   }
   int main(int argc, char const *argv[])
   {
      cout << "---------------------------------------" << endl;
      cout << "Ingresar el largo de la caja: " << endl;
      scanf("%d", largo);
      cout << "Ingresar el largo de la caja: " << endl;
      scanf("%d", ancho);
      cout << "Ingresar el largo de la caja: " << endl;
      scanf("%d", altura);
      cout << "---------------------------------------" << endl;
      cout << "El volumen de la caja es: " << &Volumen << endl;
      cout << "El area de la caja es:  " << &areaTotalcaja << endl;
      cout << "El perimemtro de la caja es:  " << &Perimetro << endl;
      cout << "---------------------------------------" << endl;
   }
};