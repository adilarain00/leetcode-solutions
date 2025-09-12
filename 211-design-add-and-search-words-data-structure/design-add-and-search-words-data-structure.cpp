class TrieNode {
public:
    TrieNode* children[26];
    bool isWord;

    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isWord = true;
    }

    bool search(string word) { return dfs(word, 0, root); }

private:
    bool dfs(const string& word, int index, TrieNode* node) {
        if (!node)
            return false;
        if (index == word.size())
            return node->isWord;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, index + 1, node->children[i]))
                    return true;
            }
            return false;
        } else {
            int idx = c - 'a';
            return dfs(word, index + 1, node->children[idx]);
        }
    }
};