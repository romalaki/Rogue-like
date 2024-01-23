#pragma once
#include "Enums.h"

class Entity{
public:
	virtual int attack() = 0;
	virtual void takeDmg(int dmg) = 0;
	virtual int getCoins() = 0;
	virtual int returnHP() = 0;
	virtual int returnDMG() = 0;


protected:
	int HP = 0;
	int Dmg = 0;
};


class Player: public Entity{
public:
	Player();
	int attack() override;
	void takeDmg(int dmg)override;
	int getCoins()override;
	int returnHP()override;
	int returnDMG()override;
	void newArmor(int buffHP);
	void newWeapon(int newDmg);
	void addCoins(int coin);
	void Buy(int price);

private:
	int coins;
};


class Zombie : public Entity {
public:
	Zombie(int dif);
	int attack() override;
	void takeDmg(int dmg)override;
	int getCoins()override;
	int returnHP()override;
	int returnDMG()override;


protected:

	type armor;
	type sword;


	int coins;
};


class Skeleton : public Entity {
public:
	Skeleton(int dif);
	int attack() override;
	void takeDmg(int dmg)override;
	int getCoins()override;
	int returnHP()override;
	int returnDMG()override;


protected:

	type armor;
	type sword;


	int coins;
};

class ZombieSkeleton : public Entity {
public:
	ZombieSkeleton(int dif);
	int attack() override;
	void takeDmg(int dmg)override;
	int getCoins()override;
	int returnHP()override;
	int returnDMG()override;


protected:

	type armor;
	type sword;


	int coins;
};