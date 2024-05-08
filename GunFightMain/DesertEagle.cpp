#include "DesertEagle.h"



DesertEagle::DesertEagle(const int damagePerRound,
	const int clipSize,
	const int remainingAmmo) : Pistol(damagePerRound, clipSize, remainingAmmo) {}


bool DesertEagle::fire(PlayerVitalData& enemyPlayerData) {

	int armorDamage = _damagePerRound / 4;
	int healthDamage = _damagePerRound / 4 * 3;

	if (_currClipBullets <= 0) {
		reload();
		return false;
	}

	_currClipBullets--;

	enemyPlayerData.armor -= armorDamage;
	if (enemyPlayerData.armor < 0) {
		enemyPlayerData.health += enemyPlayerData.armor;
		enemyPlayerData.armor = 0;
	}

	enemyPlayerData.health -= healthDamage;

	std::cout << "Enemy left with: " << enemyPlayerData.health <<
		" health and " << enemyPlayerData.armor << " armor" << std::endl;

	return enemyPlayerData.health <= 0;
}