#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"
#include <string.h>


Employee* employee_new()
{
    Employee* newEmployee;

    newEmployee = (Employee*)malloc(sizeof(Employee));

    return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id;
    int horasTrabajadas;
    int Sueldo;
    Employee* anEmployee;
    anEmployee = employee_new();


    id = atoi(idStr);
    horasTrabajadas = atoi(horasTrabajadasStr);
    Sueldo = atoi(sueldoStr);

    if(anEmployee != NULL)
    {
        employee_setId(anEmployee, id);
        employee_setNombre(anEmployee, nombreStr);
        employee_setHorasTrabajadas(anEmployee, horasTrabajadas);
        employee_setSueldo(anEmployee, Sueldo);
    }

    return anEmployee;
}



int employee_setId(Employee* this,int id)
{
    int flag=0;

    if(this != NULL && id >0)
    {
        this->id = id;
        flag = 1;
    }

    return flag;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int flag;

    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        flag = 1;
    }

    return flag;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int flag;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        flag = 1;
    }

    return flag;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int flag;

    if(this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        flag = 1;
    }

    return flag;
}


int employee_getId(Employee* this,int* id)
{
    int flag;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        flag = 1;
    }

    return flag;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int flag;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        flag = 1;
    }

    return flag;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int flag;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        flag = 1;
    }

    return flag;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int flag;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        flag = 1;
    }

    return flag;
}

int employee_CompareByName(void* e1, void* e2)
{
    Employee* auxUno = NULL;
    Employee* auxDos = NULL;
    char nombreUno[51];
    char nombreDos[51];

    auxUno = (Employee*)e1;
    auxDos = (Employee*)e2;

    employee_getNombre(auxUno, nombreUno);
    employee_getNombre(auxDos, nombreDos);


    return strcmp(nombreUno, nombreDos);
}

int employee_CompareById(void* e1, void* e2)
{
    int aux = 0;
    int idUno=0;
    int idDos=0;
    Employee* auxE1;
    Employee* auxE2;

    auxE1 = (Employee*)e1;
    auxE2 = (Employee*)e2;

    employee_getId(auxE1, &idUno);
    employee_getId(auxE2, &idDos);

    if(idUno > idDos)
    {
       aux = 1;
    }
    else if(idUno < idDos)
    {
        aux = -1;
    }



  return aux;
}
