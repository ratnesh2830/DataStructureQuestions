#include<iostream>
using namespace std;
#include<unordered_map>

class LRUcache
{
    //creating a doubly linked list
    public:
    class Node
    {
        public:

        int value;
        int key;
        Node *next;
        Node *prev;

        Node(int key,int value)
        {
            this->key=key;
            this->value=value;
            next=NULL;
            prev=NULL;
        }
    };

    Node *head=new Node(-1,-1);
    Node *tail=new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>map;

    LRUcache(int capacity)
    {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void add(Node *newNode)
    {
        Node *headnext=head->next;
        head->next=newNode;
        newNode->next=headnext;
        newNode->prev=head;
        headnext->prev=newNode;
    }

    void deleteNode(Node *deletenode)
    {
        Node *predele=deletenode->prev;
        Node *nextdele=deletenode->next;
        predele->next=nextdele;
        nextdele->prev=predele;
    }

    int get(int key)
    {
        if(map.find(key)!=map.end())
        {
            Node *existed=map[key];
            int res=existed->value;
            deleteNode(existed);
            add(existed);
            return res;
        }
        return -1;
    }
    

    void put(int key,int value)
    {
        if(map.find(key)!=map.end())
        {
            Node *existed=map[key];
            map.erase(key);
            deleteNode(existed);
            delete(existed);
        }
        if(map.size()==cap)
        {
            Node *leastfrequentnode=tail->prev;
            map.erase(tail->prev->key);
            deleteNode(leastfrequentnode);
            delete(leastfrequentnode);
        }

        Node *newNode=new Node(key,value);
        add(newNode);
        map[key]=newNode;
    }

    
};

int main()
{
    LRUcache obj(5);
    obj.put(1,10);
    obj.put(2,20);
    obj.put(3,30);
    cout<<obj.head->next->value<<endl;
    cout<<obj.head->next->next->value<<endl;
    cout<<obj.head->next->next->next->value<<endl;
    cout<<endl;
    
    cout<<obj.get(2);
    cout<<obj.get(2);


    
   
return 0;
    
   
return 0;
}