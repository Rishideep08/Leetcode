class LRUCache {
private : 
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int key, int val){
                this->key = key;
                this->val = val;
                this->next = NULL;
                this->prev = NULL;
            }
    };
    int n;
    Node* head;
    Node* last;
    unordered_map<int,Node*>um;
public:
    LRUCache(int capacity) {
        this->n = capacity;
        this->head = NULL;
        this->last = NULL;
    }
    
    void print(Node* head){
        cout<<"Start-----"<<endl;
        while(head!=NULL){
            cout<<head->key<<" "<<head->val<<endl;
            head = head->next;
        }
        cout<<"End------"<<endl;
        
    }
    
    void printLast(Node* head){
        cout<<"Start-----"<<endl;
        while(head!=NULL){
            cout<<head->key<<" "<<head->val<<endl;
            head = head->prev;
        }
        cout<<"End------"<<endl;
        
        
    }
    int get(int key) {
        // cout<<"get "<< key<<endl;
        if(um.find(key) != um.end()){
            Node* node = um[key];
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            if(prevNode!=NULL){
                prevNode->next = nextNode;
                if(nextNode!=NULL){
                    nextNode->prev = prevNode;
                }else{
                    last = prevNode;
                }
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
            }
            // print(head);
            return um[key]->val;
        }else{
            return -1;
        }
        
        
    }
    
    void put(int key, int value) {
        // cout<<"put "<< key<<" "<<value<<endl;
        if(um.find(key)!=um.end()){
            Node* node = um[key];
            node->val = value;
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            if(prevNode!=NULL){
                prevNode->next = nextNode;
                if(nextNode!=NULL){
                    nextNode->prev = prevNode;
                }else{
                    last = prevNode;
                }
                node->next = head;
                node->prev = NULL;
                head->prev = node;
                head = node;
            }
        }else{
            if(um.size() == this->n){
                um.erase((this->last)->key);
                this->last = (this->last)->prev;
                if((this->last) == NULL){
                    this->head = NULL;
                }else{
                    (this->last)->next = NULL;
                }
            }
            Node* temp = new Node(key,value);
            temp->next = this->head;
            if(this->head!=NULL){
                (this->head)->prev = temp;
            }
            (this->head) = temp;
            if(last == NULL){
                last = (this->head);
            }
            um[key] = (this->head);  
        }
        // if(key == 9 && value == 3){
        //     print(head);
        //     printLast(last);
        // }
    }
    
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */