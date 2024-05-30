#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Personaje.h"
#include "EnemigoFinal.h"

const int BOARD_WIDTH = 10;
const int BOARD_HEIGHT = 5;

Personaje* heroe;
std::vector<Personaje> enemigos;
EnemigoFinal* enemigoFinal;
int salidaX, salidaY;

void mostrarTablero() {
    char tablero[BOARD_HEIGHT][BOARD_WIDTH] = {};

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            tablero[i][j] = '.';
        }
    }

    for (auto& enemigo : enemigos) {
        tablero[enemigo.getPosY()][enemigo.getPosX()] = 'E';
    }

    tablero[heroe->getPosY()][heroe->getPosX()] = 'H';
    tablero[salidaY][salidaX] = 'S';

    for (int i = 0; i < BOARD_HEIGHT; ++i) {
        for (int j = 0; j < BOARD_WIDTH; ++j) {
            std::cout << tablero[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void generarPosicionesAleatorias() {
    srand(time(0));
    salidaX = rand() % BOARD_WIDTH;
    salidaY = BOARD_HEIGHT - 1;

    for (auto& enemigo : enemigos) {
        enemigo.setPosX(rand() % BOARD_WIDTH);
        enemigo.setPosY(rand() % (BOARD_HEIGHT - 1));
    }

    heroe->setPosX(rand() % BOARD_WIDTH);
    heroe->setPosY(0);
}

void moverHeroe() {
    char direccion;
    while (heroe->getHp() > 0) {
        mostrarTablero();
        std::cout << "Mover heroe (w/a/s/d): ";
        std::cin >> direccion;

        int newX = heroe->getPosX();
        int newY = heroe->getPosY();

        switch (direccion) {
        case 'w': newY--; break;
        case 's': newY++; break;
        case 'a': newX--; break;
        case 'd': newX++; break;
        default: std::cout << "Movimiento no valido" << std::endl; continue;
        }

        if (newX >= 0 && newX < BOARD_WIDTH && newY >= 0 && newY < BOARD_HEIGHT) {
            heroe->setPosX(newX);
            heroe->setPosY(newY);
        }
        else {
            std::cout << "Movimiento fuera de limites" << std::endl;
            continue;
        }

        for (auto it = enemigos.begin(); it != enemigos.end(); ++it) {
            if (heroe->getPosX() == it->getPosX() && heroe->getPosY() == it->getPosY()) {
                while (heroe->getHp() > 0 && it->getHp() > 0) {
                    heroe->atacar(*it);
                    if (it->getHp() > 0) {
                        it->atacar(*heroe);
                    }
                }
                if (heroe->getHp() <= 0) {
                    std::cout << "El heroe ha sido derrotado." << std::endl;
                    return;
                }
                enemigos.erase(it);
                break;
            }
        }

        if (heroe->getPosX() == salidaX && heroe->getPosY() == salidaY) {
            std::cout << "El heroe ha llegado a la salida y ha ganado el juego!" << std::endl;
            return;
        }
    }
}

int main() {
    heroe = new Personaje(100, "Heroe", 75, 0, 0);
    enemigos.push_back(Personaje(80, "Enemigo", 70, 0, 0));
    enemigos.push_back(Personaje(70, "Enemigo", 60, 0, 0));
    enemigoFinal = new EnemigoFinal(200, "EnemigoFinal", 120, 0, 0, 120, 150);

    generarPosicionesAleatorias();
    moverHeroe();

    delete heroe;
    delete enemigoFinal;

    return 0;
}
