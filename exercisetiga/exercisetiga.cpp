#include<iostream>
#include<string>
using namespace std;

class node {
public:
	int rollnumber;
	string name;
	node* next;
};

class cincularlinkedlist {
private:
	node* last;

public:
	cincularlinkedlist() {
	}
	void addnode();
	bool search(int rollno, node** rasyid, node** andi);
	bool listempty();
	bool delnode();
	void traverse();
};

void cincularlinkedlist::addnode() {
	int rollno;
	string name;
	cout << "masukkan rollnumber: ";
	cin >> rollno;
	cout << "masukkan nama: ";
	cin >> name;

	node* newnode = new node();    
	newnode->rollnumber = rollno;
	newnode->name = name;

	if (listempty()) {	//Beginning of the list
		newnode->next = newnode;
		last = newnode;
	}
	else {
		node* andi = last -> next;
		node* rasyid = last;
		while (andi->rollnumber < newnode->rollnumber && andi != last) {
			rasyid = andi;		//Between two nodes in the list
			andi = andi->next;
		}
		rasyid->next = newnode;
		newnode->next = andi;
		if (andi == last) {
			last = newnode;	
		}
	}
}

bool cincularlinkedlist::search(int rollno, node** rasyid, node** andi) {
	*rasyid = last->next;
	*andi = last->next;
	while (*andi != last) {
		if (rollno == (*andi)->rollnumber) {
			return true;
		}
		*rasyid = *andi;
		*andi = (*andi)->next;
	}
	if (rollno == last->rollnumber) {
		return true;
	}
	else {
		return false;
	}
}
bool cincularlinkedlist::listempty() {
	return last == NULL;
}

bool cincularlinkedlist::delnode() {
	if (listempty()) {
		cout << "\nlist kosong.\n";
		return;
	}

	int rollno;
	cout << "masukan nomor untuk di hapus: ";
	cin >> rollno;

	node* rasyid = NULL;
	node* andi = NULL;
	
	if (andi == last) {
		if (andi->next == last) {
			last = NULL;
		}
		else {
			last->next = andi->next;
		}
		delete andi;
		cout << "menghapus data sukses.\n";
			return true;
	}
}

void cincularlinkedlist::traverse() {
	if (listempty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		node* andinode = last->next;
		while (andinode != last) {
			cout << andinode->rollnumber << " " << andinode->name << endl;
			andinode = andinode->next;
		}
		cout << last->rollnumber << " " << last->name << endl;
	}
}

int main() {
	cincularlinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addnode();
				break;
			}
			case '2': {
				obj.delnode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}