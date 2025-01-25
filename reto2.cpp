/*
 * Lee el fichero "Challenge2.txt" incluido en el proyecto, calcula su
 * resultado e imprímelo.
 * - El .txt se corresponde con las entradas de una calculadora.
 * - Cada línea tendrá un número o una operación representada por un
 *   símbolo (alternando ambos).
 * - Soporta números enteros y decimales.
 * - Soporta las operaciones suma "+", resta "-", multiplicación "*"
 *   y división "/".
 * - El resultado se muestra al finalizar la lectura de la última
 *   línea (si el .txt es correcto).
 * - Si el formato del .txt no es correcto, se indicará que no se han
 *   podido resolver las operaciones.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <string>

using namespace std;

string readFile(string path);

double buildNum(string calculation, size_t& index);


int main(){

    string path = "Challenge2.txt";
    string calculation = readFile(path);


    try
    {
        size_t index = 0;
        double result = buildNum(calculation, index);

        while (index < calculation.length())
        {
            while (index < calculation.length() && (isspace(calculation.at(index)) || calculation.at(index)== '\n'))
            {
                index++;
            }

            if (index >= calculation.length())
            {
                break;
            }
            

            char op = calculation.at(index);
            index++;
            double nextNum = buildNum(calculation, index);
            
            switch (op)
            {       
            case '+':
                result += nextNum;
                
                break;
            case '-':
                result -= nextNum;
                
                break;
            case '*':
                result *= nextNum;
                
                break;
            case '/':
                if (nextNum == 0)
                {
                    throw runtime_error("Zero division error");
                }
                else{
                    result /= nextNum;
                    
                }
                break;
            default:
                break;//Nothing will happend OK
            }
        }
        
        cout << "Result: " << result << endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}


string readFile(string path){
    ifstream file(path);
    if(!file){
        cerr << "The file could not be opened" << endl;
        return "";
    }

    ostringstream operations;
    operations << file.rdbuf();

    return operations.str();
}

double buildNum(string calculation, size_t& index){
    
    string num;
    
    while (index < calculation.length() && (isspace(calculation.at(index)) || calculation.at(index)== '\n'))
    {
        index++;
    }

    while (index < calculation.length() && (isdigit(calculation.at(index)) || calculation.at(index) == '.'))
    {
        num += calculation.at(index);
        index++;
    }

    if(num.empty()){
        throw invalid_argument("Error at find the number");
    }

    try
    {
        return stod(num);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid argument" << '\n';
        throw;
    }
       
    
}
