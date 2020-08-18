#include <iostream>
#include "Partie.hpp"
#include "DEFINITIONS.hpp"

using namespace std;

int main() {
    TepeGolo::Partie(SCREEN_WIDTH, SCREEN_HEIGHT, "Jeu du Demineur");
    system("pause");
    return EXIT_SUCCESS;
}
