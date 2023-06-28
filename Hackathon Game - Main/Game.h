#include <iostream>
using namespace std;

struct Level{
	int levelNumber; 
	Level*next;
	
	Level(int number){
		levelNumber = number;
		next = nullptr;
	}
};

class BattleSystem {
private:
    stack<Character> enemyStack;

public:
    void addEnemy(const string& enemyName, int enemyHealth) {
        Character newEnemy(enemyName, enemyHealth);
        enemyStack.push(newEnemy);
        cout << "An enemy " << newEnemy.name << " with " << newEnemy.health << " health appears!" << endl;
    }

    void defeatEnemy() {
        if (!enemyStack.empty()) {
            Character defeatedEnemy = enemyStack.top();
            enemyStack.pop();
            cout << "You defeated " << defeatedEnemy.name << "!" << endl;
        } else {
            cout << "No enemies remaining." << endl;
        }
    }

    void showEnemies() {
        if (!enemyStack.empty()) {
            cout << "Remaining enemies:" << endl;
            stack<Character> tempStack;

            while (!enemyStack.empty()) {
                Character currentEnemy = enemyStack.top();
                cout << "- " << currentEnemy.name << " (" << currentEnemy.health << " health)" << endl;
                tempStack.push(currentEnemy);
                enemyStack.pop();
            }

            // Restore the enemies back to the original stack
            while (!tempStack.empty()) {
                Character currentEnemy = tempStack.top();
                enemyStack.push(currentEnemy);
                tempStack.pop();
            }
        } else {
            cout << "No enemies remaining." << endl;
        }
    }
};

class Game{
	private:
		Level*head;
		BattleSystem battleSystem;
	public:
		Game(){
			head=nullptr;
		}
		void addLevel(int levelNumber) {
        	Level* newLevel = new Level(levelNumber);

        	if (head == nullptr) {
        	    head = newLevel;
        	} else {
        	    Level* current = head;
        	    while (current->next != nullptr) {
        	        current = current->next;
        	    }
        	    current->next = newLevel;
        	}
    	}

    	void playGame() {
    	    Level* current = head;
    	    while (current != nullptr) {
    	        cout << "Welcome to Level " << current->levelNumber << "!" << endl;
    	        cout << "----- Gameplay for Level " << current->levelNumber << " -----" << endl;

    	        // Implement the gameplay logic for each level
    	        bool levelCompleted = playLevel(current->levelNumber);

    	        if (levelCompleted) {
    	            cout << "Level " << current->levelNumber << " completed!" << endl;
    	        } else {
        	        cout << "Level " << current->levelNumber << " failed!" << endl;
        	        break; // Exit the game if the level is failed
        	    }

        	    current = current->next;
        	}

        	if (current == nullptr) {
        	    cout << "Congratulations! You completed all levels!" << endl;
        	} else {
        	    cout << "Game Over!" << endl;
        	}
    	}

    	bool playLevel(int levelNumber) {
    	    // Implement the gameplay logic for each level
    	    cout << "Playing Level " << levelNumber << endl;
	
    	    // Sample gameplay logic - Prompt the player for a choice
    	    char choice;
    	    cout << "Enter 'A' or 'B' to make a choice: ";
    	    cin >> choice;
	
    		    // Sample condition for completing the level
    	    bool levelCompleted = (choice == 'A');

    	    if (levelCompleted) {
    	        // Example usage of inventory and battle system
    	        cout << "Level " << levelNumber << " completed! Here's your reward:" << endl;
    	        inventory.addItem("Sword");
    	        inventory.addItem("Potion");

    	        // Battle an enemy
    	        battleSystem.addEnemy("Goblin", 50);
    	        battleSystem.defeatEnemy();
    	        battleSystem.addEnemy("Skeleton", 30);
    	        battleSystem.defeatEnemy();

    	        // Show inventory and remaining enemies
    	        inventory.showInventory();
    	        battleSystem.showEnemies();
    	    }
	
    	    return levelCompleted;
    	}

};
