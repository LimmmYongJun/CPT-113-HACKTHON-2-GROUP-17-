//creating stack for battle system
#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;
//set the maximum number of enemies to be 100
const int MAX_SIZE = 100;


//Stack for the enemy
template <class T>
class Stack {
	private:
		//array of enemy
	    T arr[MAX_SIZE];
	    //stackTop
	    int top;
	
	public:
		//constructor
	    Stack() {
	        top = -1;
	    }
		//insert enemy into the stack
	    void push(T element) {
	        if (top == MAX_SIZE - 1) {
	            cout << "Stack is full. Cannot push element." << endl;
	            return;
	        }
	        arr[++top] = element;
	    }
		//remove enemy from the stack
	    void pop() {
	        if (isEmpty()) {
	            cout << "Stack is empty. Cannot pop element." << endl;
	            return;
	        }
	        top--;
	    }
		//return the element pointed by the stackTop
	    T& topElement() {
	        if (isEmpty()) {
	            // Returning a reference to a temporary variable is not ideal, but we can use it here for simplicity.
	            // In a real scenario, better error handling should be implemented.
	            return arr[0];
	        }
	        return arr[top];
	    }
		
	    bool isEmpty() {
	        return top == -1;
	    }
};

//Enemy class
class Enemy {
private:
    string name; 
    int health;
    int attack;
    int defense;
    int manaPoint;

public:
    // Default constructor
    Enemy() {
        name = "";
        health = 0;
        attack = 0;
        defense = 0;
        manaPoint = 0;
    }

    // Parameterized constructor
    Enemy(const string& name, const int& health, int attack, int defense, int manaPoint) {
        this->name = name;
        this->health = health;
        this->attack = attack;
        this->defense = defense;
        this->manaPoint = manaPoint;
    }

    // Accessor methods
    string getName() const {
        return name;
    }
    int getHealth() const {
        return health;
    }
    int getAttack() const {
		return attack;
	}
	int getDefense() const {
		return defense;
	}
	int getManaPoint() const {
		return manaPoint;
	}
	void reduceHP(int damage){
		health-=damage;
	}
};

//Battle System class
//Battle System contains stacks
//A system that handles the appearance of enemies and their attacks
class BattleSystem{
   	private:
   		Stack<Enemy> enemyStack; //create a Stack object for Enemy
    	
   	public:
   		//return enemy pointed by stackTop
   		Enemy& getTopEnemy(){
   			return enemyStack.topElement();
		}
		//insert new enemy into the stack	
		void addEnemy(const string& enemyName, int enemyHealth,int enemyATK, int enemyDEF, int enemyMP) {
            Enemy newEnemy(enemyName, enemyHealth, enemyATK, enemyDEF, enemyMP); // Provide default values for ATK, DEF, and MP
            enemyStack.push(newEnemy);
            cout << " - An enemy " << newEnemy.getName() << "(" << newEnemy.getHealth() << " HP/"<<newEnemy.getAttack()<<" ATK/"<<newEnemy.getDefense()<<" DEF)"<< endl;
        }
	    //remove enemy from the stack to fight with   
        void defeatEnemy(Character& player) {
            if (!enemyStack.isEmpty()) {
                Enemy defeatedEnemy = enemyStack.topElement();
                enemyStack.pop();
                cout << "You attacked the enemy " << defeatedEnemy.getName() << "!" << endl;
                // Implement attack logic here
                // You can use player's and enemy's showATK() and showDEF() functions to calculate damage
                int damage = player.showATK() - defeatedEnemy.getDefense();
                if (damage < 0)
                    damage = 0;
                defeatedEnemy.reduceHP(damage);
                cout << "\n> Break through the opponent's defense ("<<defeatedEnemy.getDefense()<<" DEF). Giving a "<<damage<<" ATK true damage."<<endl;
                cout << "The enemy " << defeatedEnemy.getName() << " received " << damage << " damage!" << endl;
            } else {
                cout << "No enemies remaining." << endl;
            }
        }
	     
		//If the enemyStack is null, then the battle is declared completed   
	    bool isEmpty() {
            return enemyStack.isEmpty();
        }
};



//Battle class
class Battle{
	private:
		BattleSystem battleSystem;
		Character *player;
		
	public:
		//Constructor
		Battle(){
			player = nullptr;
		}
		//choose character to fight
		void choosePlayer(LinkedList &team) {
		    char choice;
		    bool characterAvailable = false;
		
		    cout << "Choose your player: (K)night or (T)ank or (A)rcher or (M)agician: ";
		    cin >> choice;
		    //Convert the choice character to uppercase to standardize the input
			choice = toupper(choice);
		
		    ListNode *nodePtr = team.getHead(); // Using getHead() method to get the head pointer of the team list
		
		    while (nodePtr != nullptr) {
		    	//[0] is used so that it accesses the first character of the returned string
		        if (nodePtr->playerData.showRole()[0] == choice) {
		            characterAvailable = true;
		            break;
		        }
		        nodePtr = nodePtr->next;
		    }
		
		    if (!characterAvailable) {
		    	if(choice=='T'){
		    		cout << "\n> The Tank is not unlocked yet." << endl;
				}else if(choice=='M'){
					cout << "\n> The Magician is not unlocked yet." << endl;
				}else if(choice=='A'){
					cout << "\n> The Archer is not unlocked yet." << endl;
				}
		        cout << "> Invalid choice. Defaulting to Knight..." << endl;
		        cout <<"\n"<<endl;
		        player = new Knight();
		        return;
		    }
		
		    if (choice == 'K')
		        player = new Knight();
		    else if (choice == 'T')
		        player = new Tank();
		    else if (choice == 'A')
		        player = new Archer();
		    else if (choice == 'M')
		        player = new Magician();
		    else {
		        cout << "> Invalid choice. Defaulting to Knight..." << endl;
		        cout << endl;
		        player = new Knight();
		    }
		}
    	
    	//Level 1 - Monkey Battle
    	void monkeyStage(){
    		//Need Both to execute an alternate attacj effects
    		cout << "\n> Enemy in this round: " << endl;
			battleSystem.addEnemy("Ultimate Monkey ", 100, 100, 30, 0);
			battleSystem.addEnemy("Little Monkey ", 30, 30, 30, 5);
			while (!battleSystem.isEmpty()) {
		        // Player's turn
		        sleep(1);
		        cout << "\n> Player's turn:" << endl;
		        sleep(1);
		        cout << "> Attacking the enemy..." << endl;
		        sleep(1);
		        cout << "\n   (swish! swish! swish!)\n" << endl;
		        sleep(1);
		        battleSystem.defeatEnemy(*player);
		
		        // Display updated character details
		        cout << "> Current player's statistic:"<<endl;
		        cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP()<<"]" << endl;
				sleep(1);
				
		        // Opponent's turn
		        if (!battleSystem.isEmpty()) {
		            cout << "\n> Opponent's turn:" << endl;
		            sleep(1);
		            cout << "> The opponent "<<battleSystem.getTopEnemy().getName()<<" attacks!" << endl;
		            sleep(1);
					cout << "\n   (swish! swish! swish!)\n" << endl;
					sleep(1);
		            // Get the player's defense value
		            int playerDEF = player->showDEF();
		
		            // Calculate opponent's attack damage
		            int damage = battleSystem.getTopEnemy().getAttack() - playerDEF;
		            if (damage < 0)
		                damage = 0;
		
		            // Reduce player's HP
		            player->reduceHP(damage);
		            sleep(1);
		            cout << "> You received " << damage << " damage!" << endl;
		
		            // Display updated character details
		            sleep(1);
		            cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP()<<"]" << endl;
		        }
		    }
		    //If the while loop ends, mean the battle ends
		    sleep(1);
		    cout << "\n> You have slayed the Monkeys! +100G"<<endl;
		    sleep(1);
		    cout << "\n> Congratulations, you beat the monsters in this round!"<<endl;
		}
		
		
		//Level 2 - Wolf Pack Battle
    	void wolfStage(){
    		cout << "\n> Enemy in this round: " << endl;
			battleSystem.addEnemy("Wolf Alpha ", 200, 100, 30, 0);
			battleSystem.addEnemy("Wolf Beta ", 200, 100, 30, 0);
			while (!battleSystem.isEmpty()) {
		        // Player's turn
		        cout << "\n> Player's turn:" << endl;
		        sleep(1);
		        cout << "> Attacking the enemy..." << endl;
		        sleep(1);
		        cout << "\n   (swish! swish! swish!)\n" << endl;
		        sleep(1);
		        battleSystem.defeatEnemy(*player);
		
		        // Display updated character details
		        cout << "> Current player's statistic:"<<endl;
		        cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP()<<"]" << endl;
		
		        // Opponent's turn
		        if (!battleSystem.isEmpty()) {
		            cout << "\n> Opponent's turn:" << endl;
		            sleep(1);
		            cout << "> The opponent "<<battleSystem.getTopEnemy().getName()<<" attacks!" << endl;
		            sleep(1);
					cout << "\n   (swish! swish! swish!)\n" << endl;
					sleep(1);
		
		            // Get the player's defense value
		            int playerDEF = player->showDEF();
		
		            // Calculate opponent's attack damage
		            int damage = battleSystem.getTopEnemy().getAttack() - playerDEF;
		            if (damage < 0)
		                damage = 0;
		
		            // Reduce player's HP
		            player->reduceHP(damage);
		            cout << "> You received " << damage << " damage!" << endl;
					sleep(1);
		            // Display updated character details
		            cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP()<<"]" << endl;
		        }
		    }
		    //If the while loop ends, mean the battle ends
		    sleep(1);
		    cout << "\n> You have slayed the Wolf Twins and saved the girl! +150G"<<endl;
		    cout << "\n> Congratulations, you beat the monsters in this round!"<<endl;
		}
		
		//Level 5 - BLACK DRAGON BATTLE
    	void dragonStage() {
	    cout << "\n> Enemy in this round: " << endl;
	    battleSystem.addEnemy("Alpha Black Dragon Fatalis", 300, 250, 100, 0);
	    battleSystem.addEnemy("Beta Black Dragon Fatalis", 200, 250, 100, 0);
	
	    bool isPlayerTurn = true; // Flag variable to keep track of the current turn
	
	    while (!battleSystem.isEmpty()) {
	        sleep(1);
	
	        if (isPlayerTurn) {
	            // Player's turn
	            cout << "\n> Player's turn:" << endl;
	            sleep(1);
	            cout << "> Attacking the enemy..." << endl;
	            sleep(1);
	            cout << "\n   (swish! swish! swish!)\n" << endl;
	            sleep(1);
	            battleSystem.defeatEnemy(*player);
	
	            // Display updated character details
	            cout << "> Current player's statistic:" << endl;
	            cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP() << "]" << endl;
	        }
	        else {
	            // Opponent's turn
	            sleep(1);
	            cout << "\n> Opponent's turn:" << endl;
	            sleep(1);
	            cout << "> The opponent " << battleSystem.getTopEnemy().getName() << " attacks!" << endl;
	            sleep(1);
	            cout << "\n   (swish! swish! swish!)\n" << endl;
	            sleep(1);
	
	            // Get the player's defense value
	            int playerDEF = player->showDEF();
	
	            // Calculate opponent's attack damage
	            int damage = battleSystem.getTopEnemy().getAttack() - playerDEF;
	            if (damage < 0)
	                damage = 0;
	
	            // Reduce player's HP
	            player->reduceHP(damage);
	            sleep(1);
	            cout << "> You received " << damage << " damage!" << endl;
	
	            // Display updated character details
	            cout << "  [Player: HP-" << player->showHP() << ", ATK-" << player->showATK() << ", DEF-" << player->showDEF() << ", MP-" << player->showMP() << "]" << endl;
	        }
	
	        // Toggle the turn flag
	        isPlayerTurn = !isPlayerTurn;
	
	        // Check if either player or enemy has died
	        if (player->showHP() <= 0 || battleSystem.getTopEnemy().getHealth() <= 0) {
	            break;
	        }
	    }
	
	    // Check if the player or the enemy died to determine the outcome
	    if (player->showHP() <= 0) {
	        sleep(1);
	        cout << "\n> You have been defeated! Game over." << endl;
	    }
	    else {
	        sleep(1);
	        cout << "\n> You have slayed the Black Dragon Fatalis! " << endl;
	    }
	}
};




