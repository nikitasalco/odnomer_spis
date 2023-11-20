#include <iostream>
using namespace std;

template<class T>

class List
{
public:
    List();
    ~List();
    // получения размера
    int GetSize() { return Size; }
    // Удаляет элемент в начале списка.
    void pop_front();
    // Добавляет элемент в конец списка.
    void push_back(T data);
    // 	Удаляет все элементы списка.
    void clear();
    // Добавляет элемент в начало списка.
    void push_front(T data);
    // Вставляет элемент по индексу
    void insert(T value, int index);
    // Удаляет элемент по индексу
    void removeAT(int index);
    // Удаляет элемент в конце списка.
    void pop_back();
    T& operator[](const int index);
private:

    template<class T>
    class Node 
    {
    public:
        Node* pNext;
        T data;
        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;

};

template<class T>
List<T>::List()
{
    Size = 0;
    head = nullptr;
}

template<class T>
List<T>::~List()
{
    clear();
}

template<class T>
T& List<T>::operator[](const int index)
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}

template<class T>
void List<T>::pop_front()
{
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<class T>
void List<T>::push_back(T data)
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;
        while (current->pNext != nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
};

template<class T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<class T>
void List<T>::push_front(T data)
{
        head = new Node<T>(data,head);
        Size++;
}
template<class T>
void List<T>::insert(T value, int index)
{
    

    if (index == 0)
    {
        push_front;
    }
    else
    {
        Node<T> previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous.pNext;
        }
        Node<T>* newNode = new Node<T>(value, previous.pNext);
        previous.pNext = newNode;
        
        Size++;
    }
}
template<class T>
void List<T>::removeAT(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }


        Node<T>* toDelete = previous->pNext;

        previous->pNext = toDelete->pNext;

        delete toDelete;

        Size--;
    }
}
template<class T>
void List<T>::pop_back()
{
    removeAT(Size - 1);
};

int main()
{
    List<int> list;

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);
    list.push_front(5);
    list.pop_back();
    for (int i = 0; i < list.GetSize(); i++)
    {
        std::cout << list[i] << std::endl;
    }
    return 0;
}