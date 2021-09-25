#include "Bibliotecas.h"

int menuOpciones(int numero1, int numero2, int flag1, int flag2)
{
	int opcion;

	if(flag1==0 && flag2==0){
	printf("\nBienvenid@ al menu de opciones!\n\n");
	printf("1.Ingresar primer numero...\n");
	printf("2.Ingresar segundo numero...\n");
	}
	else
		if(flag1==1 && flag2==0){
			printf("\nMenu de opciones:\n\n");
			printf("Primer numero: %d", numero1);
			printf("\n1.Reingresar primer numero...\n");
			printf("2.Ingresar segundo numero...\n");

		}
		else
			if(flag1==0 && flag2==1){
				printf("\nMenu de opciones:\n\n");
				printf("Segundo numero: %d", numero2);
				printf("\n1.Ingresar primer numero...\n");
				printf("2.Reingresar segundo numero...\n");


			}
			else
				if(flag1==1 && flag2==1){
					printf("\nMenu de opciones:\n");
					printf("Primer numero: %d\n", numero1);
					printf("Segundo numero: %d\n", numero2);
					printf("\n1.Reingresar primer numero...\n");
					printf("2.Reingresar segundo numero...\n");
					printf("3.Realizar todos los calculos...\n");
					if(numero1>0 && numero2>0){
						printf("\na)Suma %d + %d\n", numero1, numero2);
						printf("b)Resta %d - %d\n", numero1, numero2);
						printf("c)Multiplicacion %d * %d\n", numero1, numero2);
						printf("d)Division %d / %d\n", numero1, numero2);
						printf("e)Factorial de %d!\n", numero1);
						printf("f)Factorial de %d!\n", numero2);
					}
					else
						if(numero1>0 && numero2<-1){
							printf("\na)Suma %d + (%d)\n", numero1, numero2);
							printf("b)Resta %d - (%d)\n", numero1, numero2);
							printf("c)Multiplicacion %d * (%d)\n", numero1, numero2);
							printf("d)Division %d / (%d)\n", numero1, numero2);
							printf("e)Factorial de %d!\n", numero1);
							printf("f)Factorial de (%d!)\n", numero2);
						}
						else
							if(numero1<-1 && numero2<-1){
								printf("\na)Suma %d + (%d)\n", numero1, numero2);
								printf("b)Resta %d - (%d)\n", numero1, numero2);
								printf("c)Multiplicacion (%d) * (%d)\n", numero1, numero2);
								printf("d)Division (%d) / (%d)\n", numero1, numero2);
								printf("e)Factorial de (%d!)\n", numero1);
								printf("f)Factorial de (%d!)\n", numero2);
							}
							else
								if(numero1<-1 && numero2>0){
									printf("\na)Suma %d + %d\n", numero1, numero2);
									printf("b)Resta %d - %d\n", numero1, numero2);
									printf("c)Multiplicacion %d * %d\n", numero1, numero2);
									printf("d)Division %d / %d\n", numero1, numero2);
									printf("e)Factorial de %d!\n", numero1);
									printf("f)Factorial de %d!\n", numero2);
								}
					printf("\n4.Mostrar todos los resultados...\n");
					printf("5.Finalizar programa...\n");
				}

	printf("Elija una de las opciones:\n");
	scanf("%d", &opcion);

	return opcion;
}

float divisionAB (int numero1, int numero2)
{
	float division;

	division = numero1 / (float)numero2;

	return division;
}

int factorialA (int numero1)
{
	int factorial=1;
	int i;

		if(numero1>1)
	{
		for(i = numero1 ; i > 1; i--)
		{
	      factorial=factorial*i;
		}
	}


	return factorial;
}


int multiplicacionAB (int numero1, int numero2)
{
	int multiplicacion;

	multiplicacion = numero1 * numero2;

	return multiplicacion;
}

int restaAB(int numero1, int numero2)
{
	int resta;

	resta=numero1-numero2;

	return resta;
}

int sumaAB(int numero1, int numero2)
{
	int suma;

	suma=numero1+numero2;

	return suma;
}



