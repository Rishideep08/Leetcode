class StreamChecker {
public:
    class Node{
        public:
            vector<Node*> children;
            bool end;
            Node(){
                children = vector<Node*>(26,NULL);
                end = false;
            }
           
    };
    
    Node* root;
    string lookup;
    void insert(string &word,Node* root){
        for(int i=word.size()-1;i>=0;i--){
            char ch = word[i];
            if(root->children[ch-'a'] == NULL){
                root->children[ch-'a'] = new Node();
            }
            root = root->children[ch-'a'];
        }
        root->end =true;
    }
    
    bool search(string &word,Node* root){
        int i=word.size()-1;
        if(root->end == true){
            return true;
        }
        while(i>=0 && root!=NULL){
            root = root->children[word[i]-'a'];
            if(root !=NULL && root->end == true){
                return true;
            }
            i--;
        }
        return false;
    }
    
    
    StreamChecker(vector<string>& words) {
        root = new Node();
        for(string word:words){
            insert(word,root);
        }
        // cout<<search("cd",root)<<endl;
    }
    
    bool query(char letter) {
        lookup+=letter;
        return search(lookup,root);
//         if(search(lookup,root) == true){
//             lookup="";
//             return true;
//         }
        
//         return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */