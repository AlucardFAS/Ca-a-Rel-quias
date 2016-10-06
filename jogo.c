#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <stdbool.h>
 
const int LARGURA_T = 900;
const int ALTURA_T = 700;
 
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *cima1 = NULL;
ALLEGRO_BITMAP *baixo1 = NULL;
ALLEGRO_BITMAP *esquerda1 = NULL;
ALLEGRO_BITMAP *direita1 = NULL;
bool iniciar();
 
int main(void)
{
    bool sair = false;
    int tecla = 0;
 
    if (!iniciar())
    {
        return -1;
    }
 
    al_draw_bitmap(fundo, 0, 0, 0);
    int x=0,y=0;
    while (!sair)
    {
        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
 
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    tecla = 1;
                    break;
                case ALLEGRO_KEY_DOWN:
                    tecla = 2;
                    break;
                case ALLEGRO_KEY_LEFT:
                    tecla = 3;
                    break;
                case ALLEGRO_KEY_RIGHT:
                    tecla = 4;
                    break;
                }
            }
            else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }
 
        if (tecla)
        {
            al_draw_bitmap(fundo, 0, 0, 0);
 
            switch (tecla)
            {
            case 1:
                al_draw_bitmap(cima1, x, y--,0);
                al_flip_display();
                break;
            case 2:
                al_draw_bitmap(baixo1, x, y++, 0);
                al_flip_display();
                break;
            case 3:
                al_draw_bitmap(esquerda1, x--, y, 0);
                al_flip_display();
                break;
            case 4:
                al_draw_bitmap(direita1, x++, y, 0);
                al_flip_display();
                break;

            }
 
            tecla = 0;
        }
 
        al_flip_display();
    }
 
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
 
    return 0;
}
 
bool iniciar()
{
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return false;
    }
 
    if (!al_init_image_addon())
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_image.\n");
        return false;
    }
 
    if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        return false;
    }
 
    janela = al_create_display(LARGURA_T, ALTURA_T);
    if (!janela)
    {
        fprintf(stderr, "Falha ao criar janela.\n");
        return false;
    }
 
    al_set_window_title(janela, "Projeto Pyongyang");
 
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return false;
    }
 
    fundo = al_load_bitmap("background.png");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    esquerda1 = al_load_bitmap("esquerda1.png");
    if (!esquerda1)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    direita1 = al_load_bitmap("direita1.png");
    if (!direita1)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    cima1 = al_load_bitmap("cima1.png");
    if (!cima1)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    baixo1 = al_load_bitmap("baixo1.png");
    if (!baixo1)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
 
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    return true;
}
