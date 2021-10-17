
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int findEmployeeById(Employee* list, int tam, int id);
int initEmployees(Employee* list, int tam);
int addEmployees(Employee* list, int tam, int* pId);
int printEmployees(Employee* list, int tam);
int removeEmployees(Employee* list, int tam);
int sortEmployees(Employee* list, int tam, int order);

#define TAM 1000


#endif /* ARRAYEMPLOYEES_H_ */

