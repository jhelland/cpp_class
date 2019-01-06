#include<iostream>
#include<list>
#include<fstream>


using namespace std;


template<typename T>
struct node {
	T data;
	node* next;
	int index;
};


template<typename T>
class LinkedList {
private:
	node<T>* head;
	node<T>* tail;
	int size;

public:
	LinkedList() : head(nullptr), tail(nullptr), size(0) {}
	~LinkedList() { clear(); }
	void push_back(T data) {
		if (head == nullptr) {
			head = new node<T>;
			tail = head;
			head->next = nullptr;
			head->data = data;
			head->index = 0;
			++size;
			return;
		}

		node<T>* prev = new node<T>;
		prev = tail;
		node<T>* tmp = new node<T>;
		tmp->data = data;
		tmp->index = tail == nullptr ? 0 : tail->index + 1;

		prev->next = tmp;
		tail = tmp;

		++size;
	}
	void insert_after(int index, T data) {
		if (index == size) {
			push_back(data);
			return;
		}

		// Set initial variables for new node
		node<T>* ins = new node<T>;
		ins->data = data;
		ins->index = index + 1;

		// Insert new node
		node<T>* current = head;
		for (int i = 0; i < index; ++i) 
			current = current->next;

		ins->next = current->next->next;
		current->next = ins;

		++size;
	}
	void erase(int index) {
		node<T>* current = head;
		node<T>* prev;
		for (int i = 0; i < index; ++i) {
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		delete current;
	}
	void clear(node<T>* current) {
		if (current == tail) {
			delete current;
			return;
		}
		
		clear(current->next);
		delete current;
	}
	void clear() { 
		clear(head); 
		head = nullptr; 
		tail = nullptr; 
		size = 0; 
	}
	void print(node<T>* current) {
		if (current == tail) {
			cout << current->data << " ";
			return;
		}

		cout << current->data << " ";
		print(current->next);
	}
	void print() { print(head); }
	int length() { return size; }
};


int main() {
	// Custom singly linked list test
	list<int> lst;
	bool quitFlag = false;

	LinkedList<int> lnk;
	cout << lnk.length() << endl;
	lnk.push_back(0);
	lnk.push_back(1);
	lnk.print();
	lnk.clear();
	cout << lnk.length() << endl;

	int tmp;
	cin >> tmp;
	

	// Simple exercise w/ STL (doubly) linked list
	/*
	while (!quitFlag) {
		cout << "Choose option:\n(0) Quit\n(1) Push back\n(2) Insert\n(3) Erase\n(4) Print\n";
		int choice;
		cin >> choice;

		switch (choice) {
		case 0:
			quitFlag = true;
			break;

		case 1:
			cout << "Enter choice: ";
			int num;
			cin >> num;
			lst.push_back(num);

			break;

		case 2: {
			cout << "Enter choice and index: ";
			int num, idx;
			cin >> num >> idx;
			if ((unsigned int) idx > lst.size() - 1) {
				cout << "ERROR: invalid list index\n";
				break;
			}

			list<int>::iterator it = lst.begin();
			for (int i = 0; i < idx; ++i, ++it);
			lst.insert(it, num);

			break;
		}

		case 3: {
			cout << "Enter index to erase: ";
			int idx;
			cin >> idx;
			if ((unsigned int) idx > lst.size()) {
				cout << "ERROR: invalid list index\n";
				break;
			}

			list<int>::iterator it = lst.begin();
			for (int i = 0; i < idx; ++i, ++it);
			lst.erase(it);

			break;
		}

		case 4:
			for (auto l : lst)
				cout << l << " " << flush;
			cout << endl;

			break;

		default:
			cout << "ERROR: invalid option\n";
			break;
		}
	}
	*/

	return 0;
}
