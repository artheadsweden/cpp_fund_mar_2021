#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    // Default constructor
    Node();
    // Constructor that takes one argument of type T.
    // Sets next to null
    Node(T data);
    // The destructor only prints that the node is destructed
    ~Node();
    // Getter for data
    T get_data();
    // Setter for data
    void set_data(T data);
    // Getter for the next pointer
    Node<T>* get_next();
    // Setter for the next pointer
    void set_next(Node<T>* next);

private:
    // Data stored in the node is of type T
    T data;
    // Pointer to the next node in the list.
    // If this is the last node in the list, this pointer should be null.
    Node<T>* next;
};

template <typename T>
class LinkedList
{
public:
    // Default constructor that creates an empty list
    LinkedList();
    // Copy constructor. Needs to copy all the nodes from the other list
    LinkedList(const LinkedList<T>& other);
    // Move constructor. Needs to take ownership of all of the other lists content
    LinkedList(LinkedList<T>&& other);
    // List destructor. Needs to delete all nodes in the list
    ~LinkedList();

    // Copy assignment operator. Needs to copy all the nodes from the other list
    LinkedList<T>& operator = (const LinkedList<T>& other);
    // Move assignment operator. Needs to take ownership of all of the other lists content
    LinkedList<T>& operator = (LinkedList<T>&& other);
    // Subscript operator. Even though the are not in continues memory we want to be able to index into it
    T operator [](int index);

    // Delete all nodes in list
    void clear();
    // Insert a new node at the list head
    void insert_head(T data);
    // Insert a new node at the list tail
    void insert_tail(T data);
    // Insert a new node at a specific location
    void insert_at(T data, int index);

    // Removes the node at the head and returns it's data
    T pop_head();
    // Removes the node at the tail and returns it's data
    T pop_tail();
    // Removes the node at index and returns it's data
    T pop_at(int index);

    // Prints the list
    void print();
    // Returns the number of nodes in the list
    int get_size();
private:
    // Helpers
    // Get a node at index
    Node<T> get_node(int index);
    // Deep copy the content from other.
    void copy(const LinkedList<T>& other);

    // Pointer to first node in list
    Node<T>* head;
    // Pointer to last node in list
    Node<T>* tail;
    // Counter to keep track of the number of nodes in the list
    int size;
};

template <typename T>
void LinkedList<T>::print()
{
   Node<T>* temp_ptr = head;
   while(temp_ptr)
   {
       cout << temp_ptr->get_data() << " ";
       if(temp_ptr->get_next())
       { 
           cout << "->";
       }
       else
       {
           cout << "-|";
       }
       temp_ptr = temp_ptr->get_next();
   }
   cout << endl; 
}


int main()
{
    return 0;
}