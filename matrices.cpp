/* 
 * File:   matrices.cpp
 * Author: titool86
 * 
 * Created on October 10, 2010, 7:59 PM
 */

#include "matrices.h"
#include <cstdlib>
#include <cstdio>
//#include <iostream>
#include <fstream>
//#include <cstdlib>
using namespace std;

matrices::matrices() {
}

matrices::matrices(const matrices& orig) {
}

matrices::~matrices() {
}

/*void matrices::leer(char* arch, char* arch2){
    int i,j;
    FILE  *file;
    FILE  *file2;
    file = fopen(arch, "rt");
    file2 = fopen(arch2, "rt");
    matriz1 = (int **) malloc(15 *sizeof (int));
    matriz2 = (int **) malloc(15 *sizeof (int));
    for(i=0;i<15;i++){
       matriz1[i] = (int *) malloc(15 *sizeof (int));
    }
    for(i=0;i<15;i++){
       matriz2[i] = (int *) malloc(15 *sizeof (int));
    }
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            fscanf(file, "%d", &matriz1[i][j]);
        }
    }
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            fscanf(file2, "%d", &matriz2[i][j]);
        }
    }

}
 */

void matrices::leer(char* arch, char *arch2){
    ifstream data;
    data.open(arch);
    matriz1 = (int**)malloc(15*sizeof(int*));
    matriz2 = (int**)malloc(15*sizeof(int*));
    for(int i =0; i < 15; i++){
        matriz1[i] = (int *) malloc(15 *sizeof (int));
        matriz2[i] = (int *) malloc(15 *sizeof (int));
    }
    
    for(int i= 0; i < 15 ; i++){
        for(int j=0; j < 15 ; j++){
            data >> matriz1[i][j];

        }
    }
    data.close();
    data.open(arch2);
    for(int i= 0; i < 15 ; i++){
        for(int j=0; j < 15 ; j++){
            data >> matriz2[i][j];

        }
    }
    data.close();
}
void matrices::print(){
     for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            printf(" %d", matriz1[i][j]);
        }
        printf("\n");
    }

}
int **matrices::getMatriz1(){
    return matriz1;
}

int **matrices::getMatriz2(){
    return matriz2;
}

