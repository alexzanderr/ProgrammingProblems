#include <iostream>
#include <string.h>

using namespace std;

struct link {
	node* peer;
	link* next;
};

struct node {
	int peer_num;
	link* peers;
};

node* nodes;

void create_link(node* node1, node* node2) {
	link* l = new link;
	l->peer = node2;
	l->next = NULL;
	link** temp = &node1->peers;
	while (*temp) {
		temp = &(*temp)->next;
	}
	*temp = l;
	node1->peer_num++;
}

void add_link(node* node1, node* node2) {
	/* Adauga muchie pentru nodul 1 catre nodule 2 */
	create_link(node1, node2);
	/* Adauga muchie pentru nodul 2 catre nodule 1 */
	create_link(node2, node1);
}

void delete_link(node* node1, node* node2) {
	link** temp = &node1->peers;
	while (*temp && (*temp)->peer != node2) {
		temp = &(*temp)->next;
	}
	if (*temp) {
		*temp = (*temp)->next;
		node1->peer_num--;	
	}
}

void remove_link(node* node1, node* node2) {
	/* Sterge muchia pentru nodul 1 catre nodul 2 */
	delete_link(node1, node2);
	/* Sterge muchia pentru nodul 2 catre nodul 1 */
	delete_link(node2, node1);
}

bool find_link(node* node1, node* node2) {
	for (link* l = node1->peers; l != NULL; l = l->next)
		if (l->peer == node2)
			return true;
	return false;
}

int main() {
	int n, m, k, x, y;
	/* Citeste datele de intrare */
	cin >> n >> m >> k;
	nodes = new node[n + 1];
	memset(nodes, 0, sizeof(node) * n);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		add_link(&nodes[x], &nodes[y]);
	}
	// a)
	for (int i = 1; i <= n; i++)
		cout << nodes[i].peer_num << ' ';
	cout << endl;
	// b)
	node self;
	memset(&self, 0, sizeof(self));
	/* Adauga persoanle cu k sau mai multi prieteni la prieteni */
	for (int i = 1; i <= n; i++)
		add_link(&self, &nodes[i]);
	bool check = true;
	while (check) {
		check = false;
		/* Verifica daca fiecare prieten are k sau mai multi prieteni in lista mea de prieteni */
		for (link* p = self.peers; p != NULL; p = p->next) {
			int total = 0;
			for (link* pp = p->peer->peers; pp != NULL; pp = pp->next)
				if (find_link(&self, pp->peer))
					total++;
			if (total < k) {
				remove_link(&self, p->peer);
				check = true;
				break;
			}
		}
	}
	check = false;
	for (int i = 1; i <= n; i++) 
		if (find_link(&self, &nodes[i])) {
			cout << i << ' ';
			check = true;
		}
	if (check) {
		cout << endl;
	} else {
		cout << "NU" << endl;
	}
}