#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max 12

typedef float tPila[max];
tPila pila;

int tope;

void CrearPilaVacia();
bool PilaLlena();
bool PilaVacia();
void AgregarDisco(float);
void Listado();
void DiscoEnTope();
void EliminarDisco();
void Menu();
float Promedio();
void CantidadDeDiscos();

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

bool PilaVacia()
{
	return(tope == -1);
}

bool PilaLlena()
{
	return(tope == (max-1));
}

void AgregarDisco(float pElem)
{
	if(!PilaLlena())
	{
		tope++;
		pila[tope] = pElem;
		printf("Disco apilado!\n", pila[tope]);
	}
	else
	{
		printf("La pila esta llena!\n");
	}
}

void EliminarDisco()
{
	if(PilaVacia())
	printf("No hay discos apilados!\n");
	else
	{
		pila[tope] = 0;
	}
	tope = tope - 1;
	system("pause");
	system("cls");
}

void Listado()
{
	int i;
	printf("Discos en la pila: \n");
	for (i=0; i<=tope; i++)
	{
		printf("%.2f\n", pila[i]);
	}
	system("pause");
	system("cls");
}

void DiscoEnTope()
{
	printf("El peso del disco que se encuentra en el tope es: %.2f\n", pila[tope]);
	system("pause");
	system("cls");
}

void CantidadDeDiscos()
{
	printf("La cantidad de discos en la pila es: %d\n", tope + 1);
	system("pause");
	system("cls");
}

float Promedio()
{
	float suma = 0.0;
	float prom = 0.0;
	int i;
	for (i=0; i<=tope; i++)
	{
		suma = suma + pila[i];
	}
	prom = suma / (tope + 1);
	printf("El promedio de peso de los discos en la pila es: %.2f\n", prom);
	system("pause");
	system("cls");
}


void Menu()
{
	int opcion;
	
	printf("*** Opciones del menu ***\n");
	printf("0-Salir\n");
	printf("1-Agregar disco a la pila\n");
	printf("2-Listado de discos en la pila\n");
	printf("3-Disco en el tope\n");
	printf("4-Promedio de peso de los discos\n");
	printf("5-Cantidad de discos en la pila\n");
	printf("6-Quitar disco de la pila\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion); 
	system("cls");
	
	while(opcion != 0)
	{
		switch(opcion)
		{
			case 1:
				{				
					float num;
					if(PilaLlena() != true)
					{
						printf("Ingrese el peso del disco a apilar(0 para mostrar el menu): ");
						scanf("%f", &num);
							while(num != 0.0)
							{							
								AgregarDisco(num);
								printf("Ingrese el peso del disco a apilar(0 para mostrar el menu): ");
								scanf("%f", &num);
							}
							system("pause");
							system("cls");
					}
					else
					{
						printf("Pila Llena!\n");
					}
				}
				break;
				
			case 2:
				{
					Listado();
				}
				break;
				
			case 3:
				{
					DiscoEnTope();
				}
				break;
				
			case 4:
				{
					Promedio();
				}
				break;	
				
			case 5:
				{
					CantidadDeDiscos();
				}
				break;
			case 6:
				{
					EliminarDisco();
				}
		}
		
		printf("\n*** Opciones del menu ***\n");
		printf("0-Salir\n");
		printf("1-Agregar disco a la pila\n");
		printf("2-Listado de discos en la pila\n");
		printf("3-Disco en el tope\n");
		printf("4-Promedio de peso de los discos\n");
		printf("5-Cantidad de discos en la pila\n");
		printf("6-Quitar disco de la pila\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion); 
		system("cls");
	}


}


































