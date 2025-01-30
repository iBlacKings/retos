/*
 * Crea una función que ordene y retorne una matriz de números.
 * - La función recibirá un listado (por ejemplo [2, 4, 6, 8, 9]) y un parámetro
 *   adicional "Asc" o "Desc" para indicar si debe ordenarse de menor a mayor
 *   o de mayor a menor.
 * - No se pueden utilizar funciones propias del lenguaje que lo resuelvan
 *   automáticamente.
 */

#include <iostream>
#include <vector>
#include <string>


void quicksort(std::vector<int>& array, int low, int high);

int partiton(std::vector<int>& array, int low, int high);

void swap(int &a, int &b);

int main(){
    
    std::vector<int> myNums = {15,3,7,6,8,4};
    
    quicksort(myNums, 0, myNums.size()-1);

    std::string option;

    std::getline(std::cin >> std::ws, option);

    if (option == "Desc")
    {
        int j = myNums.size()-1;
        for (size_t i = 0; i < myNums.size()/2; i++)
        {
            swap(myNums.at(i), myNums.at(j));
            j--;
        }
        
    }

    for(const auto value : myNums){
        std::cout << value << " ";
    }
    

}


void swap(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
}

void quicksort(std::vector<int>& array, int low, int high){

    if(low < high){
        int pivote = partiton(array, low, high);

        quicksort(array, pivote + 1, high);
        quicksort(array, low, pivote - 1);

    }
}

int partiton(std::vector<int>& array, int low, int high){

    int pivote = array[high];
    int i = low - 1;

    for (size_t j = low; j < high; j++)
    {
        if(array[j] <= pivote){
            i++;
            swap(array[i], array[j]);
        }
    }

    swap(array[i+1], array[high]);
    
    return ( i + 1 );
    

}