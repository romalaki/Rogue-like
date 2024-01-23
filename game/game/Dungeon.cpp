#pragma once
#include "Classes.h"
#include "Dungeon.h"

using namespace std;


	int Dungeon::getFloor() {
		return floor;
	}


	void Dungeon::go() {
		cout << "WELCOME" << endl;
		Player* play = new Player;

		while (play->returnHP() > 0 || getFloor() < 6) {
			steps++;

			cout << "Your HP:" << play->returnHP() << endl;
			cout << "Your DMG:" << play->returnDMG() << endl;
			cout << "Your coins:" << play->getCoins() << endl;
			cout << "Floor:" << getFloor() << endl << endl;

			int event = rand() % 100;


			if (event <= 40) {

				fight(play, floor);
				cout << endl;

			}
			else if (event < 80) {

				cout << "Nothing happend. Keep walking" << endl;
				cout << endl;


				Sleep(3000);

			}
			else {

				shop(play);
				cout << endl;

			}


			if (steps == 10) {

				steps = 0;
				floor++;

			}
		}

		if (play->returnHP() > 0) {
			cout << "Win!!";
		}
		else {
			cout << "You lost!";
		}
	}

	void Dungeon::shop(Player* play) {


		vector<type>armor{ Wood,Iron,Gold,Dimond };
		vector<string>armor_str{ "Wood","Iron","Gold","Dimond" };




		while (true) {

			cout << endl;
			cout << "Shop:" << endl;
			cout << "1:Weapon" << endl;
			cout << "2:Armor" << endl;
			cout << "3:Go away" << endl;
			cout << "You have " << play->getCoins() << " coins" << endl;



			int choice = 0;
			cin >> choice;
			cout << endl;


			if (choice == 1) {


				for (int i = 0; i < armor.size(); i++) {

					cout << i + 1 << ". I suggest " << armor_str[i] << " sword, the price is " << armor[i] << " and damage is " << armor[i] / 2 << endl;

				}

				cin >> choice;

				if (choice > 0 && choice <= 4 && play->getCoins() >= armor[choice - 1]) {

					play->Buy(armor[choice - 1]);

					play->newWeapon(armor[choice - 1]);

					cout << "Congrats, you upgraded your sword!" << endl;

				}
				else {
					cout << "Cant do it!" << endl;
				}


			}
			else if (choice == 2) {


				for (int i = 0; i < armor.size(); i++) {

					cout << i + 1 << ". I suggest " << armor_str[i] << " armor, the price and buff to your HP will be " << armor[i] << endl;

				}


				cin >> choice;

				if (choice > 0 && choice <= 4 && play->getCoins() >= armor[choice - 1]) {

					play->Buy(armor[choice - 1]);

					play->newArmor(armor[choice - 1]);

					cout << "Congrats, you upgraded your armor!" << endl;

				}
				else {
					cout << "Cant do it!" << endl;
				}
			}

			else if (choice == 3) {

				cout << "Bye" << endl;
				break;

			}
			else {

				cout << "Repeat please?" << endl;

			}
		}
	}

	void Dungeon::fight(Player* play, int dificulty) {


		int percent = rand() % 3;


		Entity* sk = nullptr;


		if (percent == 0) {

			cout << "You got attacked by skeleton!" << endl;
			sk = new Skeleton(dificulty);

		}

		else if (percent == 1) {

			cout << "You got attacked by zombie!" << endl;
			sk = new Zombie(dificulty);

		}

		else {

			cout << "You got attacked by zombie-skeleton!" << endl;
			sk = new ZombieSkeleton(dificulty);

		}


		cout << "Enemy staistics: " << endl;

		cout << "DMG: " << sk->returnDMG() << endl;

		cout << "HP: " << sk->returnHP() << endl;


		while (play->returnHP() > 0) {

			cout << "What do you do?" << endl;
			cout << "1)Fight" << endl;
			cout << "2)Run away!" << endl;


			int choice;
			cin >> choice;


			int dmg;

			cout << endl;

			if (choice == 2) {

				dmg = sk->attack();
				play->takeDmg(dmg);

				cout << "You got hit by " << dmg << " damage, and ran away" << endl;

				break;
			}
			else if (choice == 1) {

				dmg = play->attack();
				cout << "You deal: " << dmg << endl;


				sk->takeDmg(dmg);


				if (sk->returnHP() <= 0) {

					play->addCoins(sk->getCoins());
					break;

				}
			}
			else {
				cout << "You did nothing!";
			}


			dmg = sk->attack();


			play->takeDmg(dmg);


			cout << "You got hit by: " << dmg << endl;
			cout << "Enemy HP: " << sk->returnHP() << endl;
			cout << "Your HP: " << play->returnHP() << endl;

			cout << endl;


		}

		Sleep(3000);

	}

