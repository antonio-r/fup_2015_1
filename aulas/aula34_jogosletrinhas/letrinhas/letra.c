#include "letra.h"
#include <stdlib.h>


Letra letra_criar(float largura, float vx, float vy, int tam){
    Letra letra;
    letra.c = rand() % ('z' - 'a' + 1) + 'a';
    letra.y = 0;
    letra.x = rand() % (int)(largura - tam);
    letra.vx = vx;
    letra.vy = vy;
    letra.tam = tam;
    letra.angulo = rand() % 360;
    //entre -3 e +3
    letra.vangular = rand() % 6 - 3;
    return letra;
}

void letra_desenhar(sfRenderWindow * janela, sfText * text, Letra letra){
    char texto[2];
    texto[0] = letra.c;
    texto[1] = '\0';
    sfText_setColor(text, sfWhite);
    sfText_setString(text, texto);
    sfText_setRotation(text, letra.angulo);
    sfText_setPosition(text, (sfVector2f){letra.x, letra.y});
    sfText_setCharacterSize(text, 30);
    sfRenderWindow_drawText(janela, text, NULL);
}


void letra_update(Letra *letra){
    letra->x += letra->vx;
    letra->y += letra->vy;
    letra->angulo += letra->vangular;
    letra->angulo = (int)letra->angulo % 360;
}





















