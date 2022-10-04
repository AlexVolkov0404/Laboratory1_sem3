// Laboratory1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;
int size_l;

list<string> book_names;
vector<vector<string>> chrVector/*{ {"1", "2", "13" }, {"2", "1","13","4"}, {"7", "8"}, {"2", "13","4",}, {"15", "1","2","4"} }*/;
struct list_s_book
{
    int date_s;
    string name_s;
    string author_s;
    int amount_of_pages_s;
    list_s_book operator = (list_s_book a)
    {
        this->date_s = a.date_s;
        this->name_s = a.name_s;
        this->author_s = a.author_s;
        this->amount_of_pages_s = a.amount_of_pages_s;
        return *this;
    }
};
int main()
{
   
}

