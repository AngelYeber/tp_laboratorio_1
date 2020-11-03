#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"

/****************************************************
    Menu:
     (X)1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     (X)2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     (X)3. Alta de empleado
     (X)4. Modificar datos de empleado(-)
     (X)5. Baja de empleado
     (X)6. Listar empleados
     (X)7. Ordenar empleados
     (X)8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     (X)9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    (X)10. Salir
*****************************************************/


int main()
{
    LinkedList* miLista;
    miLista = ll_newLinkedList();
    int flagOpcionUno=0;
    int flagOpcionDos=0;
    int ansMenu=0;
    int cantidadDeEmpleados=0;
    int borroEmpleado=0;

    do
    {
        system("cls");
        ansMenu = mainMenu();


        switch(ansMenu)
        {

            case 1:

            if(flagOpcionDos != 1 && flagOpcionUno != 1)
            {
                system("cls");
                if(controller_loadFromText("data.csv", miLista)== 1)
                {
                    printf("\nArchivo descargado...\n");
                    cantidadDeEmpleados = ll_len(miLista);
                    printf("\nSe descargaron %d empleados\n\n", cantidadDeEmpleados);
                    flagOpcionUno = 1;
                    system("pause");
                }
                else
                {
                    printf("\nNo se pudo descargar el archivo");
                }
            }
            else
            {
                printf("\nYa se descargaron los archivos anteriormente!\n\n");
                system("pause");
            }
                break;
            case 2:
                if(flagOpcionUno != 1 && flagOpcionDos != 1)
                {
                    system("cls");
                    if(controller_loadFromBinary("data.dat", miLista)==1)
                    {
                        printf("\nArchivo descargado...\n\n");
                        flagOpcionDos = 1;
                    }
                }
                else
                {
                    printf("\nYa se descargaron los archivos anteriormente!\n\n");
                    system("pause");
                }
                break;
            case 3:
                system("cls");
                printf("\t*** Cargar Empleado ***\n");
                if(controller_addEmployee(miLista)==1)
                {
                    printf("\nSe ha cargado a un empleado exitosamente!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nHubo un error al cargar el empleado!\n\n");
                    system("pause");
                }
                break;
            case 4:
                system("cls");
                controller_editEmployee(miLista);
                break;
            case 5:
                system("cls");
                borroEmpleado = controller_removeEmployee(miLista);
                if(borroEmpleado ==  1)
                {
                    printf("\nSe ha removido al empleado exitosamente!\n\n");
                    system("pause");
                }
                if(borroEmpleado == 2)
                {
                    printf("\nSe ha cancelado la operacion\n\n");
                    system("pause");
                    break;
                }
                else
                {
                    printf("\nERROR\n\n");
                    system("pause");
                }
                break;
            case 6:
                system("cls");
                controller_ListEmployee(miLista);
                printf("\n");
                system("pause");
                break;
            case 7:
                system("cls");
                controller_sortEmployee(miLista);
                printf("\n");
                printf("Ordenado!\n");
                system("pause");
                break;
            case 8:
                system("cls");
                if(controller_saveAsText("data.csv", miLista)==1)
                {
                    printf("\nArchivo guardado!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nHubo un error al momento de guardar el archivo...\n\n");
                    system("pause");
                }

                break;
            case 9:
                system("cls");
                if(controller_saveAsBinary("data.dat", miLista)== 1)
                {

                    printf("\nArchivo guardado!\n\n");
                    system("pause");
                }
                else
                {
                    printf("\nHubo un error al momento de guardar el archivo...\n\n");
                    system("pause");
                }
                break;
            case 10:

                system("cls");
                break;
            default:
                printf("\nPor favor ingrese una opcion valida!");
                printf("\n\n");
                system("pause");
                break;
        }

    }while(ansMenu != 10);


    return 0;
}



