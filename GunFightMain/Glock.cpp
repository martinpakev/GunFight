#include "Glock.h"
#include "Glock.h"


Glock::Glock(const int damagePerRound,
	const int clipSize,
	const int remainingAmmo) : Pistol(damagePerRound, clipSize, remainingAmmo) {}


bool Glock::fire(PlayerVitalData& enemyPlayerData) {
	int armorDamage = _damagePerRound / 2;
	int healthDamage = _damagePerRound / 2;

	for (int i = 0; i < InternalDefines::ROUNDS_PER_FIRE; i++) {
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
		if (enemyPlayerData.health <= 0) return true;
	}
	return enemyPlayerData.health <= 0;
}

