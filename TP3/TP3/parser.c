#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    char id[50];
    char nombre[50];
    char horasTrabajadas[50];
    char sueldo[50];
    Employee* anEmployee;

    pFile = fopen("data.csv", "r");


    if(pFile == NULL)
    {
        printf("El archivo no existe");
        retorno = -1;
    }


    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);


    do
    {

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        anEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

        if(anEmployee != NULL)
        {
            ll_add(pArrayListEmployee, anEmployee);
            retorno = 1;
        }

    }while(!feof(pFile));

    fclose(pFile);


    return retorno;
}



int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* anEmployee;
    int returnValue = -1;


    if(pFile != NULL)
    {
        do
        {
            anEmployee = employee_new();
            fread(anEmployee, sizeof(Employee), 1, pFile);

            ll_add(pArrayListEmployee, anEmployee);

        }while(!feof(pFile));

        returnValue = 0;
    }

    return returnValue;
}
