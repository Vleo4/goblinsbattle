#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class Tybik
{
	public: int height;
	public: int health;
	public: string name;
	public: int level;
	
	Tybik(int height, string name)
	{
		this->height = height;
		this->health = 100;
		this->name = name;
		this->level = 1;
	}

	void TybikCheck()
	{
		if (this->height > 120) cout << "YOU ARE NOT A TYBIK" << endl;
		else cout << "HELLO GOBLIN" << endl;
	}

	int Hit()
	{
		int dmg = this->height * (rand() % 30 + 2) / 200;
		return dmg;
	}

};

void TybiksDick(Tybik tybik)
{
	if (tybik.height == 1283) cout << "your dick is 124545 cm" << endl;
}

Tybik SelectFighter()
{
	int choice = 0;
	do
	{
		cout << "Select your opponent\n1. Max (level 1)\n2. JFDL (level 2)\n3. Vleo (level 10)\n\nEnter your choice: ";
		cin >> choice;
	} while (choice < 1 || choice>3);

	Tybik tybik1(145, "Max");
	Tybik tybik2(165, "JFDL");
	Tybik tybik3(250, "Vleo");
	switch(choice)
	{
		case 1:
			return tybik1;
		case 2:
			return tybik2;
		case 3:
			return tybik3;
		default:
			break;
	}
}


void TybikBattle(Tybik& tybik1)
{
	Tybik tybik2 = SelectFighter();
	cout << tybik1.name <<" health = " << tybik1.health<< " , height "<< tybik1.height << "\n" << tybik2.name << " health = " << tybik2.health << " , height " << tybik2.height << endl;
	cout << "\n!Let the battle start!\n"<< endl;
	for (int i = 0; i < 1000; i++)
	{		
		//Tybik1 hit
		this_thread::sleep_for(chrono::seconds(1));
		if (rand() % 3 != 1) 
		{ 
			int hit = tybik1.Hit();
			tybik2.health -= hit; 
			cout << tybik1.name <<" hits "<< tybik2.name <<" for " << hit << " damage!" << endl;
		}
		else
		{
			cout << tybik1.name <<" missed!" << endl;
		}

		//Tybik2 hit 
		this_thread::sleep_for(chrono::seconds(1));
		if (rand() % 3 != 1)
		{
			int hit = tybik2.Hit();
			tybik1.health -= hit;
			cout << tybik2.name << " hits " << tybik1.name << " for " << hit << " damage!" << endl;
		}
		else
		{
			cout << tybik2.name <<" missed!" << endl;
		}

		cout << tybik1.name << " health = " << tybik1.health << " " << tybik2.name << " health = " << tybik2.health << endl;


		if (tybik1.health <= 0 || tybik2.health <= 0)
		{
			if (tybik1.health > tybik2.health) {
				cout << tybik1.name << " wins!" << endl;
				tybik1.level++;
				tybik1.height += 10;
				tybik1.health = 100;
				return;
			}
			else {
				cout << tybik2.name <<" wins!" << endl;
				tybik1.health = 100;
				return;
			}
		}
	}
}

void TybikAccount(Tybik tybik)
{
	cout << "\nName: " << tybik.name << "\nHeight: " << tybik.height << "\nLevel: " << tybik.level << endl;
}

int menu(Tybik tybik)
{
	int choice = 1;
	do
	{
		cout << "MENU\n1. Battle!\n2. My Account\n0. Exit\n\nEnter your choice: ";
		cin >> choice;
		cout << endl;
		switch(choice)
		{
			case 1: TybikBattle(tybik); break;
			case 2: TybikAccount(tybik); break;
			case 0: exit(1); break;
			default: break;
		}
	} while (choice != 0);
}

int main()
{
	srand(time(NULL));

	string name;
	cout << "Hello! Welcome to TybikBattle, enter your name fighter!: ";
	cin >> name;

	Tybik tybik(150, name);
	
	menu(tybik);
}