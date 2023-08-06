#ifndef SINGLELINKEDLIST_HPP
#define SINGLELINKEDLIST_HPP

#include <cstddef>
#include <iostream>
#include <vector>
/*For debugging purposes:*/
#include <typeinfo>

namespace MK2 {
    template<typename U>
    class _iterator{
        public:
/*!*****************************************************************************       	
    \brief Value type of value in the nodes
*******************************************************************************/

            using DataType = typename U::DataType; // VALUE IN SLNODE

/*!*****************************************************************************       	
    \brief Value type of value in the nodes
*******************************************************************************/        
            using DataRef = DataType&;

/*!*****************************************************************************       	
    \brief Data type that is the Node itself 
    \return slnode<T>
*******************************************************************************/   

            using TypeValue = typename U::ValueType; //SLNODE
/*!*****************************************************************************       	
    \brief Reference type of the node 
    \return slnode<T>&
*******************************************************************************/   
            using ReferenceType = TypeValue&;
/*!*****************************************************************************       	
    \brief Pointer type of the node 
    \return slnode<T>*
*******************************************************************************/   
            using PointerType = TypeValue*;
/*!*****************************************************************************       	
    \brief Default constructor deprecated
*******************************************************************************/   
            _iterator() = delete;
/*!*****************************************************************************       	
    \brief Constructor that accepts pointer pointing to any part of the list (nodes)
*******************************************************************************/   
            _iterator(PointerType ptr);
/*!*****************************************************************************       	
    \brief Constructor that accepts reference pointing to any part of the list (nodes)
    \brief Sets the iterator object private - pointer pointing to that particular node!
*******************************************************************************/   
            _iterator(ReferenceType refType);
/*!*****************************************************************************       	
    \brief Default destructor for iterator is used (compiler defined)
*******************************************************************************/   
            ~_iterator() = default;
/*!*****************************************************************************       	
    \brief Accepts another iterator by reference const.
*******************************************************************************/   
            _iterator(_iterator const&);
/*!*****************************************************************************       	
    \brief Increments by one node in the list. 
    \return returns the incremented position
*******************************************************************************/   
            _iterator& operator++();
/*!*****************************************************************************       	
    \brief Increments by one node in the list. 
    \return returns the position before increment.
*******************************************************************************/ 
            _iterator operator++(int);
/*!*****************************************************************************       	
    \brief Compares the elements of the list
    \return returns FALSE IF BOTH ARE EQUAL
*******************************************************************************/ 
            bool operator!=(_iterator const& rhs);

/*!*****************************************************************************       	
    \brief Evaluates THE VALUE THAT IS IN THE NODE
    \brief User can amend the value that resides in the node with this operator
    \return returns a reference to THAT VALUE IN THE NODE

*******************************************************************************/ 
            DataRef operator*();

        private:
            PointerType ptr;

    };
    template<typename T>
    _iterator<T>::_iterator(PointerType ptr){
        this->ptr = ptr;
    }

    template<typename T>
    _iterator<T>::_iterator(ReferenceType rftr){
        this->ptr = &(rftr);
    }

    template<typename T>
    _iterator<T>::_iterator(_iterator const&itr){
        this->ptr = itr.ptr;
    }
    template<typename T>
    _iterator<T>& _iterator<T>::operator++(){
        ptr = ptr->next;
        return *this;
    }

   template<typename T>
    _iterator<T> _iterator<T>::operator++(int){
        PointerType temp = this->ptr;
        ptr = ptr->next;
        return _iterator(temp);
    }

    template<typename T>
    bool _iterator<T>::operator!=(_iterator const& rhs){
        if(this->ptr != rhs.ptr){
            return true;
        }else{
            return false;
        }
    }
    template<typename T>
    typename _iterator<T>::DataRef _iterator<T>::operator*(){
        return ptr->value;
    }


	template<class T>
	class sllist
	{

	public:
		template<typename U>
		struct slnode
		{
            using NodeData = U;
			slnode();
			~slnode() = default;
			
			U value;  // data portion
			slnode* next;
		};
        using ValueType = sllist<T>::slnode<T>;
        using Iterator = _iterator<sllist<T>>;
        using DataType = typename ValueType::NodeData;
/*!*****************************************************************************       	
    \brief Default Constructor
*******************************************************************************/


		sllist();

/*!*****************************************************************************       	
    \brief Copy Constructor
    \param forward_list
*******************************************************************************/


		sllist(sllist<T> const&);
/*!*****************************************************************************       	
    \brief Destructor
*******************************************************************************/


		~sllist();

/*!*****************************************************************************       	
    \brief Copy Assignment Operator
    \param forward_list_reference
*******************************************************************************/


		sllist<T>& operator=(sllist<T> const&);


/*!*****************************************************************************       	
    \brief Copy Assignment Operator for pointer
    \param forward_list_pointer
*******************************************************************************/

		sllist<T>& operator=(sllist<T>* const);
/*!*****************************************************************************       	
    \brief Resize the container by deleting or adding n number of nodes
    \param size_t no. of total elements in the list
    \return true if successfully resized
    \return false if unsuccessfully resized
*******************************************************************************/


		bool re_size(size_t n);
/*!*****************************************************************************       	
    \brief Returns the size of the list
    \return size_t
*******************************************************************************/


		constexpr size_t getSize() const noexcept;

/*!*****************************************************************************       	
    \brief Pushes a node to the front of the list. Increment the list size by 1 too.
    \param Object()
*******************************************************************************/


		void push_front(T value);

/*!*****************************************************************************       	
    \brief Delete a node from the front of the list. Decrement the list size by 1 too.
*******************************************************************************/


		void pop_front();


/*!*****************************************************************************       	
    \brief Deletes all the nodes within the list
*******************************************************************************/


		constexpr void clear();

/*!*****************************************************************************       	
    \brief Prints the list, node values to std::cout
*******************************************************************************/ 



		constexpr void print() const;

/*!*****************************************************************************       	
    \brief Finds the first matching occurence specified by argument, from the front of the list
    \param Object() value to match
    \return forward_list node pointer
    \warning Use for debugging only
*******************************************************************************/ 


		slnode<T>* find(T value) const;
/*!*************************************************************************
    \brief Returns the queried VALUE IN THE NODE by index. If index is larger than the array size, returns nullptr. //throwing an exception will be a thing in the future
    \return type reference
	\return nullptr if larger than array size or invalid value (i.e. negative value) 
******************************************************************************/
		


        T& operator[](size_t index);

/*!*************************************************************************
    \brief Inserts a node containing the value specified by argument at a specified position within the list
    \brief If position is more than list, insert at the last end of the list
    \brief If position < 1, insert at the front of the list
    \return slnode reference
	\return nullptr if larger than array size or invalid value (i.e. negative value) 
*****************************************************************************/

		// Insert value in linked list at index.
		// Assume zero-based indexing with 1st element at index 0, the second element
		// at index 1, and so on. If list has 4 elements, their indices range from
		// 0 to 3. Then a call to insert() with index 4 would insert value as last
		// element of list. In the same example, if index is 10, then the value is
		// inserted at index 4. 

		void insert_after(T value, size_t position);

/*!*************************************************************************
    \brief Remove a node based on the argument specified 
	\param Object()
    \return True if successfully removed - found and removed
    \return False if not succesfully removed - error OR not found
*****************************************************************************/


		bool remove_first(T value);

		// friend std::ostream& operator<<(std::ostream& output, sllist<T> const& list);


/*!*************************************************************************
    \brief Begin
    \return Returns an Iterator object pointing at the element,  at the beginning of the list
*****************************************************************************/
    
    Iterator begin(){
        return Iterator(this->head);
    }

/*!*************************************************************************
    \brief End
    \return Returns an Iterator object pointing after the last element in the list

*****************************************************************************/
    Iterator end(){
        return Iterator((this->tail)->next);
    }



/*!*************************************************************************
    \brief Prints the entire list to the std::cout stream
	\param Object()
    \return True if successfully removed - found and removed
    \return False if not succesfully removed - error OR not found
*****************************************************************************/


		friend std::ostream& operator<<(std::ostream& os, sllist<T> const* list){
			slnode<T>* child_node = list->head;
			while(child_node){
				os<<child_node->value<<" ";
				child_node = child_node->next;
			}
			os<<std::endl;
			return os;
		}


		
	protected:

		slnode<T>* head;
		slnode<T>* tail;
	private:
		size_t size;
	};






	// Constructor for node
	template<typename T>
	sllist<T>::sllist(): head(nullptr){}
	//Default Class Constructor
	// template<class T, typename U>
	template<class T>
	template<typename U>
    sllist<T>::slnode<U>::slnode() : value(U()), next(nullptr) {
        
    }

	//Copy Constructor list
	template<class T>
	sllist<T>::sllist(sllist<T> const& cpy) : head(nullptr), size(0) {
        if(cpy.head == nullptr){
            return;
        }else{
            //Ver. 1.0 Suspect no memory overrwrite with this implementation
            slnode<T>* cp_head = cpy.head;
            slnode<T>* ts_head = this->head;
            this->clear();
            ts_head = cp_head;
            while(cp_head){
                ts_head = cp_head;
                cp_head = cp_head->next;
                ts_head = ts_head->next;
            }
            this->tail = ts_head;
            this->size = cpy.getSize();
        }
    }


	//Destructor
	template<class T>
	sllist<T>::~sllist() {
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

	template<class T>
	constexpr void sllist<T>::clear(){
        //Wrap-around exception
        slnode<T> *child_node = this->head;
        while(child_node){
            slnode<T>* tmp = child_node->next;
            delete child_node;
            child_node = tmp;
        }
        this->head = nullptr;
        this->size = 0;
    }

	template<class T>
	constexpr void sllist<T>::print() const{
        slnode<T>* child_node = this->head;
        while(child_node){
            std::cout<<child_node->value<<" ";
            child_node = child_node->next;
        }
        std::cout<<std::endl;
    }

	template<typename T>
    void sllist<T>::push_front(T value) {
        //objects are stored on heap and not on stack
        slnode<T>* new_node = new slnode<T>;
        new_node->value = value;
        // (new_node) --> (head)
        new_node->next = this->head;
        // (new_node = head) --> (old_head) *old_head is just another node after the assignment below:
        this->head = new_node;
        if(this->size == 0){
            this->tail = new_node;
        }
        this->size++;
    }
	template<class T>
	constexpr size_t sllist<T>::getSize() const noexcept{
        return this->size;
    }

	template<typename T>
	bool sllist<T>::re_size(size_t n){
		size_t cur_size = this->getSize();
        // // n < cur_size
        // remove elements at the n position until the end of the list 
        if(n < cur_size){
            slnode<T>* begin = this->head;
            slnode<T>* end_mark;
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
                slnode<T>* tmp_next = begin->next;
                delete begin;
                begin = tmp_next;
            }
            this->tail = end_mark;
            this->tail->next = nullptr;
            this->size = this->size - n;
        }else{

            //if n is more than current size of the container
            size_t n_cnt = n - this->size;
            slnode<T>* begin = this->tail;
            if(this->size == 0){
                this->head = this->tail;
            }
        
            for(size_t index = 0; index < n_cnt; ++index){
                slnode<T>* new_node = new slnode<T>;
                new_node->value = T(); //template constructor of any type e.g. std::string()
                begin->next = new_node;
                begin = begin->next;
            }
            this->size = n;
            this->tail = begin;
        }
        return true;
	}

	template<typename T>
	void sllist<T>::pop_front(){
        slnode<T>* del_node = this->head;
        this->head = del_node->next;
        delete del_node;
        this->size--;
        if(this->size == 1){
            this->tail = this->head;
        }
    }

	template<typename T>
	void sllist<T>::insert_after(T value, size_t position){
        size_t count = 0;
        size_t list_size = this->getSize();
        slnode<T>* child_node = this->head;
        //#First case (head (to be inserted)) --> (node_2) --> (node_3)
        if(!(this->head) || position == 0){
            this->push_front(value);
            return;
        }
        while(child_node){
            //#Second Case (head) --> (node_2) --> (node_3 (to be inserted))
            if (count == list_size-1 && position > count){
                this->re_size(list_size + 1);
                (this->tail)->value = value;
                break;
            //#Third Case (head) --> (node_2 (to be inserted)) --> (node_3)
            }else if(position == count && position < list_size){
                slnode<T>* new_node = new slnode<T>;
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
	template<class T>
	sllist<T>::slnode<T>* sllist<T>::find(T value) const{
        slnode<T>* child_node = this->head;
        slnode<T>* result = nullptr;
        while(child_node){
            if(child_node->value == value){
                result = child_node;
                break;
            }
            child_node = child_node->next;
        }
        return result;
    }
	template<typename T>
    bool sllist<T>::remove_first(T value){
        bool res = false;
        sllist<T>::slnode<T>* child_node = this->head;
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
	template<typename T>
	T& sllist<T>::operator[](size_t index){
			slnode<T>* begin = this->head;
			for(size_t pos = 0; pos < this->size; ++pos){
				if(pos == index){
					break;
				}
				begin = begin->next;
			}
			T& res = begin->value;
			return res;
		
	}
} // end namespace hlp2
#endif






