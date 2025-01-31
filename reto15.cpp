/*
 * Dado un array de enteros ordenado y sin repetidos,
 * crea una función que calcule y retorne todos los que faltan entre
 * el mayor y el menor.
 * - Lanza un error si el array de entrada no es correcto.
 */

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_set>
#include <algorithm>

std::vector<int> faltantes(std::vector<int>& numeros);

int main(){
    std::vector<int> numeros = {1,2,3,7,9};
    std::vector<int> faltan;
    bool ordenados = false, repetidos = false;
    try
    {
        if(numeros.empty()){
            throw std::runtime_error("Array vacio");
        }

        for (size_t i = 0; i < numeros.size(); i++)
        {
            if (numeros.at(i)<=numeros.at(i-1))
            {
                throw std::runtime_error("Array no ordenado o contiene duplicados");
            }
            
        }
        
        faltan = faltantes(numeros);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (const auto faltante:faltan)
    {
        std::cout << faltante << " ";
    }

}

std::vector<int> faltantes(std::vector<int>& numeros){

    std::vector<int> numerosFaltantes;
    int max = numeros.back();
    int min = numeros.front();

    for (size_t i = min+1; i < max; i++)
    {
        auto it = std::find(numeros.begin(), numeros.end(), i);
        if (it == numeros.end())
        {
            numerosFaltantes.push_back(i);
        }
    }
    return numerosFaltantes;
}