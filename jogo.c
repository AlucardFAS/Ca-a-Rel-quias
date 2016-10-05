#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

const int LARGURA_TELA = 900;
const int ALTURA_TELA = 700;

int telainicio()
{
    ALLEGRO_DISPLAY *janela = NULL;
    ALLEGRO_BITMAP *imagem = NULL;
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    ALLEGRO_FONT *fonte = NULL;

    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar a Allegro.\n");
        return -1;
    }
 
 
    janela = al_create_display(LARGURA_TELA, ALTURA_TELA);
    if (!janela)
    {
        fprintf(stderr, "Falha ao inicializar a janela.\n");
        return -1;
    }

    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();

/*    fonte=al_load_font("bradhitc.ttf",30,0); 
    if(!fonte)
    {
        fprintf(stderr,"Falha ao carregar fonte.\n");
        al_destroy_display(janela);
        return -1;
    }*/


    imagem = al_load_bitmap("background.png");
    if (!imagem)
    {
        fprintf(stderr, "Falha ao carregar o arquivo de imagem.\n");
        al_destroy_display(janela);
        return -1;
    }
 
    fila_eventos = al_create_event_queue();
    if (!fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_display(janela);
        return -1;
    }

 //   al_draw_text(fonte, al_map_rgb(255, 255, 255), LARGURA_TELA / 2, 90, ALLEGRO_ALIGN_CENTRE, "Iniciar");

 
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));
 
    al_draw_bitmap(imagem, 0, 0, 0);
 
    al_flip_display();
 
    while (1)
    {
        ALLEGRO_EVENT evento;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.05);
 
        int tem_eventos = al_wait_for_event_until(fila_eventos, &evento, &timeout);
 
        if (tem_eventos && evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
 
        al_draw_bitmap(imagem, 0, 0, 0);
        al_flip_display();
    }
 
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
}

int main()
{
    telainicio();
}
