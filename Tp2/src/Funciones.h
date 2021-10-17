#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "arrayEmployees.h"
#include "utn.h"


#endif /* FUNCIONES_H_ */
int buscarLibre(Employee* list, int tam);
void mostrarEmpleado(Employee list);
int modificarEmployee(Employee* list, int tam);
int menuModificacion();
int menuOpciones();
void empleadosSalarioMayor(Employee* list, int tam, float salario);
float CalcularPromedio(float salario, int empleados);
float totalSalarios(Employee* list,int tam,int* contEmpleados);
