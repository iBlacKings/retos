/*
 * Simula el funcionamiento de una máquina expendedora creando una operación
 * que reciba dinero (array de monedas) y un número que indique la selección
 * del producto.
 * - El programa retornará el nombre del producto y un array con el dinero
 *   de vuelta (con el menor número de monedas).
 * - Si el dinero es insuficiente o el número de producto no existe,
 *   deberá indicarse con un mensaje y retornar todas las monedas.
 * - Si no hay dinero de vuelta, el array se retornará vacío.
 * - Para que resulte más simple, trabajaremos en céntimos con monedas
 *   de 5, 10, 50, 100 y 200.
 * - Debemos controlar que las monedas enviadas estén dentro de las soportadas.
 */

#include <iostream>
#include <cmath>



int main(){

    

    std::cout << "------------Maquina Expendedora------------" << std::endl;
    std::cout << "1.Chocolatina - 500 \t 2.Choclitos - 250" << std::endl;
    std::cout << "3.Mani Dulce - 35  \t 4.Bonaice - 75" << std::endl;
    std::cout << "5.Bonyurt - 30    \t 6.Quipitos - 15"<< std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    
    try
    {
        int opcion;
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;
        if (opcion > 6 || opcion < 1)
        {
            throw opcion;
        }

        int monedas[5] = {5,10,50,100,200}; // Posiciones para cada moneda 0 = 5, 1 = 10, 2 = 50, 3 = 100, 4 == 200
        
        std::cout << "***Ingrese la cantidad de cada moneda a ingresar***" << std::endl;
        for (size_t i = 0; i < 5; i++)
        {
            int cantidad = 0;
            std::cout << monedas[i] << ":";
            std::cin >> cantidad;
            monedas[i] = monedas[i]*cantidad;
        }
        
        
        int precio = 0;
        switch (opcion)
        {
        case 1:
            precio = 500;
            break;
        case 2:
            precio = 250;
            break;
        case 3:
            precio = 34;
            break;
        case 4:
            precio = 76;
            break;
        case 5:
            precio = 27;
            break;
        case 6:
            precio = 13;
            break;
        default:
            break;
        }
        
        int cambio = 0;
        for (size_t i = 0; i < 5; i++)
        {
            cambio += monedas[i];
        }
        cambio = cambio - precio;
        int vuelto = cambio;
        int cambioMonedas[5] = {0,0,0,0,0};
        int monedasVuelta[5] = {200,100,50,10,5};
        for (size_t i = 0; i < 5; i++)
        {
            if (cambio >= monedasVuelta[i])
            {
                cambioMonedas[i] = cambio / monedasVuelta[i];
                cambio = cambio - (monedasVuelta[i] * cambioMonedas[i]);
            }
        }
        

        std::cout << "Cambio: " << vuelto << std::endl;
        for (size_t i = 0; i < 5; i++)
        {
            std::cout << "Monedas de " << monedasVuelta[i] << " : " << cambioMonedas[i] << std::endl;
        }
    }
    catch(...)
    {
        std::cerr << "Ingrese datos validos :D" << '\n';
    }
    


}
