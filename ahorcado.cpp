//programa del juego del ahorcado
#include <iostream>//para el system cls
#include <stdio.h>//para printf y scanf
#include <conio.h>//para getch 
#include <string.h>//para la funcion tolower
//prototipos de funciones
void menu();
void mapa(int);
int juego(char jugador1[30],char palabra1[10]);
void modificar(char palabra[8],char letra,int posicion);
void vidas(int,char palabra[8]);
int verificar(int i,bool r);
void ganar(int);
int main(){
	menu();
	return 0;
}
//Menu
/*Este apartado presenta lo que se desea hacer en nuestro  programa contiene un ciclo do while el cual lleva el control de las opciones un switch para la opcion deseada*/
void menu(){
	int opcion;
	char jugador1[30],palabra1[10],palabra2[10];	
	bool respuesta;
	do{	

	system("cls");
	printf("\t\t\t\t\t\tIngresa la opcion deseada\n");
	printf("\t\t\t\t\t\t1-Registrar\n");
	printf("\t\t\t\t\t\t2-Jugar\n");
	printf("\t\t\t\t\t\tOpcion: ");
	scanf("%d",&opcion);
	 switch(opcion){
	 	case 1:
	 //se desea registrar a los jugadores antes de empezar a jugar			
	 system("cls");
	 puts("\t\t\t\t\t\tIngresa un nombre jugador: ");
	 scanf("%s",jugador1);
	 puts("\t\t\t\t\t\tGracias por registrarse");
	 respuesta=true;
	 	break;
	 	case 2:
	 		//Evalua la opcion si es verdadera no smanda a jugar si no se debe de registrar otra vez
	 		if(respuesta==true){
	 		 system("cls");
	 		 //Se pide una palabra
	 		 printf("Ingresa una palabra de 7 letras: ");
	 		 scanf("%s",palabra1);
	 		 //se evalua si la palbra cumple con la condicion 
	 		  if(strlen(palabra1)==7){
	 		   printf("\t\t\t\t\t\tVamos a jugar"); 
			   getch();//nos da un pause
			   system("cls");
			   //se tranforma una palabra posicion por posion a minusculas en caso de que sea mayuscula
			   for(int i=0;i<7;i++){
			   	palabra2[i]=tolower(palabra1[i]);
			   }
			   //Se manda a jugar despues de todo lo anterior
	 		   juego(jugador1,palabra2);
	 		   respuesta=false;
			   }
		       //En caso de no se cumpla se debe de volver a ingresar la palabra
			   else{
			   	printf("La palabra no tiene 7 letras\n");
			   }
			 }
			 else{
			 printf("\t\t\t\t\t\tNecesitas registrarte");
			 getch();//nos da un pause
			 }
	 	break;
	 }	
	}while(opcion>0 || opcion<3);
}
//Mapa
//La funcion del mapa resive un argumento en el cual de acuerdo a lo mandado se tendra que hacer una operacion gracias al switch
void mapa(int vidas){
	switch(vidas){
	 case 0: 
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |");
	 puts("       |");
	 puts("       |");
	 puts("       |");
	 puts("_______|___________");
	 break;	
	 case 1:
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |             O");
	 puts("       |");
	 puts("       |");
	 puts("       |");
	 puts("_______|___________");
	 break;
	 case 2:
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |             O");
	 puts("       |             |");
	 puts("       |");
	 puts("       |");
	 puts("_______|___________");
	 break;
	 case 3:
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |             O");
	 puts("       |             |");
	 puts("       |             |");
	 puts("       |");
	 puts("_______|___________");
	 break;
	 case 4:
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |             O");
	 puts("       |           --|--");
	 puts("       |             |");
	 puts("       |"); 
	 puts("_______|___________");
	 break;
	 case 5:
	 puts("        _____________");
	 puts("       |             |");
	 puts("       |             O");
	 puts("       |           --|--");
	 puts("       |            _|_");
	 puts("       |          _|   |_");
	 puts("_______|___________");
	 break;
	 case 6:
	 puts("       _____________");
	 puts("      |             |");
	 puts("      |             O");
	 puts("      |           --|--");
	 puts("      |            _|_");
	 puts("      |          _|   |_");
	 puts("______|////////////////////");
	 break;
	}
}
//Juego
//Esta funcion realiza el juego lleva contadores cadenas de caracteres y caracteres
int juego(char jugador1[30],char palabra1[10]){
	int i=0,contar_letra=0,pos=0,letras=0;//contadores 
	char palabra[8]="*******",letra,letra2;//cadenas de letras y un caracter
	bool r=false,band=false;//bandera
	printf("\nAdivina la palabra: %s\n",jugador1);
	getch();
	do{
	//Borra la pantalla
	system("cls");
	//funcion de vidas
		vidas(i,palabra);
		//se pide una letra
		puts("\nIngresa una letra: ");
		fflush(stdin);//limpia la entrada
		scanf("%c",&letra);
		letra2=tolower(letra);//TRANFORMA UNA LETRA MAYUSCULA A MINUSCULA
		//se busca en la palabra se la letra ya fue intrducida en caso de que si este se pone una bandera en verdadera
		for(int k=0;k<7;k++){
			if(letra2==palabra[k]){
				band=true;
			}
		}
		//si la bandera es falsa se busca la letra ingresada con la palabra a adivinar 	
		if(band==false){
		//se busca la letra comparando uno a uno en la cadena de caracteres
	      for(int j=0;j<7;j++){	
	      //en caso de que se encuentre 
		    if(letra2==palabra1[j]){
		    r=true;//la bandera vale verdadera
		    contar_letra++;//se incrementa el contador de letras
		    pos=j;//se guarda la posicion en donde se encontro
		    modificar(palabra,letra2,pos);//funcion que modifica
		    }
	      }
	      //se manda a i para verificar si se termino el juego y debe de estar a dentro para que se incrementen las vidas gastadas
	      i=verificar(i,r);
		}
		//en caso de que la letra ya exista en la modificada se manda un mensaje de que ya existe
		else{
		printf("Letra ya introducida\n");
		}
	    //se increnta la canidad de letras para determinar un conteo total de las letras que fueron correctas
	    letras=letras+contar_letra;
	    //la bandera se cambia a falso para que comienze una nueva iteracion
	    r=false;
	    //el contador se cambia a 0 para contar desde cero las letras que se encontraron
	    contar_letra=0;
	    //se evalua el contador de las letras en caso de que sea mayor o igual a 7 el juego se debe terminar gracias al break
	    if(letras>=7){
	    	system("cls");
	    	vidas(i,palabra);
	    	
	    break;
	    }
	    //la bandera se actualiza para verificar de nuevo la existencia de una letra
		band=false;
	}while(i!=7);//se evalua la cantidad de vidas mientras sea diferente de 7 se hace una iteracion
	ganar(i);//funcion de ganar
}
//Modificar 
//La funcion  de modificar como su nombre lo dice modifica la letra que fue encontrada de acuerdo a  la palabra enviada tambien recibe la posicion para que pueda ser modificada
void modificar(char palabra[8],char letra,int posicion){
	//for que recorre de  a 
for(int i=0;i<7;i++){
	//se compara  la posicion recorrida con la enviada para poder modificar esa posicion
		if(i==posicion){
		//como si se cumplio la condicion se le asigna a esa posicion un nuevo valor que es la letra
	    palabra[i]=letra;
		}
	}
}
//Vidas
//L funcion se encarga de verificar las vidas resiviendo la posicion i y la palbra 
void vidas(int i,char palabra[8]){
	//se evalua en caso de que las vidas sean menor que 6 se mustra un mensaje incluyendo el mapa que se es mostrado
	if(i<6){
	printf("\nCantidad de vidas gastadas: %d\n",i);
	mapa(i);
	printf("%s",palabra);
	}
	//en caso contraria mustra un mensaje diferente
	else{
	printf("\nTodas las vidas se agotaron\n");
	mapa(i);
	printf("%s",palabra);
	}
}
//verificar
//La funcion incrementa o deja igual las vidas las cuales resive como arguementos y resive la bandera
int verificar(int i,bool r){
	//si la bandera  positiva de un mensaje	donde encontrada la letra en la palabra y la variable de las vidas que es i se mantiene con su valor actual
	if(r==true){
	printf("Muy bien");
	i=i;
    getch();	
	}
//bandera y  los   datos de locontrario si la bandera llega como falsa se imprime un mensaje de erro ya que no se encontro la letra presionada y se incrementa la i 
	if(r==false){
	printf("La letra que marcaste no existe\n");
	i++;
	getch();
	}
	return i;//se retorna el valor actual de la variable de vidas
}
//Ganar
//Esta funcion comprueba con la ayuda del arguemto de las vidas para ver si se gano o perdio 
void ganar(int i){
	//si i es menor que 7 es por que se ha ganado 
	if(i<7){
	printf("\nFELICIDADES GANASTE\n");
	system("pause");//pausa el mensaje
	}
	//si es mayor o igual a 7 se a perdido
	else{
	printf("\nQUE TRISTEZA PERDISTES\n");
	system("pause");
	}
}
