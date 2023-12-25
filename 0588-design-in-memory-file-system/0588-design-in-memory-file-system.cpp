class FileSystem {
public:
    class Node{
      public:
        unordered_map<string,Node*> children;
        bool isDir;
        string content;
        Node(){
            isDir = true;
            content = "";
        }
    };
    Node* root;
    FileSystem() {
        root = new Node();
    }
    
    vector<string> getThePaths(string path){
        stringstream ss(path);
        string word;
        vector<string> res;
        while(getline(ss,word,'/')){
            // cout<<word<<endl;
            if(word!=""){
                res.push_back(word);
            }
        }
        return res;
    }
    
    vector<string> ls(string path) {
        // cout<<path<<endl;
        vector<string> names = getThePaths(path);
        Node* curr = root;
        vector<string> res;
        // cout<<names.size()<<endl;
        for(string name : names){
            curr = curr->children[name];
        }
        if(curr->isDir == false){
            res.push_back(names[names.size()-1]);
        }
        
        for(auto itr = (curr->children).begin();itr != (curr->children).end();itr++){
            res.push_back(itr->first);
        }
        sort(res.begin(),res.end());
        return res;
    }
    
    void mkdir(string path) {
        vector<string> names = getThePaths(path);
        Node* curr = root;
        for(string name : names){
            if((curr->children).find(name) == (curr->children).end()){
                Node* child = new Node();
                curr->children[name] = child;
            }
            curr = curr->children[name];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> names = getThePaths(filePath);
        Node* curr = root;
        for(string name : names){
            if((curr->children).find(name) == (curr->children).end()){
                Node* child = new Node();
                curr->children[name] = child;
            }
            curr = curr->children[name];
        }
        curr->isDir = false;
        curr->content += content; 
        // cout<<curr->content<<endl;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> names = getThePaths(filePath);
        Node* curr = root;
        for(string name : names){
            if((curr->children).find(name) == (curr->children).end()){
                Node* child = new Node();
                curr->children[name] = child;
            }
            curr = curr->children[name];
        }
        return curr->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */