#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"

int menu()
{
    int answer;

    printf("\t*** Bienvenide ***\n1.Cargar un empleado.\n2.Modificar un empleado.\n3.Eliminar un empleado.\n4.Mostrar todos los empleados.\n5.Salir.\n");
    scanf("%d",&answer);

    return answer;
}

int modifyAnEmployeeMenu(sEmployee list[], int len, int id)
{
    int ans=0;
    int i;
    printf("\t*** Modificar un empleado ***\n");
    printf("%3s %8s %6s %8s %6s", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");

    for(i=0;i<len;i++)
    {
        if(list[i].id == id && list[i].isEmpty != 1)
        {
            printEmployee(list[i]);
        }
    }

    printf("\nQue desea modificar\n1.Nombre\n2.Apellido.\n3.Salario.\n4.Sector.\n5.Salir\n\nrespuesta: ");
    fflush(stdin);
    scanf("%d",&ans);

    return ans;
}

int sortMenu(sEmployee list[], int len)
{
    int returnValue;

    printf("\t**** Bienvenide ****\n1.Mostrar el listado de los empleados.\n2.Ordenar listado por apellido y sector.\n3.Total y promedio de los salarios.\n4.Empleados que superan el salario promedio.\n5.Salir\n");
    fflush(stdin);
    scanf("%d",&returnValue);

    return returnValue;
}
