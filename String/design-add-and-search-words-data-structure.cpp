class WordDictionary {
public:
   struct TrieNode{
    bool isend=false;
    TrieNode* children[26];
   };
   TrieNode* getNode(){
    TrieNode* newnode=new TrieNode();
    newnode->isend=false;
    for (int i = 0; i < 26; i++) {
    newnode->children[i] = nullptr;
}
    return newnode;
   }
   
    TrieNode* root;
    WordDictionary() {
        root=getNode();
    }
    
    void addWord(string word) {
        TrieNode* cr=root;
        for(auto it:word){
            if(cr->children[it-'a']==NULL){
                cr->children[it-'a']=getNode();
            }
            cr=cr->children[it-'a'];
        }
        cr->isend=true;
    }
     bool searchutil(TrieNode* cr, string word) {
    for (int i = 0; i < word.size(); i++) {
        if (cr == nullptr) return false;
        
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (cr->children[j] != NULL) {
                    if (searchutil(cr->children[j], word.substr(i + 1))) {
                        return true;
                    }
                }
            }
            return false;
        } 
        
        int idx = word[i] - 'a';
        if (cr->children[idx] == NULL) {
            return false;
        }
        cr = cr->children[idx];
    }
    return cr != NULL && cr->isend;
}
    bool search(string word) {
       
      return  searchutil(root,word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */