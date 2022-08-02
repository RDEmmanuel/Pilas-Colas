#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define max 20

typedef char tstring [30];

typedef tstring tCola[max];
tCola cola;
int frente, final;

void CrearColaVacia();
bool ColaLlena();
bool ColaVacia();
void AgregarVehiculo(tstring);
void EliminarVehiculoFrenteFijo();
void ListadoDeVehiculos();
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

bool ColaLlena()
{
	if(final == (max-1))
		return true;
	else
		return false;
}

bool ColaVacia()
{
	if ((frente == -1) && (final == -1))
		return true;
	else
		return false;
}

void AgregarVehiculo(tstring pVehiculo)
{
	if(!ColaLlena())
	{
		final++;
		strcpy(cola[final], pVehiculo);
		/*printf("", cola[final]);*/
	}
	else
		{
		printf("No hay lugar en el carril!\n");
		}
		 
		if (final == 0)
			frente = 0;
}

void EliminarVehiculoFrenteFijo()
{
	int i;
	if(ColaVacia())
		printf("No hay vehiculo por eliminar!\n");
	else
	{
		strcpy(cola[frente], "");
		printf("Vehiculo eliminado!\n\n");
		system("pause");
		
		for (i=frente; i<=final-1 ; i++)
		{
			strcpy(cola[i], cola[i + 1]);
		}
		strcpy(cola[final], "");
		
		if(frente == final)
		{
			frente = -1;
			final = -1;
		}
		else
			final = final - 1;
	}
	system("pause");system("cls");
}

void ListadoDeVehiculos()
{
	int i;
	if(ColaVacia())
	{	
		printf("No hay vehiculos en el carril!\n");
	}
	else
	{
		printf("Lista de vehiculos en el carril: \n");
		for (i = frente; i <= (final); i++)
		{
			printf("%s \n", cola[i]);
		}
		printf("\n");
		printf("La disponibilidad de vehiculos en este carril es: %d\n\n", (max-1) -final);
	}
	system("pause");
	system("cls");
}

void Menu()
{
	int opcion = 0;
	tstring vehiculo;
	
	printf("*** Opciones disponibles ***\n");
	printf("1-Agregar Vehiculo al carril\n");
	printf("2-Quitar Vehiculo del carril\n");
	printf("3-Lista de vehiculos en el carril\n");
	printf("Opcion: ");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	
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
							printf("Ingrese la matricula del vehiculo: ");
							scanf("%s", &vehiculo); fflush(stdin);
							AgregarVehiculo(vehiculo);
							printf("Vehiculo agregado!\n", cola[final]);
							printf("\nDesea seguir ingresando datos? s/n: ");
							scanf("%c", &rta); fflush(stdin);
							
						}while(rta != 'n');
						system("pause");
						system("cls");
						Menu();
					}
					else 
					{
						printf("El carril esta lleno!!!!!\n");
						system("pause");
					}
					printf("\n");
					Menu();
				}
				break;
				
				case 2:
					{
						EliminarVehiculoFrenteFijo();
						printf("\n");
						Menu();
					}
					break;
					
				case 3:
					{
						ListadoDeVehiculos();
						
	
						printf("\n");
						system("pause");
						Menu();
					}
					break;
				
				
		}
		printf("*** Opciones disponibles ***\n");
		printf("1-Agregar Vehiculo al carril\n");
		printf("2-Quitar Vehiculo del carril\n");
		printf("3-Lista de vehiculos en el carril\n");
		printf("Opcion: ");
		scanf("%d", &opcion); fflush(stdin);
		system("cls");
	}
}






















