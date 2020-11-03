


/** \brief Es una funcion que codifica datos guardados en un archivo ".csv"

 * \param pFile FILE* Recibe un puntero de tipo "FILE" para poder interactuar con el archivo
 * \param pArrayListEmployee LinkedList* Recibe un puntero de tipo "LinkedList" que contiene el array de empleados (destino)
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion con exito o no
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);



/** \brief Es una funcion que codifica datos de un archivo binario y los convierte
 *
 * \param pFile FILE* Recibe un puntero de tipo "FILE" para poder interactuar con el archivo
 * \param pArrayListEmployee LinkedList* Recibe un puntero de tipo "LinkedList" que contiene el array de empleados (destino)
 * \return int Retorna una bandera que verifica si se pudo realizar la operacion con exito o no
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
