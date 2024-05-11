// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train():countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
    Cage* cage = new Cage;
    cage->light = light;
    cage->next = cage;
    cage->prev = cage;
        if (first == nullptr) {
        first = cage;
   } else {
        cage->next = first;
        cage->prev = first->prev;
        first->prev->next = cage;
        first->prev = cage;
  }
}
int Train::getLength() {
    if (first == nullptr) {
    return 0;  
    }
    int getLength() {
    first->light = true;
    Cage* First = first;
    int off = 1, count = 1;
    while (first->light) {
        off = 1;
        First = first->next;
        while (!First->light) {
            First = First->next;
            off++;
        }
        count += off;
        countOp += 2 * off;
        First->light = false;  
    }
    return count;
}
int Train::getOpCount() { 
    return countOp; 
}
