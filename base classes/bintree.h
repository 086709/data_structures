#include "node.h"
#include "keyValuePair.h"

#ifndef BINTREE_H_
#define BINTREE_H_

template<typename key, typename data>
class bintree {
	node<kvPair<key, data>> *rt;
	int nodes;
	void insert(node<kvPair<key, data>> *root, kvPair<key, data> *kv);
	void print(node<kvPair<key, data>> *root);
	void remove(node<kvPair<key, data>> *root, key k);
	kvPair<key, data> *search(node<kvPair<key, data>> *root, key k);
public:
	bintree();
	~bintree();
	void insert(key k, data d);
	void print();
	void remove(key k);
	kvPair<key, data> *search(key k);
};

template<typename key, typename data>
bintree<key, data>::bintree() {

}

template<typename key, typename data>
bintree<key, data>::~bintree(){
	delete rt;
}

template<typename key, typename data>
void bintree<key, data>::insert(key k, data d) {
	kvPair<key, data> *kv = new kvPair<key, data>;
	kv->d_val = d;
	kv->k_val = k;
	if (rt == NULL) {
		rt = new node<kvPair<key, data>>(*kv);
	}
	else
		insert(rt, kv);
}

template<typename key, typename data>
void bintree<key, data>::insert(node<kvPair<key, data>> *root, kvPair<key, data> *kv) {
	if (kv->k_val < root->d_val.k_val) {
		if (root->lc == NULL)
			root->lc = new node<kvPair<key, data>>(*kv);
		else
			insert(root->lc, kv);
	}
	else if (kv->k_val >= root->d_val.k_val) {
		if (root->rc == NULL)
			root->rc = new node<kvPair<key, data>>(*kv);
		else
			insert(root->rc, kv);
	}
}

template<typename key, typename data>
void bintree<key, data>::print() {
	if (rt != NULL)
		print(rt);
}

template<typename key, typename data>
void bintree<key, data>::print(node<kvPair<key, data>> *root) {
	if (root->lc != NULL)
		print(root->lc);
	std::cout << root->d_val << std::endl;
	if (root->rc != NULL)
		print(root->rc);
}


#endif
