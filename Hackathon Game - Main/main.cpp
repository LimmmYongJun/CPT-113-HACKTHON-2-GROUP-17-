#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <unistd.h>
#include "listNode.h"
#include "Storyline.h"
#include "Shop.h"
#include "BattleSystem.h"
#include "Image.h"
using namespace std;
//function prototypes
void mainMenu(int &);
void showGameDetail();
void saveGame(LinkedList &, LinkedList &, int);
void loadGame(LinkedList &, LinkedList &, int &);
void game(StoryLine<Chapter>, int &, LinkedList &, LinkedList &);
void showRoleAttribute(Knight&, Tank&, Archer&, Magician&);


int main(){
	
	//load the story line
	Chapter chapter;
  
  	StoryLine<Chapter> storyline;
    
  	ifstream inFile;
  	//textfile array for every chapter
  	const string chapterFile [6] = {"chapter0.txt", "chapter1.txt", "chapter2.txt", "chapter3.txt", "chapter4.txt", "chapter5.txt"};
  	//read in every textfile
  	for (int i = 0; i < 6; i++)
  	{
    	inFile.open(chapterFile[i]);
    
    	int num;
    	string text, line;
  
    	chapter.setNumChapter(i);
    
    	while (getline(inFile, line))
    	{
      		text += line + "\n";
    	}
    
    	inFile.close();
    
    	chapter.setText(text);
    
    	storyline.appendNode(chapter);
 	}  
  	//initialize the current chapter to -1
	int currentChapter = -1;
	
	//Declare the data variables
	LinkedList team;
	LinkedList backpack;
	Knight knight;
    Tank tank;
    Magician magician;
    Archer archer;

    Weapon weapon;
    Armor armor;
    Potion potion;
    Coin coin;
    
    Image display;
    display.displayTheme();
	sleep(2);
	int choice;
	//input choice for main menu
	mainMenu(choice);
	
	do
	{
		//start a new game
		if (choice == 1)
		{
			//Clearing the historical data
			currentChapter = 0;
			team.clearList();
			backpack.clearList();
				
			cout << "\n> You had choose [ Start a new game ] " << endl;
			sleep(1);
			cout << "\n> Loading ..." << endl;
			sleep(1);
			cout << "\n> Please wait for a while ..." << endl;
			sleep(1);
			game(storyline, currentChapter, team, backpack);
			
			mainMenu(choice);
			
		}
		//load previous game
		else if (choice == 2)
		{
		    int loadChapter;
		    int resumeChoice;
		    
		    cout << "\n> You had choose [ Load the previous game ] " << endl;
		    sleep(1);
		    cout << "\n> Loading ..." << endl;
		    sleep(1);
			cout << "\n> Please wait for a while ..." << endl;
			sleep(1);
			cout << endl;
			sleep(1);
			
		    loadGame(team, backpack, loadChapter);
		    
		    cout << endl;
			cout << "  +---------------------------------------- [   Your Previous Data   ] ----------------------------------------+" << endl;
			cout << endl;
			cout <<"    ";
		    team.printTeam();
			cout << endl;
		    cout << "    ";
			backpack.printBackpack();
		    cout << endl;
		    currentChapter = loadChapter;
		    cout << "    > Current completed chapter: " << currentChapter << endl;
		    cout << endl;
		    cout << "  +------------------------------------------------------------------------------------------------------------+" << endl;
		    
		    currentChapter += 1;
		    
		    cout <<"\n> Do you want to resume on next chapter? (1 - Yes | 0 - No): ";
		    cin >> resumeChoice;
		    
		    while(resumeChoice != 0 && resumeChoice != 1){
		    	cout << "> Please enter a valid choice: "<<endl;
		    	cin >> resumeChoice;
			}
			
			if(resumeChoice == 1){
				game(storyline, currentChapter, team, backpack);
				mainMenu(choice);
				
			}else{
				mainMenu(choice);
				
			}
			
		}
		//show game detail
		else if (choice == 3)
		{
			cout << "\n> You had choose [ Show game detail ] " << endl;
			showGameDetail();
			mainMenu(choice);
		}
			
	}while(choice != 4); //exit game
	
	cout << "\n> You choose [ Exit the game ]" << endl;
	
	cout << "\n> Hope see you soon!" << endl;
	
	display.displayExit();
	
	return 0;
}

//------------------------------------------------- END OF MAIN FUNCTION ----------------------------------------------------------------------------

//main menu function
void mainMenu(int &choice)
{
	cout << endl;
	cout << "      _,.                   " << endl;
	cout << "    ,` -.)                  " << endl;
	cout << "   ( _/-\\\\-._             " << "\t       - WELCOME TO THE WORLD OF { DRAGON SLAYER } -" << endl;
	cout << "  /,|`--._,-^|            , " << endl;
	cout << "  \\_| |`-._/||          ,'|" << endl;
	cout <<  "    |  `-, / |         /  /" << "\t+------------------ [   MAIN MENU   ] ------------------+" << endl;
	cout <<  "    |     || |        /  / \t|" << setw(55) << "" << "|" << endl;
	cout <<  "     `r-._||/   __   /  /  " << left << setw(48) << "\t|\t    Button 1 :   Start a new game" << "\t|\t" << endl;
	cout <<  " __,-<_     )`-/  `./  /   \t|"  << setw(55) << "" << "|" << endl;
	cout <<  "'  \\   `---'   \\   /  /  " << left << setw(48) << "\t|\t    Button 2 :   Load the previous game" << "\t|\t" << endl;
	cout <<  "    |           |./  /     \t|"  << setw(55) << "" << "|" <<endl;
	cout << "    /           //  /       " << left << setw(48) << "\t|\t    Button 3 :   Show game detail" << "\t|\t" << endl;
	cout << "\\_/' \\         |/  /      \t|"  << setw(55) << "" << "|" << endl;
	cout << " |    |   _,^-'/  /         " << left << setw(48) << "\t|\t    Button 4 :   Exit the game" << "\t|\t" << endl;
	cout << " |    , ``  (\\/  /_        \t|"  << setw(55) << "" << "|" << endl;
	cout << "  \\,.->._    \\X-=/^       " << "\t+-------------------------------------------------------+" << endl;
	cout << "  (  /   `-._//^`           " << endl;
	cout << "   `Y-.____(__}             " << endl;

	cout << "\n> Please select the button: ";
	
	cin >> choice;
	
	while (choice < 1 || choice > 4)
	{
		cout << "\n> Please select a valid the button: ";
	
	cin >> choice;
	}
	
}
//show game detail function
void showGameDetail()
{
	//THIS IS USED TO SHOW THE CHARACTER AND INVENTORY STATISTIC
	Knight knight;
    Tank tank;
    Magician magician;
    Archer archer;
	
	Weapon weapon;
    Armor armor;
    Potion potion;
    
	cout << "\n   +--------------------------------- [  CHARACTER AND INVENTORY STATISTIC  ] --------------------------------+ \n"<<endl;
    cout << "\t\t> Character Details:\n";
    cout << endl;
	cout << "\t\t   1. " << left << setw(15) << knight.showRole() << ": HP-" << setw(10) << knight.showHP() << "| ATK-" << setw(10) << knight.showATK() << "| DEF-" << setw(10) << knight.showDEF() << "| MP-" <<knight.showMP()<< endl;
	cout << "\t\t   2. " << left << setw(15) << tank.showRole() << ": HP-"  << setw(10) << tank.showHP() << "| ATK-" << setw(10) << tank.showATK() << "| DEF-" << setw(10) <<  tank.showDEF() << "| MP-" <<tank.showMP()<< endl;
	cout << "\t\t   3. " << left << setw(15) << magician.showRole() << ": HP-" << setw(10) << magician.showHP() << "| ATK-" << setw(10) << magician.showATK() <<  "| DEF-" << setw(10) << magician.showDEF() << "| MP-" <<magician.showMP()<< endl;
	cout << "\t\t   4. " << left << setw(15) << archer.showRole() <<  ": HP-" << setw(10) << archer.showHP() << "| ATK-" << setw(10) << archer.showATK() << "| DEF-" << setw(10) <<  archer.showDEF() << "| MP-" <<archer.showMP()<< endl;

    cout << "\n\t\t> Adventurer's Emporium (Shop) Items:\n";
    cout << endl;
    cout << "\t\t   1. " << left << setw(15) << weapon.showCategory() << ": " << weapon.showName() << " (ATK + " << weapon.showCount() * weapon.getIncreaseATK() << ")" << endl;
    cout << "\t\t   2. " << left << setw(15) << armor.showCategory() << ": " << armor.showName() << " (DEF + " << armor.showCount() * armor.getIncreaseDEF() << ")" << endl;
    cout << "\t\t   3. " << left << setw(15) << potion.showCategory() << ": " << potion.showName() << " (HP + " << potion.showCount() * potion.getIncreaseHP() << ")" << endl;
	cout << "\n   +----------------------------------------------------------------------------------------------------------+"<<endl;
	cout << endl;
}
//save game function to save team, inventory and chapter
void saveGame(LinkedList &team, LinkedList &backpack, int chapter)
{
	team.saveTeam("team.txt");
	backpack.saveInventory("inventory.txt");
	
	ofstream outFile;
	outFile.open("chapter.txt");
	
	if(outFile)
	{
		outFile << chapter;
		outFile.close();
		cout << "> The current chapter is save successfully." << endl;
	}
	
	else
		cout << "The file not exist." << endl;
	
	
}
//load game function to read in team, inventory and chapter
void loadGame(LinkedList &team, LinkedList &backpack, int &chapter)
{
	team.loadTeam(team, "team.txt");
	backpack.loadInventory(backpack, "inventory.txt");
	
	ifstream inFile;
	inFile.open("chapter.txt");
	
	if(inFile)
	{
		inFile >> chapter;
		inFile.close();
		cout << "> The current chapter is load successfully." << endl;
	}
	
	else
		cout << "The file not exist." << endl;
}


// Create a function that shows the attribute of the hero characters
void showRoleAttribute(Knight &knight, Tank &tank, Archer &archer, Magician &magician){
	cout << "1. " << knight.showRole() << ": HP-" << knight.showHP() << ", ATK-" << knight.showATK() << ", DEF-" << knight.showDEF() << ", MP-" <<knight.showMP()<< endl;
	cout << "2. " << tank.showRole() << ": HP-" << tank.showHP() << ", ATK-" << tank.showATK() << ", DEF-" << tank.showDEF() << ", MP-" <<tank.showMP()<< endl;
	cout << "3. " << magician.showRole() << ": HP-" << magician.showHP() << ", ATK-" << magician.showATK() << ", DEF-" << magician.showDEF() << ", MP-" <<magician.showMP()<< endl;
	cout << "4. " << archer.showRole() << ": HP-" << archer.showHP() << ", ATK-" << archer.showATK() << ", DEF-" << archer.showDEF() << ", MP-" <<archer.showMP()<< endl;
}
				

//game function to control the flow of the whole game
void game(StoryLine<Chapter> storyline, int& currentChapter, LinkedList& team, LinkedList& backpack)
{	
	//Heroes awaiting to join
	Knight knight;
	Tank tank;
	Archer archer;
	Magician magician; 

	//Inventory
	Weapon weapon;
	Armor armor;
	Potion potion;
	Coin coin; 
	
	//Setting an instance for trigerring the battle system
	Battle battle;
	Image display;
	
	//So the constructor initialize the coin as 0 in amount and then it appends the coin into the backpack
	//We need to appendNode coin twice: First time is to make the instance exist in the backpack before we can use the 
	//second parameter value(getCoin) in the second time, instead of using the Default parameter value(getCoin=1)
	backpack.appendNode(coin);
	//Initialize 100 as the amount of the coin 
	backpack.appendNode(coin, 100);
	
	//Initialize the instance of the ShopInventory and instance of the items
    ShopInventory shopInventory; // Declare shopInventory outside the switch statement
	Item shopSword;
    Item shopShield;
    Item shopPotion;
    
    shopSword = Item("Weapon", "Sword", 200);
	shopShield = Item("Armor", "Shield", 150);
	shopPotion = Item("Potion", "Revival Potion", 100);
	shopInventory.addItem(shopSword);
	shopInventory.addItem(shopShield);
	shopInventory.addItem(shopPotion);
    
    //Declaring the neccessary variables for later game use
    string heroName;
  	int choiceSaveGirl, choiceJoin, choiceApple, choiceBuy, choiceSaveMan, choiceHeal;
	char choiceApply;
	bool gameOver = false;
  	bool playAgain = true;
  	int currentCoin;
    
    // Variables for battle system
	int playerHealth = 100;  // Player's initial health
	int opponentHealth = 100;  // Opponent's initial health
	int playerAttack = 20;  // Player's attack power
	int opponentAttack = 15;  // Opponent's attack power
	
	
    //storyline for every chapter
	do{
		switch (currentChapter)
		{
			//chapter 0
			case 0:
				cout << "\n> You enter a new world ..." << endl;
				sleep(1);
		        storyline.display(currentChapter);
		    
		        cout << "\n> Name your hero -> ";
		        cin.ignore();
		        getline (cin, heroName);
		      
		        cout << "\n> " << heroName << ", let's embark on the thrilling journey full of challenges and dangers ..." << endl;
		        sleep(1);
		        cout << "\n> In the mysterious land of Eldoria, there are countless hidden treasures, but also great dangers." << endl;
		        sleep(1);
		        cout << "> Although you will still reach your final destination, \"The Pit of End\"." << endl;
		        sleep(1);
		        cout << "> It is a place where the legendary black dragon, Fatalis lives." << endl;
		        sleep(1);
		        cout << "> To make sure you are not alone in the journey, the Kingdom sends a knight to accompany and assist you."<< endl;
		        sleep(1);
		        // Append knight
		        cout<<"\nSYSTEM: Congratulation!! Now, the KNIGHT has honorably joined your team."<<endl;
		        sleep(1);
		        team.appendNode(knight);
		        cout << "\n> Now, you are good to start your journey ..." << endl;
		        sleep(1);
		        cout << "\n------------------------------------ THE END OF CHAPTER 0 ------------------------------------------------" << endl;
		        break;
			//chapter 1
			case 1:
				sleep(1);
				storyline.display(currentChapter);
		        display.displayMonkey();
		        sleep(1);
		        team.printTeam();
				/* TODO (MiinNing#1#): Make a input validation so that the user can 
				                       only choose the character available currently */
				battle.choosePlayer(team);
				battle.monkeyStage();
				
		    	// Add reward cash
		        // Earn the cash reward(A confirmed win condition for the player)
				backpack.appendNode(coin, 100);
				// Print the current cash
				backpack.printCoin();
		        cout << "\n------------------------------------ THE END OF CHAPTER 1 ------------------------------------------------" << endl;
				
				break;
			//chapter 2
			case 2:
				sleep(1);
				storyline.display(currentChapter);
        		display.displayWolf();
        		sleep(1);
				cout << "> Choose your move ... (1 - Help the girl | 0 - Run away)" << endl;
		        do{
		          cout << "> make sure you choice is either 0 or 1: ";
		          cin >> choiceSaveGirl;
		        }while (choiceSaveGirl <0  || choiceSaveGirl > 1);
		        
		        if (choiceSaveGirl == 1)
		        {
		          	// Battle System
		        	cout << "\n> Beat the wolf pack alpha to save the girl!"<< endl;
		          	battle.choosePlayer(team);
		          	battle.wolfStage();
		          /* TODO (Lemon#1#): After the beat the Wolf, get the Cash Reward 
		                              $200G */
			    	// Add reward cash
			        // Earn the cash reward(A confirmed win condition for the player)
					backpack.appendNode(coin, 200);
					// Print the current cash
					backpack.printCoin();
		          
		          
		          	sleep(1);
		          	cout << "\n> The girl: Thank you for saving me! <3 " << endl;
		          	sleep(1);
		          	cout << "> The girl: My name is Emily and I'm actually a magician. " << endl;
		          	sleep(1);
		          	cout << "\n> You: You are welcome! I'm " << heroName << "." << endl;
		          	sleep(1);
		          	cout << "\n> The girl: Seems like you are on an adventure, do you mind if I want to join you? (1 - Yes | 0 - No)" << endl;
		          	cout << endl;
		          	do{
		            	cout << "> make sure you choice is either 0 or 1: ";
		            	cin >> choiceJoin;
		          	}while (choiceJoin <0  || choiceJoin > 1);
		        
		          	if (choiceJoin == 1)
		          	{
		          		//To be implemented
		            	team.appendNode(magician);
		            	cout << "\n> Emily (The Magician) has joined your squad." << endl;
		            	sleep(1);
		          	  	team.printTeam();
		          	}
		          	else if (choiceJoin == 0)
		          	{
		            	cout << "> You continue your journey on your own ..." << endl;
		            	sleep(1);
		          	}
		        	gameOver = false;
		        }
		        
		        else if (choiceSaveGirl == 0)
		        {
		          	cout << "\n> You left the girl and ran away ... " << endl;
		          	sleep(1);
		          	cout << "> This is an action of a coward! You don't deserve to be a hero! " << endl;
		          	sleep(1);
		          	gameOver = true;
		        }
		        
		        cout << "\n------------------------------------ THE END OF CHAPTER 2 ------------------------------------------------" << endl;;
		        break;
		    //chapter 3   
			case 3:
				sleep(1);
				storyline.display(currentChapter);
        		display.displayApple();
        		sleep(1);
		        cout << "\n> Do you want to eat the apple? (1 - Yes | 0 - No)";
		        cout << endl;
		        do{
		        	cout << "> make sure you choice is either 0 or 1: ";
		        	cin >> choiceApple;
		        }while (choiceApple <0  || choiceApple > 1);
		        	
		        if (choiceApple == 1)
		        {
		        	sleep(1);
		          	cout << "\n> You lost consciousness ... " << endl;
		          	sleep(1);
		          	cout << "> The apple is poisonous ... " << endl;
		          	sleep(1);
		          	gameOver = true;
		        }
		        
		        else if (choiceApple == 0)
		        {
		        	sleep(1);
		        	cout << "\n> You went to a food stall nearby to have a bowl of noodles." << endl;
		        	sleep(1);
		        	cout << "> A roaming equipment supplier comes to you." << endl;
		        	sleep(1);
		        	cout << "> Equipment supplier: Do you want to buy any supplies?  (1 - Yes | 0 - No)" << endl;
		        	do{
		              cout << "> make sure you choice is either 0 or 1: ";
		              cin >> choiceBuy;
		            }while (choiceBuy <0  || choiceBuy > 1);
		            
		            
		          	if (choiceBuy == 1)
		          	{
		            	// Current coin amount
						int playerCurrency = backpack.searchCoinNum();
						// Display the shop items
						// Pass playerCurrency as we will show it on the other side of this function.
						shopInventory.displayShop(playerCurrency);
						
						// Shop loop
						while (true) 
						{
							// Prompt player for item selection
							sleep(1);
							cout << "\n> Enter the number of the item you want to purchase (or 0 to exit): ";
							int choice;
							cin >> choice;
		
							if (choice == 0) {
								sleep(1);
								cout << "> Thank you for visiting the shop!" << endl;
								break;
							}
		
							// Get the selected item from the shop inventory
							Item selectedItem = shopInventory.getItemAtIndex(choice);
		
							// Validate the choice
							if (selectedItem.name == "") {
								cout << "> Invalid choice. Please try again." << endl;
								continue;
							}
		
							// Check if the player has enough currency
							if (playerCurrency < selectedItem.price) {
								cout << "> Insufficient funds. You cannot afford this item." << endl;
								continue;
							}
		
							// Perform the purchase
							backpack.removeNode(coin,selectedItem.price);
							cout << "> Congratulations! You purchased a " << selectedItem.name << "." << endl;
							cout << "> Remaining Currency: " << backpack.searchCoinNum() << endl;
							sleep(1);
		
							// Add the purchased item to the inventory backpack
							if(selectedItem.name=="Sword"){
								backpack.appendNode(weapon);
							}else if(selectedItem.name=="Shield"){
								backpack.appendNode(armor);
							}else if(selectedItem.name=="Revival Potion"){
								backpack.appendNode(potion);
							}
						}
					}//End of the supplier shopping
				
		          
		          	sleep(1);
		          	cout << "\n> You exited the shop and heard some people talking about the story of the Black Dragon." << endl;
		          	sleep(1);
		          	cout << "\n> A strong man: Hey, young man. Have you ever heard about Fatalis, the mighty black dragon? " << endl;
		          	sleep(1);
		          	cout << "> A strong man: It took away my family's life when it attacked my village last year. " << endl;
		          	sleep(1);
		          	cout << "> A strong man: I want to have my revenge by hunting it down! " << endl;
		          	sleep(1);
		          	cout << "> A strong man: Oh, I'm The Rock by the way." << endl;
		          	sleep(1);
		          	cout << "\n> Do you want to invite The Rock (Tank) to your squad? (1 - Yes | 0 - No)" << endl;
		          	do{
		            	cout << "> make sure you choice is either 0 or 1: ";
		            	cin >> choiceJoin;
		          	}while (choiceJoin <0  || choiceJoin > 1);
		          
		          	if (choiceJoin == 1)
		          	{	
		          		sleep(1);
		          		cout << "\n> You: We have the same target, do you want to join my squad? " << endl;
		          		sleep(1);
		            	cout << "> The Rock: Sure, let's do it!" << endl;
		            	sleep(1);
		            	// to be implement
		            	cout << "> The Rock (Tank) joined your squad." << endl;
		            
		            	//Appending the Tank node to the team
		            	team.appendNode(tank);
		            	team.printTeam();
		          	}
		          
		          	else if (choiceJoin == 0)
		          	{
		            	sleep(1);
						cout << "> You: I wish you good luck! Hope to see you again!" << endl;
		          	}
		          	
		          	sleep(1);
		          	cout << "\n> You enter the village ... " << endl;
		          	sleep(1);
		          	cout << "\n> When you are walking around the village, you saw an old man carrying a stack of sticks." << endl;
		          	sleep(1);
		          	cout << "> Do you want to help the old man? (1 - Yes | 0 - No)" << endl;
		          	cout << endl;
		          
		          	do{
		            	cout << "> make sure you choice is either 0 or 1: ";
		            	cin >> choiceSaveMan;
		          	}while (choiceSaveMan <0  || choiceSaveMan > 1);
		          
		          	if (choiceSaveMan == 1)
		          	{
		            	cout << "\n> You helped the old man to carry the sticks to his house." << endl;
		            	sleep(1);
		            	cout << "> Old man: Thank you for your help! Here's some reward for you ... " << endl;
		            	sleep(1);
		            	cout << "> Info System: +300G"<<endl;
		            	// Give the cash reward to the player after helping the old man
		            	backpack.appendNode(coin,300);
		            	// Printing the current cash
		            	backpack.printCoin(); 
		          	}
		          	
		          	else if (choiceSaveMan == 0)
		          	{
		          		sleep(1);
		          		cout << "\n> You pretend like didn't see the old man and go away ... " << endl;
					}
		    		gameOver = false;
		        }
		        sleep(1);
		        cout << "\n------------------------------------ THE END OF CHAPTER 3 ------------------------------------------------" << endl;
		        break;
			//chapter 4
			case 4:	
        		sleep(1);
		        storyline.display(currentChapter);
		        
		        display.displayBat();
		        
		        sleep(1);
		        cout << "> You try to attack the Evil bat ... \n" << endl;
		        system("pause");
		        
				cout << "\n> (Your attack missed!)" << endl;
				sleep(1);
				cout << "\n> Evil Bat uses super sonic wave attack!" << endl;
				sleep(1);
				cout << "\n  * SCREEEEEECH!! *\n" << endl; 
				sleep(1);
				cout << "> (You -500HP)" << endl;
				sleep(1);
				cout << "\n> You try to attack the Evil bat again ... \n" << endl;
		        system("pause");
		        
				cout << "\n> (Your attack missed!)" << endl;
				sleep(1);
				cout << "\n> Evil Bat uses super sonic wave attack!" << endl;
				sleep(1);
				cout << "\n  * SCREEEEEECH!! *\n" << endl; 
				sleep(1);
				cout << "> (You -500HP)" << endl;
				sleep(1);
				cout << endl;
		        cout << "\n> Suddenly, you heard a voice ... " << endl;
		        sleep(1);
		        cout << "> Mysterious man: Seems like you are in a big trouble young man. " << endl;
		        sleep(1);
		        cout << "> Mysterious man: Let me help you with that. " << endl;
		        sleep(1);
		        cout << "\n> The man pulls out a bow and an arrow and shoot the Evil Bat to dead." << endl;
		        sleep(1);
		        cout << "\n> You: Thank you for your help! " << endl;
		        sleep(1);
		        cout << "> You: You saved us! By the way, we are going to hunt the black dragon, do you want to join our squad?" << endl;
		        sleep(1);
		        cout << "> Mysterious man: Nah, I'm not interested in that." << endl;
		        sleep(1);
		        cout << "> Mysterious man: I'm just interested in earning money. " << endl;
		        sleep(1);
		        cout << "> Mysterious man: If you can offer me 500G, I'll consider helping you with that. " << endl;
		        sleep(1);
				
				cout << "\n> Do you want to accept the man's offer? (1 - Yes | 0 - No)" << endl;
				cout << "> ";
				backpack.printCoin();
		        cout << endl;
		        do{
		            cout << "> make sure you choice is either 0 or 1: ";
		            cin >> choiceJoin;
		          }while (choiceJoin <0  || choiceJoin > 1);
		          
		        currentCoin = backpack.searchCoinNum();  
		          
		        if (choiceJoin == 1 && currentCoin>=500)
		        {
		        	cout << "\n> You: Alright, here you go. Here is the money you want." << endl;
		          	// to be implement
		          	// Reduce the 500G to recruit the archer.
		          	backpack.removeNode(coin,500);
		          	backpack.printCoin();
		          	
		          	cout << "\n> Chris: Have fun working together. By the way, I'm Chris." << endl;
		        	cout << "> Chris (Archer) joined your squad." << endl;
		        	
		        	//Appending the archer node to the team
		        	team.appendNode(archer);
		        	team.printTeam();
		        	
		        }else if(choiceJoin == 0 && currentCoin>=500){ //You have enough money but you reject the offer
		        	cout << "\n> You: I think we will keep that money for something valuable later. Have a nice day, Sir "<<endl;
		        	cout << "\n> You leave that man behind in the village and continue your Dragon's Slaying Journey..."<<endl;
				}else if(choiceJoin==1 && currentCoin<500){
					cout <<"\n> You want to have the man in your team, but you realize that you don't have enough money to recruit Chris,"<<endl;
					cout <<"  so you reject the man's offer and continue your Dragon's Slaying Journey..."<<endl;
				}else if(choiceJoin ==0 && currentCoin<500){
					cout <<"\n> You: Thanks for the offer, sir. But I'm afraid that we don't need anymore member in our team.\n";
					cout <<"  Besides, we don't have much moeny to recruit you in our team."<<endl;
					cout <<"\n> Chris: Well, that's sad to hear about, Young Hero. At least take my wish along your Dragon Slaying Journey. Farewell..."<<endl;
					cout <<"\n> Your team and Chris go separate paths as you continue on your journey."<<endl;
				}
				sleep(1);
				gameOver = false;
		        cout << "\n------------------------------------ THE END OF CHAPTER 4 ------------------------------------------------" << endl;
		        break;
			//chapter 5
			case 5:
				sleep(1);
				storyline.display(currentChapter);
				display.displayVolcano();
				sleep(1);
				cout << "> * You are damaged by a volcano outburst! * (-500HP)" << endl;
				sleep(1);
				//Damage the HP of every Character
				knight.reduceHP(500);
				tank.reduceHP(500);
				magician.reduceHP(500);
				archer.reduceHP(500);
				
		        cout << "Do you want to heal? (1 - Yes | 0 - No)" << endl;
		        do{
		          cout << "> make sure you choice is either 0 or 1: ";
		          cin >> choiceHeal;
		        }while (choiceHeal <0  || choiceHeal > 1);
		        
		        if (choiceHeal == 1)
		        {
		        	cout << "\n> On which character would you like to apply the Revival Potion on?"<<endl;
		        	cout << " | (K)night | (T)ank | (M)agician | (A)rcher | :";
		        	cin >> choiceApply;
		        	if(choiceApply=='K' || choiceApply=='k'){
		        		// Search and use Revival Potion on a character only
		          		backpack.searchUseNode(potion,knight);
					}else if(choiceApply=='T' || choiceApply=='t'){
						backpack.searchUseNode(potion,tank);
					}else if(choiceApply=='M' || choiceApply=='m'){
						backpack.searchUseNode(potion,magician);
					}else if(choiceApply=='A' || choiceApply=='a'){
						backpack.searchUseNode(potion,archer);
					}else{
						cout << "> Invalid choice. Defaulting to Knight..."<<endl;
						backpack.searchUseNode(potion,knight);
					}
		          
		        }
		        sleep(1);
		        cout << "\n> You continue your way and enter the final realm - the Pit of End." << endl;
		        sleep(1);
		        cout << "> The black dragon (Fatalis) is already waiting for your arrival." << endl;
		        sleep(1);
		        display.displayDragon();
		        
		        // FINAL BOSS: Black Dragon Battle
		        sleep(1);
		        battle.choosePlayer(team);
		        battle.dragonStage();
		        
		        display.displayDragonKnight();
		        sleep(1);
		        cout << "> You saved the world from destruction!" << endl;
		        sleep(1);
		        cout << "> You get a new title --- \"DragonSlayer\"." << endl;
		        sleep(1);
		        cout << "> It's a long journey with you, adventurer. " << endl;
		        sleep(1);
		        cout << "> Till we meet again ... " << endl;
		        sleep(1);
		        cout << endl;
		        
		        cout << "\n------------------------------------ THE END OF CHAPTER 5 ------------------------------------------------" << endl;
		        break;
			}
			
			// game over (player dies)
			if (gameOver) 
			{
			    display.displayGameOver();
				char restartChoice;
				sleep(1);
			    cout << "\n> Game Over! Do you want to restart the chapter? (Y/N) ";
			    cin >> restartChoice;
			    
			    while (toupper(restartChoice) != 'N' && toupper(restartChoice) != 'Y')
				{
			        cout << "\n> Please enter a valid choice (Y/N): ";
			        cin >> restartChoice;
	    		}	
	
			    if (toupper(restartChoice) == 'Y') 
				{
			        continue;
			    } 
				
				else 
				{
			        gameOver = true;
			        playAgain = false;
			        break;
			    }
			}
			//the game continues
			else
			{
				//To prevent the error(Occurrence of Chapter 6) when loading the chapter that is completed at Chapter 5
				if(currentChapter<=5){
					cout << "\n> You had successfully passed the chapter " << currentChapter << "!" << endl;
				
					//Buying Session in every turn
					cout <<"\n> Do you want to buy equipment? (1 - Yes | 0 - No): ";
					cin >> choiceBuy;
		
					while(choiceBuy!= 1 && choiceBuy!=0)
					{
						cout<< "\n> Please enter a valid choice -> ";
						cin >> choiceBuy;
					}		
					
					if(choiceBuy==1){
						// Current coin amount
						int playerCurrency = backpack.searchCoinNum();
						// Display the shop items
						// Pass playerCurrency as we will show it on the other side of this function.
						shopInventory.displayShop(playerCurrency);
		
						// Shop loop
						while (true) 
						{
							// Prompt player for item selection
							cout << "\n> Enter the number of the item you want to purchase (or 0 to exit): ";
							int choice;
							cin >> choice;
		
							if (choice == 0) {
								cout << "> Thank you for visiting the shop!" << endl;
								break;
							}
		
							// Get the selected item from the shop inventory
							Item selectedItem = shopInventory.getItemAtIndex(choice);
		
							// Validate the choice
							if (selectedItem.name == "") {
								cout << "> Invalid choice. Please try again." << endl;
								continue;
							}
		
							// Check if the player has enough currency
							if (playerCurrency < selectedItem.price) {
								cout << "> Insufficient funds. You cannot afford this item." << endl;
								continue;
							}
		
							// Perform the purchase
							
							backpack.removeNode(coin,selectedItem.price);
							playerCurrency = backpack.searchCoinNum();
							cout << "> Congratulations! You purchased a - " << selectedItem.name << " - ." << endl;
							cout << "> Remaining Currency: " << playerCurrency << endl;
		
							// Add the purchased item to the inventory backpack
							if(selectedItem.name=="Sword"){
								backpack.appendNode(weapon);
							}else if(selectedItem.name=="Shield"){
								backpack.appendNode(armor);
							}else if(selectedItem.name=="Revival Potion"){
								backpack.appendNode(potion);
							}
						}
					}
					
					//After buying session, turn to Inventory Utilization & Self-Upgrading Session
					int inventoryChoice;
					cout << "\n> Do you wish to apply the inventory? (1 - Yes | 0 - No):";
					cin >>inventoryChoice;
					
					//Temporary Variable
					int inputInventory;
					int appliedRole;
					Inventory tempInventory;
					Character tempCharacter;
					
					
					while (inventoryChoice != 0 && inventoryChoice!= 1){
						cout<< "\n> Please enter a valid choice -> ";
						cin >> inventoryChoice;
					}
					
					while(true){
						if (inventoryChoice == 1){
							cout<<"\n> Initial Character Attributes: "<<endl;
							showRoleAttribute(knight,tank, archer, magician);
							
							backpack.printBackpack();
							cout<<"\n> Which inventory do you want to use?(Enter the number)"<<endl;
							cout<<"1. Sword (+150 ATK)"<<endl;
							cout<<"2. Shield (+100 DEF)"<<endl;
							cout<<"3. Revival Potion (+150 HP)"<<endl;
							cin>>inputInventory;
							
							//Input validation
							while(inputInventory!=1 && inputInventory!=2 && inputInventory!=3){
								cout<<"/> Invalid input. Please input the correct option: ";
								cin >> inputInventory;
							}
							
							if(inputInventory==1){
								tempInventory = weapon;
							}else if(inputInventory==2){
								tempInventory = armor;
							}else if(inputInventory==3){
								tempInventory = potion;
							}
							
							team.printTeam();
							cout<<"\n> On which heroes do you want to apply the inventory onto?(Enter the number)"<<endl;
							cout<<"1. Knight" <<endl;
							cout<<"2. Tank" <<endl;
							cout<<"3. Magician"<<endl;
							cout<<"4. Archer"<<endl;
							cin>> appliedRole;
							
							while(appliedRole!=1 && appliedRole!=2 && appliedRole!=3&& appliedRole!=4){
								cout<<"\n> Invalid input. Please input the correct option: ";
								cin >> appliedRole;
							}
							
							if(appliedRole==1){
								tempCharacter = knight;
							}else if(appliedRole==2){
								tempCharacter = tank;
							}else if(appliedRole==3){
								tempCharacter = magician;
							}else if(appliedRole==4){
								tempCharacter = archer;
							}
							
							backpack.searchUseNode(tempInventory,tempCharacter);
							
							cout<<"\n> Updated Character Attributes: "<<endl;
							showRoleAttribute(knight,tank, archer, magician);
							sleep(1);
							cout<<"\nDo you wish to continue applying the inventory? (1 - Yes | 0 - No):";
							cin >> inventoryChoice;
							while (inventoryChoice != 0 && inventoryChoice!= 1){
								cout<< "\n> Please enter a valid choice -> ";
								cin >> inventoryChoice;
							}
							
						}else if(inventoryChoice == 0){
							cout<<"> SYSTEM: Exiting the inventory page..."<<endl;
							break; //Loop the applying the inventory function until the user wants to exit
						}
					}

					char saveChoice;
					
					cout << "\n> Do you want to save the game? (Y/N) ";
					
					cin >> saveChoice;
					
					while (toupper(saveChoice) != 'N' && toupper(saveChoice) !='Y')
					{
						cout<< "\n> Please enter a valid choice -> ";
						cin >> saveChoice;	
					}
					
					if (toupper(saveChoice) == 'Y')
					{
						cout << endl;
						saveGame(team, backpack, currentChapter);
					}
		
					if(currentChapter < 5)
					{
						char contChoice;
						cout << "\n> Are you ready to start a next chapter? (Y/N) ";
						cin >> contChoice;
						while (toupper(contChoice) != 'N' && toupper(contChoice) !='Y')
						{
							cout<< "\n> Please enter a valid choice -> ";
							cin >> contChoice;	
						}
						
						if (toupper(contChoice) == 'Y')
							currentChapter++;
						else{
							break;
						}
					}else{
						currentChapter++;
					}
				}else{
					cout << "\n> You have already completed all chapters, Dear Hero.\n";
					sleep(1);
					cout << "\n> Choose button [ Start a new game ] if you wish to play again. \n";
					sleep(1);
				}
				
			}
	}while(currentChapter <= 5 && playAgain == true);
}




