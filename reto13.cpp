/*
 * Dado un listado de números, encuentra el SEGUNDO más grande
 */

#include <iostream>
#include <vector>
#include <limits>

int segundoMayor(std::vector<int>& numeros);

int main(){
    std::vector<int> numeros = {1,2,3,4,5,6,7,8,9,9};

    int sm = segundoMayor(numeros);
    
    if (sm == std::numeric_limits<int>::min()) std::cout << "No existe un segundo numero mas grande";
    else{std::cout << "El segundo numero mas grande es: " << sm;}

    
    
}

int segundoMayor(std::vector<int>& numeros){

    if (numeros.size() < 2) return std::numeric_limits<int>::min();
    

    int max1 = std::numeric_limits<int>::min();
    int max2 = std::numeric_limits<int>::min();

    for (auto number : numeros)
    {
        if (number > max1)
        {
            max2 = max1;
            max1 = number;
        }
        else if (number > max2 && number < max1)
        {
            max2 = number;
        }
    }
    return max2;
}