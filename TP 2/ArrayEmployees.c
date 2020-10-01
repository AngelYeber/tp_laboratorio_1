#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "menu.h"
#define T 1000



sEmployee addEmployee(void)
{
    sEmployee employee;


    printf("Ingrese el nombre: ");
    fflush(stdin);
    scanf("%[^\n]", employee.name);

    printf("Ingrese el apellido: ");
    fflush(stdin);
    scanf("%[^\n]", employee.lastName);

    printf("Ingrese el salario: ");
    fflush(stdin);
    scanf("%f",&employee.salary);

    printf("Ingrese el sector: ");
    fflush(stdin);
    scanf("%d",&employee.sector);

    employee.isEmpty = 0;

    return employee;

}

void printEmployee(sEmployee employee)
{
    if(employee.isEmpty != 1)
    {
        printf("\n%d", employee.id);
        printf("%8s", employee.name);
        printf("%6s", employee.lastName);
        printf("%10.f", employee.salary);
        printf("%6d", employee.sector);
    }


}

void initEmployees(sEmployee list[], int len)
{
    int i;
    char name[51] = {"xxxx"};
    char lastName[51]= {"xxxx"};

    for(i=0;i<len;i++)
    {
        list[i].id = 0;
        list[i].isEmpty = 1;
        strcpy(list[i].name, name);
        strcpy(list[i].lastName, lastName);
        list[i].salary = 0;
        list[i].sector = 0;
    }

}

void printAllEmployees(sEmployee list[], int len)
{
    int i;



        printf("%3s %8s %6s %8s %6s", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");

        for(i=0;i<len;i++)
        {
          if(list[i].isEmpty != 1)
          {

            printEmployee(list[i]);

          }

        }

}

int findEmployeeById(sEmployee list[], int len, int id)
{
    int i;
    int index = -1;

    for(i=0;i<len;i++)
    {
        if(list[i].id == id && list[i].isEmpty != 1)
        {
            index = i;
            break;
        }

    }

    return index;
}

int removeAnEmployee(sEmployee list[], int len, int id)
{

   int flag=0;
   int ansID=0;
   int  i;

   ansID = findEmployeeById(list, len, id);

   for(i=0;i<len;i++)
   {

       if(ansID != -1 && list[i].isEmpty != 1)
       {
            printEmployee(list[i]);
            list[i].isEmpty = 1;
            list[i].id = 0;
            flag = 1;
            break;
       }

   }



   return flag;
}

void modifyAnEmployee(sEmployee list[], int len, int id)
{

    int i;
    int ans=0;
    char ansName;
    char ansLastName;
    char ansSalary;
    char ansSector;
    char ansWhile;
    char name[51];
    char lastName[51];
    float salary=0;
    int sector=0;


    for(i=0;i<len;i++)
    {

        if(id == list[i].id && list[i].isEmpty !=1)
        {
            do
            {
                ans = modifyAnEmployeeMenu(list, len, id);

                switch(ans)
                {

                    case 1:
                        printf("\nIngrese el nuevo nombre: ");
                        fflush(stdin);
                        scanf("%[^\n]", name);

                        printf("estas seguro de querer modificar este campo? s/n: ");
                        fflush(stdin);
                        scanf("%c",&ansName);
                        if(ansName == 's')
                        {
                          strcpy(list[i].name, name);
                          printf("\nEl nombre fue modificado exitosamente.");
                        }
                        else
                        {
                            printf("\nOperacion cancelada.");
                        }
                        break;
                    case 2:
                        printf("\nIngrese el nuevo apellido: ");
                        fflush(stdin);
                        scanf("%6[^\n]", lastName);

                        printf("estas seguro de querer modificar este campo? s/n: ");
                        fflush(stdin);
                        scanf("%c",&ansLastName);
                        if(ansLastName == 's')
                        {
                          strcpy(list[i].lastName, lastName);
                          printf("\nEl apellido fue modificado exitosamente.");
                        }
                        else
                        {
                            printf("\nOperacion cancelada.");
                        }
                        break;
                    case 3:
                        printf("\nIngrese el nuevo salario: ");
                        fflush(stdin);
                        scanf("%10f",&salary);

                        printf("estas seguro de querer modificar este campo? s/n: ");
                        fflush(stdin);
                        scanf("%c",&ansSalary);
                        if(ansSalary == 's')
                        {
                          list[i].salary = salary;
                          printf("\nEl salario fue modificado exitosamente.");
                        }
                        else
                        {
                            printf("\nOperacion cancelada.");
                        }
                        break;
                    case 4:
                        printf("\nIngrese el nuevo sector: ");
                        fflush(stdin);
                        scanf("%6d",&sector);

                        printf("\nestas seguro de querer modificar este campo? s/n: ");
                        fflush(stdin);
                        scanf("%c",&ansSector);
                        if(ansSector == 's')
                        {
                          list[i].sector = sector;
                          printf("\nEl sector fue modificado exitosamente.");
                        }
                        else
                        {
                            printf("\nOperacion cancelada.");
                        }
                        break;

                }

                printf("\nDesea seguir modificando parametros del mismo empleado? s/n: ");
                fflush(stdin);
                scanf("%c",&ansWhile);
                system("cls");

            }while(ansWhile == 's');

            break;

        }

    }

}


int loadListEmployees(sEmployee list[],int len)
{

    int i;
    char ans='s';
    int flag = -1;

    do
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 1)
            {
                printf("\t****Cargar listado de empleados****\n");
                list[i] = addEmployee();
                list[i].id = 100+i;
                list[i].isEmpty = 0;
                flag = 1;
                printf("\nQueres seguir cargando empleados? s/n \nrespuesta: ");
                fflush(stdin);
                scanf("%c",&ans);
                if(ans == 'n')
                {
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                }

            }
        }

        if(isEmpty(list,len) != 1)
        {
            printf("\nNO hay mas espacio para cargar empleados!\n\n");
            break;
        }

    }while(ans=='s');

    return flag;

}

int isEmpty(sEmployee list[], int len)
{
    int i;
    int index=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = 1;
            break;
        }
    }

    return index;
}

void sortEmployees(sEmployee list[], int len)
{
    int i;
    int j;
    sEmployee auxName;
    sEmployee auxSector;


    for(i=0;i<len-1;i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(list[i].sector == list[j].sector)
            {
                if(strcmp(list[i].lastName, list[j].lastName)<0 && list[i].isEmpty != 1)
                {
                    auxName = list[i];
                    list[i] = list[j];
                    list[j] = auxName;
                }
            }

        }

    }

    for(i=0;i<len-1;i++)
    {
        for(j=i+1; j<len; j++)
        {
            if(list[i].sector == list[j].sector)
            {

                if(strcmp(list[i].lastName, list[j].lastName)>0 && list[i].isEmpty == 0)
                {
                    auxSector = list[i];
                    list[i] = list[j];
                    list[j] = auxSector;
                }

            }

        }

    }

}

float allSalaries(sEmployee list[], int len)
{
    int i;
    float acc=0;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty != 1)
        {
            acc = list[i].salary + acc;
        }
    }

    return acc;
}

int totalSalariesAverage(sEmployee list[], int len)
{
    int i;
    int cont=0;
    float acc=0;
    int result;

    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty != 1)
        {
            cont++;
        }
    }

    acc = allSalaries(list, len);

    result = acc / cont;

    return result;
}

int EmployeesWhoExceedTheSalaryAverage(sEmployee list[], int len)
{
    int i;
    float totalAverages=0;
    int flag = 0;

    totalAverages = totalSalariesAverage(list,len);

    for(i=0;i<len;i++)
    {
       if(list[i].salary > totalAverages)
       {
            printEmployee(list[i]);
            flag = 1;
       }
    }

    return flag;
}

int searchEmployee(sEmployee list[], int len)
{
    int index = -1;
    int i;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty != 1)
        {
            index = 1;
            break;
        }
    }

    return index;
}

void mainFunctionality(sEmployee list[], int len)
{
    char ans;
    int ansSortMenu;
    int flag=0;
    int flagLoadListOfEmployees=0;
    int flagRemoveAnEmployee=0;
    int flagEWETSA=0;
    int idModify=0;
    int idRemove=0;
    float allEmployeesSalaries;
    float totalAverages;



    do
    {

        ans = menu();

        switch(ans)
        {
            case 1:
                flag=1;
                system("cls");
                flagLoadListOfEmployees = loadListEmployees(list, T);
                if(flagLoadListOfEmployees == 1)
                {
                    printf("\nLa carga se ha realizado con exito!\n\n");
                    system("pause");
                    system("cls");
                }
                else
                {
                    printf("\nNo se ha podido realizar la carga.");
                }
                break;
            case 2:
                flag = searchEmployee(list, T);
                if(flag == 1)
                {
                    system("cls");
                    printf("\t*** Modificar un empleado ***\n");
                    printAllEmployees(list, T);
                    printf("\nIngrese el ID del empleado que desea modificar: ");
                    fflush(stdin);
                    scanf("%d",&idModify);
                    system("cls");
                    modifyAnEmployee(list, T, idModify);
                }
                else
                {
                    printf("\nERROR tenes que ingresar al menos 1 empleado!\n");
                    system("pause");
                    system("cls");
                }


                break;
            case 3:

                flag = searchEmployee(list, T);

                if(flag == 1)
                {
                    system("cls");
                    printf("\t*** Eliminar un empleado ***\n");
                    printAllEmployees(list, T);
                    printf("\nIngrese el ID del empleado que desea eliminar: ");
                    fflush(stdin);
                    scanf("%d",&idRemove);
                    flagRemoveAnEmployee = removeAnEmployee(list, T, idRemove);
                    if(flagRemoveAnEmployee == 1)
                    {
                        printf("\nSe ha eliminado al empleado del listado exitosamente!\n");
                        system("pause");
                        system("cls");
                    }
                    else
                    {
                        printf("\nNo se ha podido realizar la remocion del empleado.");
                        system("pause");
                        system("cls");
                    }
                }
                else
                {
                    printf("\nERROR tenes que ingresar al menos 1 empleado!\n");
                    system("pause");
                    system("cls");
                }


                break;
            case 4:
                flag = searchEmployee(list, T);

                if(flag == 1)
                {
                    system("cls");
                    printf("\t***Listado de empleados***\n");
                    printAllEmployees(list, T);
                    printf("\n");
                    system("pause");

                    do{

                        system("cls");
                        ansSortMenu = sortMenu(list, T);

                        switch(ansSortMenu)
                        {
                            case 1:
                                system("cls");
                                printAllEmployees(list, T);
                                system("pause");
                                break;

                            case 2:
                                system("cls");
                                printf("\t***Listado de empleados***\n");
                                sortEmployees(list, T);
                                printAllEmployees(list, T);
                                printf("\n");
                                system("pause");
                                system("cls");
                                break;
                            case 3:
                                system("cls");
                                printf("\t***Listado de empleados***\n");
                                allEmployeesSalaries = allSalaries(list,T);
                                totalAverages = totalSalariesAverage(list, T);
                                printf("\nLa suma de todos los salarios es: %2.f", allEmployeesSalaries);
                                printf("\nEl promedio de la suma de todos los salarios es: %2.f\n",totalAverages);
                                system("pause");
                                system("cls");
                                break;
                            case 4:
                                system("cls");
                                printf("\t***Listado de empleados***\n");
                                printf("\nEmpleados que superan el salario promedio\n");
                                printf("%3s %8s %6s %8s %6s", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");
                                flagEWETSA = EmployeesWhoExceedTheSalaryAverage(list, T);
                                if(flagEWETSA != 1)
                                {
                                    printf("\nNo hay empleados que superen el salario promedio");
                                }
                                printf("\n");
                                system("pause");
                                system("cls");
                                break;
                            case 5:
                                printf("Hasta luego!\n");
                                system("pause");
                                system("cls");
                                break;

                        }

                     }while(ansSortMenu != 5);

                }
                else
                {
                    printf("\nERROR tenes que ingresar al menos 1 empleado!\n");
                    system("pause");
                    system("cls");
                }

                break;
            case 5:
                printf("\nHasta luego!");
                break;

         }

    }while(ans != 5);
}
