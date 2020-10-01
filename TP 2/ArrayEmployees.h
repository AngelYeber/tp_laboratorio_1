#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}sEmployee;


/** \brief Agrega un empleado de tipo "sEmployee".
 *
 * \param void No recibe ningun valor por parametro.
 * \return sEmployee Retorna una variable de tipo "sEmployee" cargada con datos ingresados por el usuario.
 *
 */
sEmployee addEmployee(void);

/** \brief Imprime a un empleado con todos sus parametros.
 *
 * \param sEmployee Recibe una variable de tipo "sEmployee".
 * \return void No retorna nada.
 *
 */
void printEmployee(sEmployee);

/** \brief Inicializa a un array de tipo "sEmployee" poniendo los parametros en valores nulos.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return void No retorna nada.
 *
 */
void initEmployees(sEmployee list[], int len);

/** \brief Imprime un listado de todos los empleados cargados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return void No retorna nada.
 *
 */
void printAllEmployees(sEmployee list[], int len);

/** \brief Busca un empleado por el ID.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \param id int Recibe el ID del empleado para hacer una comparacion.
 * \return int Retorna el indice del empleado si es que hay, en caso de no haber retorna -1.
 *
 */
int findEmployeeById(sEmployee list[], int len, int id);

/** \brief Realiza una baja logica de un empleado poniendo el atributo "isEmpty" de la estructura en 1(verdadero).
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \param id int Recibe el ID del empleado para hacer una comparacion.
 * \return int Retorna una bandera (1) si se pudo realizar la baja (-1) si no se pudo realizar la baja.
 *
 */
int removeAnEmployee(sEmployee list[], int len, int id);

/** \brief Modifica atributos de un empleado.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \param id int Recibe el ID del empleado para poder hacer una comparacion.
 * \return void No retorna nada.
 *
 */
void modifyAnEmployee(sEmployee list[], int len, int id);

/** \brief Carga un listado de empleados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int el tamaño del array para poder iterar.
 * \return int Retorna una bandera (1) si se pudo realizar la carga exitosamente. (-1) si no se pudo.
 *
 */
int loadListEmployees(sEmployee list[],int len);

/** \brief Es una funcion que busca espacio libre dentro de un array de tipo "sEmployee".
 *
 * \param list[] sEmployee  Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return int Retorna una bandera (1) si encontro lugar. (-1) si no encontro lugar.
 *
 */
int isEmpty(sEmployee list[], int len);

/** \brief Ordena el listado de empleados cargados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return void No retorna nada.
 *
 */
void sortEmployees(sEmployee list[], int len);

/** \brief Es una funcion que suma todos los sueldos del listado de empleados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return float Retorna el resultado de la suma de todos los sueldos.
 *
 */
float allSalaries(sEmployee list[], int len);

/** \brief Es una funcion que calcula el promedio entre todos los salarios de los empleados.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return int Retorna el promedio de todos los sueldos.
 *
 */
int totalSalariesAverage(sEmployee list[], int len);

/** \brief Es una funcion que calcula los empleados que superan el salario promedio y los muestra.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return int Retorna una bandera (1) si hay por lo menos una persona que supere el salario promedio. (-1) si no lo hay.
 *
 */
int EmployeesWhoExceedTheSalaryAverage(sEmployee list[], int len);

/** \brief Busca en el listado que al menos haya 1 empleado cargado.
 *
 * \param list[] sEmployee Recibe un array de tipo "sEmployee".
 * \param len int Recibe el tamaño del array para poder iterar.
 * \return int Retorna una bandera (1) si se encontro una persona cargada. (-1) si no hay personas cargadas.
 *
 */
int searchEmployee(sEmployee list[], int len);

/** \brief Es una funcion que contiene las funciones principales del programa
 *
 * \param list[] sEmployee
 * \param len int
 * \return void
 *
 */
void mainFunctionality(sEmployee list[], int len);

#endif // ARRAYEMPLOYEES_H_INCLUDED
