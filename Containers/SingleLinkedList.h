#ifndef LIST_H
#define LIST_H


namespace MK2 {

	class sllist
	{
	public:

		struct slnode
		{
			slnode();
			~slnode() = default;
			
			int value;  // data portion
			slnode* next;
		};
		//Default ctor
		sllist();

		// Copy ctor
		sllist(sllist const&);
		// Destructor
		~sllist();

		// Copy assignment operator
		sllist& operator=(sllist const&);
		/*!*************************************************************************
    ****       	\brief Resize the container by deleting or adding n number of nodes
                \return true if successfully resized
				\return false if unsuccessfully resized
                ****************************************************************************
    ***/
		bool re_size(size_t n);
		// Returns the count of elements of the container
		size_t getSize() const;

		// Add a new value to the beginning 
		void push_front(int value);

		// Remove the front node
		void pop_front();


		//Clears the list 
		void clear();

		// Print the contents 
		void print() const;

		// Find first occurrence 
		slnode* find(int value) const;

		// Insert value in linked list at index.
		// Assume zero-based indexing with 1st element at index 0, the second element
		// at index 1, and so on. If list has 4 elements, their indices range from
		// 0 to 3. Then a call to insert() with index 4 would insert value as last
		// element of list. In the same example, if index is 10, then the value is
		// inserted at index 4. 
		void insert_after(int value, size_t position);

		/*!*************************************************************************
    ****       	\brief removes the first occurence of value specified in the linked list
                \return true if successfully found and remove.
				\return false if not found or unable to remove
                ****************************************************************************
    ***/
		bool remove_first(int value);

		friend std::ostream& operator<<(std::ostream& output, sllist const& list);

		friend std::ostream& operator<<(std::ostream& output, sllist const* list);


		
	protected:

		slnode* head;
		slnode* tail;
	private:
		size_t size;
	};



} // end namespace hlp2

#endif