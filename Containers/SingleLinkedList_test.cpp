#include <iostream>
#include "SingleLinkedList.hpp"

template <typename T>
void insertion_case(MK2::sllist<T> * new_list){
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->push_front(4.03);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->push_front(5.01);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->push_front(6.2);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
}

template <typename T>
void insertion_test_case(MK2::sllist<T>* new_list){
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after(4.01, 0);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after(5.05, 0);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after(6.40, 4);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after(4.52, 2);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
}

// void delete_case(MK2::sllist* new_list){
//     std::cout<<std::endl;
//     std::cout<<"The list is about to be cleared!"<<std::endl;
//     new_list->clear();
//     new_list->print();
// }

// void remove_slowly(MK2::sllist* new_list){
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->remove_first(6);
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->remove_first(5);
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->remove_first(4);
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();

// }


// void pop_test(MK2::sllist* new_list){
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->pop_front();
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->pop_front();
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->pop_front();
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
//     new_list->pop_front();
//     std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
//     new_list->print();
// }
template<typename T>
void find_test(MK2::sllist<T>* new_list){
    // MK2::sllist<T>::slnode<T>* result = new_list->find(4);
    typename MK2::sllist<T>::template slnode<T>* result = new_list->find(4.52);
    std::cout<<"The value of found node is: "<<result->value<<std::endl;
}

int main(){
    std::cout<<"Single Linked List Test"<<std::endl;
    MK2::sllist<double>* new_list = new MK2::sllist<double>{};

    insertion_test_case(new_list);
    // std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    // new_list->print();
    find_test(new_list);
    std::cout<<new_list<<std::endl;
    return 0;
}