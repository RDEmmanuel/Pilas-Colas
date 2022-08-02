#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 8

typedef int tPila[max];
tPila contenedores;

int tope;

void CrearPilaVacia();
bool PilaLlena();
bool PilaVacia();
void ApilarContenedor(int);
void VisualizarContenedores();
void DesapilarContenedor();
void Menu();

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

void ApilarContenedor(int pCont)
{
	if(PilaLlena() != true)
	{
		tope++;
		contenedores[tope] = pCont;
		printf("Contenedor apilado!\n", contenedores[tope]);
	}
	else
	{
		printf("No hay lugar para apilar!\n\n");
	}
}

void VisualizarContenedores()
{
	int i;
	if(PilaVacia() == true)
	{
		printf("No hay contenedores apilados!\n");
		system ("pause");
	}
	else
	{
		printf("\nContenedores en pila: \n");
		for(i=0; i<=tope; i++)
		{
			printf("%d\n", contenedores[i]);
		}
	}
	printf("La cantidad de contenedores en la pila es: %d\n", tope + 1);
	system("pause");
	system("cls");
}

void DesapilarContenedor()
{
	if(PilaVacia() == true)
		{
			printf("No hay contenedores en la pila!!!\n");
		}
		else
		{
			contenedores[tope] = 0;
			tope = tope - 1;
			printf("\nContenedor desapilado!\n\n");
		}
		printf("El contenedor que se encuentra en la cima es: %d\n", contenedores[tope]);
		system("pause");
		system("cls");
}

void Menu()
{
	int menu;
	printf("Opciones del menu:\n");
	printf("1-Apilar un contenedor\n");
	printf("2-Visualizar contenedores en pila\n");
	printf("3-Desapilar un contenedor\n");
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
					if(!PilaLlena())
					{
						printf("Ingrese el codigo del contenedor: ");
						scanf("%d", &num);
						while(num != 0)
						{
							ApilarContenedor(num);
							printf("Ingrese el codigo del contenedor (0 para volver al menu): ");
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
						VisualizarContenedores();
						Menu();
					}
				
				case 3:
					{
						DesapilarContenedor();
						Menu();
						
						
						
					}
		}
		printf("Opciones del menu:\n");
		printf("1-Apilar un contenedor\n");
		printf("2-Visualizar contenedores en pila\n");
		printf("3-Desapilar un contenedor\n");
		printf("Elija una opcion: ");
		scanf("%d", &menu);
		system("cls");
	}
}
















