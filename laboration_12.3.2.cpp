#include <iostream>
using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
void print(Elem* current);
void reverse(Elem*& first);

int main() {
    Elem* first_1 = nullptr;
    Elem* last_1 = nullptr;
    Info input;

    cout << "Input elements for list 1 (-1 to break): " << endl;
    enqueue(first_1, last_1, 0);

    print(first_1);

    reverse(first_1);
    print(first_1);

    return 0;
}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    if (value != -1) {
        cin >> value;
        if (value != -1) {
            Elem* tmp = new Elem;
            tmp->info = value;
            tmp->next = nullptr;
            if (last != nullptr)
                last->next = tmp;
            tmp->prev = last;
            last = tmp;
            if (first == nullptr)
                first = tmp;
            enqueue(first, last, 0);
        }
    }
}

void print(Elem* current) {
    if (current != nullptr) {
        cout << current->info << " ";
        print(current->next);
    }
    cout << endl;
}

void reverse(Elem*& first) {
    if (first == nullptr || first->next == nullptr) {
        return; 
    }

    Elem* rest = first->next; 
    reverse(rest);            

    first->next->next = first; 
    first->next = nullptr;      
    first = rest;               
}

