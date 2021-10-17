#include "utn.h"
#include "arrayEmployees.h"
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int initEmployees(Employee* list, int tam){
	int todoOk = 0;
	if(list != NULL && tam > 0){
		for(int i = 0 ; i < tam ; i++){
			list[i].isEmpty = 1;
		}
		todoOk = 1;
	}
    return todoOk;
}

int addEmployees(Employee* list, int tam, int* pId){
	int todoOk;
	int indice;
	char seguir;
	Employee auxEmpleado;
	do{
	if(list != NULL && tam > 0 && pId != NULL){
		indice = buscarLibre(list, tam);
		if(indice==-1){
			printf("\n  ***No hay lugar para mas empleados***   ");
		}
		else{
			auxEmpleado.id= *pId;
			(*pId)++;
			getString("Ingrese nombre: ", auxEmpleado.name, 51);

			getString("Ingrese apellido: ", auxEmpleado.lastName, 51);

			auxEmpleado.salary = getFloat("Ingrese el salario: ", 1, 1000000);

			auxEmpleado.sector = getInt("Ingrese el sector: ", 1, 10000);

			auxEmpleado.isEmpty = 0;

			list[indice] = auxEmpleado;
			todoOk=1;
		}
	}
	printf("--Quiere seguir ingresando empleados? s/n :");
	fflush(stdin);
	scanf("%c", &seguir);
	while(seguir!= 'n' && seguir != 's'){
		printf("\n-- Error. Elija una opcion valida s/n : ");
		scanf("%c", &seguir);
	}
	}while(seguir=='s');
	return todoOk;
}

int findEmployeeById(Employee* list, int tam,int id)
{
  int indice= -1;

    if(list!=NULL && tam>0 && id>=1)
    {
        for(int i=0;i<tam;i++)
        {
            if(list[i].id==id&&list[i].isEmpty==0)
            {
                indice=i;
                break;

            }

        }
    }
        return indice;
}
int removeEmployees(Employee* list, int tam){
	int todoOk;
	int idDeBaja;
	int indice;
	char confirmacion;
	printf("\n  ----Menu de Baja----  \n");
	idDeBaja=getInt("Ingrese el Id del usuario: ", 1, 1000);
	indice=findEmployeeById(list,tam, idDeBaja);

	if(indice == -1){
		printf("\nNo existe un empleado con ese Id");
	}
	else{
		mostrarEmpleado(list[indice]);

		printf("\n--Confirma la baja de este empleado? s/n : ");
		fflush(stdin);
		scanf("%c", &confirmacion);

		if(confirmacion == 'n'){
			list[indice].isEmpty=1;
			todoOk=1;
		}
		else{
			printf("\nSe ha cancelado la baja del empleado");
			}
		todoOk=0;
	    }

	return todoOk;
}

int printEmployees(Employee* list, int tam){
	int todoOk;
	int flag=1;
	if(list != NULL  && tam > 0){
		system("cls");
		printf("   ***Listado de empleados***  \n"
				"");
		printf("|  Id  |  Nombre  |  Apellido  |  Salario  |  Sector  |\n");
		printf("-------------------------------------------------------\n");
		for(int i=0 ; i<tam ; i++){
			if(!list[i].isEmpty){
				mostrarEmpleado(list[i]);
				flag=0;
			}
		}
		if(flag){
			printf("----No hay empleados cargados en el sistema----");
		}
		todoOk=1;
	}

	return todoOk;
}

int sortEmployees(Employee* list, int tam, int order)
{
 int todoOk=-1;
 Employee auxEmpleado;
 if(list != NULL && tam > 0){
	todoOk=1;
    for(int i=0; i < tam ; i++){
			for(int j=0; j < tam ; j++){

				if(order==1 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)<0)  || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector > list[j].sector))){
					auxEmpleado = list[i];
					list[i]=list[j];
					list[j]=auxEmpleado;
				}
				if(order==0 && list[i].isEmpty==0 && ((strcmp(list[i].lastName,list[j].lastName)>0) || (strcmp(list[i].lastName,list[j].lastName)==0 && list[i].sector < list[j].sector))){
					auxEmpleado = list[i];
					list[i]=list[j];
					list[j]=auxEmpleado;
				}
			}
		}
	}
    return todoOk;
}

