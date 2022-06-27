#include <map>
#include "Rec.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
#include <iostream>
#include <typeinfo>
#include <typeindex>
#include "ImmuneGift.h"
#include "EatEnemyGift.h"
#include "CollisionHandling.h"

#include "Board.h"
bool  immune = false;
bool ifEat = false;
int counter_gift_immune = 0;
int counter_gift_eat = 0;
namespace {
	void playerEnemy(Objects& player,Objects& enemy)
	{
		Player& p = static_cast<Player&>(player);
		//אם אין הגנה על השחקן יורד לו ניקוד וחוזר למקום ההתחלתי
		if (!immune)
		{
			p.setLives(p.getLives() - 1);
			p.setPosInBoard({ 0,0 });
		}
		//אם ממוגן השתמש פעם אחת ויורד לו מהמונה
		if (immune)
			counter_gift_immune--;
		//אם יכול לאכול אויב
		if (ifEat)
		{
			Enemy& e = static_cast<Enemy&>(enemy);
			sf::Sprite s;
			e.setObject(s);
			counter_gift_eat--;
		}
		if (counter_gift_eat <= 0)
			ifEat = false;
		if (counter_gift_immune <= 0)
			immune = false;
	}
	void playerGiftEat(Objects& player,Objects& giftEat)
	{
		Player& p = static_cast<Player&>(player);
		EatEnemyGift& g = static_cast<EatEnemyGift&>(giftEat);
		sf::Sprite s ;
		g.setObject(s);
		ifEat = true;
		immune = true;
		counter_gift_eat++;
	}
	void playerGift(Objects& player,Objects& gift)
	{
		Player& p = static_cast<Player&>(player);
		ImmuneGift& g = static_cast<ImmuneGift&>(gift);
		sf::Sprite s;
		g.setObject(s);
		immune = true;
		counter_gift_immune++;
	}
	void enemyRec(Objects& enemy,Objects& rec)
	{}
	void playerRec(Objects& player,Objects& rec)
	{}
	void enemyGiftEat(Objects& enemy,Objects& giftEat)//לא קורה כלום
	{}
	void enemyGift(Objects& enemy,Objects& gift)//לא קורה כלום
	{}
	void enemyEnemy(Objects& enemy1, Objects& enemy2)//שלא יעלו אחד על השני
	{
		Enemy& e1 = static_cast<Enemy&>(enemy1);
		Enemy& e2 = static_cast<Enemy&>(enemy2);
		
	}
	void enemyPlayer(Objects& enemy, Objects& player){playerEnemy(player, enemy);}
	void recEnemy(Objects& Rec, Objects& enemy){enemyRec(enemy, Rec);}
	void recPlayer(Objects& rec, Objects& player){ playerRec(player, rec);}

	using HitFunctionPtr = void (*)(Objects&, Objects&);
	using Key = std::pair<std::type_index, std::type_index>;
	using HitMap = std::map<Key, HitFunctionPtr>;

	HitMap initializeCollisionMap()
	{
		HitMap phm;
		phm[Key(typeid(Player), typeid(Enemy))] = &playerEnemy;
		phm[Key(typeid(Enemy), typeid(Player))] = &enemyPlayer;
		phm[Key(typeid(Enemy), typeid(Enemy))] = &enemyEnemy;
		phm[Key(typeid(Player), typeid(EatEnemyGift))] = &playerGiftEat;
		phm[Key(typeid(Player), typeid(ImmuneGift))] = &playerGift;
		phm[Key(typeid(Enemy), typeid(Rec))] = &enemyRec;
		phm[Key(typeid(Player), typeid(Rec))] = &playerRec;
		phm[Key(typeid(Enemy), typeid(EatEnemyGift))] = &enemyGiftEat;
		phm[Key(typeid(Enemy), typeid(ImmuneGift))] = &enemyGift;
		phm[Key(typeid(Rec), typeid(Enemy))] = &recEnemy;
		phm[Key(typeid(Rec), typeid(Player))] = &recPlayer;

		return phm;
	}
	//מחזיר את הפונקציה המתאימה לפי האובייקטים
	HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
	{
		static HitMap collisionMap = initializeCollisionMap();
		auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
		if (mapEntry == collisionMap.end())
		{
			return nullptr;
		}
		return mapEntry->second;
	}
}

void processCollision(Objects& obj1, Objects& obj2)
{
	auto phf = lookup(typeid(obj1), typeid(obj2));
	if (!phf)
	{
		throw UnknownCollision(obj1, obj2);
	}
	phf(obj1, obj2);
}
