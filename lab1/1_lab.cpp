#include <iostream>
#include <thread>
using namespace std;
 
void factorial(int start, int stopp, int& result) {
    int fct = 1;
    for (int i=start; i <= stopp ; i++){
        fct = fct * i;
    }
    result = result * fct;
}
 
int main() {
    long double fct = 0;
    int count = 0;
    cout << "Enter a number " <<"\n";
    cin >> count;
    int result = 1;
    int count2 = 0;
    if  (count % 2 == 0) count2 = count / 2;
    else count2 = (count + 1) / 2;

    // Создание двух потоков
    thread thread1(factorial,1, (count2 - 1),ref(result));
    thread thread2(factorial,count2, count,ref(result));
 
    // Ожидание завершения потоков
    thread1.join();
    thread2.join();
    cout << count << "! = " <<result;
    return 0;
}