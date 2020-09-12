#include <stdio.h>
#include <stdlib.h>
#include "archivo.h"


int main()
{
   float numeroUno;
   float numeroDos;
   float resultadoSuma;
   float resultadoResta;
   float resultadoMultiplicacion;
   float resultadoDivision;
   long int resultadoFactorialUno;
   long int resultadoFactorialDos;
   int flagUno;
   int flagDos;
   int flagTres;

   char opcion;

   flagUno = 0;
   flagDos = 0;
   flagTres = 0;



   do
   {

        opcion = menu();

        switch(opcion)
        {
            case '1':
                numeroUno = getFloat(numeroUno);
                flagUno = 1;
                break;
            case '2':
                numeroDos = getFloat(numeroDos);
                flagDos = 1;
                break;
            case '3':
                if(flagUno == 0)
                {
                    printf("\nTenes que agregar el primer operando.\n");
                    system("pause");

                }
                else if(flagDos == 0)
                {
                    printf("\nTenes que agregar el segundo operando.\n");
                    system("pause");
                }
                else
                {

                    resultadoSuma = suma(numeroUno, numeroDos);
                    resultadoResta = resta(numeroUno, numeroDos);
                    resultadoMultiplicacion = multiplicacion(numeroUno, numeroDos);
                    resultadoDivision = division(numeroUno, numeroDos);
                    resultadoFactorialUno = factorial(numeroUno);
                    resultadoFactorialDos = factorial(numeroDos);
                    printf("\nCalculando...\n\n");
                    system("pause");
                    flagTres = 1;
                }
                break;
            case '4':
                if(flagTres == 0)
                {
                    printf("\nTenes que cargar los dos operandos antes de calcular.\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl resultado de %2.f + %2.f es: %f", numeroUno, numeroDos, resultadoSuma);
                    printf("\nEl resultado de %2.f - %2.f es: %f", numeroUno, numeroDos, resultadoResta);
                    printf("\nEl resultado de %2.f * %2.f es: %f", numeroUno, numeroDos, resultadoMultiplicacion);
                    printf("\nEl resultado de %2.f / %2.f es: %f", numeroUno, numeroDos, resultadoDivision);
                    printf("\nEl resultado del factorial de %2.f es %ld y el resultado del factorial de %2.f es %ld\n", numeroUno
                                                                                                                      ,resultadoFactorialUno
                                                                                                                      ,numeroDos
                                                                                                                      ,resultadoFactorialDos);
                    system("pause");
                }

                break;
            case '5':
                printf("\nMuchas gracias!\n\n");
                system("pause");
                break;

        }


        system("cls");



   }while(opcion != '5');


    return 0;
}


