/* 
 * File:   main.cpp
 * Author: titool86
 *
 * Created on October 10, 2010, 3:59 PM
 */

#include <cstdlib>
#include <cstdio>
#include "matrices.h"
#include "Particula.h"
#include "Swarm.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    int s, m, n, in, iter, i, j, c;
    int **matriz1;
    int **matriz2;
    float c1, c2;
    if(argc == 4){
        s = atoi(argv[1]);
        c1 = atof(argv[2]);
        c2 = atof(argv[3]);
    }else{
        printf("chupala222222\n");
        return -1;
    }
    
    //s = 1000;
    n =4;
    m = 14;
    c = 6;
    in = 0.9;
    iter = 1000;
    //s = 10;
    //c1 = 0.2;
    //c2 = 0.7;
    matrices matriz;
    matriz.leer("td1.txt","tt1.txt");
    //matriz.print();
    Swarm *swarm = new Swarm(s, n, m, in, 0, 0, c);
    matriz1 = matriz.getMatriz1();
    matriz2 = matriz.getMatriz2();
    swarm->fly(matriz1, matriz2, iter, c1, c2);
    
    return 0;
}

