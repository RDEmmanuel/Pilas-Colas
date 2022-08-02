#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

typedef float tPila[max];
tPila pila;
int tope;

void CrearPilaVacia();
bool PilaLlena();
bool PilaVacia();
void Apilar(float);
void VisualizarElementos();
void EliminarElemento();
float Sumar();
void Menu();

int main()
{
	Menu();
	return 0;
}

void CrearPilaVacia()
{
	tope = -1;
}

bool PilaVacia()
{
	return(tope == -1);
}

bool PilaLlena()
{
	if (tope == (max-1))
		{
			return true;
		}
		else
		{
			return false;
		}
}

void Apilar(float pElemento)
{
	if (PilaLlena() != true)
	{
		tope = tope + 1;
		pila[tope] = pElemento;
		printf("Elemento Insertado!\n", pila[tope]);
	}
	else
	{
		printf("Pila Llena!\n");
	}
}

void EliminarElemento()
{
	if(PilaVacia())
	printf("No hay elementos por eliminar!\n");
	else 
	{
		pila[tope] = 0;
		printf("Elemento eliminado!\n");
	}
	tope = tope - 1;
}

void VisualizarElementos()
{
	int i;
	printf("Elementos en pila: \n");
	for (i=0; i<=tope; i++)
	{
		printf("%.2f\n", pila[i]);
	}
}

float Sumar()
{
	float suma = 0.0;
	int i;
	for (i=0; i<=tope; i++)
	{
		suma = suma + pila[i];
	}
	return suma;
}

void Menu()
{
	int menu;
	CrearPilaVacia();
	
	printf("Menu de opciones\n");
	printf("0.Salir\n");
	printf("1.Agregar Elemento\n");
	printf("2.Eliminar Elemento\n");
	printf("3.Suma Total\n");
	printf("4.Mostrar Elementos\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &menu);
	system ("cls");
	
	while(menu != 0)
	{
		switch(menu)
		{
			case 1:
				{
					float num;
					if (!PilaLlena())
					{
					printf("Ingrese un numero Real (0.0 = fin):");
					scanf("%f", &num); 
						while (num != 0.0)
						{
							Apilar(num);
						printf("Ingrese un numero Real (0.0 = fin):");
						scanf("%f", &num); 
						}
					}
					else
					{
					printf("Pila Llena!\n");
					}
				break;
				}
			case 3:
				{
					float sumaTotal = Sumar();
					printf("El valor de suma es: %.2f\n", sumaTotal);
					break;
				}
			case 2:
				{
					EliminarElemento();
					
				}break;
				
			case 4:
				{
					VisualizarElementos();
				}break;
		}
		
		system("pause");
		system("cls");
		printf("Menu de opciones\n");
		printf("0.Salir\n");
		printf("1.Agregar Elemento\n");
		printf("2.Eliminar Elemento\n");
		printf("3.Suma total\n");
		printf("4.Mostrar Elementos\n");
		printf("Ingrese una opcion ");
		scanf("%d", &menu);
		system ("cls");  
	}
}


































