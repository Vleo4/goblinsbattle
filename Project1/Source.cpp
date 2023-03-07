#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class Tybik
{
	public: int age;
	public: int height;
	public: int health;
	public: string name;
	
	Tybik(int age, int height, string name)
	{
		this->age = age;
		this->height = height;
		this->health = 100;
		this->name = name;
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


void TybikBattle(Tybik tybik1, Tybik tybik2)
{
	cout << tybik1.name <<" health = " << tybik1.health << "\n"<<tybik2.name<< " health = " << tybik2.health << endl;
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
				return;
			}
			else {
				cout << tybik2.name <<" wins!" << endl;
				return;
			}
		}
	}
}

int main()
{
	srand(time(NULL));

	Tybik ostap(18, 168, "ostap");
	Tybik maxx(15, 152, "max");

	TybikBattle(ostap, maxx);
}