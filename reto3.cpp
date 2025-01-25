/*
 * Crea una función que reciba dos array, un booleano y retorne un array.
 * - Si el booleano es verdadero buscará y retornará los elementos comunes
 *   de los dos array.
 * - Si el booleano es falso buscará y retornará los elementos no comunes
 *   de los dos array.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
 */


#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

vector<int> macthOrNotMacth(vector<int>& array1, vector<int>& array2, bool busqueda);


int main(){

    vector<int> array1 = {1,2,7,2,6};
    vector<int> array2 = {1,2,3,4,5,6,5};

    vector<int> result = macthOrNotMacth(array1, array2, false);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result.at(i);
    }
    



}

vector<int> macthOrNotMacth(vector<int>& array1, vector<int>& array2, bool busqueda){

    vector<int> commons;

    for (size_t i = 0; i < array1.size(); i++)
    {
        int count = 0;
        for (size_t j = 0; j < array2.size(); j++)
        {
            if(array1.at(i) == array2.at(j)){
                count++;
                break;
            }
        }
        
        if (count != 0)
        {
            if (find(commons.begin(), commons.end(), array1.at(i)) == commons.end())
            {
                commons.push_back(array1.at(i));
            }           
        }
    } 
    if (busqueda)
    {
        return commons;
    }
    
    else{
        vector<int> nocommons;
        for (const auto value:array1)
        {
            if (find(nocommons.begin(), nocommons.end(), value) == nocommons.end())
            {
                nocommons.push_back(value);
            }      
            
        }
        for (const auto value:array2)
        {
            if (find(nocommons.begin(), nocommons.end(), value) == nocommons.end())
            {
                nocommons.push_back(value);
            }      
        }

        for (const auto value : commons)
        {
            nocommons.erase(std::remove(nocommons.begin(), nocommons.end(), value), nocommons.end());
        }
        
        return nocommons;
        
    }
}

