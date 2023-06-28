//creating shop class
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent an item in the shop
struct Item {
    string category;
    string name;
    int price;

    Item() : category(""), name(""), price(0) {}

    Item(const string& category, const string& name, int price)
        : category(category), name(name), price(price) {}
};


// Node class for the dynamic linked list
class Node {
public:
    Item item;
    Node* next;

    Node(const Item& item) : item(item), next(nullptr) {}
};

// Class representing the shop inventory
class ShopInventory {
private:
    Node* head;

public:
    ShopInventory(){
		head=nullptr; 
	}

    // Function to add an item to the shop
    void addItem(const Item& item) {
        Node* newNode = new Node(item);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* nodePtr = head;
            while (nodePtr->next != nullptr) {
                nodePtr = nodePtr->next;
            }
            nodePtr->next = newNode;
        }
    }

    // Function to display the available items in the shop
    void displayShop(int &playerCurrency) {
        cout << "\n\t\t\t\t<<~~~~~Welcome to the Adventurer's Emporium!~~~~~>>" << endl;
        cout << "\n\t\t| \t\tYour Currency($): "<< setw(40) << playerCurrency << " | " << endl;
        cout <<	"\t\t| " << setw(72) << "" << " | " << endl;
        cout << "\t\t| \t\tAvailable Items:" << setw(42) << "" << " | " << endl;

        Node* nodePtr = head;
        int count = 1;
        while (nodePtr != nullptr) {
            cout << "\t\t| \t\t" << count << ". " << left << setw(15) << nodePtr->item.name << " - Price: " << nodePtr->item.price << setw(27) << "" << " | " << endl;
            nodePtr = nodePtr->next;
            count++;
        }
    }

    // Function to get the item at a specific index in the shop
    Item getItemAtIndex(int index) {
    	Node* nodePtr = head;
    	int count = 1;
    	while (nodePtr != nullptr) {
    	    if (count == index) {
    	        return nodePtr->item;
    	    }
    	    nodePtr = nodePtr->next;
    	    count++;
    	}
    	return Item();
	}


    // Function to delete the dynamically allocated memory
    ~ShopInventory() {
        Node* nodePtr = head;
        while (nodePtr != nullptr) {
            Node* current = nodePtr;
            nodePtr = nodePtr->next;
            delete current;
        }
    }
};


