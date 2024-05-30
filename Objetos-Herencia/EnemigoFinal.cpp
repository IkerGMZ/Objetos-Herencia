#include "EnemigoFinal.h"
#include <cstdlib>

EnemigoFinal::EnemigoFinal(int pHp, std::string pName, int pAttack, int pPosX, int pPosY, int pSuperAttack1, int pSuperAttack2)
    : Personaje(pHp, pName, pAttack, pPosX, pPosY), superAttack1(pSuperAttack1), superAttack2(pSuperAttack2) {}

int EnemigoFinal::getSuperAttack1() { return superAttack1; }
int EnemigoFinal::getSuperAttack2() { return superAttack2; }

void EnemigoFinal::atacar(Personaje& enemigo) {
    int attackType = rand() % 3;
    int damage;

    if (attackType == 0) {
        damage = attack;
    }
    else if (attackType == 1) {
        damage = superAttack1;
    }
    else {
        damage = superAttack2;
    }

    damage -= enemigo.getAttack();

    if (damage > 0) {
        enemigo.setHp(enemigo.getHp() - damage);
    }
}
