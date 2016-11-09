#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include <stdbool.h>
 
const int LARGURA_T = 900;
const int ALTURA_T = 700;
int itens[3] = {0,0,0};
 
ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *cima[2];
ALLEGRO_BITMAP *baixo[2];
ALLEGRO_BITMAP *esquerda[2];
ALLEGRO_BITMAP *direita[2];
ALLEGRO_SAMPLE *trilha = NULL;
ALLEGRO_BITMAP *parado[1];
ALLEGRO_BITMAP *item[3];
ALLEGRO_SAMPLE_INSTANCE *inst_trilha = NULL;

bool iniciar();
int acharoseta(int x, int y);
int achanarmer(int x, int y);
int abrirbau();
int jogo()
{
    bool sair = false;
    int tecla = 0;
    int i=0;
 
    if (!iniciar())
    {
        return -1;
    }
 
    al_draw_bitmap(fundo, 0, 0, 0);
    int x=450,y=350;
    while (!sair)
    {
        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            al_play_sample_instance(inst_trilha);//toca musica até o jogo ser fechado
 
            if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
            {
                switch(evento.keyboard.keycode)// muda a variavel tecla para utilizar o teclado no switch do outro if
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
                case ALLEGRO_KEY_ENTER:
                    tecla = 5;
                    break;
                case ALLEGRO_KEY_B:
                    tecla = 6;
                    break;
                case ALLEGRO_KEY_H:
                    tecla = 7;
                    break;
                case ALLEGRO_KEY_1:
                    tecla = 8;
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
            /*case 0:
                al_draw_bitmap(parado[0], x, y, 0);*/ //ainda nao fica parado
            case 1: // movimenta pra cima
                if(y<=245 && x<=300)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else if(y<=245 && x>=560)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else if(y<=200)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(cima[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else
                {
                    if(i==0)
                    {
                        al_draw_bitmap(cima[i], x, y-=5,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(cima[i], x, y-=5,0);
                        i--;
                    }
                    al_flip_display();
                }

                al_flip_display();
                sleep(0.1);//funciona
                break;
            case 2: // movimenta pra baixo
                if(y>=520)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(baixo[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(baixo[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else
                {
                    if(i==0)
                    {
                        al_draw_bitmap(baixo[i], x, y+=5,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(baixo[i], x, y+=5,0);
                        i--;
                    }
                    al_flip_display();
                }
                al_flip_display();
                sleep(0.1);
                break;
            case 3: // movimenta pra esquerda
                if(x<=310 && y<=230)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(esquerda[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(esquerda[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else if(x<=0)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(esquerda[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(esquerda[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else
                {
                    if(i==0)
                    {
                        al_draw_bitmap(esquerda[i], x-=5, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(esquerda[i], x-=5, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                al_flip_display();
                sleep(0.1);
                break;
            case 4: // movimenta pra direita
                if(x>=560 && y<=230)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(direita[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(direita[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else if(x>=860)
                {
                    if(i==0)
                    {
                        al_draw_bitmap(direita[i], x, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(direita[i], x, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                else
                {
                    if(i==0)
                    {
                        al_draw_bitmap(direita[i], x+=5, y,0);
                        i++;
                    }
                    else if(i==1)
                    {
                        al_draw_bitmap(direita[i], x+=5, y,0);
                        i--;
                    }
                    al_flip_display();
                }
                al_flip_display();
                sleep(0.1);
                break;
            case 5: // interage com o item

                if(x>=310 && y>=200 && x<=560 && y<=245)// acha o item 1
                {
                    acharoseta(x,y);
                    sleep(1);
                }
                else if(x>=280 && y>=420 && x<=380 && y<=520 && itens[0]!=0)
                {
                    achanarmer(x,y);
                    sleep(1);
                }
                else
                {
                    al_draw_bitmap(parado[0],x,y,0);
                    sleep(0.1);//mantem 0.1 segundo parado se clicar no local errado
                    al_flip_display();
                }
                break;
            case 6:
                abrirbau();
                break;
            case 7:
            
                al_show_native_message_box(NULL, "Ajuda",
                "Setas movimentam", "",
                NULL, ALLEGRO_MESSAGEBOX_QUESTION);

                al_show_native_message_box(NULL, "Ajuda",
                "Enter interage", "",
                NULL, ALLEGRO_MESSAGEBOX_QUESTION);

                al_draw_bitmap(parado[0],x,y,0);
                al_flip_display();
             
            }
            
            tecla = 0;
        }
    al_flip_display();

    }

    //-----destruindo ponteiros para as variaveis--------
    al_destroy_bitmap(fundo);
    al_destroy_bitmap(cima[0]);
    al_destroy_bitmap(esquerda[0]);
    al_destroy_bitmap(direita[0]);
    al_destroy_bitmap(baixo[0]); 
    al_destroy_bitmap(cima[1]);
    al_destroy_bitmap(esquerda[1]);
    al_destroy_bitmap(direita[1]);
    al_destroy_bitmap(baixo[1]); 
    al_destroy_bitmap(parado[0]);
    al_destroy_sample_instance(inst_trilha);
    al_destroy_display(janela);
    al_destroy_event_queue(fila_eventos);
    al_destroy_sample(trilha);

    return 0;
}

 
int main(void)
{
    jogo();
}

int abrirbau()
{
    ALLEGRO_DISPLAY *bau = NULL;
    ALLEGRO_EVENT_QUEUE *evento_bau = NULL;
    bau = al_create_display(450,300);
    al_set_new_display_flags(ALLEGRO_NOFRAME);
    al_set_window_position(bau, 450,300);
    evento_bau = al_create_event_queue();
    al_register_event_source(evento_bau, al_get_display_event_source(bau));

    bool fechatela = false;

    while(!fechatela)
    {
        while(!al_is_event_queue_empty(evento_bau))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(evento_bau, &evento);
            if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                fechatela = true;
            }
            al_flip_display();
        }
    }
    al_destroy_display(bau);
    al_destroy_event_queue(evento_bau);
    
}

int acharoseta(int x,int y)
{
    al_draw_bitmap(parado[0],x,y,0);
    al_draw_bitmap(item[0],450,350,0);
    itens[0] = 1;
    al_flip_display();

    return 1;
}

int achanarmer(int x, int y)
{
    al_draw_bitmap(parado[0],x,y,0);
    al_draw_bitmap(item[1],450,350,0);
    itens[1] = 1;
    al_flip_display();

    return 1;
}
    
 //metodo para inicializacao
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
 
    fundo = al_load_bitmap("fundojogo.png");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    esquerda[0] = al_load_bitmap("esquerda1.png");
    if (!esquerda[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        return false;
    }
    esquerda[1] = al_load_bitmap("esquerda2.png");
    if (!esquerda[1])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        return false;
    }
    direita[0] = al_load_bitmap("direita1.png");
    if (!direita[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(esquerda[1]);
        return false;
    }
    direita[1] = al_load_bitmap("direita2.png");
    if (!direita[1])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(esquerda[1]);
        return false;
    }
    cima[0] = al_load_bitmap("cima1.png");
    if (!cima[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        return false;
    }
    cima[1] = al_load_bitmap("cima2.png");
    if (!cima[1])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        return false;
    }
    baixo[0] = al_load_bitmap("baixo1.png");
    if (!baixo[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        return false;
    }
    baixo[1] = al_load_bitmap("baixo2.png");
    if (!baixo[1])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        return false;
    }
    if (!al_install_audio())
    {
        fprintf(stderr, "Falha ao inicializar áudio.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        return false;
    }

    if (!al_init_acodec_addon())
    {
        fprintf(stderr, "Falha ao inicializar codec de audio.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        return false;
    }

    if (!al_reserve_samples(5))
    {
        fprintf(stderr, "falha ao inicializar a reserva de samples.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        return false;
    }

    trilha = al_load_sample("mus.ogg");
    if (!trilha)
    {
        fprintf(stderr, "falha ao inicializar a trilha.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        return false;
    }

    inst_trilha = al_create_sample_instance(trilha);
    if (!inst_trilha)
    {
        fprintf(stderr, "falha ao inicializar a trilha sonora.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_sample(trilha);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        al_destroy_sample(trilha);
        return false;
    }
    parado[0]= al_load_bitmap("parado.png");
    if (!parado[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);   
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        al_destroy_sample(trilha);
        al_destroy_sample_instance(inst_trilha);
        return false;
    }
    item[0]= al_load_bitmap("frag_roseta.png");
    if (!item[0])
    {
        fprintf(stderr, "Falha ao carregar itens de jogo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);   
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        al_destroy_sample(trilha);
        al_destroy_sample_instance(inst_trilha);
        al_destroy_bitmap(parado[0]);
        return false;
    }
    item[1]= al_load_bitmap("Narmer.png");
    if (!item[1])
    {
        fprintf(stderr, "Falha ao carregar itens de jogo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        al_destroy_bitmap(direita[0]);
        al_destroy_bitmap(esquerda[1]);   
        al_destroy_bitmap(direita[1]);
        al_destroy_bitmap(cima[0]);
        al_destroy_bitmap(cima[1]);
        al_destroy_bitmap(baixo[0]);
        al_destroy_bitmap(baixo[1]);
        al_destroy_sample(trilha);
        al_destroy_sample_instance(inst_trilha);
        al_destroy_bitmap(parado[0]);
        al_destroy_bitmap(item[0]);
        return false;
    }

    //-----funções para o inicio do jogo------

    al_attach_sample_instance_to_mixer(inst_trilha, al_get_default_mixer());//alocando o musica em um mixer padrão(Ubuntu)
    al_set_sample_instance_playmode(inst_trilha, ALLEGRO_PLAYMODE_LOOP);//loop para a musica.
    al_set_sample_instance_gain(inst_trilha, 0.3);//volume da musica de fundo.

 
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}
