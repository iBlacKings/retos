/*
 * Crea una función que imprima los 30 próximos años bisiestos
 * siguientes a uno dado.
 * - Utiliza el menor número de líneas para resolver el ejercicio.
 */
#include <iostream>

void isBicisto(int year);

int main(){
    isBicisto(1984);
}

void isBicisto(int year){
    while (year % 4 != 0 && (year % 100 == 0 || year % 400 != 0)) year++;  

    for (size_t i = 0; i < 1000; i++,year += 4) std::cout << year << std::endl;
}