#include <iostream>
#include <fstream>
//#include "D:\__Alexzander_files__\__computer_science__\cplusplus_stuff\__graphs__\util.hpp"

using namespace std;

ifstream input("bfs.in");
ofstream output("bfs.out");

#define lim 100005

struct Node {
    int value;
    Node *next;
};

void AddNode(Node* location, int value) {
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

void VisualizeNodesVector(Node *Nodes[lim], int nodesNumber) {
    cout << "Adjacency List:\n[\n";
    for(int index = 1; index <= nodesNumber ; index++) {
        cout << "\t" << Nodes[index]->value << " -> [ ";
        Node *iter = Nodes[index]->next;
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

int nodes;
int edges;
int starting_node;
Node* Nodes[lim];

void AllocateNodes() {
    for(int i = 1; i <= nodes; i++) {
        Nodes[i] = new Node;
        Nodes[i]->value = i;
        Nodes[i]->next = nullptr;
    }
}

void ReadNodes() {
    for(int i = 0; i < edges; i++) {
        int x, y;
        input >> x >> y;
        AddNode(Nodes[x], y);
    }
}

int visited[lim];
int distances[lim];
int queue[lim];
int degrees[lim];

int Degree(Node *node) {
    int deg = 0;
    while(node->next) {
        deg++;
        node = node->next;
    }
    return deg;
}

void CreateDegrees() {
    for(int i = 1; i <= nodes; i++) {
        degrees[i] = Degree(Nodes[i]);
    }
}

void BreadthFirstSearch(int node) {
    int begin = 1;
    int end = 1;

    queue[1] = node;
    visited[node] = 1;
    distances[node] = 0;

    while (begin <= end) {
        int item = queue[begin++];
        for (Node* elem = Nodes[item]; elem != nullptr; elem = elem->next) {
            if (!visited[elem->value]) {
                visited[elem->value] = 1;
                queue[++end] = elem->value;
                distances[queue[end]] = distances[item] + 1;
            }
        }
    }
}

void PrintDistances() {
    for(int i = 1; i <= nodes; i++) {
        cout << distances[i] << " ";
    }
}

int main() {   
    input >> nodes >> edges >> starting_node; 

    AllocateNodes();
    ReadNodes();
    CreateDegrees();
    //VisualizeNodesVector(Nodes, nodes);
    BreadthFirstSearch(starting_node);

    for(int i = 1; i <= nodes; i++) {
        if (distances[i] == 0 && i != starting_node) {
            distances[i] = -1;
        }
    }
    for(int i = 1; i <= nodes; i++) {
        output << distances[i] << " ";
    }

    input.close();
    output.close();

    return 0;
}