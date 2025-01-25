/*
 * Crea una función que sume 2 números y retorne su resultado pasados
 * unos segundos.
 * - Recibirá por parámetros los 2 números a sumar y los segundos que
 *   debe tardar en finalizar su ejecución.
 * - Si el lenguaje lo soporta, deberá retornar el resultado de forma
 *   asíncrona, es decir, sin detener la ejecución del programa principal.
 *   Se podría ejecutar varias veces al mismo tiempo.
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <functional>

/*
void AsynSum(int num1, int num2, int time, std::promise<int> & result);

int main() {

    std::promise<int> result1p;
    std::future<int> result1 = result1p.get_future();

    std::thread sum1 {AsynSum, 2,5,3, ref(result1p)};
    
    std::promise<int> result2p;
    std::future<int> result2 = result2p.get_future();

    std::thread sum2 {AsynSum, 3,7,1, ref(result2p)};

    sum1.join();
    sum2.join(); 

}

void AsynSum(int num1, int num2, int time, std::promise<int> & result){
    std::this_thread::sleep_for(std::chrono::seconds(time));
    int answer = num1 + num2;
    std::cout << "Result: " << answer << std::endl;
    result.set_value(answer);
}
*/

/*

int AsynSum(int num1, int num2, int time){
    std::this_thread::sleep_for(std::chrono::seconds(time));
    int answer = num1 + num2;
    std::cout << "Result: " << answer << std::endl;
    return answer;
}

int main(){

    std::future<int> sum1 = std::async(std::launch::async, AsynSum, 5,3,4);
    std::future<int> sum2 = std::async(std::launch::async, AsynSum, 1,20,2);

}
*/

void asyncSum(int num1, int num2, int time, std::function<void(int)> callback){
        std::this_thread::sleep_for(std::chrono::seconds(time));
        int result = num1 + num2;
        callback(result);
}

int main(){
    
    std::thread sum1(asyncSum, 2,5,4,[](int x){
        std::cout << "Result: " << x << std::endl;
    });

    std::thread sum2(asyncSum, 4,8,2,[](int x){
        std::cout << "Result: " << x << std::endl;
    });

    sum1.join();
    sum2.join();
}