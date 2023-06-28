//linked list consists of overloaded member functions to APPEND, REMOVE, PRINT inventory and character

#include <iostream>
#include <fstream>
#include <string>
#include "character.h"
#include "inventory.h"
using namespace std;

//***************START OF ListNode and LinkedList***************//
//Node class
class ListNode{
	public:
		
		//Character
		Character playerData;
		ListNode *next;
		//This needs to insert whole the data attribute of the character
		ListNode(Character playerData){
			this->playerData = playerData;
			next = nullptr;
		}
		
		//Inventory
		Inventory item;
		//This needs to insert whole the data attribute of the inventory
		ListNode(Inventory item){
			this->item = item;
			next = nullptr;
		}
};


//Dynamic linked list
class LinkedList{
	private:
		ListNode *head;
	public:
		//constructor
		LinkedList(){
			head = nullptr;
		}
		//destructor
		~LinkedList(){
			clearList();
		}
		
		//Return head
		ListNode* getHead() const{
			return head;
		}
		
		//overloaded member functions
		//CHARACTER VERSION
		void appendNode(Character character ){
			ListNode *newNode;
			newNode = new ListNode(character );
			
			if(head==nullptr){  //If the list is empty
				head = newNode;
			}else{	//If the list already has some node inside it
				ListNode *nodePtr = head;
				
				while(nodePtr->next	!= nullptr){
					nodePtr = nodePtr->next;
				}
				
				nodePtr->next = newNode;
				
			}
		}
		//search for character
		bool searchNode(Character character){
			if(head==nullptr){
				cout<<"> The team is empty. Cannot find the character."<<endl;
				return false;
			}else{
				ListNode *nodePtr = head;
				while(nodePtr!=nullptr && nodePtr->playerData.showRole() != character.showRole()){
					nodePtr = nodePtr -> next;
				}
				if(nodePtr==nullptr){
					cout<<"> The character is not in the team"<<endl;
					return false;
				}else{
					cout<<"> The character is found in the team"<<endl;
					return true;
				}
			}
		}
		//remove character
		void removeNode(Character character){
			if(head==nullptr){
				cout<<"> The team is empty. Cannot remove the character."<<endl;
			}else{
				ListNode *nodePtr = head;
				ListNode *prevNode = nullptr;
				
				//If there's a playerData whose role is same as character's role
				while(nodePtr != nullptr && nodePtr->playerData.showRole() != character.showRole()){
					prevNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				
				if(nodePtr==nullptr){
					cout<<"> The character is not in the list."<<endl;
				}else{
					cout<<"> The character is found. Removing it..."<<endl;
					prevNode->next = nodePtr->next;
					delete nodePtr;
					cout<<"> The character is successfully removed."<<endl;
				}
			}			
		}
		//display characters list
		void printTeam(){
			if(head==nullptr){
				cout<<"> The team is empty."<<endl;
			}else{
				ListNode *nodePtr = head;
				cout<<"> Current teammate(s): | ";
				while(nodePtr!=nullptr){
					cout<<nodePtr->playerData.showRole()<<" | ";
					nodePtr = nodePtr->next;
				}	
			}
			cout << endl;
		}
			
		//INVENTORY VERSION
		//If the inventory appended is all inventories(except for coin), then their amount will be increased by the default parameter value(itemGet), which is 1;
		//If the inventory appended is Coin, then the amount is increased by the parameter accepted(itemGet) from the calling function, 
		//and it is not using the default value, which is 1.
		void appendNode(Inventory &newItem, int itemGet = 1) {
		    ListNode* nodePtr = head;
		    //Stop the iteration loop when the import new item is already existed in the backpack
		    while (nodePtr != nullptr && nodePtr->item.showCategory() != newItem.showCategory() ){
		        nodePtr = nodePtr->next;
		    }
		    if (nodePtr == nullptr) {
		        ListNode* newNode = new ListNode(newItem);
		
		        if (head == nullptr) {  // If the list is empty
		            head = newNode;
		        } else {  // If the list already has some nodes
		            ListNode* nodePtr = head;
		
		            while (nodePtr->next != nullptr) {
		                nodePtr = nodePtr->next;
		            }
		            nodePtr->next = newNode;
		        }
		    } else {
		        nodePtr->item.incrementItemCount(itemGet);
		    }
		}
		//return current number of coins
		int searchCoinNum(){
			if(head==nullptr){
				cout<<"> The backpack is empty."<<endl;
			}else{
				ListNode *nodePtr = head;
				while(nodePtr!=nullptr && nodePtr->item.showCategory()!="Coin"){
					nodePtr = nodePtr->next;
				}
				if(nodePtr){
					return nodePtr->item.showCount();
				}
			}
			
		}
		
		//to use items in inventory
		void searchUseNode(Inventory item, Character &character){
			if(head==nullptr){
				cout<<"> The backpack is empty. Cannot find the inventory."<<endl;
			
			}else{
				ListNode *nodePtr = head;
				//Stop at the item that I want to apply
				while(nodePtr!=nullptr && nodePtr->item.showName() != item.showName()){
					nodePtr = nodePtr -> next;
				}
				cout << "> The player selects to use the inventory: " << item.showCategory()<< endl;
				if(nodePtr==nullptr){
					cout<<"> The "<<item.showCategory()<<" is not to be found in the backpack."<<endl;
					
				}else{
            		cout << "Searching the " << item.showCategory() << "... ..." << endl;
            
            		// Declare the inventory variable outside the if statement
            		Inventory *inventory = nullptr;
            
            		// Calling the corresponding instance based on the class (category) being used.
            		if (item.showCategory() == "Weapon") {
            		    Weapon *weapon = new Weapon();
            		    inventory = weapon;
            		} else if (item.showCategory() == "Armor") {
            		    Armor *armor = new Armor();
            		    inventory = armor;
            		} else if (item.showCategory() == "Potion") {
            		    Potion *potion = new Potion();
            		    inventory = potion;
            		}
            
            		
            		if (character.showRole() == "Knight") {
            		    character.increaseHP(inventory->getIncreaseHP());
            		    character.increaseATK(inventory->getIncreaseATK());
            		    character.increaseDEF(inventory->getIncreaseDEF());
            		} else if (character.showRole() == "Tank") {
            		    character.increaseHP(inventory->getIncreaseHP());
            		    character.increaseATK(inventory->getIncreaseATK());
            		    character.increaseDEF(inventory->getIncreaseDEF());
            		} else if (character.showRole() == "Archer") {
            		    character.increaseHP(inventory->getIncreaseHP());
            		    character.increaseATK(inventory->getIncreaseATK());
            		    character.increaseDEF(inventory->getIncreaseDEF());
            		} else if (character.showRole() == "Magician"){
						character.increaseHP(inventory->getIncreaseHP());
            		    character.increaseATK(inventory->getIncreaseATK());
            		    character.increaseDEF(inventory->getIncreaseDEF());
					} else {
            		    cout << "> Invalid character role." << endl;
            		}
            		
            		removeNode(item);
				}
			}
		}
		
		//Set a default parameter value for other inventories except coin which will accept a user value
		//to remove or decrease number of item from inventory after being used
		void removeNode(Inventory &item, int decrement=1){
			if(head==nullptr){
				cout<<"> The backpack is empty. Cannot remove the inventory."<<endl;
			}else{
				ListNode *nodePtr = head;
				ListNode *prevNode = nullptr;
				
				//If there's a item whose category is same as search item 's category
				while(nodePtr != nullptr && nodePtr->item.showName() != item.showName()){
					prevNode = nodePtr;
					nodePtr = nodePtr->next;
				}
				
				if(nodePtr==nullptr){
					cout<<"> The "<<item.showName()<<" is not in the backpack."<<endl;
				}else if(nodePtr->item.showCount()>0){
					cout<<"> The "<<item.showName()<<" is found. Using it..."<<endl;
					nodePtr->item.decrementItemCount(decrement);
					cout<<"> The "<<nodePtr->item.showName()<<" is successfully used."<<endl;
				}else{
					cout<<"> The "<<item.showName()<<" is found. Using it..."<<endl;
					prevNode->next = nodePtr->next;
					delete nodePtr;
					cout<<"> The "<<item.showName()<<" is successfully used."<<endl;
				}
			}	
		}	
		//display the current items in inventory	
		void printBackpack(){
			if(head==nullptr){
				cout<<"> The backpack is empty."<<endl;
			}else{
				ListNode *nodePtr = head;
				cout<<"> Current inventory item(s) in the backpack: | ";
				while(nodePtr!=nullptr){
					if(nodePtr->item.showCategory()=="Coin"){
						cout<<nodePtr->item.showName()<<"(Amount: "<<nodePtr->item.showCount()<<") | ";
						nodePtr = nodePtr->next;
					}else{
						cout<<nodePtr->item.showName()<<" | ";
						nodePtr = nodePtr->next;
					}
				}
			}
			cout << endl;
		}
		
		//display current amount of coins 
		void printCoin(){
			if(head==nullptr){
				cout<<"> The backpack is empty."<<endl;
			}else{
				ListNode *nodePtr = head;
				cout<<"> Amount of Gold Coin(s): ";
				while(nodePtr!=nullptr && nodePtr->item.showCategory()!="Coin"){
					nodePtr = nodePtr->next;
				}
				if(nodePtr->item.showCategory()=="Coin"){
					cout<<nodePtr->item.showCount()<<"G."<<endl;
				}else{
					cout<<"0";
				}
			}
		}
		
		//save the current inventory to a textfile
		void saveInventory(const string& inventory) const
		{
		    ofstream outFile(inventory);
		
		    if (outFile.is_open())
		    {
		        ListNode *nodePtr = head;
		
		        while (nodePtr)
		        {
		            outFile << nodePtr->item.showCategory() << "\n";
		            outFile << nodePtr->item.showName() << "\n";
		            outFile << nodePtr->item.showCount() << "\n";
		            nodePtr = nodePtr->next;
		        }
		
		        outFile.close();
		        cout << "> Inventory saved successfully ...\n";
		    }
		    else
		    {
		        cout << "Unable to open file: " << inventory << endl;
		    }
		}
		//save the current team into a textfile
		void saveTeam(const string& team) const
		{
		    ofstream outFile(team);
		
		    if (outFile.is_open())
		    {
		        ListNode *nodePtr = head;
		
		        while (nodePtr)
		        {
		            outFile << nodePtr->playerData.showRole() << "\n";
		            outFile << nodePtr->playerData.showHP() << "\n";
		            outFile << nodePtr->playerData.showATK() << "\n";
		            outFile << nodePtr->playerData.showDEF() << "\n";
		            outFile << nodePtr->playerData.showMP() << "\n";
		            nodePtr = nodePtr->next;
		        }
		
		        outFile.close();
		        cout << "> Team saved successfully ...\n";
		    }
		    else
		    {
		        cout << "Unable to open file: " << team << endl;
		    }
		}
		//extract the previously saved inventory 
		void loadInventory(LinkedList &backpack, const string &inventoryFile)
		{
		    ifstream inFile(inventoryFile);
		  
		    if (inFile.is_open())
		    {
		    	backpack.clearList();
		
		        string category;
		        string name;
		        int numItem;
		        
		        string line;
		
		        while (getline(inFile, line))
		        {
		            category = line;
		            getline(inFile, line);
		            name = line;
		            getline(inFile, line);
		            numItem = stoi(line);
		
		            Inventory item;
		            item.setCategory(category);
		            item.setName(name);
		            item.setItemCount(numItem);

		            backpack.appendNode(item);
		        }
		
		        inFile.close();
		        
		        cout << "> Inventory loaded successfully ...\n";
		    }
		    else
		    {
		        cout << "Unable to open file: " << inventoryFile << endl;
		    }
		}
		//extract the previously saved team
		void loadTeam(LinkedList &team, const string &teamFile)
		{
		    ifstream inFile(teamFile);
		  
		    if (inFile.is_open())
		    {
		    	team.clearList();
		
		        string role;
		        int HP;
		        int ATK;
		        int DEF;
		        int MP;
		        
		        string line;
		
		        while (getline(inFile, line))
		        {
		            role = line;
		            getline(inFile, line);
		            HP = stoi(line);
		            getline(inFile, line);
		            ATK = stoi(line);
		            getline(inFile, line);
		            DEF = stoi(line);
		            getline(inFile, line);
		            MP = stoi(line);
		            
		            Character item(role, HP, ATK, DEF, MP);
		            
		            team.appendNode(item);
		        }
		
		        inFile.close();
		        
		        cout << "> Team loaded successfully ... \n";
		    }
		    else
		    {
		        cout << "Unable to open file: " << teamFile << endl;
		    }
		}
		
		//COMMON-USE Member Function
		//clear the dynamic linked list
		void clearList(){
			ListNode *nodePtr = head;
			ListNode *nextNode;
			while(nodePtr != nullptr){
				nextNode = nodePtr->next;
				delete nodePtr;
				nodePtr = nextNode;
			}
			
			head = nullptr;
		}
};
//***************END OF ListNode and LinkedList***************//
