#include <bits/stdc++.h>
#define input freopen("inTrie.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node {
    char currentCharacter;
    bool endOfWord;
    node *children[26];
    node() {
        endOfWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insert(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = new node();
        }
        currentNode = currentNode->children[index];
        currentNode->currentCharacter = word[i];
    }
    currentNode->endOfWord = true;
}

bool search(node *trie, string word) {
    node *currentNode = trie;
    for (int i = 0; i < word.size(); i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            return false;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->endOfWord;
}

// Ve si un nodo tiene hijos
bool hasChildren(node *currentNode) {
    for (int i = 0; i < 26; i++) {
        if (currentNode->children[i] != NULL) {
            return true;
        }
    }
    return false;
}

// Elimina una palabra del Trie y limpia nodos sin uso
bool deleteWord(node *&currentNode, string word, int depth = 0) {
    if (!currentNode) return false;

    if (depth == word.size()) {
        if (currentNode->endOfWord) {
            currentNode->endOfWord = false;

            if (!hasChildren(currentNode)) {
                delete currentNode;
                currentNode = NULL;
                return true;
            }
            return false;
        }
    }

    int index = word[depth] - 'a';
    if (deleteWord(currentNode->children[index], word, depth + 1)) {
        if (!hasChildren(currentNode) && !currentNode->endOfWord) {
            delete currentNode;
            currentNode = NULL;
            return true;
        }
    }
    return false;
}

int main() {
    int wordsNumber;
    cout << "Ingrese el número de palabras: ";
    cin >> wordsNumber;

    node *trie = new node();

    cout << "Ingrese las palabras: " << endl;
    while (wordsNumber--) {
        string word;
        cin >> word;
        insert(trie, word);
    }

    if (search(trie, "apt")) {
        cout << "existe la palabra apt" << endl; // Ve si la palabra "apt" existe en el Trie
    } else {
        cout << "No existe la palabra apt" << endl;
    }

    if (search(trie, "appli")) {
        cout << "existe la palabra appli" << endl; // Ve si "appli" existe
    } else {
        cout << "No existe la palabra appli" << endl;
    }

    if (search(trie, "application")) {
        cout << "existe la palabra application" << endl; // Ve si "application" existe
    } else {
        cout << "No existe la palabra application" << endl;
    }

    insert(trie, "appli");

    if (search(trie, "appli")) {
        cout << "existe la palabra appli" << endl;
    } else {
        cout << "No existe la palabra appli" << endl;
    }

    // Elimina la palabra "application" del Trie
    deleteWord(trie, "application");
    if (search(trie, "application")) {
        cout << "existe la palabra application" << endl;
    } else {
        cout << "No existe la palabra application" << endl;
    }

    return 0;
}
