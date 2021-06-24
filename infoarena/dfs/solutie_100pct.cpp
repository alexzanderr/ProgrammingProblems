#include <iostream>
#include <fstream>

using namespace std;

#define dim 100005

struct Node {
    int value;
    Node *next;
};

void visualizeLinkedLists(Node* list[dim], int nodesNumber) {
    cout << "[\n";
    for(int i = 1; i <= nodesNumber; i++) {
        cout << "\t" << list[i]->value << " -> [ ";
        Node *iter = list[i]->next;
        if (iter == nullptr) {
            cout << "]\n";
        } else {
            while (iter->next) {
                cout << iter->value << ", ";
                iter = iter->next;
            }
            cout << iter->value << " ]\n";
        }

        
    }
    cout << "]\n";
}

void addNode(Node* location, int value) {
    Node* node = new Node;
    node->value = value;
    node->next = nullptr;

    if (location->next == nullptr) {
        location->next = node;
    } else {
        Node* iter = location->next;
        while (iter->next) {
            iter = iter->next;
        } 
        iter->next = node;
    }
}

void DepthFirstSearch(Node *NodesVector[dim], int visited[dim], int node) {
    visited[node] = 1;
    for (Node *iter = NodesVector[node]; iter != nullptr; iter = iter->next) {
        if (!visited[iter->value]) {
            DepthFirstSearch(NodesVector, visited, iter->value);
        }
    }
}

int main() {

    Node* NodesVector[dim];
    
    ifstream input("dfs.in");
    ofstream output("dfs.out");

    for(int i = 0; i < dim; i++) {
        NodesVector[i] = nullptr;
    }

    int nodes;
    int edges;
    input >> nodes >> edges;

    for(int i = 1; i <= nodes; i++) {
        // aici alocam capul fiecarui element din vector
        // nu folosim implementarea clasica pentru ca este crap
        // adica pentru fiecare vertex din graf ii se va aloca 
        // valoarea vertexului pe indexul cu valorea vertexului
        // asta initial si dupa la fiecare muchie ce citeste partea 
        // dreapta si se adauga la nodurile existente in graf
        NodesVector[i] = new Node;
        NodesVector[i]->value = i;
        NodesVector[i]->next = nullptr;
    }

    // citim din fisier
    for(int i = 0; i < edges; i++) {
        int x;
        int y;
        input >> x >> y;
        addNode(NodesVector[x], y);
        addNode(NodesVector[y], x);
    }

    //visualizeLinkedLists(NodesVector, nodes);

    int visited[dim];
    for(int i = 0; i < dim; i++) {
        visited[i] = 0;
    }

    int conexComponents = 0;
    for(int i = 1; i <= nodes; i++) {
        if (!visited[i]) {
            conexComponents++; 
            DepthFirstSearch(NodesVector, visited, i);
        }
    }
   
    output << conexComponents;
    return 0;
}