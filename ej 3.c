#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 20

typedef int tPila[max];
tPila pila;

int tope;

void CrearPilaVacia();
bool PilaLlena();
bool PilaVacia();
void ApilarTv(int);
void ListadoDeTv();
void Menu();
void DesapilarTv();


int main()
{
	CrearPilaVacia();
	Menu();
	
	return 0;
}

void CrearPilaVacia()
{
	tope = -1;
}

bool PilaLlena()
{
	if(tope == (max-1))
	return true;
	else
	return false;
}

bool PilaVacia()
{
	if(tope == -1)
	return true;
	else
	return false;
}

void ApilarTv(int pTelevisor)
{
	if(!PilaLlena())
	{
		tope++;
		pila[tope] = pTelevisor;
		printf("Televisor apilado!\n", pila[tope]);		
	}
	else
	{	
		printf("\nLa pila esta llena!\n\n");
	}
	
}

void ListadoDeTv()
{
	int i;
	if (PilaVacia() == true)
	{
		printf("\nNo hay televisores apilados!\n\n");
		
	}
	else
	{
	printf("\nListado de Televisores en la pila: \n");
		for (i=0; i<=tope; i++)
		{	
			printf("%d\n", pila[i]);
			
		}
		
		
	}
	
	printf("La cantidad de Televisores apilados es: %d", tope + 1);
	printf("\n");
	system("pause");
	system("cls");
}

void DesapilarTv()
{
	if(PilaVacia())
		printf("No hay televisor por desapilar!\n");
	else
	{
		pila[tope] = 0;
		tope = tope - 1;
		printf("\nTelevisor Desapilado!\n\n");
	}
	printf("El televisor que se encuentra en el tope es: %d\n", pila[tope]);
	system("pause");
	system("cls");
}

void Menu()
{
	int menu;
	printf("--- Opciones del menu ---\n");
	printf("1-Apilar Televisor\n");
	printf("2-Listado de televisores\n");
	printf("3-Desapilar un televisor\n");
	printf("Elija una opcion: ");
	scanf("%d", &menu);
	system("cls");
	
	while (menu != 0)
	{
		switch(menu)
		{
			case 1:
				{
					int num;
					if (!PilaLlena())
					{
						printf("Ingrese las pulgadas del televisor: ");
						scanf("%d", &num);
						while(num != 0)
						{
							ApilarTv(num);
							printf("Ingrese las pulgadas del televisor (0 para mostrar menu): ");
							scanf("%d", &num);																																		
						}
						system("pause");
						system("cls");
					}
					else
					printf("Pila Llena!\n");
				}
				break;
				
			case 2:
				{
					ListadoDeTv();
					Menu();
				}
				break;
				
			case 3:
				{
					DesapilarTv();
					Menu();
				}	
		}
	printf("\n");	
	printf("--- Opciones del menu ---\n");
	printf("1-Apilar Televisor\n");
	printf("2-Listado de televisores\n");
	printf("3-Desapilar un televisor\n");
	printf("Elija una opcion: ");
	scanf("%d", &menu);
	system("cls");
	}
	
	
	
	
	
}

