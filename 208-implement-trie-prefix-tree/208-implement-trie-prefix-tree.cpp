class Trie {
public:
    class Node{
        public:
        vector<Node*> data;
        bool end;
        Node(){
            data = vector<Node*>(26,NULL);
            end = false;
        }
    };
    Node* start;
    Trie() {
        start = new Node();
    }
    
    void insert(string word) {
        Node* temp = start;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(start->data[index] == NULL)
                start->data[index] = new Node();
            start = start->data[index];
        }
        start->end = true;
        start = temp;
    }
    
    bool search(string word) {
        Node* temp = start;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(temp->data[index] == NULL){
                return false;
            }else{
                temp = temp->data[index];
            }
        }

        return temp->end;
        
    }
    
    bool startsWith(string word) {
        Node* temp = start;
        for(int i=0;i<word.size();i++){
            int index = word[i]-'a';
            if(temp->data[index] == NULL){
                return false;
            }else{
                temp = temp->data[index];
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */