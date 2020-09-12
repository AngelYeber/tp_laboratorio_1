#include "archivo.h"
#include <stdlib.h>
#include <stdio.h>

char menu()
{
    char valorDeRetorno;

    printf("\tBienvenido\n1.Ingrese el primer operando\n2.Ingrese el segundo operando\n3.Calcular todas las operaciones\n4.Mostrar todos los resultados\n5.Salir.\nQue desea realizar ");

    scanf("%c",&valorDeRetorno);

    return valorDeRetorno;

}

float getFloat(float numero)
{

    printf("\nIngrese un numero: ");
    scanf("%f",&numero);

    return numero;
}

float suma(float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno + numeroDos;

    return resultado;
}

float resta(float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno - numeroDos;

    return resultado;
}

float multiplicacion(float numeroUno, float numeroDos)
{
    float resultado;

    resultado = numeroUno * numeroDos;

    return resultado;

}

float division(float numeroUno, float numeroDos)
{
    float resultado;

    if(numeroUno == 0 || numeroDos == 0)
    {
        printf("\nNo es posible dividir por 0 (cero)");
    }
    else
    {
        resultado = numeroUno / numeroDos;
    }

    return resultado;

}

long int factorial(float num)
{

  long int factorial;
  int i;

  factorial = 1;
    if(num<0)
    {
        factorial = printf("No se posible calcular el factorial de un numero negativo.");
    }

    for (i = num; i > 0; i--)
    {
        factorial = factorial * i;
    }

  return factorial;

}



