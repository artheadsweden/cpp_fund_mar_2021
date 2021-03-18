#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person() : name{"NoName"} {}
    Person(string n) : name{n} {}
    string get_name() {return name;}
private:
    string name;
};

template <typename T>
class Node
{
public:
    // Default constructor
    Node();
    // Constructor that takes one argument of type T.
    // Sets next to null
    explicit Node(T data);
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
Node<T>::Node() : data{T()}, next{nullptr}{}

template <typename T>
Node<T>::Node(T data) : data{data}, next{nullptr} {}

template <typename T>
Node<T>::~Node()
{
    cout << "Deleting node with data "  << data << endl;
}

template <typename T>
T Node<T>::get_data()
{
    return data;
}

template <typename T>
void Node<T>::set_data(T data)
{
    this->data = data;
}

template <typename T>
Node<T>* Node<T>::get_next()
{
    return next;
}

template <typename T>
void Node<T>::set_next(Node<T>* next)
{
    this->next = next;
}


template <typename T>
class LinkedList
{
public:
    // Default constructor that creates an empty list
    LinkedList();
    // Copy constructor. Needs to copy all the nodes from the other list
    LinkedList(const LinkedList<T>& other);
    // Move constructor. Needs to take ownership of all of the other lists content
    LinkedList(LinkedList<T>&& other) noexcept;
    // List destructor. Needs to delete all nodes in the list
    ~LinkedList();

    // Copy assignment operator. Needs to copy all the nodes from the other list
    LinkedList<T>& operator = (const LinkedList<T>& other);
    // Move assignment operator. Needs to take ownership of all of the other lists content
    LinkedList<T>& operator = (LinkedList<T>&& other) noexcept;
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
    //T pop_at(int index);

    // Prints the list
    void print();
    // Returns the number of nodes in the list
    int get_size();
private:
    // Helpers
    // Get a node at index
    Node<T>* get_node(int index);
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
LinkedList<T>::LinkedList() : head{nullptr}, tail{nullptr}, size{0} {}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head{nullptr}, tail{nullptr}, size{0}
{
    copy(other);
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) noexcept : head{nullptr}, tail{nullptr}, size{0}
{
    swap(head, other.head);
    swap(tail, other.tail);
    swap(size, other.size);
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <typename T>
LinkedList<T>& LinkedList<T>::operator = (const LinkedList<T>& other)
{
    copy(other);
    return *this;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator = (LinkedList<T>&& other) noexcept
{
    if(&other == this)
    {
        return *this;
    }

    if(head) {
        clear();
    }
    swap(head, other.head);
    swap(tail, other.tail);
    swap(size, other.size);

    return *this;
}

template <typename T>
T LinkedList<T>::operator [](int index)
{
    return get_node(index)->get_data();
}

template <typename T>
void LinkedList<T>::insert_head(T data)
{
    if(!head)
    {
        head = new Node<T>(data);
        tail = head;
    }
    else
    {
        auto temp_ptr = new Node<T>(data);
        temp_ptr->set_next(head);
        head = temp_ptr;
    }
    size++;
}


template <typename T>
void LinkedList<T>::insert_tail(T data)
{
    if(!tail)
    {
        tail = new Node<T>(data);
        head = tail;
    }
    else
    {
        tail->set_next(new Node<T>(data));
        tail = tail->get_next();
    }
    size++;
}

template <typename T>
void LinkedList<T>::insert_at(T data, int index)
{
    if(index > size || index < 0)
    {
        return;
    }
    if(index == 0)
    {
        insert_head(data);
        return;
    }
    if(index == size)
    {
        insert_tail(data);
        return;
    }
    auto temp_ptr = get_node(index-1);
    auto rest_of_list = temp_ptr->get_next();
    temp_ptr->set_next(new Node<T>(data));
    temp_ptr = temp_ptr->get_next();
    temp_ptr->set_next(rest_of_list);
    size++;
}

template <typename T>
T LinkedList<T>::pop_head()
{
    if(!head)
    {
        // Exception??
        return T();
    }
    auto data = head->get_data();
    auto temp_ptr = head->get_next();
    delete head;
    head = temp_ptr;
    if(!head)
    {
        tail = head;
    }
    size--;
    return data;
}

template <typename T>
T LinkedList<T>::pop_tail()
{
    if(!tail)
    {
        return T();
    }

    if(!head->get_next())
    {
        auto data = head->get_data();
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return data;
    }
    auto temp_ptr = head;
    while(temp_ptr->get_next() != tail)
    {
        temp_ptr = temp_ptr->get_next();
    }
    auto data = tail->get_data();
    delete tail;
    tail = temp_ptr;
    tail->set_next(nullptr);
    size--;
    return data;
}
          

template <typename T>
void LinkedList<T>::clear()
{
    if(!head)
    {
        return;
    }
    tail = head;
    while(tail)
    {
        tail = head->get_next();
        delete head;
        head = tail;
    }
    size = 0;
}

template <typename T>
void LinkedList<T>::print()
{
   if(!head)
   {
       cout << "<< EMPTY LIST >>" << endl;
   }
   auto temp_ptr = head;
   while(temp_ptr)
   {
       cout << temp_ptr->get_data().get_name() << " ";
       if(temp_ptr->get_next())
       { 
           cout << "-> ";
       }
       else
       {
           cout << "-|";
       }
       temp_ptr = temp_ptr->get_next();
   }
   cout << endl; 
}


template <typename T>
int LinkedList<T>::get_size()
{
    return size;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& other)
{
    if(&other == this)
    {
        return;
    }

    clear();

    if(!other.head)
    {
        return;
    }

    auto temp_ptr = other.head;
    while(temp_ptr)
    {
        insert_tail(temp_ptr->get_data());
        temp_ptr = temp_ptr->get_next();
    }
}

template <typename T>
Node<T>* LinkedList<T>::get_node(int index)
{
    if(!head || index > size - 1 || index < 0)
    {
        return nullptr;
    }

    int pos = 0;
    auto temp_ptr = head;
    while(pos < index)
    {
        temp_ptr = temp_ptr->get_next();
        pos++;
    }
    return temp_ptr;
}

int main()
{
    LinkedList<Person> values;
    values.insert_tail(Person("Alice"));
    values.insert_tail(Person("Bob"));
    values.insert_tail(Person("Charlie"));
    cout << values.get_size() << endl;
    auto person = values.pop_head();
    cout << values.get_size() << endl;
    cout << person.get_name() << endl;

    
    return 0;
}