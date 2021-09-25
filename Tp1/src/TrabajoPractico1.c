#include "Bibliotecas.h"

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	int numero1;
	int numero2;
    int suma;
    int resta;
    int multiplicacion;
    float division;
	int factorial1;
	int factorial2;
	int flag1=0;
	int flag2=0;
	int flag3=0;

	printf("Esta es la calculadora de Franco Donato Gonzalez.\n\n");

	do
	{
		system("cls");
		opcion=menuOpciones(numero1, numero2, flag1, flag2);

	switch(opcion)
	{
		case 1:if(flag1==0)
		{
			printf("\nIngrese el primer numero:\n");
			scanf("%d", &numero1);
			flag1++;
		}
		else
		{
			printf("\nReingrese el primer numero:\n");
			scanf("%d", &numero1);
			flag3=0;
		}
			break;
		case 2:if(flag2==0)
		{
			printf("\nIngrese el segundo numero:\n");
			scanf("%d", &numero2);
			flag2++;
		}
		else
		{
			printf("\nReingrese el segundo numero:\n");
			scanf("%d", &numero2);
			flag3=0;
		}

			break;
		case 3:
			if(flag1==0 || flag2==0){
				printf("Antes debe ingresar ambos numeros.");
			}
			else
			{
			suma=sumaAB(numero1, numero2);
			resta=restaAB(numero1, numero2);
			multiplicacion=multiplicacionAB(numero1, numero2);
			if(numero2!=0){
				division=divisionAB(numero1, numero2);
			}
			factorial1=factorialA(numero1);
			factorial2=factorialA(numero2);
			flag3++;
			printf("\n\nCalculos realizados con exito! ...");
			}
			break;
		case 4:
			if(flag3==0){
				printf("Antes debe realizar los calculos ...");
			}
			else
				if(flag3==1){
					printf("\na)La suma entre %d y %d es: %d", numero1, numero2, suma);
					printf("\nb)La resta de %d y %d es: %d", numero1, numero2, resta);
					printf("\nc)La multiplicacion entre %d y %d es: %d", numero1, numero2, multiplicacion);
					if(numero2==0){
						printf("\nd)No es posible dividir por 0...");
					}
					else
					{
						printf("\nd)La division entre %d y %d es: %.2f", numero1, numero2, division);
					}
					if (numero1>1){
						printf("\ne)El factorial de %d es: %d", numero1, factorial1);
					}
					else
					{
						printf("\ne)No es posible realizar el factorial de %d porque es negativo.", numero1);
					}
					if(numero2>1){
						printf("\nf)El factorial de %d es: %d ", numero2, factorial2);

					}
					else
					{
						printf("\nf)No es posible realizar el factorial de %d porque es negativo.", numero2);
					}
				}

			break;
		case 5:
			printf("\n\nMuchas gracias por utilizar la calculadora! Adios.");
			break;
		default:
			printf("\n\nError! Ingrese una opcion valida");
			break;
	}
	 system("pause");
	}while(opcion!=5);

}
