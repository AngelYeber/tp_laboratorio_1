#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Es una funcion que crea un espacio en el heap para un empleado por malloc
 *
 * \return Employee*
 *
 */
Employee* employee_new();



/** \brief Funcion que carga un empleado con cadena de caracteres para su posterior guardado
 *
 * \param idStr char* ID del empleado
 * \param nombreStr char* Nombre del empleado
 * \param horasTrabajadasStr char* Horas trabajadas del empeado
 * \param sueldoStr char* Sueldo del empleado
 * \return Employee* Retorna un puntero de tipo estructura
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);



/** \brief Es un setter que asigna el atributo "ID" a un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param id int Recibe el id para asignarlo al empleado
 * \return int retorna una bandera que verifica si se pudo realizar la operacion o no
 *
 */
int employee_setId(Employee* this,int id);



/** \brief Es un getter que obtiene el valor del atributo ID de un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param id int* Recibe un puntero de tipo entero que contiene la direccion de memoria del atributo ID del empleado
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion o no
 *
 */
int employee_getId(Employee* this,int* id);




/** \brief Es un setter que asigna el atributo "Nombre" a un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param nombre char* Recibe un puntero de tipo char que contiene la direccion de memoria donde va a ser guardado el nombre del empleado
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion con exito o no
 *
 */
int employee_setNombre(Employee* this,char* nombre);



/** \brief Es un getter que obtiene el valor del atributo "Nombre" a un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param nombre char* Recibe un puntero a char que contiene la direccion de memoria donde se obtiene el atributo "Nombre" del empleado
 * \return int Retorna una bandera que verifica si al operacion se pudo realizar con exito o no
 *
 */
int employee_getNombre(Employee* this,char* nombre);




/** \brief Es un setter que asigna un valor al atributo "HorasTrabajadas" a un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param horasTrabajadas int Recibe una variable de tipo entero donde se va a almacenar las horas trabajadas del empleado
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion con exito o no
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);



/** \brief Es un getter que obtiene el valor del atributo "HorasTrabajadas" de un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param horasTrabajadas int* Recibe un puntero de tipo int donde se obtiene el valor guardado en el atributo "HorasTrabajadas" del empleado
 * \return int Retorna una bandera que verifica si se pudo reallizar la opercaion con exito o no
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);




/** \brief Es un setter que asigna un valor al atributo "sueldo" a un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param sueldo int Recibe una variable de tipo int que contiene el valor a asignar en "sueldo"
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion con exito o no
 *
 */
int employee_setSueldo(Employee* this,int sueldo);



/** \brief Es un getter que obtiene el valor del atributo "sueldo" de un empleado
 *
 * \param this Employee* Recibe un puntero de tipo "Employee" (un empleado)
 * \param sueldo int* Recibe un puntero de tipo int que contiene el valor almacenado en el atributo "sueldo" del empleado
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion o no
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);


/** \brief Es un comparador que se fija la diferencia entre los valores de los nombres
 *
 * \param e1 Employee* Es el primer empleado a comparar
 * \param e2 Employee* Es el segundo empleado a comparar
 * \return int Devuelve el valor determinado por la comparacion
 *
 */
int employee_CompareByName(void* e1, void* e2);

/** \brief Es un comparador que se fija la diferencia entre los valores de los id's
 *
 * \param e1 Employee* Es el primer empleado a comparar
 * \param e2 Employee* Es el segundo empleado a comparar
 * \return int Devuelve el valor determinado por la comparacion
 *
 */
int employee_CompareById(void* e1, void* e2);

#endif // employee_H_INCLUDED
