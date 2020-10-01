#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Es el menu de opciones principal.
 *
 * \return int Retorna un valor entero que el usuario ingrese.
 *
 */
int menu();

/** \brief  Es el menu que contiene las opciones de modificar un empleado.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \param id int Recibe el ID para hacer una comparacion.
 * \return int Retorna un valor entero que el usuario ingrese.
 *
 */
int modifyAnEmployeeMenu(sEmployee list[], int len, int id);

/** \brief Es el menu que contiene las opciones de ordenar el listado de empleados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int recibe el tamaño del array para poder iterar.
 * \return int Retorna un valor entero que el usuario ingrese.
 *
 */
int sortMenu(sEmployee list[], int len);

#endif // MENU_H_INCLUDED
