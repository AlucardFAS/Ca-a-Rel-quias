#include "inicializar.h"
#include <stdio.h>
 

int itens[5] = {0,0,0,0,0};
 
bool iniciar();
int acharoseta(int x, int y);
int achanarmer(int x, int y);
int abrirbau(int x, int y);
//int nivel_grecia();

int jogo(int x, int y)
{

	bool sair = false;
	int tecla = 0;
    int i=0;

    while (!sair)
    {
    	
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
            case 6: // abre o bau
                abrirbau(x,y);
                break;
            case 7: // caixas de dialogo HELP
            
                al_show_native_message_box(NULL, "Ajuda",
                "Setas movimentam", "",
                NULL, ALLEGRO_MESSAGEBOX_QUESTION);

                al_show_native_message_box(NULL, "Ajuda",
                "Enter interage", "",
                NULL, ALLEGRO_MESSAGEBOX_QUESTION);

                al_draw_bitmap(parado[0],x,y,0);
                al_flip_display();
                break;
            case 8:
            	al_draw_bitmap(livro,0,0,0);
                al_flip_display();             
                break;
            case 9:
            	al_draw_bitmap(parado[0],x,y,0);
            	if(itens[0]!=0)
            	{
            		al_draw_bitmap(desc[0],0,0,0);
            	}
            	al_flip_display();
            	break;
            }


         	tecla = 0;
            //nivel_grecia();

        }

    al_flip_display();
    	

    }
    return 0;
}
 
int main(void)
{
	
    
 
    if (!iniciar())
    {
        return -1;
    }
 
    al_draw_bitmap(fundo, 0, 0, 0);
    int x=450,y=350;
    
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
    al_destroy_bitmap(item[0]);
    al_destroy_bitmap(item[1]);
    al_destroy_bitmap(im_item);
    al_destroy_bitmap(bau[0]);
    al_destroy_bitmap(bau[1]);
    al_destroy_bitmap(bau[2]);
    al_destroy_bitmap(bau[3]);
    al_destroy_bitmap(bau[4]);
    al_destroy_bitmap(bau[5]);
    al_destroy_bitmap(livro);
    al_destroy_bitmap(desc[0]);

}

int abrirbau(int x, int y)
{
    if (itens[0]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[0],300,200,0);
        al_flip_display();
    }
    else if (itens[0]!=0 && itens[1]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[1],300,200,0);
        al_flip_display();    
    }
    else if (itens[1]!=0 && itens[2]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[2],300,200,0);
        al_flip_display();
    }
    else if (itens[2]!=0 && itens[3]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[3],300,200,0);
        al_flip_display();
    }
    else if (itens[3]!=0 && itens[4]==0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[4],300,200,0);
        al_flip_display();
    }
    else if (itens[4]!=0)
    {
        al_draw_bitmap(parado[0],x,y,0);
        al_draw_bitmap(bau[5],300,200,0);
        al_flip_display();
    }
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

/*int nivel_grecia()
{
    if (itens[1]!= 0)  
    {
        al_draw_bitmap(fundo, 0, 0, 0);
        al_draw_bitmap(esquerda[0], 30, 3, 0);
        al_draw_bitmap(direita[1], 3, 30, 0);
        al_flip_display();
    }
}*/

