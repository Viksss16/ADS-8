// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train():countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
    Cage* cage = new Cage;
    cage->light = light;
   if (first == nullptr) {
           cage->next = cage;
           cage->prev = cage;
           first = cage;
       }
       else {
           cage->next = first;
           cage->prev = first->prev;
           first->prev->next = cage;
           first->prev = cage;
       }
   }
int Train::getLength() {
   first->light = true;
    Cage* First = first;
    int off = 0, count = 1;
    while (first->light) {
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
