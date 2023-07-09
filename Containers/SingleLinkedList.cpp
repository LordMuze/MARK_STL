#include <iostream>
#include "SingleLinkedList.h"
namespace MK2{
    //Constructor for singlelinkedlist node
    sllist::slnode::slnode() : value(0), next(nullptr) {
        
    }
    //Default Constructor
    sllist::sllist(): head(nullptr){}

    //Copy Constructor
    sllist::sllist(sllist const& cpy) : head(nullptr) {
        if(cpy.head == nullptr){
            	/*!*************************************************************************
    **** 
                \return exception
                ****************************************************************************
    ***/
            return;
        }else{
            //Ver. 1.0 Suspect no memory overrwrite with this implementation
            slnode* cp_head = cpy.head;
            slnode* ts_head = this->head;
            this->clear();
            ts_head = cp_head;
            while(cp_head){
                ts_head = cp_head;
                cp_head = cp_head->next;
                ts_head = ts_head->next;
            }
        }
    }
    //Destructor
    sllist::~sllist() {
        if(this->size() == 0){
                        	/*!*************************************************************************
    **** 
                \return exception
                ****************************************************************************
    ***/
            return;
        }else{
            this->clear();
        }
    }
    //Empty contents of the list
    void sllist::clear(){
        //Wrap-around exception
        slnode *child_node = this->head;
        while(child_node){
            slnode* tmp = child_node->next;
            delete child_node;
            child_node = tmp;
        }
        this->head = nullptr;
    }
    //std io stream print
    void sllist::print() const{
        slnode* child_node = this->head;
        while(child_node){
            std::cout<<child_node->value<<" ";
            child_node = child_node->next;
        }
        std::cout<<std::endl;
    }

    void sllist::push_front(int value) {
        //objects are stored on heap and not on stack
        slnode* new_node = new slnode;

        new_node->value = value;
        // (new_node) --> (head)
        new_node->next = this->head;
        // (new_node = head) --> (old_head) *old_head is just another node after the assignment below:
        this->head = new_node;
    }

    size_t sllist::size() const{
        size_t count = 0;
        slnode* child_node = this->head;
        while(child_node){
            ++count;
            child_node = child_node->next;
        }
        return count;
    }
    bool sllist::remove_first(int value){
        bool res = false;
        slnode* child_node = this->head;
        while(child_node){
            //#First case (head (to be deleted)) --> (node_2) --> (node_3)
            if(child_node->value == value){
                this->head = child_node->next;
                delete child_node;
                break;
            }
            //#Second Case (head) --> (node_2 (to be deleted)) --> (node_3)
            //#Third Case (head) --> (node_2) --> (node_3 (to be deleted))
            if((child_node->next)->value == value){
                //#Third case
                if((child_node->next)->next == nullptr){
                    delete child_node->next;
                    child_node->next = nullptr;
                    res = true;
                    break;
                }else{
                    //#Second Case
                    child_node->next = (child_node->next)->next;
                    delete child_node->next;
                    res = true;
                    break;
                }
            }
            child_node = child_node->next;
        }
        return res;
    }
    void sllist::pop_front(){
        slnode* del_node = this->head;
        this->head = del_node->next;
        delete del_node;
    }


    void sllist::insert(int value, size_t position){
        size_t count = 0;
        size_t list_size = this->size();
        slnode* child_node = this->head;
        //#First case (head (to be inserted)) --> (node_2) --> (node_3)
        if(!(this->head) || position == 0){
            this->push_front(value);
            return;
        }
        while(child_node){
            //#Second Case (head) --> (node_2) --> (node_3 (to be inserted))
            if (count == list_size-1 && position >= count){
                slnode* new_node = new slnode;
                new_node->value = value;
                child_node->next = new_node;
                new_node->next = nullptr;
                return;
            //#Third Case (head) --> (node_2 (to be inserted)) --> (node_3)
            }else if(position == count && position < list_size){
                slnode* new_node = new slnode;
                new_node->value = value;
                new_node->next = child_node->next; // (new_node) --> (someother_node)
                child_node->next = new_node; //child_node --> new_node
                break;
            }
            child_node = child_node->next;
            ++count;
        }
    }
    sllist::slnode* sllist::find(int value) const{
        slnode* child_node = this->head;
        slnode* result = nullptr;
        while(child_node){
            if(child_node->value == value){
                result = child_node;
                break;
            }
            child_node = child_node->next;
        }
        return result;
    }
    
}