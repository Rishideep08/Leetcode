class Solution {
public:
    class Node{
        public : 
            vector<Node*> children;
            bool end = false;
            Node(){
                children = vector<Node*> (26,NULL);
            };
    };
    
    Node* root;
    
    
    void insertInTrie(string product,Node* root){
        for(char ch:product){
            int index = ch-'a';
            if((root->children)[index] == NULL){
                Node* child = new Node();
                (root->children)[index] = child;
            }
            root = (root->children)[index];
        }        
        root->end = true;
    }

    void preProcess(vector<string> products,Node* root){
        for(string product : products){
            insertInTrie(product, root);
        }
    }
    
    void calcMin(Node* root,string word,vector<string> &ans){
        if(ans.size() ==3){
            return;
        }
        if(root->end == true){
            ans.push_back(word);
        }
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                char ch = ('a'+i);
                string temp= word+ch;
                calcMin(root->children[i],temp,ans);
            }
        }
        return;
    }
    
    vector<string> search(string word,Node* root){
        int i = 0;
        while(root!=NULL && i<word.size()){
            root = root->children[word[i]-'a'];
            i++;
        }
        vector<string> ans;
        int count = 0;
        if(root != NULL){
           calcMin(root,word,ans);
        }
        return ans;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Node* root = new Node();
        preProcess(products,root);
        vector<vector<string>> ans;
        for(int i=0;i<searchWord.size();i++){
            ans.push_back(search(searchWord.substr(0,i+1),root));
        }
        return ans;
    }
};