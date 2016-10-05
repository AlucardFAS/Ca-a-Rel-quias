#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
 
int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *janela = NULL;//janela principal
	ALLEGRO_BITMAP *imagem = NULL;//imagem
 
	if (!al_init())
	{
		fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
		return -1;
	}
 
	al_init_image_addon();

	janela = al_create_display(900, 700); //dimensão da janela
	if (!janela)
    {
        fprintf(stderr, "Falha ao criar a janela\n");
        return -1;
    }

	
	imagem = al_load_bitmap("background.jpg");//carregando imagem no programa

	al_draw_bitmap(imagem,0,0,0);//carregando imagem para tela

 	al_flip_display();
    al_rest(10.0);
    al_destroy_display(janela);
 
    return 0;
}
