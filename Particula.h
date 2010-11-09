/* 
 * File:   Particula.h
 * Author: titool86
 *
 * Created on October 10, 2010, 4:00 PM
 */

#ifndef PARTICULA_H
#define	PARTICULA_H
class Swarm;
class Particula {
friend class Swarm;
public:
    Particula();
    Particula(int n, int m);
    int getNrutas();
    int getNnodos();
    virtual ~Particula();
    int **getSolution();

  int **solucion;
    int **solucion_best;
private:
    int nrutas, nnodos;
    
    float **velocity_add;
    float **velocity_swap;
    int fitness;
    int fitness_best;

};

#endif	/* PARTICULA_H */

