/*
 * Crea un programa que calcule el daño de un ataque durante
 * una batalla Pokémon.
 * - La fórmula será la siguiente: daño = 50 * (ataque / defensa) * efectividad
 * - Efectividad: x2 (súper efectivo), x1 (neutral), x0.5 (no es muy efectivo)
 * - Sólo hay 4 tipos de Pokémon: Agua, Fuego, Planta y Eléctrico 
 *   (buscar su efectividad)
 * - El programa recibe los siguientes parámetros:
 *  - Tipo del Pokémon atacante.
 *  - Tipo del Pokémon defensor.
 *  - Ataque: Entre 1 y 100.
 *  - Defensa: Entre 1 y 100.
 */



#include <iostream>
#include <limits>


double damageMadeIt(int& tpAttPK, int& tpDefPk, double& attack, double& defense);

int main(){

    int attackPKM, defensePKM;
    double attack, defense;
    bool ok = false;

    while (!ok)
    {
            try
        {   
            std::cout << std::string(20,'*') << std::endl;
            std::cout << "SELECT THE TYPE OF THE ATTACK AND THE DEFENSE POKEMONS" << std::endl;
            std::cout << "1.FIRE  \t2.WATER" << std::endl;
            std::cout << "2.PLANT \t4.ELECTRIC" << std::endl << std::endl;

            std::cout << "Attack Pokemon: "; std::cin >> attackPKM;
            std::cout << "Defense Pokemon: "; std::cin >> defensePKM;

            if (std::cin.fail())
            {
                throw std::runtime_error("Ingresa solo numeros.");
            }
            

            
            std::cout << "Attack:"; std::cin >> attack;
            std::cout << "Defense:"; std::cin >> defense;
            if (std::cin.fail())
            {
                throw std::runtime_error("Ingresa solo numeros.");
            }
            

            if ((attack > 100 || attack < 1)||(defense > 100 || defense < 1))
            {
            throw std::runtime_error("Values of attack or defense are not valid.");
            }
            ok = true; //Everything is okay the program can continue
        
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    std::cout << "The damage is: " << damageMadeIt(attackPKM, defensePKM, attack, defense);
    
    
}

double damageMadeIt(int& tpAttPK, int& tpDefPk, double& attack, double& defense){

    double efectivityTable[4][4] = {{0.5, 2, 0.5, 1}, //Order table on rows and colums is water fire plant electry
                                {0.5, 0.5, 2, 1},    
                                {2, 0.5, 0.5, 1},
                                {1, 1, 2, 0.5}};

    double efectivity = efectivityTable[tpAttPK-1][tpDefPk-1];

    return 50*(attack/defense)*efectivity;
}