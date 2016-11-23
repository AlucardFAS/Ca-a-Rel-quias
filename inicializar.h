#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_acodec.h>
#include <stdbool.h>
#include <stdio.h>

const int LARGURA_T = 900;
const int ALTURA_T = 700;

ALLEGRO_DISPLAY *janela = NULL;
ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
ALLEGRO_BITMAP *fundo = NULL;
ALLEGRO_BITMAP *cima[2];
ALLEGRO_BITMAP *baixo[2];
ALLEGRO_BITMAP *esquerda[2];
ALLEGRO_BITMAP *direita[2];
ALLEGRO_SAMPLE *trilha = NULL;
ALLEGRO_BITMAP *parado[1];
ALLEGRO_BITMAP *bau[6];
ALLEGRO_SAMPLE_INSTANCE *inst_trilha = NULL;
ALLEGRO_BITMAP *livro = NULL;
ALLEGRO_BITMAP *desc[5];
ALLEGRO_BITMAP *hist[3];

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
 
    fundo = al_load_bitmap("itensfundos/fundojogo.png");
    if (!fundo)
    {
        fprintf(stderr, "Falha ao carregar imagem de fundo.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        return false;
    }
    esquerda[0] = al_load_bitmap("img Personagem/esquerda1.png");
    if (!esquerda[0])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        return false;
    }
    esquerda[1] = al_load_bitmap("img Personagem/esquerda2.png");
    if (!esquerda[1])
    {
        fprintf(stderr, "Falha ao carregar personagem.\n");
        al_destroy_display(janela);
        al_destroy_event_queue(fila_eventos);
        al_destroy_bitmap(fundo);
        al_destroy_bitmap(esquerda[0]);
        return false;
    }
    direita[0] = al_load_bitmap("img Personagem/direita1.png");
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
    direita[1] = al_load_bitmap("img Personagem/direita2.png");
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
    cima[0] = al_load_bitmap("img Personagem/cima1.png");
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
    cima[1] = al_load_bitmap("img Personagem/cima2.png");
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
    baixo[0] = al_load_bitmap("img Personagem/baixo1.png");
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
    baixo[1] = al_load_bitmap("img Personagem/baixo2.png");
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
    parado[0]= al_load_bitmap("img Personagem/parado.png");
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

    bau[0]= al_load_bitmap("img B itens/itemvazio.png");
    if (!bau[0])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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

    bau[1]= al_load_bitmap("img B itens/item1.png");
    if (!bau[1])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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
        al_destroy_bitmap(bau[0]);
        return false;
    }
    bau[2]= al_load_bitmap("img B itens/item2.png");
    if (!bau[2])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        return false;
    }
    bau[3]= al_load_bitmap("img B itens/item3.png");
    if (!bau[3])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        return false;
    }
    bau[4]= al_load_bitmap("img B itens/item4.png");
    if (!bau[4])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        return false;
    }
    bau[5]= al_load_bitmap("img B itens/item5.png");
    if (!bau[5])
    {
        fprintf(stderr, "Falha ao carregar itens do bau.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        return false;
    }
    livro= al_load_bitmap("img L desc/tLivro.png");
    if (!livro)
    {
        fprintf(stderr, "Falha ao carregar livro.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        return false;
    }
    desc[0]= al_load_bitmap("img L desc/tRos.png");
    if (!desc[0])
    {
        fprintf(stderr, "Falha ao carregar descrição.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        return false;
    }
    desc[1] = al_load_bitmap("img L desc/tPaleta.png");
    if (!desc[1])
    {
        fprintf(stderr, "Falha ao carregar descrição.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);   
    }
    desc[2] = al_load_bitmap("img L desc/tFarao.png");
    if (!desc[2])
    {
        fprintf(stderr, "Falha ao carregar descrição.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]);  
    }
    desc[3] = al_load_bitmap("img L desc/tHorus.png");
    if (!desc[3])
    {
        fprintf(stderr, "Falha ao carregar descrição.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]); 
        al_destroy_bitmap(desc[2]); 
    }
    desc[4] = al_load_bitmap("img L desc/tTyet.png");
    if (!desc[4])
    {
        fprintf(stderr, "Falha ao carregar descrição.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]); 
        al_destroy_bitmap(desc[2]);
        al_destroy_bitmap(desc[3]); 
    }
    hist[0]= al_load_bitmap("img L desc/tHistoria.png");
    if (!hist[0])
    {
        fprintf(stderr, "Falha ao carregar história1.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]); 
        al_destroy_bitmap(desc[2]);
        al_destroy_bitmap(desc[3]);
        al_destroy_bitmap(desc[4]);
        return false;
    }
    hist[1]= al_load_bitmap("img L desc/tTela1.png");
    if (!hist[1])
    {
        fprintf(stderr, "Falha ao carregar história2.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]); 
        al_destroy_bitmap(desc[2]);
        al_destroy_bitmap(desc[3]);
        al_destroy_bitmap(desc[4]);
        al_destroy_bitmap(hist[0]);
        return false;
    }
    hist[2]= al_load_bitmap("img L desc/tTela2.png");
    if (!hist[2])
    {
        fprintf(stderr, "Falha ao carregar história3.\n");
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
        al_destroy_bitmap(bau[0]);
        al_destroy_bitmap(bau[1]);
        al_destroy_bitmap(bau[2]);
        al_destroy_bitmap(bau[3]);
        al_destroy_bitmap(bau[4]);
        al_destroy_bitmap(bau[5]);
        al_destroy_bitmap(livro);
        al_destroy_bitmap(desc[0]);
        al_destroy_bitmap(desc[1]); 
        al_destroy_bitmap(desc[2]);
        al_destroy_bitmap(desc[3]);
        al_destroy_bitmap(desc[4]);
        al_destroy_bitmap(hist[0]);
        al_destroy_bitmap(hist[1]);
        return false;
    }


    //-----funções para o inicio do jogo------

    al_attach_sample_instance_to_mixer(inst_trilha, al_get_default_mixer());//alocando o musica em um mixer padrão(Ubuntu)
    al_set_sample_instance_playmode(inst_trilha, ALLEGRO_PLAYMODE_LOOP);//loop para a musica.
    al_set_sample_instance_gain(inst_trilha, 0.8);//volume da musica de fundo.

    al_set_window_position(janela, LARGURA_T, ALTURA_T);
    al_register_event_source(fila_eventos, al_get_keyboard_event_source());
    al_register_event_source(fila_eventos, al_get_display_event_source(janela));

    return true;
}
