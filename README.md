# CPT 113 HACKTHON 2 (GROUP 17)
This is the CPT 113 HACKATHON 2 PROJECT presented to you by Group 17.


## Group Members:
1. Lim Yong Jun (164598)
2. Lim Miin Ning (163133)
3. Teoh Kai Lun (164277)


## Description of the Game
"DragonSlayer" is an exciting adventure game where you play as a hero on a mission to defeat the powerful black dragon, Fatalis, and save the realm of Eldoria. Journey through different landscapes, gather allies, and equip yourself with strong gear. Face challenging enemies and make important decisions. Reach the ultimate showdown in the Pit of End and slay the black dragon to become the legendary DragonSlayer. Can you save Eldoria from destruction? It's up to you!


## Features of the Game
1. Start a new game
- This feature allows you to begin a new game session. You can create a new hero character, choose a name for your hero, and embark on a fresh adventure in the game world.
- How is it implemented: The current chapter is set to 0, the team linked list and the inventory linked list are cleared.


2. Save the game
- This feature will be available after you complete every chapter. It allows you to save your current progress including your team, inventory, gold and chapter you left.
- How is it implemented: The saveGame function takes team and backpack, both of which are references to LinkedList objects, and chapter, an integer representing the current chapter as parameters. The purpose of this function is to save the game progress by writing the contents of the team and backpack objects to separate files, as well as storing the current chapter in another file.


3. Load the previous game
- With this feature, you can load a previously saved game. If you have a saved game file, you can load it and continue the chapter from where you left off. This feature ensures that you can resume your game without losing any of your previous game data like team, inventory and chapter you left.
- How is it implemented: The loadGame function takes team and backpack, both of which are references to LinkedList objects, and chapter, an integer representing the current chapter as parameters. It reads in the data from team, inventory and chapter files.

  
4. Show game detail
- This feature provides information and details about the game. It includes character and inventory statistics that help you understand the game better.
- How is it implemented: The showGameDetail function creates objects of the character classes (Knight, Tank, Magician, Archer) and inventory item classes (Weapon, Armor, Potion). Then, use 'cout' statement to print member functions (showRole(), showHP(), showATK(), etc.) within these classes to retrieve the respective statistics.

  
5. Exit the game
- This feature allows you to gracefully exit the game. When you choose to exit, the game will close.


6. Battle System
- The battle system is implemented using a stack-based approach.
- How is it implemented: The BattleSystem class contains an instance of the Stack class to manage the enemies in the battle. It has methods to add enemies to the stack (addEnemy), defeat enemies (defeatEnemy), and check if the enemy stack is empty (isEmpty). The addEnemy method creates a new instance of the Enemy class with the specified parameters and pushes it onto the enemy stack. The defeatEnemy method pops the top enemy from the stack, calculates the damage inflicted by the player, reduces the enemy's health, and displays the battle outcome.


7. Player's Inventory System
- The player's inventory is stored in a linked list.
- How is it implemented: The inventory items are represented by the Inventory class. Each node in the linked list contains an Inventory object.
- The member functions of the linked list are as follows:
  - Append: When a new item is obtained, we check if an item with the same category already exists in the list. If it does, we increment the count of that item. 
  Otherwise, we create a new node with the item data and add it to the end of the list.

  - Search: To find a specific item, we traverse the linked list and compare the name of each item with the desired item.

  - Remove: When an item is used or discarded, we search for it in the linked list. If found, we either decrement the count of the item or remove it from the list 
  if the count becomes zero.

  - Printing: We can print the inventory by traversing the linked list and displaying the category, name, and count of each item.


8. Shop Inventory System:
- The shop inventory is displayed during the game to enable player to buy equipments and potions.
- How is it implemented: implemented by using a linked list. It includes a Node class to represent each item in the inventory and a ShopInventory class to manage the inventory as a whole. The displayShop function displays the available items in the shop. It traverses the linked list and prints the item name and price for each node.


## How to Play the Game
To play "DragonSlayer," follow these steps:

1. Start the game and create your hero, giving him a name.
2. Navigate through the game using the provided options and prompts. Explore captivating landscapes, battle monsters, and interact with characters you encounter.
3. Engage in combat by selecting your attacks during battles. Pay attention to your health (HP) and defeat enemies to earn rewards like gold (G).
4. Manage your resources wisely. Use gold to buy equipment from shops, consider purchasing healing items like potions.
5. Make choices throughout the game that impact your journey. Help NPCs in need, recruit allies, and decide whether to accept offers or join forces with other characters.
6. Progress through the chapters and overcoming challenges. Meet new acquaintances who can join your squad and provide valuable assistance.
7. Approach the final realm, the Pit of End, where the black dragon Fatalis awaits. Engage in a climactic battle, utilizing your squad's skills and abilities to defeat Fatalis.
8. Complete the game by slaying the black dragon and saving Eldoria. Celebrate your victory as the renowned DragonSlayer and witness the game's conclusion.

Remember, the choices you make and the actions you take will determine the outcome of your heroic journey in "DragonSlayer." Good luck, and may Eldoria be saved!


## How object-oriented concepts were used to develop the game
In the program, several object-oriented concepts were used to develop the game.

1. Inheritance
- Inheritance was utilized to establish an "is-a" relationship between classes.
- For instance, the classes Knight, Tank, Magician, and Archer inherited from a common base class Hero.
- This allowed them to inherit common attributes and methods from the base class while also having their own unique characteristics.

  
2. Composition
- Composition was used to create complex objects by combining simpler objects or components.
- For example, the LinkedList class contained a composition relationship with the ListNode class, where each node was composed of data and a reference to the next node.

  
3. Encapsulation
- Classes were used to encapsulate related data and functionality.
- For example, classes like Knight, Tank, Magician, Archer, Weapon, Armor, Potion, Coin, etc., were created to encapsulate the properties and behaviors of specific game entities or items.


4. Polymorphism
- Polymorphism was employed to enable different classes to be used interchangeably through a common interface.
- The Hero base class had virtual functions that were overridden by the derived classes, allowing objects of different derived classes to be treated uniformly based on their shared base class.


5. Abstraction
- Abstraction was utilized to represent essential features while hiding unnecessary details.
- For instance, the LinkedList class abstracted the implementation details of a linked list, providing high-level methods to manipulate the list without exposing the underlying implementation.


## How linked lists/stacks/queues play a role in the game
We have a total of 3 linked lists and 1 stack implemented in the program.

1. One linked list overloaded by multiple member functions to manage the game inventory and team.
- It provides functionality to append new nodes (characters or inventory items) to the list, search for specific nodes, remove nodes, and print the contents of the list.

  
2. One linked list to manage the storyline in the game.
- Each node of the linked list represents a chapter in the game's story.
- Allowing easy traversal and retrieval of specific chapters as needed.

  
3. One linked list is used to implement the shop inventory system in the game.
- Serves as a data structure to store and manage the available items in the shop.
- Each node in the linked list represents an item, and the next pointer connects the nodes to form a chain.
- Provides a user interface for players to browse and purchase items from the shop.


4. A stack is used as part of the game's battle system.
- Stores the enemy characters that the player will face.
- Each time a new enemy appears, it is added to the stack using the push function.
- The player fights with enemies by using the pop function to remove the top enemy from the stack.


## A link to the game demo video
[Demo Video Link](https://youtu.be/_WqLARpHzRg)


   
