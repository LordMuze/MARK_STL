#include <iostream>
#include "SingleLinkedList.h"

void insertion_case(MK2::sllist* new_list){
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->push_front(4);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->push_front(5);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->push_front(6);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
}


void insertion_test_case(MK2::sllist* new_list){
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->insert(4, 0);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->insert(5, 0);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->insert(6, 1);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->insert(4, 2);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
}

void delete_case(MK2::sllist* new_list){
    std::cout<<std::endl;
    std::cout<<"The list is about to be cleared!"<<std::endl;
    new_list->clear();
    new_list->print();
}

void remove_slowly(MK2::sllist* new_list){
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->remove_first(6);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->remove_first(5);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->remove_first(4);
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();

}


void pop_test(MK2::sllist* new_list){
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The size of the list is: "<<new_list->size()<<std::endl;
    new_list->print();
}

void find_test(MK2::sllist* new_list){
    MK2::sllist::slnode* result = new_list->find(4);
    std::cout<<"The value of found node is: "<<result->value<<std::endl;
}


int main(){
    std::cout<<"Single Linked List Test"<<std::endl;
    MK2::sllist* new_list = new MK2::sllist{};
    insertion_test_case(new_list);
    //delete_case(new_list);
    find_test(new_list);
    pop_test(new_list);
    return 0;
}