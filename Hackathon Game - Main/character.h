//creating character class
#include <iostream>
using namespace std;

//***************START OF Character Struct ADS***************//
class Character{ //Base class/Parent class
	private:
		string role; //role: knight|magician|tank|archer
		int HP; //health point
		int ATK; //attack
		int DEF; //defense
		int MP; //mana point
	public:
		//Default constructor
		Character(){
			role="";
			HP=0;
			ATK=0;
			DEF=0;
			MP=0;
		}
		//Parameterized constructor
		Character(string role, int HP, int ATK, int DEF, int MP){
			this->role = role;
			this->HP = HP;
			this->ATK = ATK;
			this->DEF = DEF;
			this->MP = MP;
		}
		
		//Accessor
		string showRole(){
			return role;
		}
		
		int showHP(){
			return HP;
		}
		int showATK(){
			return ATK;
		}
		int showDEF(){
			return DEF;
		}
		int showMP(){
			return MP;
		}
		
		//Mutator
		void setHP(int change){
			HP=change;
		}
		
		void setATK(int change){
			ATK=change;	
		}
		
		void setDEF(int change){
			DEF=change;
		}
		
		void setMP(int change){
			MP=change;
		}
		
		//Increase the attribute
		void increaseHP(int amount){
			HP+=amount;
		}
		void increaseATK(int amount){
			ATK+=amount;
		}
		void increaseDEF(int amount){
			DEF+=amount;
		}
		
		
		//For battle damage use
		void reduceHP(int damage){
			HP-=damage;
			if(HP<0){
				HP=0;
			}
		}
};

//ROLES
//Declare class Knight as the derived class of class Character(Base class)
class Knight : public Character{ //Derived class
	public:
		Knight(): Character("Knight",1500,180,200,50){
		}	
};

//Declare class Tank as the derived class of class Character(Base class)
class Tank : public Character{
	public:
		Tank(): Character("Tank",2000,100,250,50){
		}
};
//Declare class Magician as the derived class of class Character(Base class)
class Magician : public Character{
	public:
		Magician(): Character("Magician",800,200,100,300){
		}
};
//Declare class Archer as the derived class of class Character(Base class)
class Archer : public Character{
	public:
		Archer(): Character("Archer",1000,250,120,100){
		}
};
//***************END OF Character Struct ADS***************//
