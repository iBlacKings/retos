/*
 * Crea dos funciones, una que calcule el máximo común divisor (MCD) y otra
 * que calcule el mínimo común múltiplo (mcm) de dos números enteros.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

int mcd(int n1, int n2);

int mcm(int n1, int n2);


int main(){

    cout << mcd(465,255) << endl;
    cout << mcm(465,255);

}

int mcd(int n1, int n2){

    int a = (n1 > n2 ? n1 : n2);
    int b = (n1 < n2 ? n1 : n2);

    while (b != 0)
    {
        int aux;
        aux = b;
        b = a%b;
        a = aux; 
    }
    
    return a;

}

int mcm(int n1, int n2){
    return (abs(n1*n2)/mcd(n1,n2));
}