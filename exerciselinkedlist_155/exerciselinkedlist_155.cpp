#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class Circularlinkedlist {
private:
	Node* LAST;

public:
	Circularlinkedlist() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollNo, Node** Akbar, Node** Muhammad);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void Circularlinkedlist::addNode() {
	int nim;		//mendeklarasikan tipe data integer dengan nama variabel nim
	string nama;	//mendeklarasikan tipe data string dengan nama variabel nama
	cout << "\nEnter the roll number of the student : ";	//membuat inputan rollNumber
	cin >> nim;
	cout << "\nEnter the name of the student : ";		//membuat inputan nama
	cin >> nama;
	Node* newNode = new Node();		//membuat pointer Node ke newNode
	newNode->rollNumber = nim;		//menetapkan nilai ke newNode
	newNode->name = nama;			//menetapkan nilai ke newNode

	if (LAST == NULL || nim <= LAST->rollNumber) {			//jika last sama dengan null atau nim kurang dari sama dengan last->rollNumber
		if (LAST != NULL && nim == LAST->rollNumber) {		//jika last tidak sama dengan null dan nim sama dengan last->rollNumber
			cout << "Buat linked list terlebih dahulu" << endl;	
			return;
		}

		LAST = newNode;			//membuat last menjadi newnode atau titik saat ini
		newNode->next = LAST;	//deklarasi point newnode ke node berikutnya 
		return;					//mengulangi langkah diatas
	}

	Node* akbar = LAST;			//membuat current menjadi last
	Node* kurniawan = NULL;		//membuat point sebelemnya menjadi NULL

}


bool Circularlinkedlist::search(int rollNo, Node** Akbar, Node** Muhammad) {
	*Akbar = LAST->next;
	*Muhammad = LAST->next;
	
	while (*Muhammad != LAST) {
		if (rollNo == (*Muhammad)->rollNumber) {
			return true;
		}

		*Akbar = *Muhammad;
		*Muhammad = (*Muhammad)->next;
	}

	if (rollNo == LAST->rollNumber) {
		return true;
	}
	else{
		return false;
	}
}

bool Circularlinkedlist::listEmpty() {
	return LAST == NULL;
}

bool Circularlinkedlist::delNode() {
	if (listEmpty()) {
		cout << "List is empty" << endl;		//membuat output tampilan jika tidak ada inputan angka/kosong 
		return false;
	}

	if (LAST->next == LAST) {		//jika last.next sama dengan last
		delete LAST;		//hapus last
		LAST = NULL;		//last menjadi null
	}
	else {									//jika tidak
		Node* Muhammad = LAST->next;		//mendeklarasikan current menjadi last.next
		LAST->next = Muhammad->next;		//last.next menjadi current.next
		delete Muhammad;					//hapus nodecurrent
		return true;
	}

}

void Circularlinkedlist::traverse() {
	if (listEmpty()) {
		cout << "\List is Empty\n";
	}
	else{
	cout << "\nRecords in the list are:\n";
	Node* MuhammadNode = LAST->next;
	while (MuhammadNode != LAST) {
		cout << MuhammadNode->rollNumber << " " << MuhammadNode->name << endl;
		MuhammadNode = MuhammadNode->next;
		}	
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	Circularlinkedlist obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-4): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
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