class Solution {
    private : 

public:
        class Node{
        public :
            int rank;
            int parent;
            int size;
            Node(int parent,int rank,int size){
                this->rank = rank;
                this->parent = parent;
                this->size = size;
            }
    };
    vector<Node*> friendNodes;
    
    Node* findParent(int u){
        if(u == friendNodes[u]->parent){
            return friendNodes[u];
        }
        Node* y = findParent(friendNodes[u]->parent);
        friendNodes[u]->parent = y->parent;
        return y;
    }
    
    int doUnion(vector<int> log){
        int timestamp = log[0];
        int u = log[1];
        int v = log[2];
        Node* x = findParent(u);
        Node* y = findParent(v);
        if( x->parent!= y->parent){
            x->parent = y->parent;
            y->rank = timestamp;
            y->size = x->size+y->size;
        } 
        
        return y->rank;
    }
    
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        for(int i=0;i<n;i++){
            Node* x = new Node(i,0,1);
            friendNodes.push_back(x);
        }
        int maxTime = INT_MIN;
        for(int i=0;i<logs.size();i++){
            maxTime = max(maxTime,doUnion(logs[i]));
        }
        
        if(findParent(0)->size != n){
            return -1;
        }
        
        
        return maxTime;
    }
};