/*
 * Crea un programa que dibuje un cuadrado o un triángulo con asteriscos "*".
 * - Indicaremos el tamaño del lado y si la figura a dibujar es una u otra.
 * - EXTRA: ¿Eres capaz de dibujar más figuras?
 */


#include <iostream>

using namespace std;

void draw(int size, int shape);

int main(){

    int size, shape;
    cout << "Type the size of the shape:";
    cin >> size;

    cout << "Select the shape that you want below" << endl;
    cout << "1.Square" << endl;
    cout << "2.Triangle"<< endl;

    cin >> shape;

    draw(size, shape);
}

void draw(int size, int shape){

    string symbol = "x";

    switch (shape)
    {
    case 1:
        for (size_t i = 0; i < size; i++)
        {   
            for (size_t j = 0; j < size; j++)
            {
                cout << symbol;
            }
            
            cout << endl;
        }
        
        break;
    case 2:
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                cout << symbol;
                if (i == j)break;
                
            }
            cout << endl;
        }
        
        break;
    default:
        break;
    }



}