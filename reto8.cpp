/*
 * Crea un programa que determine si dos vectores son ortogonales.
 * - Los dos array deben tener la misma longitud.
 * - Cada vector se podría representar como un array. Ejemplo: [1, -2]
 */

#include <iostream>
#include <cmath>

bool ortogonales(int vector1[2], int vector2[2]);

int main(){

    int vector1[2] = {1,-2};
    int vector2[2] = {2,1};

    std::cout << "Los vectores " << (ortogonales(vector1, vector2) ? "SI":"NO") << " son ortogonales"; 


}

bool ortogonales(int vector1[2], int vector2[2]){

    int result = (vector1[0]*vector2[0])+(vector1[1]*vector2[1]);

    return result == 0;

}