#include "Personaje.h"

Personaje::Personaje(int pHp, std::string pName, int pAttack, int pPosX, int pPosY)
    : hp(pHp), attack(pAttack), name(pName), posicionX(pPosX), posicionY(pPosY) {}

int Personaje::getHp() { return hp; }
int Personaje::getAttack() { return attack; }
std::string Personaje::getName() { return name; }
int Personaje::getPosX() { return posicionX; }
int Personaje::getPosY() { return posicionY; }

void Personaje::setHp(int php) { hp = php; }
void Personaje::setAttack(int pAttack) { attack = pAttack; }
void Personaje::setName(std::string pName) { name = pName; }
void Personaje::setPosX(int pPosX) { posicionX = pPosX; }
void Personaje::setPosY(int pPosY) { posicionY = pPosY; }

void Personaje::recibirAtaque(int pAtaque) {
    int damage = pAtaque - attack;
    if (damage > 0) {
        hp -= damage;
    }
}

void Personaje::atacar(Personaje& enemigo) {
    int damage = attack - enemigo.getAttack();
    if (damage > 0) {
        enemigo.setHp(enemigo.getHp() - damage);
    }
}
