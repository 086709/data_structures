#include <iostream>

#ifndef NODE_H_
#define NODE_H_

/*
*basic node template
*to be used for storing data elements that support comparison operations
*/

template<typename data>
class node {
public:
	data d_val;
	node<data> *lc;
	node<data> *rc;
	node();
	node(data dat);
	node(const node<data> &n);
	~node();
	void operator=(const node<data> &n);
	bool operator<(node<data> *n);
	bool operator>(node<data> *n);
	bool operator<=(node<data> *n);
	bool operator>=(node<data> *n);
	bool operator==(node<data> *n);

};

template<typename data>
node<data>::node() {

}

template<typename data>
node<data>::node(data dat) {
	d_val = dat;
}

template<typename data>
node<data>::~node() {
	delete lc;
	delete rc;
}

template<typename data>
void node<data>::operator=(const node<data> &n) {
	d_val = n.d_val;
	lc = n.lc;
	rc = n.rc;
}

template<typename data>
bool node<data>::operator>(node<data> *n) {
	return(d_val > n.d_val);
}

template<typename data>
bool node<data>::operator<(node<data> *n) {
	return(d_val < n.d_val);
}

template<typename data>
bool node<data>::operator<=(node<data> *n) {
	return(d_val <= n.d_val);
}

template<typename data>
bool node<data>::operator>=(node<data> *n) {
	return(d_val >= n.d_val);
}

template<typename data>
bool node<data>::operator==(node<data> *n) {
	return(d_val == n.d_val);
}


template<typename data>
std::ostream &operator<<(std::ostream &os, node<data> &n) {
	os << n.d_val;
	return os;
}

template<typename data>
std::ostream &operator<<(std::ostream &os, node<data> *n) {
	os << n->d_val;
	return os;
}
#endif
