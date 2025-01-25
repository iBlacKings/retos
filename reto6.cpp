/*
 * Crea un programa que calcule quien gana más partidas al piedra,
 * papel, tijera.
 * - El resultado puede ser: "Player 1", "Player 2", "Tie" (empate)
 * - La función recibe un listado que contiene pares, representando cada jugada.
 * - El par puede contener combinaciones de "R" (piedra), "P" (papel)
 *   o "S" (tijera).
 * - Ejemplo. Entrada: [("R","S"), ("S","R"), ("P","S")]. Resultado: "Player 2".
 */


#include <iostream>

using namespace std;

string checkPlay(string jugadas[][2]);

int main(){

    string jugadas[][2] = {{"R","S"}, {"S","R"}, {"P","S"}};

    cout << checkPlay(jugadas) << endl;

}

string checkPlay(string jugadas[][2]){

    int countP1 = 0;
    int countP2 = 0;

    for (size_t i = 0; i < 3; i++)
    {
        char n1,n2;
        
        n1 = jugadas[i][0][0];
        n2 = jugadas[i][1][0];

        switch (n1)
        {
        case 'R':
            if (n2 == 'P')
            {
                countP2++;
            }
            else if(n2 == 'S'){
                countP1++;
            }
            break;
        case 'P':
            if (n2 == 'S')
            {
                countP2++;
            }
            else if(n2 == 'R'){
                countP1++;
            }
            break;
        case 'S':
            if (n2 == 'R')
            {
                countP2++;
            }
            else if(n2 == 'P'){
                countP1++;
            }
            break;
        default:
            break;
        }
        
    }
    
    if (countP1 == countP2)
    {
        return "Tie";
    }

    return (countP1 > countP2 ? "Player 1":"Player 2");
    

}

