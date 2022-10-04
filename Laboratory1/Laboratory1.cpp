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
struct list_s
{
    list_s_book mass[100];
    int last;
};
list_s a;
class Book {
public:
    char name[256];
    char author[256];
    int date;
    int amount_of_pages;
    char annottation[256];
};
Book book;
class Сharacter {
public:
    string ch_name;
    vector<string> books;
    vector<string> roles;
};
struct Node {
    char l_name[256];
    char l_author[256];
    int l_date;
    int l_amount_of_pages;
    char l_annottation[256];
    Node* next;
    Node* prev;
};
struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    int push() {
        Book book;
        FILE* b;
        if ((b = fopen("books.txt", "r+b")) == NULL) {
            perror("Error occured while opening file");
            return 1;
        }
        while (fread(&book, sizeof(class Book), 1, b) == 1) {
            Node* ptr = new Node;
            ptr->next = NULL;
            ptr->l_amount_of_pages = book.amount_of_pages;
            strcpy(ptr->l_annottation, book.annottation);
            strcpy(ptr->l_author, book.author);
            ptr->l_date = book.date;
            strcpy(ptr->l_name, book.name);
            if (head != NULL) {
                ptr->prev = tail;
                tail->next = ptr;
                tail = ptr;
            }
            else {
                ptr->prev = NULL;
                head = tail = ptr;
            }
        }
        fclose(b);
        return 0;
    }
    int push_last() {
        /*Book book;*/
        FILE* b;
        if ((b = fopen("books.txt", "r+b")) == NULL) {
            perror("Error occured while opening file");
            return 1;
        }
        fseek(b, size_l * sizeof(class Book), 0);
        fread(&book, sizeof(class Book), 1, b);
        Node* ptr = new Node;
        ptr->next = NULL;
        ptr->l_amount_of_pages = book.amount_of_pages;
        strcpy(ptr->l_annottation, book.annottation);
        strcpy(ptr->l_author, book.author);
        ptr->l_date = book.date;
        strcpy(ptr->l_name, book.name);
        if (head != NULL) {
            ptr->prev = tail;
            tail->next = ptr;
            tail = ptr;
        }
        else {
            ptr->prev = NULL;
            head = tail = ptr;
        }

        fclose(b);
        return 0;
    }
    int showl() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->l_name << " " << ptr->l_author << " " << ptr->l_date << " " << ptr->l_amount_of_pages << " " << ptr->l_annottation << endl;
            ptr = ptr->next;
        }
        return 0;
    }
    int search_d(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_date;

            }

            ptr = ptr->next;
        }


    }
    int search_p(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_amount_of_pages;

            }

            ptr = ptr->next;
        }


    }
    string search_a(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_author;

            }

            ptr = ptr->next;
        }


    }
    int sort_big_amount_of_pages_buble_sort() {
        /* Node* ptr = head;*/
        int temp_p; // временная переменная для обмена элементов местами
        int temp_d;
        char temp_n[256];
        char temp_a[256];
        char temp_an[256];
        // Сортировка массива пузырьком
        for (int i = 0; i < size_l - 1; i++) {
            Node* ptr = head;
            for (int j = 0; j < size_l - i - 1; j++) {

                if (ptr->l_amount_of_pages > ptr->next->l_amount_of_pages) {
                    // меняем элементы местами
                    temp_p = ptr->l_amount_of_pages;
                    ptr->l_amount_of_pages = ptr->next->l_amount_of_pages;
                    ptr->next->l_amount_of_pages = temp_p;

                    temp_d = ptr->l_date;
                    ptr->l_date = ptr->next->l_date;
                    ptr->next->l_date = temp_d;

                    strcpy(temp_n, ptr->l_name);
                    strcpy(ptr->l_name, ptr->next->l_name);
                    strcpy(ptr->next->l_name, temp_n);

                    strcpy(temp_a, ptr->l_author);
                    strcpy(ptr->l_author, ptr->next->l_author);
                    strcpy(ptr->next->l_author, temp_a);

                    strcpy(temp_an, ptr->l_annottation);
                    strcpy(ptr->l_annottation, ptr->next->l_annottation);
                    strcpy(ptr->next->l_annottation, temp_an);
                }
                ptr = ptr->next;
            }
        }

        return 0;
    }
    int sort_big_name_clist_sort() {
        Node* ptr = head;
        while (ptr != NULL) {
            book_names.push_back(ptr->l_name);
            ptr = ptr->next;
        }

        return 0;
    }
    int sort_big_date_quick_sort() {
        /* Node* ptr = head;*/
        int temp_p; // временная переменная для обмена элементов местами
        int temp_d;
        char temp_n[256];
        char temp_a[256];
        char temp_an[256];
        // Сортировка массива пузырьком
        for (int i = 0; i < size_l - 1; i++) {
            Node* ptr = head;
            for (int j = 0; j < size_l - i - 1; j++) {

                if (ptr->l_date > ptr->next->l_date) {
                    // меняем элементы местами
                    temp_p = ptr->l_amount_of_pages;
                    ptr->l_amount_of_pages = ptr->next->l_amount_of_pages;
                    ptr->next->l_amount_of_pages = temp_p;

                    temp_d = ptr->l_date;
                    ptr->l_date = ptr->next->l_date;
                    ptr->next->l_date = temp_d;

                    strcpy(temp_n, ptr->l_name);
                    strcpy(ptr->l_name, ptr->next->l_name);
                    strcpy(ptr->next->l_name, temp_n);

                    strcpy(temp_a, ptr->l_author);
                    strcpy(ptr->l_author, ptr->next->l_author);
                    strcpy(ptr->next->l_author, temp_a);

                    strcpy(temp_an, ptr->l_annottation);
                    strcpy(ptr->l_annottation, ptr->next->l_annottation);
                    strcpy(ptr->next->l_annottation, temp_an);
                }
                ptr = ptr->next;
            }
        }

        return 0;
    }
};
int main()
{
   
}

