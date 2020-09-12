#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED


/** \brief Es un menu de opciones que consta de 5 opciones
 *
 * \return char
 *
 */
char menu();


/** \brief Es una función que permite el ingreso de un numero de tipo 'float'.
 *
 * \param float Pide el ingreso de un número y se lo toma como operando.
 * \return float Retorna el mismo número.
 *
 */
float getFloat(float);


/** \brief Es una función para realizar una suma entre dos numeros.
 *
 * \param numeroUno float  Pide el ingreso del primer operando.
 * \param numeroDos float  Pide el ingreso del segundo operando.
 * \return float Retorna el valor obtenido de la suma entre ambos operandos.
 *
 */
float suma(float numeroUno, float numeroDos);


/** \brief Es una función para realizar una resta entre dos numeros
 *
 * \param numeroUno float Pide el ingreso del primer operando.
 * \param numeroDos float Pide el ingreso del segundo operando.
 * \return float Retorna el valor obtenido de la resta entre ambos operandos.
 *
 */
float resta(float numeroUno, float numeroDos);


/** \brief  Es una función para realizar una division entre dos numeros.
 *
 * \param numeroUno float Pide el ingreso del primer operando.
 * \param numeroDos float Pide el ingreso del segundo operando.
 * \return float Retorna el valor obtenido de la división entre ambos operandos.
 *
 */
float division(float numeroUno, float numeroDos);

/** \brief  Es una función para realizar una multiplicación entre dos numeros.
 *
 * \param numeroUno float Pide el ingreso del primer operando.
 * \param numeroDos float Pide el ingreso del segundo operando.
 * \return float Retorna el valor obtenido de la multiplicación entre ambos operandos.
 *
 */
float multiplicacion(float numeroUno, float numeroDos);

/** \brief  Es una función para obtener el valor factorial de un número.
 *
 * \param numero float Pide el ingreso de un numero.
 * \return long long int Retorna el valor del factorial del número ingresado.
 *
 */
long int factorial(float numero);


#endif // ARCHIVO_H_INCLUDED
