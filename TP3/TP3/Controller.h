/** \brief Es una funcion que controla la carga de datos de un archivo ".csv"
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Destino
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);



/** \brief Es una funcion que controla la carga de datos de un archivo ".bin" o ".dat"
 *
 * \param path char* Nombre del archivo
 * \param pArrayListEmployee LinkedList* Destino
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Es una funcion que controla la carga de un empleado a la Linked List
 *
 * \param pArrayListEmployee LinkedList* Array donde esta almacenado el empleado
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);



/** \brief Es una funcion que controla poder editar un empleado de la linked list
 *
 * \param pArrayListEmployee LinkedList* Array donde esta almacenado el empleado
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);



/** \brief Funcion que controla la remocion de un empleado de la Linked List
 *
 * \param pArrayListEmployee LinkedList* Array donde esta almacenado el empleado a eliminar
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);



/** \brief Funcion que controla mostrar el listado de los empleados que contenga la linked list
 *
 * \param pArrayListEmployee LinkedList* Array donde estan almacenado los empleados
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);



/** \brief Funcion que controla los criterios de ordenamiento para posteriormente ser mostrados
 *
 * \param pArrayListEmployee LinkedList* Array donde estan almacenados los empleados
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);



/** \brief Funcion que controla el guardado de la Linked List en formato "csv"
 *
 * \param path char* Nombre de el archivo destino
 * \param pArrayListEmployee LinkedList* Linked List a guardar
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);



/** \brief Es una funcion que controla el guardado de la Linked List en formato binario
 *
 * \param path char* Nombre del archivo destino
 * \param pArrayListEmployee LinkedList* Nombre de la Linked List a guardar
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



/** \brief Es una funcion que busca el indice de un empleado basandose en el ID del mismo
 *
 * \param pArrayListEmployee LinkedList* Linked List que contiene el empleado
 * \param id int Id del empleado en cuestion
 * \return int Retorna el indice donde se encuentra el ID del empleado
 *
 */
int controller_buscarIndicePorId(LinkedList* pArrayListEmployee, int id);

