#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 30

typedef char tstring[30];

typedef tstring tCola[max];
tCola cola;

int frente, final;

void CrearColaVacia();
bool ColaVacia();
bool ColaLlena();
void RegistrarEmbarcacion(tstring);
void EliminarEmbarcacionFrenteFijo();
void ListadoEmbarcaciones();
void Menu();

int main()
{
	CrearColaVacia();
	Menu();
	return 0;
}

void CrearColaVacia()
{
	frente = -1;
	final = -1;
}

bool ColaVacia()
{
	return ((frente == -1) && (final == -1));
}

bool ColaLlena()
{
	return (final == (max-1));
}

void RegistrarEmbarcacion(tstring pBarco)
{
	if(ColaLlena())
	printf("No hay lugar!\n");
	else 
	{
		final++;
		strcpy(cola[final] , pBarco);		
	}
	if (final == 0)
		frente = 0;
}

void EliminarEmbarcacionFrenteFijo()
{
	int i;
	if(ColaVacia())
		printf("No hay embarcaciones en cola!\n");
	else
	{
		strcpy(cola[frente], "");
		printf("Embarcacion eliminada!\n");
		system("pause");
		
		for(i=frente; i<=final-1; i++)
		{
			strcpy(cola[i], cola[i + 1]);
		}
		strcpy(cola[final], "");
		
		if (frente == final)
		{
			frente = -1;
			final = -1;
		}
		else 
			final = final -1;
	}
}

void ListadoEmbarcaciones()
{
	int i;
	if(ColaVacia())
		printf("No hay embarcaciones en cola!\n");
	else
	{
		printf("Listado de embarcaciones en cola: \n");
		for (i=frente; i<=final; i++)
		{
			printf("%s \n", cola[i]);
		}
		printf("\n");
		printf("La disponibilidad de lugar en la cola es: %d", (max-1) - final);
	}
}

void Menu()
{
	int opcion = 0;
	tstring barco;
	
	printf("*** Opciones disponibles ***\n");
	printf("1-Registrar embarcacion\n");
	printf("2-Quitar embarcacion de la cola\n");
	printf("3-Lista de embarcaciones\n");
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	
	while (opcion != 0)
	{
		switch (opcion)
		{
			case 1:
				{
				char rta;
					if(!ColaLlena())
					{											
						do
						{
							printf("Ingrese el nombre de la embarcacion: ");
							scanf("%s", &barco); fflush(stdin);
							RegistrarEmbarcacion(barco);
							printf("Embarcacion registrada!\n", cola[final]);
							printf("\nDesea seguir ingresando datos? s/n:\n");
							scanf("%c", &rta); fflush(stdin);
							printf("\n");
						}while(rta != 'n');
						Menu();
					}
					else 
					{
						printf("La cola esta llena!!!!!\n");
						system("pause");
					}
					printf("\n");
					Menu();
				}
				break;
				
				case 2:
					{
						EliminarEmbarcacionFrenteFijo();
						printf("\n");
						Menu();
					}
					break;
					
				case 3:
					{
						ListadoEmbarcaciones();
						printf("\n");
						system("pause");
						Menu();
					}
					break;
		}
	printf("*** Opciones disponibles ***\n");
	printf("1-Registrar embarcacion\n");
	printf("2-Quitar embarcacion de la cola\n");
	printf("3-Lista de embarcaciones\n");
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	
	}
}












