#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

const int LARGURA_DE_TELA = 900;
const int ALTURA_DE_TELA = 700;
 
int janela();

int main(int argc, char *argv[])
{
	ALLEGRO_DISPLAY *janela = NULL;//janela principal
	ALLEGRO_BITMAP *imagem = NULL;//imagem
	ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;//eventos
 
	if (!al_init()) //CASO NÃO SEJA POSSÍVEL CARREGAR O ALLEGRO
	{
		fprintf(stderr, "Falha ao inicializar a Allegro 5\n");
		return -1;
	}
 
	if (!al_init_image_addon()) //CASO NÃO SEJA POSSÍVEL CARREGAR IMAGENS
	{
		fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
		return -1;
	}

	janela = al_create_display(LARGURA_DE_TELA, ALTURA_DE_TELA); //dimensão da janela

	if (!janela) //CASO A JANELA NÃO ABRA
	{
		fprintf(stderr, "Falha ao criar a janela\n");
		return -1;
	}
	
	imagem = al_load_bitmap("background.jpg");//carregando imagem no programa
	if (!imagem)//CASO A IMAGEM NÃO SEJA CARREGADA
	{
		fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
		al_destroy_display(janela);
		return -1;
	}


	al_draw_bitmap(imagem,0,0,0);//carregando imagem para tela
 	al_flip_display();
	
	janela();//chama a janela com a fila de eventos

	al_destroy_display(janela);
 
	return 0;
}


int janela()
{
	while (1)
	{
		ALLEGRO_EVENT evento;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.05);

		int os_eventos = al_wait_for_event_until(fila_eventos,&evento,&timeout);
		
		if (os_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		al_draw_bitmap(imagem,0,0,0);
		al_flip_display();
	}
	al_destroy_event_queue(fila_eventos);
	return 1;
}

