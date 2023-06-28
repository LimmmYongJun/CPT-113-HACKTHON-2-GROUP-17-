//create inventory class
#include <iostream>
using namespace std;

//***************START OF Inventory Struct ADS***************//
class Inventory{
	private:
		string category;
		string name;
		int itemCount;
	public: 
		//Default constructor
		Inventory(){
			category = "";
			name="";
			itemCount = 0;
		}
		//Parameterized constructor
		Inventory(string category,string name, int itemCount){
			this->category = category;
			this->name=name;
			this->itemCount = itemCount;
		}
		
		//Accessor
		string showCategory(){
			return category;
		}
		string showName(){
			return name;
		}
		int showCount(){
			return itemCount;
		}
		
		//Mutator
		void setCategory(string category){
			this->category = category;
		}
		void setName(string name){
			this->name = name;
		}
		void setItemCount(int itemCount){
			this->itemCount = itemCount;
		}
		void incrementItemCount(int coinGet){
			this->itemCount += coinGet;
		}
		void decrementItemCount(int coinSpend){
			this->itemCount -= coinSpend;
		}
		
		//Virtual function
		virtual int getIncreaseHP(){
			return 0;
		}
		
		virtual int getIncreaseATK(){
			return 0;
		}
		
		virtual int getIncreaseDEF(){
			return 0;
		}
};


//Declare class Weapon as the derived class of class Inventory(Base class)
class Weapon: public Inventory{
	private:
		int increaseATK;
	public:
		Weapon(): Inventory("Weapon","Sword",1){ 
			increaseATK = 50;
		}
		//calling virtual function
		int getIncreaseATK() override{
			return increaseATK;
		}
};
//Declare class Armor as the derived class of class Inventory(Base class)
class Armor: public Inventory{
	private:
		int increaseDEF;
	public:
		Armor(): Inventory("Armor","Shield",1){  //When inventory Armor is picked, the item will increase by 1
			increaseDEF = 75;
		}
		int getIncreaseDEF() override{
			return increaseDEF;
		}
};
//Declare class Potion as the derived class of class Inventory(Base class)
class Potion: public Inventory{
	private:
		int increaseHP;
	public:
		Potion(): Inventory("Potion","Revival Potion",1){
			increaseHP = 150;
		}
		int getIncreaseHP() override{
			return increaseHP;
		}
		
};
//Declare class Coin as the derived class of class Inventory(Base class)
class Coin: public Inventory{
	public:
		//Initialize the coin amount as 0
		Coin(): Inventory("Coin","Gold Coin",0){
		}
};

//***************END OF Inventory Struct ADS***************//
