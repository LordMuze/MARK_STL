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
            this->tail = ts_head;

        }
    }
    //Destructor
    sllist::~sllist() {
        if(this->size == 0){
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
        this->size = 0;
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
        this->size++;
    }

    bool sllist::re_size(size_t n) {
        size_t cur_size = this->getSize();
        // n < cur_size
        // remove elements at the n position until the end of the list 
        if(n < cur_size){
            slnode* begin = this->head;
            slnode* end_mark;
            size_t index = 0;
            while(begin){
                begin = begin->next;
                index = index + 1;
                if(index == n){
                    break;
                }else if(index == n - 1){
                    //Preparing to assign the last element before the positon as the tail
                    end_mark = begin;
                }
            }
            while(begin){
                // (begin) -> to first - > (next)
                // (deleted) - - > (next)
                // (begin = next)
                // (begin) -> to first -> (next) // {repeat}
                slnode* tmp_next = begin->next;
                delete begin;
                begin = tmp_next;
            }
            this->tail = end_mark;
            this->tail->next = nullptr;
            this->size = this->size - n;
        }else{
            //if n is more than current size of the container
            size_t n_cnt = n - this->size;
            slnode* begin = this->tail;
            for(size_t index = 0; index < n_cnt; ++index){
                slnode* new_node = new slnode;
                new_node->value = 0;
                begin->next = new_node;
                begin = begin->next;
            }
            this->size = n;
        }
        return true;
    }

    size_t sllist::getSize() const{
        return this->size;
    }

    bool sllist::remove_first(int value){
        bool res = false;
        slnode* child_node = this->head;
        while(child_node){
            //#First case (head (to be deleted)) --> (node_2) --> (node_3)
            if(child_node->value == value){
                this->head = child_node->next;
                this->size--;
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
                    this->size--;
                    this->tail = child_node;
                    break;
                }else{
                    //#Second Case
                    child_node->next = (child_node->next)->next;
                    delete child_node->next;
                    res = true;
                    this->size--;
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
        this->size--;
    }


    void sllist::insert_after(int value, size_t position){
        size_t count = 0;
        size_t list_size = this->getSize();
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
                this->tail = new_node;
                this->size++;
                break;
            //#Third Case (head) --> (node_2 (to be inserted)) --> (node_3)
            }else if(position == count && position < list_size){
                slnode* new_node = new slnode;
                new_node->value = value;
                new_node->next = child_node->next; // (new_node) --> (someother_node)
                child_node->next = new_node; //child_node --> new_node
                this->size++;
                break;
            }
            child_node = child_node->next;
            ++count;
            
        }
    }
    //Linear time implementation
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