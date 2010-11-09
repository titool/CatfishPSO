/* 
 * File:   matrices.h
 * Author: titool86
 *
 * Created on October 10, 2010, 7:59 PM
 */

#ifndef MATRICES_H
#define	MATRICES_H

class matrices {
public:
    matrices();
    matrices(const matrices& orig);
    void leer(char*, char*);
    int **getMatriz1();
    int **getMatriz2();
    virtual ~matrices();
    void print();
private:
    int **matriz1;
    int **matriz2;

};

#endif	/* MATRICES_H */

