#include <iostream>
#ifndef KVP_H_
#define KVP_H_


/*
_---Key value pair template---_
*Can store arbitraty pairs of any type
*Pairs can be compared by key values
*Comparators must be defined for key
 class if user defined class
*/
template<typename key, typename data>
class kvPair {
public:
	key k_val;
	data d_val;
	~kvPair();
	kvPair();
	kvPair(key k, data d);
	kvPair(const kvPair<key, data> &kvp);
	void operator=(const kvPair<key, data> &kvp);

	bool operator==(kvPair<key, data> &kvp);
	bool operator>=(kvPair<key, data> &kvp);
	bool operator<=(kvPair<key, data> &kvp);
	bool operator>(kvPair<key, data> &kvp);
	bool operator<(kvPair<key, data> &kvp);
};

template<typename key, typename data>
kvPair<key, data>::kvPair() {

}

template<typename key, typename data>
kvPair<key, data>::kvPair(key k, data d) {
	k_val = k;
	d_val = d;
}

template<typename key, typename data>
kvPair<key, data>::kvPair(const kvPair<key, data> &kvp) {
	k_val = kvp.k_val;
	d_val = kvp.d_val;
}

template<typename key, typename data>
kvPair<key, data>::~kvPair() {

}

template<typename key, typename data>
void kvPair<key, data>::operator=(const kvPair<key, data> &kvp) {
	k_val = kvp.k_val;
	d_val = kvp.d_val;
}

template<typename key, typename data>
bool kvPair<key, data>::operator==(kvPair<key, data> &kvp) {
	return (k_val == kvp.k_val);
}

template<typename key, typename data>
bool kvPair<key, data>::operator>=(kvPair<key, data> &kvp) {
	return(k_val >= kvp.k_val);
}

template<typename key, typename data>
bool kvPair<key, data>::operator<=(kvPair<key, data> &kvp) {
	return(k_val <= kvp.k_val);
}

template<typename key, typename data>
bool kvPair<key, data>::operator>(kvPair<key, data> &kvp) {
	return(k_val > kvp.k_val);
}

template<typename key, typename data>
bool kvPair<key, data>::operator<(kvPair<key, data> &kvp) {
	return(k_val < kvp.k_val);
}

//stream operators
template<typename key, typename data>
std::ostream &operator<<(std::ostream &os, kvPair<key, data> &kvp) {
	std::cout << '<';
	os << kvp.k_val << ", " << kvp.d_val;
	std::cout << '>';
	return os;
}
#endif

