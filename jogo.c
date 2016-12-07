#include "inicializar.h"
#include <stdio.h>
 
//-----variaveis globais-------
int itens[5] = {0,0,0,0,0};
int controle_fecha_jogo = 0;
int controle_mantem_aberto = 1;

//----funções usados dentro da função jogo()-------
bool iniciar();
int abrirbau(int x, int y);
int fecha_teste();
int acharitem(int x, int y);

//------funções usadas no main-----

int historia()//carrega 4 imagem, 3 sobre a historia do persongem e 1 ẽ a tela de inico
{
    for (int j = 0; j < 3; j++)
    {
        al_draw_bitmap(hist[j],0,0,0);
        al_flip_display();
        sleep(10);
    }
        al_draw_bitmap(tela_inicio, 0,0,0);
        sleep(1);
    return 0;
}

int jogo(int x, int y)//jogo completo
{
    bool sair = false;
    int tecla = 0;
    int i=0;
    int condicao = 0;

    while (!sair)//condição para o fechamneto do jogo
    {
        fecha_teste();
        al_play_sample_instance(inst_trilha);//toca musica até o jogo ser fechado


        while(!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
 
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
                case ALLEGRO_KEY_L:
                    tecla = 8;
                    break;
                case ALLEGRO_KEY_1:
                    tecla = 9;
                    break;
                case ALLEGRO_KEY_2:
                    tecla = 10;
                    break;
                case ALLEGRO_KEY_3:
                    tecla = 11;
                    break;
                case ALLEGRO_KEY_4:
                    tecla = 12;
                    break;
                case ALLEGRO_KEY_5:
                    tecla = 13;
                    break; 
                /*case ALLEGRO_KEY_R:
                    tecla = 14;
                    break;*/
                }
            }

            else if (itens[4]!=0 && controle_fecha_jogo == 1 || 
                evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                sair = true;
            }
        }


        if (tecla)
        {
            al_draw_bitmap(fundo, 0, 0, 0);
            if (controle_mantem_aberto == 0)//if de controle para manter o bitmap que fecha o jogo desenhado.
            {
                al_draw_bitmap(fundo,0,0,0);
                al_draw_bitmap(porta_final,0,0,0);
                al_flip_display();
            }

            switch (tecla)
            {
            case 1: // movimenta o personagem para cima
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
                else if(y<=150)
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
            case 2: // movimenta o personagem para baixo
                if(y>=540 && x<=320)
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
                else if (y>=630)
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
            case 3: // movimenta o personagem para esquerda
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
                else if (x<=320 && y>=550)
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
            case 4: // movimenta o personagem para direita
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
            case 5: // interação do jogo

                if(x>=310 && y>=160 && x<=560 && y<=245)//item 1
                {
                    if (itens[0]==0)
                    {
                        acharitem(x,y);
                    }
                    al_draw_bitmap(parado[0],x,y,0);
                    itens[0] = 1;
                    al_flip_display();
                }
                else if(x>=200 && y>=420 && x<=380 && y<=520 && itens[0]!=0)//item 2
                {
                    if (itens[1]==0)
                    {
                        acharitem(x,y);
                    }
                    al_draw_bitmap(parado[0],x,y,0);
                    itens[1] = 1;
                    al_flip_display();
                }
                else if (x>=350 && y<=155 && itens[0]!=0 && itens[1]!=0)//item 3
                {
                    if (itens[2]==0)
                    {
                        acharitem(x,y);
                    }
                    al_draw_bitmap(parado[0],x,y,0);
                    itens[2] = 1;
                    al_flip_display();
                }
                else if (x>=530 && y>=500 && y<=550 
                && x<=600 && itens[0]!=0 && itens[1]!=0 && itens[2]!=0)//item 4
                {
                    if (itens[3]==0)
                    {
                        acharitem(x,y);
                    }
                    al_draw_bitmap(parado[0],x,y,0);
                    itens[3] = 1;
                    al_flip_display();
                }
                else if (x>=50 && x<=100 && y<=420 && y>=380 
                && itens[0]!=0 && itens[1]!=0 && itens[2]!=0 && itens[3]!=0)//item 5
                {
                    if (itens[4]==0)
                    {
                        acharitem(x,y);
                    }
                    al_draw_bitmap(parado[0],x,y,0);
                    itens[4] = 1;
                    al_flip_display();
                }
                else if (x>=400 && x<=500 && y>=500 
                && y<=600 && itens[0]!=0 && itens[1]!=0 
                && itens[2]!=0 && itens[3]!=0 && itens[4]!=0)//desenha o bitmap que fecha o jogo
                {
                    controle_mantem_aberto = 0;
                    al_draw_bitmap(porta_final,0,0,0);
                    al_draw_bitmap(parado[0],x,y,0);
                    al_flip_display();
                }
                else if (x>=420 && y>=350 && x<=480 
                    && itens[0]!=0 && itens[1]!=0 && itens[2]!=0 
                    && itens[3]!=0 && itens[4]!=0 && controle_mantem_aberto!=1)//fecha o jogo
                {
                    controle_fecha_jogo = 1;
                }
                else
                {
                    al_draw_bitmap(parado[0],x,y,0);
                    sleep(0.1);//mantem 0.1 segundo parado se clicar no local errado
                    al_flip_display();
                    if (condicao==0)//logica para colocar a ajuda quando iniciar o jogo
                    {
                        al_draw_bitmap(parado[0],x,y,0);
                        al_draw_bitmap(help,0,0,0);
                        al_flip_display();
                        condicao =1;
                    }
                }
                break;
            case 6: // abre o bau
                abrirbau(x,y);
                break;
            case 7: // HELP
                
                al_draw_bitmap(parado[0],x,y,0);
                al_draw_bitmap(help,0,0,0);
                al_flip_display();
                break;
            case 8: // Descrição do jogo e dica do 1 item
                al_draw_bitmap(livro,0,0,0);
                al_flip_display();             
                break;
            case 9: // Descrição dos itens 
                al_draw_bitmap(parado[0],x,y,0);
                if(itens[0]!=0)
                {
                    al_draw_bitmap(desc[0],0,0,0);
                }
                al_flip_display();
                break;
            case 10:// Descrição dos itens
                al_draw_bitmap(parado[0],x,y,0);
                if(itens[1]!=0)
                {
                    al_draw_bitmap(desc[1],0,0,0);
                }
                al_flip_display();
                break;
            case 11:// Descrição dos itens
                al_draw_bitmap(parado[0],x,y,0);
                if(itens[2]!=0)
                {
                    al_draw_bitmap(desc[2],0,0,0);
                }
                al_flip_display();
                break;
            case 12:// Descrição dos itens
                al_draw_bitmap(parado[0],x,y,0);
                if(itens[3]!=0)
                {
                    al_draw_bitmap(desc[3],0,0,0);
                }
                al_flip_display();
                break;
            case 13:// Descrição dos itens
                al_draw_bitmap(parado[0],x,y,0);
                if(itens[4]!=0)
                {
                    al_draw_bitmap(desc[4],0,0,0);
                }
                al_flip_display();
                break;
            /*case 14:

                itens[5]= (0,0,0,0,0);
                break;*/
            }

            tecla = 0;
            

        }

    al_flip_display();
        

    }
    return 0;
}
 
int main(void)
{
    
    if (!iniciar())//inicia o header com imagens, musica, fila de eventos e a janela
    {
        return -1;
    }
 
    al_draw_bitmap(fundo, 0, 0, 0);
    int x=450,y=350;
    
    historia();

    jogo(x, y);





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
    al_destroy_bitmap(hist[2]);
    al_destroy_bitmap(tela_inicio);

}

int abrirbau(int x, int y)//função da tecla B do jogo
{
    if (itens[0]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[0],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();
    }
    else if (itens[0]!=0 && itens[1]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[1],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();    
    }
    else if (itens[1]!=0 && itens[2]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[2],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();
    }
    else if (itens[2]!=0 && itens[3]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[3],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();
    }
    else if (itens[3]!=0 && itens[4]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[4],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();
    }
    else if (itens[4]!=0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[5],300,200,0);
        al_draw_bitmap(guia_itens,0,550,0);
        al_flip_display();
    }
}

int acharitem(int x, int y)// caixa de dialogo para quando o item é encontrado
{
    al_show_native_message_box(NULL, "",
    "Você achou um item!", "",
    NULL, ALLEGRO_MESSAGEBOX_QUESTION);
    al_show_native_message_box(NULL, "",
    "Pressione 'B' para informações sobre o item.", "",
    NULL, ALLEGRO_MESSAGEBOX_QUESTION);
}

int fecha_teste()//função para testar se o jogo pode fechar
{

    if (itens[4]!= 0 && controle_fecha_jogo ==1)  
    {
        al_show_native_message_box(NULL, "",
        "Parabéns, você concluiu o jogo!", "",
        NULL, ALLEGRO_MESSAGEBOX_QUESTION);

        /*al_show_native_message_box(NULL, "",
        "Para recomeçar o jogo, pressione 'R'!", "",
        NULL, ALLEGRO_MESSAGEBOX_QUESTION);*/
    }
    return 0;
}
