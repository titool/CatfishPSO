/* 
 * File:   Particula.cpp
 * Author: titool86
 * 
 * Created on October 10, 2010, 4:00 PM
 */

#include "Particula.h"
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <iostream>


Particula::Particula() {
}

Particula::Particula(int n, int m) {
    srand(time(NULL));
    int i,j;
    nrutas = n;
    nnodos = m;     //numero nodos total
    solucion = (int **) malloc(nnodos *sizeof (int));
    for(i=0;i<nnodos;i++){
       solucion[i] = (int *) malloc((nrutas) *sizeof (int));
    }
    solucion_best = (int **) malloc(nnodos *sizeof (int));
    for(i=0;i<nnodos;i++){
       solucion_best[i] = (int *) malloc((nrutas) *sizeof (int));
    }
    
    fitness = 0;
    fitness_best = 0;
    velocity_add = (float **) malloc(nnodos *sizeof (float));
    velocity_swap = (float **) malloc(nrutas *sizeof (float));
    for(i=0;i<15;i++){
       velocity_add[i] = (float *) malloc(nnodos *sizeof (float));
       velocity_swap[i] = (float *) malloc(nrutas *sizeof (float));
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            velocity_add[i][j] = 0.0;
            velocity_swap[i][j] = 0.0;
        }
    }
}
Particula::~Particula() {
    delete solucion;delete solucion_best;
}

int Particula::getNrutas(){
    return nrutas;
}

int Particula::getNnodos(){
    return nnodos;
}

int** Particula::getSolution(){
    return solucion;

}