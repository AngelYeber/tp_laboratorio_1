#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;


    pFile = fopen(path, "r");
    parser_EmployeeFromText(pFile, pArrayListEmployee);

    if(pFile == NULL)
    {
        printf("\nNo existe el archivo\n");
    }
    fclose(pFile);

    return 1;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        parser_EmployeeFromBinary(pFile, pArrayListEmployee);
    }
    else
    {
        printf("\nNo existe el archivo\n");
    }
     fclose(pFile);

    return 1;;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    Employee* anEmployee = NULL;
    int i;
    int len;
    int intId;
    char id[21];
    char nombre[51];
    char sueldo[21];
    char horasTrabajadas[21];

    len = ll_len(pArrayListEmployee);

    for(i=0;i<len;i++)
    {
        if(pArrayListEmployee != NULL)
        {
            intId = len+1;
            employee_setId(anEmployee, intId);

            itoa(intId, id, 10);

            printf("\nIngrese el nombre del nuevo empleado: ");
            fflush(stdin);
            scanf("%[^\n]", nombre);

            printf("\nIngrese las horas trabajadas del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", horasTrabajadas);

            printf("\nIngrese el sueldo del empleado: ");
            fflush(stdin);
            scanf("%[^\n]", sueldo);

        }

        anEmployee = employee_newParametros(id, nombre,  horasTrabajadas, sueldo);
        ll_add(pArrayListEmployee, anEmployee);

        break;
    }


    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* anEmployee = NULL;
    int id;
    int ansMenu;
    char ansWhile;
    char nombre[21];
    int sueldo;
    int horasTrabajadas;
    char auxNombre[21];
    int auxSueldo=0;
    int auxHorasTrabajadas;
    char ansNombre;
    char ansSueldo;
    char ansHorasTrabajadas;
    int index;


    controller_ListEmployee(pArrayListEmployee);


    printf("\nIngrese el ID del empleado que desea modificar: ");
    fflush(stdin);
    scanf("%d",&id);

    index = controller_buscarIndicePorId(pArrayListEmployee, id);

    if(index != -1)
    {
        anEmployee = (Employee*)ll_get(pArrayListEmployee, index);

        employee_getNombre(anEmployee, nombre);
        employee_getSueldo(anEmployee, &sueldo);
        employee_getHorasTrabajadas(anEmployee, &horasTrabajadas);
    }

    if(anEmployee != NULL )
    {
        do
        {
            system("cls");
            printf("\n\t   %s %d %d\n\n", nombre, horasTrabajadas, sueldo);
            ansMenu = menuEditAnEmployee();

            switch(ansMenu)
            {

                case 1:
                    system("cls");
                    printf("\nIngrese el nuevo nombre: ");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);

                    printf("\nEstas seguro de querer modificar el nombre de %s a %s?(s/n):", nombre, auxNombre);
                    fflush(stdin);
                    scanf("%c",&ansNombre);

                    if(ansNombre == 's')
                    {
                        employee_setNombre(anEmployee, auxNombre);
                        printf("\nSe ha modificado el nombre exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se ha modificado el nombre.\n");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("\nIngrese las nuevas horas trabajadas: ");
                    fflush(stdin);
                    scanf("%d",&auxHorasTrabajadas);

                    printf("\nEstas seguro de modificar las horas trabajadas de %d a %d?(s/n):", horasTrabajadas, auxHorasTrabajadas);
                    fflush(stdin);
                    scanf("%c",&ansHorasTrabajadas);

                    if(ansNombre == 's')
                    {
                        employee_setHorasTrabajadas(anEmployee, auxHorasTrabajadas);
                        printf("\nSe han modificado las horas exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se han modificado las horas trabajadas.\n");
                    }
                    break;
                case 3:
                    system("cls");
                    printf("\nIngrese el nuevo sueldo: ");
                    fflush(stdin);
                    scanf("%d",&sueldo);

                    printf("\nEstas seguro de querer modificar el sueldo de %d a %d?(s/n):", sueldo, auxSueldo);
                    fflush(stdin);
                    scanf("%c",&ansSueldo);

                    if(ansSueldo == 's')
                    {
                        employee_setSueldo(anEmployee, auxSueldo);
                        printf("\nSe ha modificado el sueldo exitosamente!\n");
                    }
                    else
                    {
                        printf("\nNo se ha modificado el sueldo.");
                    }
                    break;
                case 4:
                    break;
            }
            if(ansMenu == 4)
            {
                break;
            }

            printf("\nDesea modificar algun otro parametro?(s/n): ");
            fflush(stdin);
            scanf("%c",&ansWhile);

        }while(ansWhile == 's');
    }

    return 1;
}

int controller_buscarIndicePorId(LinkedList* pArrayListEmployee, int id)
{
    int index=-1;
    int i;
    int size;
    Employee* auxEmployee;
    int auxId;

    size = ll_len(pArrayListEmployee);


    for(i=0;i<size;i++)
    {
        auxEmployee  = (Employee*)ll_get(pArrayListEmployee, i);
        employee_getId(auxEmployee, &auxId);

        if(auxId == id)
        {
            index = i;
            break;
        }

    }

    return index;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* anEmployee = NULL;
    int id;
    int sueldo;
    int horasTrabajadas;
    char nombre[51];
    int idTrue;
    char ans;
    int returnValue;

    controller_ListEmployee(pArrayListEmployee);

    printf("\nIngrese el (ID) del empleado que desea eliminar: ");
    fflush(stdin);
    scanf("%d",&id);

    idTrue = controller_buscarIndicePorId(pArrayListEmployee, id);

    system("cls");

    if(idTrue != -1)
    {
        anEmployee = (Employee*)ll_get(pArrayListEmployee, idTrue);



        if(anEmployee != NULL)
        {
            employee_getId(anEmployee, &id);
            employee_getHorasTrabajadas(anEmployee, &horasTrabajadas);
            employee_getSueldo(anEmployee, &sueldo);
            employee_getNombre(anEmployee, nombre);

            printf("\n\n%d %s %d %d\n\n", id, nombre, horasTrabajadas, sueldo);

            printf("\nEstas seguro de borrar este empleado?(s/n):");
            fflush(stdin);
            scanf("%c",&ans);

            if(ans == 's')
            {
                ll_remove(pArrayListEmployee, idTrue);
                returnValue = 1;
            }
            else
            {
                returnValue = 2;
            }

        }
        else
        {
            returnValue = -1;
        }

    }


    return returnValue;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int tam;
    Employee* aux;
    int i;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    tam = ll_len(pArrayListEmployee);

    printf("%5s %18s %25s %10s","ID", "NOMBRE", "HORAS TRABAJADAS", "SUELDO");

    for(i=0;i<tam;i++)
    {

        aux = (Employee*) ll_get(pArrayListEmployee, i);

        employee_getId(aux, &id);
        employee_getNombre(aux, nombre);
        employee_getHorasTrabajadas(aux, &horasTrabajadas);
        employee_getSueldo(aux, &sueldo);

        printf("\n%5d)   %15s   %15d   %15d", id, nombre, horasTrabajadas, sueldo);


    }

    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ans;

    do
    {
        ans = menuSortEmployee();

        switch(ans)
        {
            case 1:
                ll_sort(pArrayListEmployee, employee_CompareByName, 1);
                break;
            case 2:
                ll_sort(pArrayListEmployee, employee_CompareByName, 0);
                break;
            case 3:
                ll_sort(pArrayListEmployee, employee_CompareById, 1);
                break;
            case 4:
                ll_sort(pArrayListEmployee, employee_CompareById, 0);
                break;
            case 5:
                break;
            default:
                printf("\nPor favor ingrese una opcion valida");
                break;
        }

        break;

    }while(ans != 5);

    return 1;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int len;
    FILE* pFile;
    Employee* employee;
    int i;
    int id;
    char nombre[51];
    int horasTrabajadas;
    int sueldo;

    pFile = fopen(path, "w");

    len = ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i=0;i<len;i++)
        {
            employee = ll_get(pArrayListEmployee,i);

            employee_getId(employee,&id);
            employee_getNombre(employee, nombre);
            employee_getHorasTrabajadas(employee, &horasTrabajadas);
            employee_getSueldo(employee, &sueldo);

            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);

            returnValue = 1;
        }
    }

    fclose(pFile);

    return returnValue;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnValue = 0;
    int tam;
    FILE* pFile;
    Employee* employeeAux;
    int i;
    int auxWrite;


    pFile = fopen(path,"wb");
    tam = ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        for(i=0;i<tam;i++)
        {
            employeeAux = ll_get(pArrayListEmployee,i);

            auxWrite = fwrite(employeeAux,sizeof(Employee),1,pFile);
            if(auxWrite)
            {
              returnValue = 1;
            }

        }

    }

    fclose(pFile);

    return returnValue;
}

