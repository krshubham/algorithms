class TrieNode {
    private boolean end;
    private TrieNode[] children;

    public TrieNode() {
        this.end = false;
        this.children = new TrieNode[28];
        for(int i = 0; i < 28; i++) {
            children[i] = null;
        }
    }

    public void setEnd() {
        this.end = true;
    }

    public boolean isEnd() {
        return isEnd;
    }
}

public class Trie {
    private TrieNode root;
    public Trie() {
        root = new TrieNode();
    }
    public void add(String word) {
        TrieNode temp = root;
        for(char c: word) {
            int index = c-'a';
            if(temp.children[index] == null) {
                temp.children[index] = new TrieNode();
            }
            temp = temp.children[index];
        }
        temp.setEnd();
    }

    public void contains(String word) {
        TrieNode temp = root;
        for(char c: word) {
            int index = c - 'a';
            if(temp.children[index] != null) {
                temp = temp.children[index];
            }
            else {
                return false;
            }
        }
        return temp != null && temp.isEnd;
    }
}