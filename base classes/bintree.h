#include "node.h"
#include "keyValuePair.h"

#ifndef BINTREE_H_
#define BINTREE_H_


/*
*Binary tree template
*creates binary trees from <key, data> pairs
*can use with any data class
*use only keys with comparison operations
*/
template<typename key, typename data>
class bintree {
	node<kvPair<key, data>> *rt;
	int nodes;
	//recurisve insert
	void insert(node<kvPair<key, data>> *root, kvPair<key, data> *kv);
	//inorder print traversal
	void print(node<kvPair<key, data>> *root);
	//removes node from tree and re-organizes
	void remove(node<kvPair<key, data>> *root, key k);
	//postorder traversal
	void pprint(node<kvPair<key, data>> *root);
	//gets leftmost node of root subtree
	node<kvPair<key, data>>* min(node<kvPair<key, data>> *root);
	//gets rightmost node of root subtree
	node<kvPair<key, data>>* max(node<kvPair<key, data>> *root);
	//returns pointer to key value pair matching the key, returns
	//NULL if kvpair does not exist
	node<kvPair<key, data>> *search(node<kvPair<key, data>> *root, key k);
	
public:
	bintree();
	~bintree();
	//non recursive calling functions
	void insert(key k, data d);
	void print();
	void pprint();
	kvPair<key, data> &min();
	kvPair<key, data> &max();
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

template<typename key, typename data>
void bintree<key, data>::pprint() {
	pprint(rt);
}

template<typename key, typename data>
void bintree<key, data>::pprint(node<kvPair<key, data>> *root) {
	if (root->lc != NULL)
		pprint(root->lc);
	if (root->rc != NULL)
		pprint(root->rc);
	std::cout << root->d_val << std::endl;
}

template<typename key, typename data>
kvPair<key, data> &bintree<key, data>::min() {
	if (rt != NULL)
		return min(rt)->d_val;
	else
		return rt->d_val;

}

template<typename key, typename data>
node<kvPair<key, data>> *bintree<key, data>::min(node<kvPair<key, data>> *root) {
	if (root->lc != NULL)
		return(min(root->lc));
	else
		return root;
}

template<typename key, typename data>
kvPair<key, data> &bintree<key, data>::max() {
	if (rt != NULL)
		return max(rt)->d_val;
	else
		return rt->d_val;
}

template<typename key, typename data>
node<kvPair<key, data>> *bintree<key, data>::max(node<kvPair<key, data>> *root) {
	if (root->rc != NULL)
		return max(root->rc);
	else
		return root;
}

template<typename key, typename data>
kvPair<key, data> *bintree<key, data>::search(key k) {
	return (rt != NULL) ? (&search(rt, k)->d_val) : (NULL);
}

template<typename key, typename data>
node<kvPair<key, data>> *bintree<key, data>::search(node<kvPair<key, data>> *root, key k) {
	return ((root->d_val.k_val == k) ? (root) : ((k < root->d_val.k_val) ? ((root->lc == NULL) ? (NULL) : (search(root->lc, k))) : ((root->rc == NULL) ? (NULL) : (search(root->rc, k)))));
}

template<typename key, typename data>
void bintree<key, data>::remove(key k) {
	

}
#endif
