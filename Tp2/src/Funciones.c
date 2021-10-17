#include "Funciones.h"
#include "utn.h"
#include "arrayEmployees.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 1000

int menuOpciones(){
	int opcion;
	printf("\n----------------------------------");
	printf("\n    ***Menu principal***    ");
	printf("\n----------------------------------");
	printf("\n   1-Altas");
	printf("\n   2-Modificar");
	printf("\n   3-Baja");
    printf("\n   4-Informar");
    printf("\n   5-Salir");
    printf("\n    Elija una opcion: ");
    scanf("%d", &opcion);

	return opcion;
}




int buscarLibre(Employee* list, int tam){
	int libre;
	if(list != NULL && tam > 0){
		for(int i=0 ; i<tam ; i++){
			if(list[i].isEmpty){
				libre=i;
			}
		}
	}
	return libre;
}




void mostrarEmpleado(Employee list){
	printf("|  %d   |  %s     %s     %.2f      %d\n",
			list.id,
			list.name,
			list.lastName,
			list.salary,
			list.sector);
}

float totalSalarios(Employee* list,int tam,int* contEmpleados){
    float totalSalarios=0;
	int cantidadEmpleados=0;

	for(int i=0; i<tam; i++){
		if(list[i].isEmpty==0){
			cantidadEmpleados++;
			totalSalarios += list[i].salary;
		}
		else{
			break;
		}
	}

	*contEmpleados = cantidadEmpleados;
	return totalSalarios;

}
float CalcularPromedio(float salario, int empleados)
{
    float promedio;
    if(empleados==0)
    {
        promedio=-1;
    }
    else{
        promedio=(float)salario/empleados;
    }

    return promedio;
}
void empleadosSalarioMayor(Employee* list, int tam, float salario)
{
    for(int i=0;i<tam;i++)
    {
        if(list[i].salary>salario&&list[i].isEmpty==0)
        {
            mostrarEmpleado(list[i]);
        }
    }
}
int menuModificacion()
{
    int opcion;

    printf("1.Modificar nombre\n");
    printf("2.Modificar apellido\n");
    printf("3.Modificar salario\n");
    printf("4.Modificar sector\n");
    printf("5.Cancelar modificacion\n");
    opcion=getInt("Ingrese una opcion: ",1,5);
    return opcion;
}
int modificarEmployee(Employee* list, int tam)
{
    int todoOk=0;
    int id;
    int indice;
    char confirma;
    char auxName[51];
    char auxLastName[51];
    float auxSalary;
    int auxSector;

    if(list!=NULL&&tam>0)
    {
        system("cls");
        printf("    ***Modificar empleado***    \n");
        printf("---------------------------------\n");
        id= getInt("Ingrese id del empleado: ",1,1000);
        indice = findEmployeeById(list, tam, id);
        if(indice<0){
            printf("No existe un empleado con id %d\n",id);
        }
        else{
            printf("  Id     |Nombre         |Apellido    |Salario    |Sector\n");
            printf("------------------------------------------------------------\n");
            mostrarEmpleado(list[indice]);
            printf("Desea modificar este empleado?(s/n): ");
            fflush(stdin);
            scanf("%c", &confirma);
            while(confirma!= 's' && confirma!='n')
            {
                printf("Opcion invalida, ingrese una opcion correcta(s/n): ");
                fflush(stdin);
                scanf("%c",&confirma);
            }
            if (confirma=='s'){
                    system("cls");
             printf("    ***Modificar empleado***    \n");
                switch(menuModificacion()){
                    case 1:
                    getString("Ingrese un nuevo nombre: ",auxName,51);
                    strcpy(list[indice].name,auxName);
                    break;
                    case 2:
                    getString("Ingrese un nuevo apellido: ",auxLastName,51);
                    strcpy(list[indice].lastName,auxLastName);
                    break;
                case 3:
                    getValidFloat("Ingrese un nuevo salario: ","Dato invalido. Ingrese nuevamente el salario");
                    scanf("%f",&auxSalary);
                    list[indice].salary=auxSalary;
                    break;
                case 4:
                    getValidInt("Ingrese un nuevo sector: ","Dato invalido. Ingrese nuevamente el sector");
                    scanf("%d", &auxSector);
                    list[indice].sector = auxSector;
                    break;
                case 5:
                    printf("\nSe ha cancelado la modificacion\n");
                    break;
                }
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }

        }
    }
    return todoOk;
}
