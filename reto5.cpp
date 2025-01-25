/*
 * Quiero contar del 1 al 100 de uno en uno (imprimiendo cada uno).
 * ¿De cuántas maneras eres capaz de hacerlo?
 * Crea el código para cada una de ellas.
 */

#include <iostream>

using namespace std;


int main(){

    for (size_t i = 1; i < 101; i++)
    {
        cout << i << endl;
    }

    int count = 0;

    while (count != 100)
    {
        count++;
        cout << count << endl;
    }
       

}