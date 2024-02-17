#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


template <class T>
class LListNode{
    
    T data;
    LListNode< T >* next;

    public:
        LListNode(T newdata  = T(), LListNode<T>* newNext = nullptr) :
        data(newdata), next(newNext){}
        friend class LList < T >;
}

template <class T>
class LList{
    LListNode<T>* head;
    LListNode<T>* recursiveCopy(LListNode<T>* rhs){
        if(rhs == nullptr){
            return nullptr;
        }
        return new LListNode<T>(rhs->data, recursiveCopy(rhs->next));
    }

    public:
        LList() :head(nullptr){}
        LList(const LList& rhs) :head(nullptr){ *this = rhs};
        LList<T>& operator = (const<T>& rhs);
        ~LList(){ clear(); }
        void insertAtHead(T newdata);
        T removeFromHead();
        bool isEmpty() const {return head == nullptr;}
        void clear();
        void insertAtTail(T newdata){
            if (isEmpty()){
                insertAtHead(newdata);
                return
            }

            LListNode<T>* temp = new LListNode<T>(newdata);
            LListNode<T>* end = temp;
            while(end->next != nullptr){
                end = end->next;
            }
        };

        void insertAtPoint(LListNode<T>* ptr, T newdata);

        int size() const{
            int count = 0;
            LListNode<T>* temp = head;
            while (temp != nullptr){
                count++;
                temp = temp->next;
            }
            return count;
        }
}

int main(){

    
    return 0;
}