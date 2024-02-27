#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <fstream>

using namespace std;

mutex myMutex;


void write_to_file(string name) {
    fstream ofs( "text.txt", ios::app);
    cout << "Книгу забрал(а) "<<name<<"\n";
    ofs << "Книгу забрал(а) "<<name<<"\n";
    
    cout<<"Пожалуйста, подождите"<<"\n";
    ofs<<"Пожалуйста, подождите"<<"\n";
    cout << "Книга свободна!"<<"\n";
    ofs << "Книга свободна!"<<"\n";
    ofs.close();
}
void thread_func(const char *content) {
    unique_lock<mutex> lock(myMutex);
    write_to_file(content);
    lock.unlock(); 

}
 
int main() {
    fstream ofs;
    ofs.open("text.txt", fstream::out | fstream::trunc);
    ofs.close();
    
    thread thread1(thread_func,"Маша");
    thread thread2(thread_func,"Саша");
    thread thread3(thread_func,"Ксюша");
    thread thread4(thread_func,"Дима");

 
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    cout << "Библиотека закрыта :(" ;
    return 0;
}
