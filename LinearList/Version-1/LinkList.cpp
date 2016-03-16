#include <iostream>
using namespace std;

template <class ElemType>
struct Node{
    ElemType data;
    Node<ElemType> *pNext;
};



template <class ElemType>
class LinkList {
    int length;
    Node<ElemType> *head;
    
public:
    void init();
    void creatList();
    void destoryList();
    int length();
    bool isEmpty();
    
    
};

int main()
{
    
}