/*
 * Crea una función que reciba un texto y muestre cada palabra en una línea,
 * formando un marco rectangular de asteriscos.
 * - ¿Qué te parece el reto? Se vería así:
 *   **********
 *   * ¿Qué   *
 *   * te     *
 *   * parece *
 *   * el     *
 *   * reto?  *
 *   **********
 */


#include <iostream>
#include <string>
#include <vector>


void jumps(std::string text);


int main(){

    jumps("¿Qué te parece el reto?");



}

void jumps(std::string text){

    std::vector<std::string> words;
    std::string temp;
    for(const auto& letter : text){
        
        if (letter == ' ')
        {
            words.push_back(temp);
            temp = "";
        }else{
            temp += letter;
        }
        
    }

    if(!temp.empty()){

        words.push_back(temp);
    }

    int max = 0;

    for(const auto& word : words){
        if (word.size() > max)
        {
            max = word.size();
        }
    }

    std::string border(max + 4, '*'); 

    std::cout << border << std::endl;
    for (const auto& word : words) {
        std::cout << "* " << word << std::string(max - word.size(), ' ') << " *" << std::endl;
    }
    std::cout << border << std::endl; 
}