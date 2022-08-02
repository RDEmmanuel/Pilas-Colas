#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define max 20

typedef char tstring[30];

typedef tstring tCola[max];
tCola pacientes;
int i, frente, final;

void CrearColaVacia();
bool ColaVacia();
bool ColaLlena();
void AgregarPaciente(tstring);
void VisualizarPacientes();
void EliminarPacienteFrenteMovil();
bool HayTurnosDisponibles();
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
	if (final == (max-1))
	return true;
	else
	return false;
}

void AgregarPaciente(tstring pPaciente)
{
	if (!ColaLlena())
	{
		final++;
		strcpy(pacientes[final], pPaciente);
		printf("", pacientes[final]);

		if (final == 0)
		 	frente = 0;
	}
}

void EliminarPacienteFrenteMovil()
{
	if (ColaVacia() == true)
	{
		printf("No hay pacientes por eliminar!\n");
	}
	else
	{	
		printf("Paciente atendido!---> %s\n", pacientes[frente]);
		strcpy(pacientes[frente], "");		
	}
	system("pause");
	system("cls");
	if (frente == final)
	{
		frente = -1;
		final = -1;
	}
	else
		frente = frente + 1;
}

void VisualizarPacientes()
{
	int i;
	printf("Lista de pacientes: \n");
	for (i=frente; i<=final; i++)
	{
		printf("%s\n", pacientes[i]);
	}
	printf("\n");
	system("pause");
	system("cls");
}

bool HayTurnosDisponibles()
{
	
	 if(ColaLlena() == true)
	 {
	 	printf("No hay turnos disponibles\n");
	 }
	 else
	 {
	 	printf("Si hay turnos disponibles\n");
	 }
	 system("pause");
	system("cls");
}

void Menu()
{
	
	int opcion = 0;
	tstring paciente;
	
	printf("1-Agregar un paciente\n");
	printf("2-Lista de pacientes:\n");
	printf("3-Hay turnos disponibles?\n");
	printf("4-Paciente atendido:\n");
	printf("Opcion:");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	
	while(opcion != 0)
	{
	switch (opcion)
	{
		
		case 1:
			{
			int num;
			char respuesta;	
			if (!ColaLlena())
			{														
				do
				{														
				printf("Ingrese nombre del paciente: ");
				gets(paciente); fflush(stdin);
				AgregarPaciente(paciente);
				printf("Paciente agregado!\n\n");
				printf("Desea agregar otro paciente? s/n: ");
				scanf("%s", &respuesta); fflush(stdin);
				
				}while (respuesta != 'n');
				system("pause");
				system("cls");
				printf("\n");
				Menu();
				
			}
			else 
			{
			printf("\n*** Cola Llena ***\n");
			system("pause");
			}
			printf("\n");
			Menu();
			}		
			break;
			
		case 2:
			{
				VisualizarPacientes();
				printf("\n");
				Menu();
			}
			break;
				
		case 3:
			{ 
				HayTurnosDisponibles();
				printf("\n");
				Menu();
			}
			break;
			
		case 4:
			{
				EliminarPacienteFrenteMovil();
				printf("\n");
				Menu();
			}
			break;	
									
	}
	printf("1-Agregar un paciente\n");
	printf("2-Lista de pacientes:\n");
	printf("3-Hay turnos disponibles?\n");
	printf("4-Paciente atendido:\n");
	printf("Opcion:");
	scanf("%d", &opcion); fflush(stdin);
	system("cls");
	}	
}


















