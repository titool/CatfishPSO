/* 
 * File:   Swarm.cpp
 * Author: titool86
 * 
 * Created on October 10, 2010, 4:09 PM
 */

#include "Swarm.h"
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstdio>

Swarm::Swarm() {
}

Swarm::Swarm(int s, int n1, int m1, double in, double hist, double best, int c0) {

         int i,j;
	 size = s;
         n = n1;
         m = c0;
         c = m1;
	 Member =new Particula *[size+1];
	 for (i=1;i<=size;i++){
	       Member[i] = new Particula(n, m);
	 }
         Best_member = new Particula *[1];
         Best_member[0] = new Particula(n, m);

         inertia = in;
	 history_info = hist;
	 best_info = best;
         for(i=0;i<n;i++){
             for(j=0;j<m;j++){
             //Best_member[0]->solucion[i][j] = Member[0]->solucion[i][j];
             }
         }
	 
	 maximum_velocity = 0;

	 for (i=1;i<=size;i++){
		 for(j=1;j<=m;j++)
		 {
	       //Member[i]->velocity[j] = normal_random_variable(0.0,1.0);
		 }
	 }
}

Swarm::~Swarm() {
    int i;
    Best_member = 0;
    for (i=1;i<=size;i++){
        delete Member[i];
	}
    delete Member[size+1] ;
}


void Swarm::SetMaximumVelocity(double vmax)
{
	maximum_velocity  =vmax;
}

void Swarm::SetInertiaWeight(double v)
{
    inertia=v;
}

void Swarm::SetHistoryWeight(double v)
{
    history_info =v;
}

void Swarm::SetCollaborationWeight(double v)
{
    best_info = v;
}
int Swarm::verificar(int **solucion){
    int y ,u , h, var=0, res=0, res2=0;
    for(y=0;y<n;y++){
           for(u=0;u<m;u++){
              var = solucion[y][u];
              res=0;
              if(var!=-1){
              for(h=0;h<m;h++){
                 if(solucion[y][h]==var){
                   res++;
                 }
                 if(res>1){
                     res2 = 1;
                 }
              }
              }
           }
    }
    return res2;
}
void Swarm::reparar(int **solucion){
    srand(time(NULL));
     int y ,u , h, var=0, res=0, res2=0, var1,w,q,lala=0;
    for(y=0;y<n;y++){
               if(solucion[y][0]==-1){
                   solucion[y][0] = rand()%(c+1);
               }
               if(solucion[y][1]==-1){
                   solucion[y][1] = rand()%(c+1);
               }
           
       }
     do{
    for(y=0;y<n;y++){
           for(u=0;u<m;u++){
              var = solucion[y][u];
              res=0;
              if(var!=(-1)){
              for(h=0;h<m;h++){
                 if(solucion[y][h]==var){
                   res++;
                   if(res>1){
                       solucion[y][h]=rand()%(c+1);
                   }
                 }
                 
              }
              }
           }
    }
       
    var1 = Swarm::verificar(solucion);
    }while(var==1);

}





void Swarm::quicksort(int A[],int izq, int der ){
    int i, j, x , aux;

i = izq;
j = der;
x = A[ (izq + der) /2 ];

do{
while( (A[i] < x) && (j <= der) )
{
i++;
}while( (x < A[j]) && (j > izq) )
{
j--;
}if( i <= j )
{
aux = A[i]; A[i] = A[j]; A[j] = aux;
i++; j--;

}
}while( i <= j );
if( izq < j )
Swarm::quicksort( A, izq, j );
if( i < der )
Swarm::quicksort( A, i, der );
}
/*void Swarm::print(){
     for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            printf(" %d", matriz1[i][j]);
        }
        printf("\n");
    }

} ]*/
int Swarm::fitness_funcion(int **matriz1, int **matriz2, int **solucion){
    srand(time(NULL));
    int i, j, uno, dos, d, p, sum=0, mul=0, k, l, dd=0;
    int sum_total=0,sum_total1=0;
    for(i=0;i<n;i++){
        for(j=0;j<m-1;j++){
            if(solucion[i][j]!=-1 && solucion[i][j+1]!=-1){
            uno = solucion[i][j];
            dos = solucion[i][j+1];
            sum = matriz1[uno][dos];
            sum_total = sum_total + sum;
            
            //mul += mul;
            }
        }
        sum_total1 = sum_total1 + sum_total;
        //sum_total = sum_total + sum;
    }
        //sum_total = (rand()%1000);

    //calculo de pij
    return sum_total1;
}

void Swarm::printPosition(int **matriz1){
 for(int i=0;i<14;i++){
        for(int j=0;j<14;j++){
            printf(" %d", matriz1[i][j]);
        }
        printf("\n");
    }


}
void Swarm::fly(int **matriz1, int **matriz2, int iter, float c1, float c2){
    int i, j, p, k, y, u, swap, swap_var,w,q;
    double r1=0, r2=0, r=0;
    float num, P_c, P_s, Tot, f1, r3=0;
    int  num1;
    int num2;
    srand(time(NULL));
    //inicializa las particulas con numeros aleatorios
     for (p=1;p<size;p++){
         for(k=0;k<n;k++){
             for(j=0;j<m;j++){
                 if(j==0){
                     num2 = rand()%(c+1);
                     Member[p]->solucion[k][j] =  num2;
                 }else{
                 num = (float) rand()/RAND_MAX;
                 if(num<=0.8 && Member[p]->solucion[k][j-1]!= -1){
                    num1 = rand()%(c+1);
                    Member[p]->solucion[k][j] = num1;
                 }else{
                 Member[p]->solucion[k][j] = -1;
                 }
                 Swarm::reparar(Member[p]->solucion);
                 Member[p]->solucion_best[k][j] = Member[p]->solucion[k][j];
                 }
             }
         }
     }
    
    Best_member[0]->fitness = 1000000;
    //inicializa fitness
    for (p=1;p<size;p++)
	{
		Member[p]->fitness = fitness_funcion(matriz1, matriz2,Member[p]->solucion);
               
		Member[p]->fitness_best = Member[p]->fitness;
		if (Member[p]->fitness_best < Best_member[0]->fitness){
                    for(k=0;k<n;k++){
                         for(j=0;j<m;j++){
                                Best_member[0]->solucion[k][j] = Member[p]->solucion[k][j];
                         }
                    }
                    Best_member[0]->fitness = Member[p]->fitness_best;
                    
                }
	}
    

    for (i=1;i<iter;i++)
	{
        for (p=1;p<size;p++)
		{
			r1=(double) rand()/RAND_MAX;
			r2=(double) rand()/RAND_MAX;
                        r=(double) rand()/RAND_MAX;
                        r3=(double) rand()/RAND_MAX;
                        for(k=0;k<n;k++){
                            for(j=0;j<m;j++){
                                //inertia
                                P_c = c1 * r1;
                                P_s = c2 * r2;
                                Tot = P_c + P_s;
                                f1 = (P_c)/Tot;
                                //f2 = (P_s*100)/Tot;
                                if(r3<=f1){
                                  swap = Best_member[0]->solucion[k][j];
                                }else{
                                    swap = Member[p]->solucion_best[k][j];
                                }
                                //swap
                                if(swap!=-1){
                                swap_var = 0;
                                
                                for(y=0;y<n;y++){
                                    for(u=0;u<m;u++){
                                        if(swap_var==1){
                                            swap--;
                                        }
                                        if(Member[p]->solucion[y][u]==swap){
                                            Member[p]->solucion[y][u]=Member[p]->solucion[k][j];
                                            Member[p]->solucion[k][j]=swap;
                                        }
                                    }
                                }
                                swap_var = verificar(Member[p]->solucion);
                                if(swap_var==1){
                                Swarm::reparar(Member[p]->solucion);
                                }
                                }
                            }
                        }
                        /*for(w=0;w<n;w++){
                                        for(q=0;q<m;q++){
                                            printf("%d ",Member[p]->solucion[w][q]);
                                        }
                                printf("\n");
                                }
                                printf("\n");
                       */
                        //calculo del fitness de la nueva particula
                        Member[p]->fitness = fitness_funcion(matriz1, matriz2,Member[p]->solucion);
                        //actualizacion del lbest
                         //printf("%d \n", Member[p]->fitness);
                        if (Member[p]->fitness < Member[p]->fitness_best)
			{

				for(k=0;k<n;k++){
                                    for(j=0;j<m;j++){
                                        Member[p]->solucion_best[k][j]=Member[p]->solucion[k][j];
                                    }
                                }
				Member[p]->fitness_best = Member[p]->fitness;

			}
                        //actualizacion del gbest
                        if (Member[p]->fitness_best < Best_member[0]->fitness)
			{
                            for(k=0;k<n;k++){
                                    for(j=0;j<m;j++){
                            Best_member[0]->solucion[k][j] = Member[p]->solucion[k][j];
                                    }
                            }
                            Best_member[0]->fitness = Member[p]->fitness_best;
                           
			}
                        
                        //printf("%d \n",Member[p]->fitness);
                }
        //Catfish
        
        printf(" %d \n",Best_member[0]->fitness);
        
        for(k=0;k<n;k++){
            for(j=0;j<m;j++){
               printf("%d ",Best_member[0]->solucion[k][j]);
                            }
            printf("\n");

        }
        printf("\n");
        }
        
        
    }
