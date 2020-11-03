#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int menuSortEmployee()
{
    int ans;

    printf("\t*** Menu de ordenamiento ***\n");
    printf("1.Ordenar por nombre de la A-Z\n2.Ordenar por nombre de la Z-A\n3.Ordenar por ID de menor a mayor\n4.Ordenar por ID de mayor a menor\n5.Salir\n");
    scanf("%d",&ans);


    return ans;
}



int menuEditAnEmployee()
{
    int respuesta;

    printf("\t*** Menu modificar ***\n");

    printf("\n1.Modificar el nombre\n2.Modificar horas trabajadas\n3.Modificar sueldo\n4.Salir\nQue desea modificar: ");
    fflush(stdin);
    scanf("%d",&respuesta);



    return respuesta;
}

int mainMenu()
{
    int respuesta;

    printf("\t**** Bienvenido ***\n");
    printf("\n1.Cargar los datos de los empleados desde el archivo data.csv\n2.Cargar los datos de los empleados desde el archivo data.dat\n3.Alta de empleado\n4.Modificar datos de empleado\n5.Baja de empleado\n6.Listar empleados\n7.Ordenar empleados\n8.Guardar los datos de los empleados en el archivo data.csv\n9.Guardar los datos de los empleados en el archivo data.dat\n10.Salir\n");
    fflush(stdin);
    scanf("%d", &respuesta);

    return respuesta;
}






