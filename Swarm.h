/* 
 * File:   Swarm.h
 * Author: titool86
 *
 * Created on October 10, 2010, 4:09 PM
 */
#include "Particula.h"
#ifndef SWARM_H
#define	SWARM_H

class Swarm {
public:
    Swarm();
    Swarm(int s, int n1, int m1,double in, double hist , double best, int c0);
    virtual ~Swarm();
    int fitness_funcion(int **matriz1, int **matriz2, int **solucion);
    void fly(int **matriz1, int **matriz2, int iter, float c1, float c2);
    void SetMaximumVelocity(double vmax);
    void SetInertiaWeight(double v);
    void SetHistoryWeight(double v);
    void SetCollaborationWeight(double v);
    void quicksort(int *A,int izq, int der );
    int verificar(int **solucion);
    void reparar(int **solucion);
    void printPosition(int**);
    //void print();
private:
    int size;
    int n;
    int m;
    int c;
    Particula **Member;
    float inertia;
    double history_info;
    double best_info;
    Particula **Best_member;
    double maximum_velocity;

};

#endif	/* SWARM_H */

