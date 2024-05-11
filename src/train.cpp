// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train():countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
   if (first == nullptr) {
           Cage* cage = new Cage;
           cage->light = light;
           cage->next = cage;
           cage->prev = cage;
           first = cage;
       }
       else {
           Cage* cage = new Cage;
           cage->light = light;
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
    first->light = true;
    int count = 1, off = 0;
    Cage* current = first->next;
    while (current != first) {
        if (!current->light) {
            off++;
        } else {
            count += off + 1;
            countOp += 2 * off;
            off = 0;
            current->light = false;
        }
        current = current->next;
    }
    return count;
}
int Train::getOpCount() { 
    return countOp; 
}
