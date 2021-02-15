#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>
void Palabra(char oracion[5000], int *guardar);
int testing(void);
int main(void){
int guardar = 0;
char oracion[5000];
testing();
printf("Inserte el parrafo (Limite 5 parrafos): ");
scanf("%[^\n]", oracion);
Palabra(oracion, &guardar);
}
void Palabra(char oracion[5000], int *guardar){
    char c;
    int contar = 0;
    int posicion = 0;
    int asignar = 0;
    int saltar = 0;
    int mayor = 0;
    int alfabeto[27][2];
for (int i = 0; oracion[i] != '\0'; i++){
    oracion[i] = tolower(oracion[i]);
}
for (int x = 97; x < 122; x++){ //Codigo ASCII (a-z)
asignar = 0;
c = x;
contar = 0;
for (int y = 0; oracion[y] != '\0'; y++){
if(oracion[y] == c){
    contar++;
    asignar = 1;
}
if((oracion[y+1] == '\0') && (asignar == 1)){
    alfabeto[posicion][0] = x;
    alfabeto[posicion][1] = contar;
posicion++;
}
}
}
for (int m = 0; m<10; m++){
    mayor = 0;
for (int q = 0; q<posicion; q++){
    if (alfabeto[q][1] > mayor){
        mayor = alfabeto[q][1];
        saltar = q;
    }
    if((q+1) == posicion){
        printf("%c %d: ", alfabeto[saltar][0], mayor);
        for(int t = 0; t<mayor; t++){
            printf("*");
        }
    for(int v = saltar; v<posicion; v++){
        alfabeto[v][0] = alfabeto[v+1][0];
        alfabeto[v][1] = alfabeto[v+1][1];
    }
    posicion = posicion-1;
    printf("\n");
}
*guardar = mayor;
}
}
}