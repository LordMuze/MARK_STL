#include <iostream>
#include "SingleLinkedList.hpp"
#include <string>

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
    new_list->insert_after("This is the song", 0);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after("for the broken hearted", 0);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after("silent prayer", 4);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
    new_list->insert_after("for the faith departed", 2);
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    std::cout<<new_list;
}



// void delete_case(MK2::sllist* new_list){
//     std::cout<<std::endl;
//     std::cout<<"The list is about to be cleared!"<<std::endl;
//     new_list->clear();
//     new_list->print();
// }
// template <typename T>
// void remove_slowly(MK2::sllist<T>* new_list){
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

template<typename T>
void pop_test(MK2::sllist<T>* new_list){
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
    new_list->pop_front();
    std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    new_list->print();
}
template<typename T>
void find_test(MK2::sllist<T>* new_list){
    // MK2::sllist<T>::slnode<T>* result = new_list->find(4);
    // typename MK2::sllist<T>::template slnode<T> result = (*new_list)[3];
    T& lmao = (*new_list)[3];
    std::cout<<"The value of found node is: "<<lmao<<std::endl;
    // std::cout<<"Lets have some fun shall we"<<std::endl;
    // typename MK2::sllist<T>::template slnode<T>* result = &((*new_list)[1]);

}

int main(){
    std::cout<<"Single Linked List Test"<<std::endl;
    MK2::sllist<std::string>* new_list = new MK2::sllist<std::string>{};

    insertion_test_case(new_list);
    // std::cout<<"The getSize of the list is: "<<new_list->getSize()<<std::endl;
    // new_list->print();
    // find_test(new_list);
    std::cout<<new_list<<std::endl;
    pop_test(new_list);
    return 0;
}