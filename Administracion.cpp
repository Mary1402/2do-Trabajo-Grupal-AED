#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<windows.h>
#include"funciones_y_estructuras.h"


//**********************************FUNCIONES***********************************

void Inicio_de_Sesion();
int MenuPrincipal_Administracion();

//******************************************************************************


main()
{
	setlocale(LC_CTYPE,"spanish");
	system("color 3");
	
	//*****************Datos a utilizar*************
	
	int bandera=1,contrasena;
	char Opcion;
	Datos_Veterianrios Datos;
	
	//**********************************************
	
	Inicio_de_Sesion();//inicio del m�dulo de administracion
	LimpiarPantalla();
	
	do
	{
		Opcion=MenuPrincipal_Administracion();
		switch(Opcion)
		{
			case'a':case'A':
				break;
			case'b':case'B':
				break;
			case'c':case'C':
				break;
			case'd':case'D':
				break;
			case'e':case'E':
				break;
			case'f':case'F':
				bandera=0;
				LimpiarPantalla();
				gotoxy(35,2);
				printf("__________________");
				gotoxy(35,3);
				printf("*FIN DEL PROGRAMA*");
				gotoxy(35,4);
				printf("==================");
				break;
			default:
				gotoxy(25,14);
				printf("=========================================");
				gotoxy(25,15);
				printf("ERROR!!");
				gotoxy(25,16);
				printf("NO SE INGRES� UN OPCI�N V�LIDA");
				break;
		}
		LimpiarPantalla();
		
	}while(bandera==1);
}

void Inicio_de_Sesion()
{
	palabra contrasena1,contrasena2;
	int Cont=0;
	
	FILE * Contrasena_Administracion;
	Contrasena_Administracion=fopen("Clave_Modulo_Administracion","r+b");
	fread(&contrasena1,sizeof(palabra),1,Contrasena_Administracion);
	
	if(Contrasena_Administracion==NULL || strlen(contrasena1)<6)
	{
		fclose(Contrasena_Administracion);
		Contrasena_Administracion=fopen("Clave_Modulo_Administracion","w+b");
		gotoxy(15,2);
		printf("BIENVINIDO AL M�DULO DE ADMINISTRACI�N");
		gotoxy(15,3);
		printf("--------------------------------------------------------------------------------------------");
		gotoxy(15,4);
		printf("COMO ES SU PRIMER INCIO LE PEDIMOS QUE INGRESE LA CONTRASE�A DE INGRESO DE 6 A 36 CARACTERES");
		gotoxy(15,5);
		printf("--------------------------------------------------------------------------------------------");
		gotoxy(15,6);
		printf("CONTRASE�A:");
		gets(contrasena1);
		while((strlen(contrasena1)<6 || strlen(contrasena1)>36) && Cont<3)
		{
			LimpiarPantalla();
			gotoxy(15,2);
			printf("LA CONTRSE�A INGRESADA ES INCORRECTA");
			gotoxy(15,3);
			printf("-----------------------------------------");
			gotoxy(15,4);
			printf("POR FAVOR VUELVA A INGRESAR LA CONTRASE�A");
			gotoxy(15,5);
			printf("-----------------------------------------");
			gotoxy(15,6);
			printf("CONTRASE�A:");
			gets(contrasena1);
		}
		
		if(Cont==3)
		{
			LimpiarPantalla();
			gotoxy(15,2);
			printf("SE EXEDI� EL L�MITE DE INTENTOS PERMITIDO!");
			gotoxy(35,4);
			printf("__________________");
			gotoxy(35,5);
			printf("*FIN DEL PROGRAMA*");
			gotoxy(35,6);
			printf("==================");
			exit(1);
		}
		
		fwrite(&contrasena1,sizeof(palabra),1,Contrasena_Administracion);
		gotoxy(15,8);
		printf("CONTRASE�A GUARDADA CON �XITO!!!");
		gotoxy(15,9);
		printf("-------------------------------------------------------------------");
		gotoxy(15,10);
		printf("CADA QUE VEZ QUE INGRESE A �STE M�DULO SE LE PEDIR� �STA CONTRASE�A");
	}
	else
	{
		gotoxy(15,2);
		printf("BIENVENIDO DE NUEVO!");
		gotoxy(15,3);
		printf("--------------------------------");
		gotoxy(15,4);
		printf("POR FAVOR INGRESE LA CONTRASE�A:");
		gets(contrasena2);
		while(strcmp(contrasena1,contrasena2)!=0 && Cont<3)
		{
			LimpiarPantalla();
			gotoxy(15,2);
			printf("SE INGRES� UNA CONTRASE�A INCORRECTA!!");
			gotoxy(15,3);
			printf("------------------------------------------");
			gotoxy(15,4);
			printf("POR FAVOR,VUELVA A INGRESAR LA CONTRASE�A:");
			gets(contrasena2);
			Cont++;
		}
		if(Cont==3)
		{
			LimpiarPantalla();
			gotoxy(15,2);
			printf("SE EXEDI� EL L�MITE DE INTENTOS PERMITIDO!");
			gotoxy(35,4);
			printf("__________________");
			gotoxy(35,5);
			printf("*FIN DEL PROGRAMA*");
			gotoxy(35,6);
			printf("==================");
			exit(1);
		}
	}
	fclose(Contrasena_Administracion);
}

int MenuPrincipal_Administracion()
{
	char OP;
	
	gotoxy(25,1);
	printf("=========================================");
	gotoxy(37,2);
	printf("MEN� ADMINISTRACION");
	gotoxy(25,3);
	printf("========================================="); 
	gotoxy(25,4);
	printf("a._Registrar Veterinario");
	gotoxy(25,5);
	printf("b._Registrar Asistente");
	gotoxy(25,6);
	printf("c._Atenciones por Veterinarios");
	gotoxy(25,7);
	printf("d._Ranking de Veterinarios por Atenciones");
	gotoxy(25,8);
	printf("e._Mostrar Asistentes");
	gotoxy(25,10);
	printf("f._Cerrar Aplicaci�n");
	gotoxy(25,12);
	printf("Ingrese una opci�n:");
	_flushall();
	scanf("%c",&OP);
	return OP;
}
