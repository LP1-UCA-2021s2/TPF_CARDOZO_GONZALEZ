#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int i, j,n=0;// contador, tamaño tablero
int aux=0;// validacion para punto 2
int x=0;// validacion para finalizar juego
int turno=1;//carga de matriz
int user=0;//usuario
int user1[2]={0,0};//vector de usuario para puntajes
int m1=0;// validacion para mensaje de bienvenida para tamaño tablero
int m2=0;// validacion para mensaje de bienvenida  quien inicia y color
char matriz[30][30];// 
int fila[1000],columna[1000];//2vectores para la seleccion random
int pf1=1,pc1=1,pf2,pc2;//Posiciones para los puntos
int aux1=0;//validacion para punto 1
int aux2;//guardamos el valor del puntaje para verificar si aumenta
int lf,lc;//guardar punto
int band=0;//contador de conexiones
int aux3=0,aux4=0;//verificador de lineas ocupadas
int fin=0;//fin del juego, si no hay espacios disponibles
int y,z,w;//para menu inicializar
void inicio(void){
	printf("\n*************************************************");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*\t\tBIENVENIDO AL JUEGO!!!\t\t*");
	printf("\n*\t\tDOTS AND BOXES\t\t\t*");
	printf("\n*\t\t\t\t\t\t*");
	printf("\n*************************************************");
}
void tablero(void){
	if (m1==0){
		while (y<1 || y>2 ){
			printf("\n\nPresione 1, si desea ingresar por teclado el tamaño del tablero: ");
			printf("\n\nPresione 2, si desea generar aleatoriamente el tamaño del tablero: \n");
			scanf("%d",&y);//leer 1 o 2
			if (y==1){
				while (n<3 || n>15 ){
				printf("\n\nIngrese el tamaño de la matriz: ");
				scanf("%d",&n);
				}	
			}else if(y==2){
				while (n<3){ //|| n>15
					n=rand()%16;//genera del 1 al 15		
				}
			}
			//printf("n es %d",n);
			n=n+(n-1);//para tablero real
			
			//printf(",n tablero %d",n);
			m1=1;
		}
	
	}
}
void jugador(void){
	while (z<3 || z>4){
		printf("\n\nPresione 3, si desea ingresar por teclado quien inicia el juego: ");
		printf("\n\nPresione 4, si desea generar aleatoriamente quien inicia el juego: \n");
		scanf("%d",&z);
		if(z==3){
			while (user<1 || user>2){
				printf("Seleccionar jugador inicial\n");
				printf("\n1: Jugador, 2:Computadora\n");
				scanf("%d",&user);//leer user 1 o 2
			}	
		}else if(z==4){
			user=1+rand()%2;//sumar uno al random para limitarlo entre 1 user o 2 compu		
		}
	}
	while (w<5 || w>6){
		printf("\n\nPresione 5, si desea ingresar por teclado su color: ");
		printf("\n\nPresione 6, si desea generar aleatoriamente los colores: \n");
		scanf("%d",&w);
		y=0;
		if(w==5){
			while (y<1 || y>2){
				printf("Seleccione su color\n");
				printf("\npresione 1 para Rojo\npresione 2 para Azul\n");
				scanf("%d",&y);
			}	
		}else if(w==6){
			y=1+rand()%2;//sumar uno al random para limitarlo entre 1 rojo o 2 azul
		}
		m2=1;
	}
}
void turnos(void){
	if (pf1!=99){
		printf("\n\n\n**************************");
		printf("\nTurno del Jugador:%d",user);
		if(user==1 && y==1){//y color rojo
			printf("\nCOLOR: ROJO");
		} else if(user==1 && y==2){// y color azul
			printf("\nCOLOR: AZUL");
		} else if(user==2 && y==1){
			printf("\nCOLOR: AZUL");
		} else if(user==2 && y==2){
			printf("\nCOLOR: ROJO");
		}
		printf("\n**************************\n");	
	}
}
void carga_matriz(void){
	if (turno==1){
		for(i=0; i<n; i++){
		printf("\n");
			for(j=0; j<n; j++){
				if (i%2==0 && j%2==0){//colocar los astericos en las posiciones de fila y columna que son multiplos de 2
					matriz[i][j]='*';//carga astericos//////
				}else matriz[i][j]='0';//cargado de la matriz
				printf("%c",matriz[i][j]);//imprimir matriz
			}
		}	
	}
	turno++;
		
	printf("\n");
}
void verificar_aleatorio(void){
	aux1=0;//para que solicite la carga de P1
	fin=0;//para que cambie en 1 si solo si en el siguente for encuentra una jugada posible
	z=0;//contador de los posibles puntos a seleccionar por random
	for (i=0;i<n;i++){
		for (j=0;j<n;j++){
			if (matriz[i][j]=='0'){
				fin=1;//condicion para que el juego continue
			}
			//verificacion para seleccion de P1 para random
			if (matriz[i][j]=='*'){
				if(matriz[i+1][j]=='0'){//conexion abajo
					fila[z]=i;//guardar esa posicion en vector fila
					columna[z]=j;//guardar esa posicion en vector columna
					z++;
				}
				if(matriz[i][j+1]=='0'){//conexion derecha
					fila[z]=i;
					columna[z]=j;
					z++;
				}
				if(matriz[i-1][j]=='0'){//conexion arriba
					fila[z]=i;
					columna[z]=j;
					z++;
				}
				if(matriz[i][j-1]=='0'){//conexion izq
					fila[z]=i;
					columna[z]=j;
					z++;
				}
			}
		}
	}
}
void game_over(void){
	if (fin==0){//condicion GAME OVER
		printf("GAME OVER");
		x=1;//condicion para que no vuelva a repetir turnos
		aux1=1;// condicion para que no pida p1
		pf1=99;	//condicion para que no pida p2
		//agregar ganador	
		if (user1[0]>user1[1]){//compara vector de puntaje
			printf("\nyou win");
		}else if(user1[0]<user1[1]){
			printf("\nyou lose");
		}else{
			printf("\nit's a tie");
		}
	}
}
void punto1(void){			
	if(user==1){
		printf("Ingrese el punto 1: \n");
		printf("\nEn el caso que quiera terminar el juego presione 99 \n");
		printf("fila: ");
		scanf("%d",&pf1);
		if (pf1!=99){
			pf1=pf1-(2-pf1);//traducir fila a posiciones 
		}
		if (pf1==99){
			x=1;
			aux1=1;
		}	
	}else{
		w=rand()%(z);//z se carga al final de cada carga de losvectores, por ende el ultimo z++ no llevara ningun valor util.
		pf1=fila[w];//compu
	}
	
	if(user==1 && pf1!=99){
		printf("columna: ");
		scanf("%d",&pc1);//user
		pc1=pc1-(2-pc1);//traducir columna a posiciones
	}else if(pf1!=99){
		pc1=columna[w];//compu
	}
	
	/*printf("\nP1(%d,%d) ",pf1,pc1);
	for(i=0;i<z;i++){
		printf("\nV%d(%d,%d) ",i,fila[i],columna[i]);
	}*/
	
	if (pf1%2==0 && pc1%2==0 && pf1>=0 && pf1<=n && pc1>=0 && pc1<=n){//verificar fila o columna sea par, y no se encuentre fuera
		/////////para que pida cargar de nuevo el punto 1//////
		if(pf1-1>=0){//verificar que haya una jugada posible
			aux4++;//contador jugadas posibles
			if(matriz[pf1-1][pc1]=='|'){
				aux3++;		//jugadas realizadas arriba
			}
		}
		if(pc1+1<=(n-1)){//verificar que haya una jugada posible derecha
			aux4++;
			if(matriz[pf1][pc1+1]=='-'){
				aux3++;		
			}
		}
		if(pf1+1<=(n-1)){//verificar que haya una jugada posible aabajo
			aux4++;//contador posiciones posibles
			if(matriz[pf1+1][pc1]=='|'){
				aux3++;		
			}
		}
		if(pc1-1>=0){//verificar que haya una jugada posible izquierda
			aux4++;//contador posiciones posibles
			if(matriz[pf1][pc1-1]=='-'){
				aux3++;		
			}
		}
		if(aux4!=aux3){//punto ocupado,vuelve a pedir ingresar
			aux1=1;	
		}
	//	printf("\njuagadas posibles:%d jugada hechas:%d",aux4,aux3);
		aux3=0;
		aux4=0;

		//printf("\npunto 1 (%d , %d)",pf1 ,pc1);

	}else if(pf1==99){
		printf("Game over\n");
		printf("\nPuntaje del user 1:%d",user1[0]);
		printf("\nPuntaje del user 2:%d",user1[1]);
		if (user1[0]>user1[1]){//compara vector de puntaje
			printf("\n\nyou win");
		}else if(user1[0]<user1[1]){
			printf("\n\nyou lose");
		}else{
			printf("\n\nit's a tie");
		}
		//////////////////////////if
	}
		
}
void punto2(void){	
	if(user==1){
		printf("Ingrese el punto 2: \n");
		printf("fila: ");
		scanf("%d",&pf2);
		pf2=pf2-(2-pf2);
			
	}else{
		pf2=rand()%(n);
		//printf("\nfila random %d",pf2);
	}
	
	if(user==1){
		printf("columna: ");
		scanf("%d",&pc2);
		pc2=pc2-(2-pc2);
	}else{
		pc2=rand()%(n);
		//printf("\ncolumna random %d",pc2);
	}
	if (pf2==pf1-2 && pc2==pc1 && pf2>=0){//arriba
		if(matriz[pf1-1][pc1]=='0' ){
			matriz[pf1-1][pc1]='|';//conexion de puntos
			lf=pf1-1;
			lc=pc1;
			aux=1;	
		//	printf("\npunto 2 (%d,%d)",pf2,pc2);
		}
	
	}else if(pf2==pf1 && pc2==pc1+2 && pc2<=n){//derecha
		if(matriz[pf1][pc1+1]=='0' ){
			matriz[pf1][pc1+1]='-';//conexion de puntos
			lf=pf1;
			lc=pc1+1;
			aux=1;	
			//printf("\npunto 2 (%d,%d)",pf2,pc2);
		}
		
	}else if(pf2==pf1+2 && pc2==pc1 && pf2<=n){//abajo
		if(matriz[pf1+1][pc1]=='0' ){
			matriz[pf1+1][pc1]='|';//conexion de puntos
			lf=pf1+1;
			lc=pc1;
			aux=1;	
			//printf("\npunto 2 (%d,%d)",pf2,pc2);
		}
	}else if(pf2==pf1 && pc2==pc1-2 && pc2>=0){//izquierda
		if(matriz[pf1][pc1-1]=='0' ){
			matriz[pf1][pc1-1]='-';//conexion de puntos
			lf=pf1;
			lc=pc1-1;
			aux=1;	
			//printf("\npunto 2 (%d,%d)",pf2,pc2);
		}
	}	
}
void verificar_cuadrado(void){
	//abajo
	band=0;
	if (matriz[lf][lc]=='-'){//si lo ultimo que conectaste fue un guion
		if(matriz[lf-1][lc-1]=='|'){
			band++;
		}
		if(matriz[lf-2][lc]=='-'){
			band++;
		}
		if(matriz[lf-1][lc+1]=='|'){
			band++;
		}
		if (band==3 && pf1!=99){
			user1[user-1]=user1[user-1]+10;
			printf("se completo un cuadrado");
			if(user==1 && y==1){
				matriz[lf-1][lc]='R';
			} else if(user==1 && y==2){
				matriz[lf-1][lc]='A';
			} else if(user==2 && y==1){
				matriz[lf-1][lc]='A';
			} else if(user==2 && y==2){
				matriz[lf-1][lc]='R';
			}
		}
		band=0;
		/// verificar cuadrados arriba
		if(matriz[lf+1][lc-1]=='|'){
			band++;
		}
		if(matriz[lf+2][lc]=='-'){
			band++;
		}
		if(matriz[lf+1][lc+1]=='|'){
			band++;
		}
		if (band==3 && pf1!=99){
			user1[user-1]=user1[user-1]+10;
			printf("\nse completo un cuadrado\n");
			if(user==1 && y==1){
				matriz[lf+1][lc]='R';
			} else if(user==1 && y==2){
				matriz[lf+1][lc]='A';
			} else if(user==2 && y==1){
				matriz[lf+1][lc]='A';
			} else if(user==2 && y==2){
				matriz[lf+1][lc]='R';
			}
		}
		band=0;
	// verificar conexion derecha vertical 			
	}else if(matriz[lf][lc]=='|'){//si lo ult que pusiste fue linea vertical
		if(matriz[lf-1][lc-1]=='-'){
			band++;
		}
		if(matriz[lf][lc-2]=='|'){
			band++;
		}
		if(matriz[lf+1][lc-1]=='-'){
			band++;
		}
		if (band==3 && pf1!=99){
			user1[user-1]=user1[user-1]+10;
			printf("\nse completo un cuadrado\n");
			if(user==1 && y==1){
				matriz[lf][lc-1]='R';
			} else if(user==1 && y==2){
				matriz[lf][lc-1]='A';
			} else if(user==2 && y==1){
				matriz[lf][lc-1]='A';
			} else if(user==2 && y==2){
				matriz[lf][lc-1]='R';
			}
		}	
		band=0;
		//verificar conexion izquierda vert
		if(matriz[lf-1][lc+1]=='-'){
			band++;
		}
		if(matriz[lf][lc+2]=='|'){
			band++;
		}
		if(matriz[lf+1][lc+1]=='-'){
			band++;
		}
		if (band==3 && pf1!=99){
			user1[user-1]=user1[user-1]+10;
			printf("\nse completo un cuadrado\n");
			if(user==1 && y==1){
				matriz[lf][lc+1]='R';
			} else if(user==1 && y==2){
				matriz[lf][lc+1]='A';
			} else if(user==2 && y==1){
				matriz[lf][lc+1]='A';
			} else if(user==2 && y==2){
				matriz[lf][lc+1]='R';
			}
		}
		band=0;	
	}		
}
void imprimir_matriz(){
	if (pf1!=99){
		for(i=0; i<n; i++){
		printf("\n");
			for(j=0; j<n; j++){
				printf("%c",matriz[i][j]);
			}
		}
	}
	
}
int main(int argc, char *argv[]) {
	
	inicio();
	srand(time(NULL));
	while (x==0){
		tablero();
		
		while (m2==0){
			jugador();
		}
		carga_matriz();
		verificar_aleatorio();
		game_over();
		turnos();
		
		while(aux1==0){
			punto1();
		}
		
		
		if (pf1!=99){
			aux=0;//condicion para que no pida el P2
		}else{
			aux=1;//condicion para que pida el p2
		}
		printf("\n");
		
		
		while(aux==0){
			punto2();
		}
		
		aux2=user1[user-1];//guardamos el valor del puntaje para verificar si aumenta
		
		verificar_cuadrado();
		imprimir_matriz();
		
		
		if (user==1){//cambio de turno
			if(aux2==user1[user-1]){// si puntaje anterior es igual al puntaje nuevo, juega maquina, si cambia entonces vuelve a jugar
				user=2;		
			}	
		}else{
			if(aux2==user1[user-1]){// si puntaje anterior es diferente al puntaje nuevo, juega usuario, si cambia entonces vuelve a jugar
				user=1;		
			}
		}
		
		
		
		if (pf1!=99){
			printf("\nPuntaje del user 1:%d",user1[0]);
		
			if (user1[0]==user1[1]){//para empate
				printf("\n\tEmpate");
			}
			printf("\nPuntaje del user 2:%d",user1[1]);		
		}
	}
		
}

