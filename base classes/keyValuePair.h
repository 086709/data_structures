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
	key k_val;
	data d_val;
public:
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

	//returns key value
	key key_();
	//returns data value
	data dat_();

	//sets key value
	void wkey(key k);
	//sets data value
	void wdat(data d);

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
	k_val = kvp.key_();
	d_val = kvp.dat_();
}

template<typename key, typename data>
kvPair<key, data>::~kvPair() {

}

template<typename key, typename data>
void kvPair<key, data>::operator=(const kvPair<key, data> &kvp) {
	k_val = kvp.key_();
	d_val = kvp.dat_();
}

template<typename key, typename data>
bool kvPair<key, data>::operator==(kvPair<key, data> &kvp) {
	return (k_val == kvp.key_());
}

template<typename key, typename data>
bool kvPair<key, data>::operator>=(kvPair<key, data> &kvp) {
	return(k_val >= kvp.key_());
}

template<typename key, typename data>
bool kvPair<key, data>::operator<=(kvPair<key, data> &kvp) {
	return(k_val <= kvp.key_());
}

template<typename key, typename data>
bool kvPair<key, data>::operator>(kvPair<key, data> &kvp) {
	return(k_val > kvp.key_());
}

template<typename key, typename data>
bool kvPair<key, data>::operator<(kvPair<key, data> &kvp) {
	return(k_val < kvp.key_());
}

template<typename key, typename data>
key kvPair<key, data>::key_() {
	return k_val;
}

template<typename key, typename data>
data kvPair<key, data>::dat_() {
	return d_val;
}

template<typename key, typename data>
void kvPair<key, data>::wkey(key k) {
	k_val = k;
}

template<typename key, typename data>
void kvPair<key, data>::wdat(data d) {
	d_val = d;
}

//stream operators
template<typename key, typename data>
std::ostream &operator<<(std::ostream &os, kvPair<key, data> &kvp) {
	std::cout << '<';
	os << kvp.key_() << ", " << kvp.dat_();
	std::cout << '>';
	return os;
}
#endif
