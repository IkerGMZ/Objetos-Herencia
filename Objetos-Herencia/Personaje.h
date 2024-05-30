#pragma once
#include <string>

class Personaje {
protected:
    int hp;
    int attack;
    std::string name;
    int posicionX;
    int posicionY;

public:
    Personaje(int pHp, std::string pName, int pAttack, int pPosX, int pPosY);

    int getHp();
    int getAttack();
    std::string getName();
    int getPosX();
    int getPosY();

    void setHp(int php);
    void setAttack(int pAttack);
    void setName(std::string pName);
    void setPosX(int pPosX);
    void setPosY(int pPosY);

    void recibirAtaque(int pAtaque);
    virtual void atacar(Personaje& enemigo);
};
