#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje {
private:
    int superAttack1;
    int superAttack2;

public:
    EnemigoFinal(int pHp, std::string pName, int pAttack, int pPosX, int pPosY, int pSuperAttack1, int pSuperAttack2);

    int getSuperAttack1();
    int getSuperAttack2();

    void atacar(Personaje& enemigo) override;
};
