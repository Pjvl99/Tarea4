#include <stdio.h>
#include <time.h>
#include <unistd.h>
extern void Palabra(char oracion[5000], int *guardar);
int testing(void){
int fails = 0;
int mayor = 0;
int tests = 0;
double time_spent = 0.0;
char prueba[] = "aaaaaaaaaa";
clock_t begin = clock();
Palabra(prueba, &mayor);
if(mayor == 10){
    tests++;
    mayor = 0;
}
else{
    printf("Error in funtion 'Palabra'");
    fails++;
}
strcpy(prueba, "eeeeeeee");
Palabra(prueba, &mayor);
if(mayor == 8){
    tests++;
    mayor = 0;
}
else{
    printf("Error in funtion 'Palabra'");
    fails++;
}
strcpy(prueba, "tttttt");
Palabra(prueba, &mayor);
if(mayor == 6){
    tests++;
    mayor = 0;
}
else{
    printf("Error in funtion 'Palabra'");
    fails++;
}
sleep(3);
clock_t end = clock();
time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("---------------------------------------------------------------------\n");
    printf("Ran %d tests in %f s\n\n", (tests+fails), time_spent);
    if(tests == 3){
        printf("OK\n\n");
    }
    else{
        printf("FAILED (failures=%d)\n\n", fails);
    }
}