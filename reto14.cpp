/*
 * Crea un función, que dado un año, indique el elemento 
 * y animal correspondiente en el ciclo sexagenario del zodíaco chino.
 * - Info: https://www.travelchinaguide.com/intro/astrology/60year-cycle.htm
 * - El ciclo sexagenario se corresponde con la combinación de los elementos
 *   madera, fuego, tierra, metal, agua y los animales rata, buey, tigre,
 *   conejo, dragón, serpiente, caballo, oveja, mono, gallo, perro, cerdo
 *   (en este orden).
 * - Cada elemento se repite dos años seguidos.
 * - El último ciclo sexagenario comenzó en 1984 (Madera Rata).
 */

#include <iostream>
#include <vector>

void sexagenario(int year);

int main(){
    sexagenario(1924);
}

void sexagenario(int year){

    std::vector<std::string> materiales = {"madera", "fuego", "tierra", "metal", "agua"};
    std::vector<std::string> animales = {"rata", "buey", "tigre", "conejo", "dragon"
                                , "serpiente","caballo", "oveja", "mono", "gallo", "perro", "cerdo"};

    if (year < 604)
    {
        std::cout << "El calendario se invento en el año 604";
        return;
    }
    
    int sexagenaryYear = (year-4) % 60;
    std::string material = materiales.at((sexagenaryYear%10)/2);
    std::string animal = animales.at(sexagenaryYear%12);

    std::cout << "El año" << year << " tiene como animal a '" << animal << "' y elemento '" << material << '\'';

}