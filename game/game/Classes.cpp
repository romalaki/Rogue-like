#pragma once
#include "Enums.h"
#include "Classes.h"
using namespace std;




type randtool(int dificulty) {
	while (true) {

		int r = rand() % 100;


		if (r <= 25) {
			return None;
		}

		else if (r <= 50) {
			return Wood;
		}

		else if (r <= 75 && dificulty >= 2) {
			return Iron;
		}

		else if (r <= 90 && dificulty >= 3) {
			return Gold;
		}

		else if (r > 90 && dificulty >= 4) {
			return Dimond;
		}

		else {
			return Wood;
		}


	}
}





	Player::Player() {
		HP = 100;
		Dmg = 10;
	}

	int Player::returnHP()  {
		return HP;
	}

	int Player::returnDMG()  {
		return Dmg;
	}


	int Player::attack() {
		return Dmg + rand() % 3 - 2;
	}



	void Player::takeDmg(int dmg) {
		HP -= dmg;
	}


	void Player::newArmor(int buffHP) {
		HP += buffHP;
	}


	void Player::newWeapon(int newDmg) {
		Dmg += newDmg / 2;
	}


	int Player::getCoins()  {
		return coins;
	}


	void Player::addCoins(int coin) {
		coins += coin;
	}


	void Player::Buy(int price) {
		coins = coins - price;
	}





	Skeleton::Skeleton(int dificulty) {

		sword = randtool(dificulty);
		armor = randtool(dificulty);

		coins = 10 + (sword + armor) / 2;

		Dmg = 5 + sword / 2;

		HP = 10 + armor;
	}

	int Skeleton::returnHP()  {
		return HP;
	}

	int Skeleton::returnDMG()  {
		return Dmg;
	}

	int Skeleton::attack() {
		return Dmg + rand() % 3 - 2;
	}



	void Skeleton::takeDmg(int dmg) {
		int evasion = rand() % 100;


		if (evasion < 90) {
			HP -= dmg;
		}

		else {
			cout << "Enemy evaded your atack!" << endl;
		}


		if (HP <= 0) {
			cout << "You won, your price: " << coins << " coins" << endl;
		}
	}


	int Skeleton::getCoins()  {
		return coins;
	}





	Zombie::Zombie(int dificulty) {
		sword = randtool(dificulty);
		armor = randtool(dificulty);


		coins = 15 + (sword + armor) / 2;

		Dmg = 5 + sword / 2;

		HP = 15 + armor;
	}

	int Zombie::returnHP()  {
		return HP;
	}

	int Zombie::returnDMG()  {
		return Dmg;
	}



	void Zombie::takeDmg(int dmg) {
		HP -= dmg;

		if (HP <= 0) {

			cout << "You won, your price: " << coins << " coins" << endl;

		}
	}



	int Zombie::attack() {

		int dealDmg = Dmg + rand() % 3 - 2;

		HP += dealDmg / 2;

		return dealDmg;
	}


	int Zombie::getCoins()  {
		return coins;
	}






	ZombieSkeleton::ZombieSkeleton(int dificulty) {
		sword = randtool(dificulty);
		armor = randtool(dificulty);
		coins = 15 + (sword + armor) / 2;
		Dmg = 5 + sword / 2;
		HP = 15 + armor;
	}


	int ZombieSkeleton::returnHP() {
		return HP;
	}

	int ZombieSkeleton::returnDMG()  {
		return Dmg;
	}


	void ZombieSkeleton::takeDmg(int dmg) {
		int evasion = rand() % 100;

		if (evasion < 90) {
			HP -= dmg;
		}

		else {
			cout << "Enemy evaded your atack!" << endl;
		}

		if (HP <= 0) {
			cout << "You won, your price: " << coins << " coins" << endl;
		}

	}

	int ZombieSkeleton::getCoins()  {
		return coins;
	}


	int ZombieSkeleton::attack() {

		int dealDmg = Dmg + rand() % 3 - 2;

		HP += dealDmg / 2;

		return dealDmg;
	}

