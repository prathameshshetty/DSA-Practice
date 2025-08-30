class LRUCache {
public:

    class Node
    {
        public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int _key,int _val)
        {
            key=_key;
            val=_val;
        }

    };


    int cap;
    unordered_map<int,Node*> mpp;
    Node* head= new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    

    void addNodeHead(Node* newNode)
    {
        Node* headNext=head->next;
        newNode->next=headNext;
        newNode->prev=head;
        head->next=newNode;
        headNext->prev=newNode;
    }


    void deleteNode(Node* delNode)
    {
        Node* delPrev=delNode->prev;
        Node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }

    int get(int key) {
        //Check if the val is there or not
        if(mpp.find(key)!=mpp.end())
        {   
            Node* temp=mpp[key];
            int res=temp->val;
            mpp.erase(key);
            deleteNode(temp);
            addNodeHead(temp);
            mpp[key]=head->next;
            return res;
        }

        return -1;
    }
    
    void put(int key, int value) {
        //before putting check if the node exists in our LL
        if(mpp.find(key)!=mpp.end())
        {
            //now update its val
            Node* temp=mpp[key];
            mpp.erase(key);
            deleteNode(temp);
        }

        if(mpp.size()==cap)
        {
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);

        }

        addNodeHead(new Node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */