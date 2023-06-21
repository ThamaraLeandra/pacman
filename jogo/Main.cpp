#include <stdio.h>
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "Objeto.h"
#include <allegro5/allegro_native_dialog.h>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 570;
const int SCREEN_H = 570;

int main(int argc, char **argv)
{


 ALLEGRO_DISPLAY *display = NULL; //Tela

   if(!al_init()) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o Allegro",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   if(!al_init_image_addon()) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o al_init_image_addon!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }

   //Cria uma tela com essas dimensoes
   display = al_create_display(SCREEN_H,SCREEN_W);

   if(!display) {
      al_show_native_message_box(display, "Error", "Error", "Falha ao iniciar o display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
      return 0;
   }
// matriz
    int matriz[19][19] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                         {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
                         {0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0},
                         {0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
                         {0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0},
                         {0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0},
                         {0,1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0},
                         {0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
                         {0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,1,1,0},
                         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};



   ALLEGRO_BITMAP *brick, *pill;

   int pos_x = 0;
   int pos_y = 0;
   //Carrega a Imagem
    brick = al_load_bitmap("brickbg.png");
   pill = al_load_bitmap("pill.png");
   if(!brick || !pill) {
      fprintf(stderr, "failed to create bitmap!\n");
      al_destroy_display(display);

      return -1;
   }

    int pixel_x,pixel_y = 0;
   for (pos_x = 0; pos_x < 19; pos_x ++) {
        for (pos_y = 0; pos_y < 19; pos_y ++) {

             if (matriz[pos_x][pos_y] == 0) {
                al_draw_bitmap_region(brick, 0, 0, 30, 30, pixel_y, pixel_x, 0);
             } else {
                al_draw_bitmap_region(pill, 0, 0, 30, 30, pixel_y, pixel_x, 0);
             }
             pixel_y = pixel_y + 30;

        }
        pixel_y = 0;
        pixel_x = pixel_x + 30;

   }




   al_flip_display();//Atualiza o Buffer da Tela

   al_rest(30); //Tempo que a tela fica ativa (em segundos)

   al_destroy_display(display); //Destroi a tela
   al_destroy_bitmap(brick);
    al_destroy_bitmap(pill); //Destroi a imagem




   return 0;
}
