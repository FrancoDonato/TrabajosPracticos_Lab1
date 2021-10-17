#include "utn.h"
#include "arrayEmployees.h"
#include "Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main(void){
	setbuf(stdout, NULL);
	int nextId=0;
	int opcion;
	int orden;
	float salarioTotal;
	int validar;
	float promedio;
	float promedioSueldo;
	int flag=0;
	int contEmpleados = 0;
	Employee nominaEmpleados[TAM];
	char seguir = 's';
	if(initEmployees(nominaEmpleados, TAM)==1){
		printf("    ***La nomina ha sido inicializada con exito***    ");
	}
	else{
		printf("\n    ***Ocurrio un error durante la inicializacion***    ");
	}

	system("cls");
do{
	switch(menuOpciones()){
	case 1:
		system("cls");

		printf("\n  ---- Menu de Altas ----  \n");
		if(addEmployees(nominaEmpleados, TAM, &nextId)){
			printf("  --El alta se realizo exitosamente--  ");
			flag++;
            system("pause");

		}
		break;
	case 2:
		system("cls");
		if(flag==0){
			printf("\n Error! Aun no hay empleados ingresados.");
		}
		else{
		if(removeEmployees(nominaEmpleados, TAM)){
			printf("\n----La baja se realizo exitosamente----");
            system("pause");

			}
		}

		break;
	case 3:
		system("cls");
		if(flag==0){
		printf("\n Error! Aun no hay empleados ingresados.");
		}
		else{
		validar=modificarEmployee(nominaEmpleados,TAM);
	    if(validar==1){
                printf("Modificacion exitosa!");
		  }
		}



		break;
	case 4:
		system("cls");
		if(flag==0){
		printf("\n Error! Aun no hay empleados ingresados.");
		}
		else{
		printf("\n  ---- Informes de los empleados ----  \n");

		printf("\n  1- Lista de los empleados.");
		printf("\n  2- Informe de los salarios.");
		printf("\n  3- Regresar al menu principal.");
		opcion=getInt("\n  Ingrese una opcion", 1, 3);

		if(opcion==1){
		printf("\n  ---- Lista de los empleados ----  \n");
		printf("\n  1-Ascendente");
		printf("\n  2-Descendente");
		orden=getInt("\n--Elija el orden en que quiere ver los empleados: ", 1,2);

		if(orden==2){
				orden=0;
		}
		if(sortEmployees(nominaEmpleados, TAM, orden)){
			if(printEmployees(nominaEmpleados, TAM)){
				printf("\n----Se ha informado la lista de empleados----");
                system("pause");

			}
		  }
		}
		else if(opcion==2){
			printf("\n  ---- Informes de los salarios ----  \n");
			salarioTotal=totalSalarios(nominaEmpleados,TAM,&contEmpleados);
			promedioSueldo=CalcularPromedio(salarioTotal,contEmpleados);
			if(promedioSueldo==-1){
				printf("\n No se pudo calcular el promedio salarial porque no hay empleados");
			}
			else{
			printf("El promedio de los salarios es: %.2f\n", promedio);
		    printf("     ---Empleados que superan el promedio salarial--- \n");
			printf("|  Id  |  Nombre  |  Apellido  |  Salario  |  Sector  |\n");
			printf("------------------------------------------------------------\n");
			empleadosSalarioMayor(nominaEmpleados,TAM,promedio);
            system("pause");
			}
		}
		else{
			printf("\n  ---Usted regreso al menu principal---  ");
		  }
		}
		break;
	case 5:
		system("cls");

		printf("\n----Gracias por utilizar el programa, adios!----");
		seguir='n';
		break;
	default:
		printf("\n  **** Opcion invalida ****  ");
		break;
  }
	system("pause");

 }while(seguir=='s');
}





