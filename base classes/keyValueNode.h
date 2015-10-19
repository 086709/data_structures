#include<iostream>
#ifndef KVPNODE_H_
#define KVPNODE_H_
template<typename key, typename elem>
class kvp_node {
	bool setinel;
	key k_val;
	elem e_val;
	kvp_node<key, elem> *next;
	kvp_node<key, elem> *prev;
public:
	//default constructor
	kvp_node();
	//use this constructor
	kvp_node(key k, elem e, bool set = false);
	//destructor
	~kvp_node();
	//copy constructor
	kvp_node(const kvp_node<key, elem> &kvp);
	//assignment constructor
	void operator=(const kvp_node<key, elem> &kvp_);
	//use to set just the element
	void operator=(elem &e);

	//returns keyvalue
	key key_();
	//returns element
	elem elm_();

	//sets key value
	void set_key(key k);
	//sets element value
	void set_elm(elem e);

	//comparators, all will use the default comparators for the key type
	bool operator==(kvp_node<key, elem> &kvp);
	bool operator>=(kvp_node<key, elem> &kvp);
	bool operator<=(kvp_node<key, elem> &kvp);
	bool operator>(kvp_node<key, elem> &kvp);
	bool operator<(kvp_node<key, elem> &kvp);

	//returns next node
	kvp_node<key, elem> *gnext();
	//returns previous node
	kvp_node<key, elem> *gprev();

	//node linking functions
	//sets the next node
	void set_next(kvp_node<key, elem> *kvp);
	//sets the previous node
	void set_prev(kvp_node<key, elem> *kvp);
	//links node a forward to b and b backward to a
	void link_nodes(kvp_node<key, elem> *A, kvp_node<key, elem> *B);

	//setinel functions
	//makes setinel
	void set_set();
	//returns setinel value
	bool set();
	//prints node in (key, elem) format provided key
	//and elem classes have stream'<<' operators
	void pprint(kvp_node<key, elem> *kvp= NULL);

};

//constructors, destructors, assignment
template<typename key, typename elem>
kvp_node<key, elem>::kvp_node() {
}

template<typename key, typename elem>
kvp_node<key, elem>::kvp_node(key k, elem e, bool set) {
	k_val = k;
	e_val = e;
	setinel = set;
}

template<typename key, typename elem>
kvp_node<key, elem>::~kvp_node(){

}

template<typename key, typename elem>
kvp_node<key, elem>::kvp_node(const kvp_node<key, elem> &kvp) {
	k_val = kvp.key_();
	e_val = kvp.elm_();
	setinel = kvp.set();
}

template<typename key, typename elem>
void kvp_node<key, elem>::operator=(const kvp_node<key, elem> &kvp) {
	k_val = kvp.key_();
	e_val = kvp.elm_();
	setinel = kvp.set();
}
// ==================================
//get object values
template<typename key, typename elem>
key kvp_node<key, elem>::key_() {
	return k_val;
}

template<typename key, typename elem>
elem kvp_node<key, elem>::elm_() {
	return e_val;
}

template<typename key, typename elem>
bool kvp_node<key, elem>::set() {
	return setinel;
}
// ==================================
//set object values
template<typename key, typename elem>
void kvp_node<key, elem>::set_key(key k) {
	k_val = k;
}

template<typename key, typename elem>
void kvp_node<key, elem>::set_elm(elem e) {
	e_val = e;
}

template<typename key, typename elem>
void kvp_node<key, elem>::set_set() {
	setinel = true;
}

template<typename key, typename elem>
void kvp_node<key, elem>::operator=(elem &e) {
	e_val = e;
}
// =================================
//get neighbor kv pair nodes
template<typename key, typename elem>
kvp_node<key, elem> *kvp_node<key, elem>::gnext() {
	return next;
}

template<typename key, typename elem>
kvp_node<key, elem> *kvp_node<key, elem>::gprev() {
	return prev;
}
// =================================
//set neighbor kv pair nodes
template<typename key, typename elem>
void kvp_node<key, elem>::set_next(kvp_node<key, elem> *kvp) {
	next = kvp;
}

template<typename key, typename elem>
void kvp_node<key, elem>::set_prev(kvp_node<key, elem> *kvp) {
	prev = kvp;
}

template<typename key, typename elem>
void kvp_node<key, elem>::link_nodes(kvp_node<key, elem> *A, kvp_node<key, elem> *B) {
	A->set_next(B);
	B->set_prev(A);
}
// ==================================
//comparison operators
template<typename key, typename elem>
bool kvp_node<key, elem>::operator<(kvp_node<key, elem> &kvp) {
	return (k_val < kvp.key_()) ? (true) : (false);
}

template<typename key, typename elem>
bool kvp_node<key, elem>::operator>(kvp_node<key, elem> &kvp) {
	return (k_val > kvp.key_()) ? (true) : (false);
}

template<typename key, typename elem>
bool kvp_node<key, elem>::operator<=(kvp_node<key, elem> &kvp) {
	return (k_val <= kvp.key_()) ? (true) : (false);
}

template<typename key, typename elem>
bool kvp_node<key, elem>::operator>=(kvp_node<key, elem> &kvp) {
	return (k_val >= kvp.key_()) ? (true) : (false);
}

template<typename key, typename elem>
bool kvp_node<key, elem>::operator==(kvp_node<key, elem> &kvp) {
	return (k_val == kvp.key_()) ? (true) : (false);
}
// ==================================
//stream operators

template<typename key, typename elem>
std::ostream &operator<<(std::ostream &os, kvp_node<key, elem>& kvp) {
	if (!kvp.set()) {
		os << kvp.elm_();
	}
	return os;
}

template<typename key, typename elem>
std::ostream &operator<<(std::ostream &os, kvp_node<key, elem> *kvp) {
	if (!kvp->set()) {
		os << kvp->elm_();
	}
	return os;
}

//==================================
//prints pair in (key, elem) format
template<typename key, typename elem>
void kvp_node<key, elem>::pprint(kvp_node<key, elem> *kvp) {
	if (kvp == NULL)
		kvp = this;
	std::cout << '<' << kvp->key_() << ','<< ' ' << kvp->elm_() << '>';

}

#endif
