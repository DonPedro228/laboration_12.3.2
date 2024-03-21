#pragma once

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
bool check(Elem* L1_first, Elem* L2_first);

bool search(Elem* currentL1, Elem* L2_first) {
    if (L2_first == nullptr)
        return false;
    if (currentL1->info == L2_first->info)
        return true;
    return search(currentL1, L2_first->next);
}

bool check(Elem* L1_first, Elem* L2_first) {
    if (L1_first == nullptr)
        return true;
    return search(L1_first, L2_first) && check(L1_first->next, L2_first);
}