#include "keyValueNode"
#ifndef LISTDICT_H_
#define LISTDICT_H_

//stores Key value pairs in a linked list format
template<typename key, typename elem>
class dict : private kvp_node<key, elem> {
	kvp_node<key, elem> *head;
	kvp_node<key, elem> *tail;
	kvp_node<key, elem> *curr;
	int records;
	void m_next();
	void m_prev();
public:
	// constructors/destructor and assignment operators
	dict();
	~dict();
	dict(const dict<key, elem> &d);
	void operator=(const dict<key, elem> &d);
	//insert a kvp_node into the list in the correct spot
	void insert(kvp_node<key, elem> *kvp);
	//prefered way of inserting, makes kvpair and then calls
	//regular insert function with the kvpair
	void insert(key k, elem e);
	//finds first instance of a node with the matching key value
	//and returns a pointer to the element
	kvp_node<key, elem> *search(key k);
	//removes first instance of node with the matching key value
	//from the list and then returns a copy of the stored element
	elem remove(key &k);
	//deletes first instance of node with matching key value and
	//returns void
	void del(key &k);
	//indexing operation, returns pointer to the stored element
	//can be used for accessing keys or setting values to a key
	//syntax ' dict[k_val] ' decays to a pointer to the element
	//stored with that key. If the key is not in the dictionary 
	//It will make a new kv_pair and return a pointer to the e-
	//lement stored at that key location
	//can be used to create a new node and set it to a value:
	//    dict[key k_val] = elem e_val;
	//which will create a new entry if k_does not exist
	elem operator[](key k);
	//returns number of pairs stored in the dict
	int len();
	//prints out dictionary
	void print();

	kvp_node<typename key, typename elem>::link_nodes;
	kvp_node<typename key, typename elem>::pprint;
};

//==================================
//dictionary template functions
template<typename key, typename elem>
dict<key, elem>::dict() {
	head = new kvp_node<key, elem>();
	tail = new kvp_node<key, elem>();
	head->set_set();
	tail->set_set();
	link_nodes(head, tail);
	curr = head;
	records = 0;
}

template<typename key, typename elem>
dict<key, elem>::~dict() {
	/*
	curr = head;
	while (curr) {
		head = curr->gnext();
		delete curr;
		curr = head;
	}
	*/
}

//==================================
//move functions
template<typename key, typename elem>
void dict<key, elem>::m_next() {
	if (curr->gnext() && !curr->gnext()->set()) {
		curr = curr->gnext();
	}
}

template<typename key, typename elem>
void dict<key, elem>::m_prev() {
	if (curr->gprev() && !curr->gprev()->set()) {
		curr == curr->gprev();
	}
}

template<typename key, typename elem>
void dict<key, elem>::insert(kvp_node<key, elem> *kvp) {
	curr = head;
	if (head->gnext()->set()) {
		link_nodes(head, kvp);
		link_nodes(kvp, tail);
	}
	else {
		curr = head;
		while (curr->gnext()->key_() <= kvp->key_() && !curr->gnext()->set()) {
			curr = curr->gnext();
		}
		link_nodes(kvp, curr->gnext());
		link_nodes(curr, kvp);
	}
	++records;
}

template<typename key, typename elem>
void dict<key, elem>::insert(key k, elem e) {
	kvp_node<key, elem> *temp = new kvp_node<key, elem>(k, e);
	this->insert(temp);
}

 template<typename key, typename elem>
 void dict<key, elem>::print() {
	 std::cout << '{';
	 curr = head;
	 while (curr) {
		 if (!curr->set()) {
			 pprint(curr);
			 std::cout << ", ";
		 }
		 curr = curr->gnext();
	 }
	 std::cout << "\b\b}";
 }

template<typename key, typename elem>
int dict<key, elem>::len() {
	return records;
}

template<typename key, typename elem>
kvp_node<key, elem> *dict<key, elem>::search(key k) {
	curr = head->gnext();
	int br = 0;
	while (br == 0) {
		if (curr->key_() == k)
			return curr;
		else if (curr->set()) {
			std::cout << "key not found\n";
			return NULL;
		}
		curr = curr->gnext();
	}
}

template<typename key, typename elem>
elem dict<key, elem>::operator[](key k) {
	kvp_node<key, elem> *temp = search(k);
	return temp->elm_();
}

#endif