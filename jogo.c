#include <stdio.h>
#include <allegro.h>

int main()
{
  allegro_init();
  install_timer();
  install_keyboard();
  set_color_depth(32);
  set_gfx_model(GFX_AUTODETECT_WINDOWED, 900, 700, 0, 0);
  set_window_title("Projeto Pyongyang");
  
  while(!key[KEY_ESC])
  {
    
    
    
  }
  return 0;
}
 END_OF_MAIN();
