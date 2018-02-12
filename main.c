#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = 0;
  c.blue = 0;

  clear_screen(s);
  
  int x = 500;
  int y = 0;

  while (y++ < 499 && x-- > 1) {
    c.red = MAX_COLOR * ((x+y) / 600.0);
    c.green = MAX_COLOR * (x / 600.0);
    c.blue = MAX_COLOR * (y / 600.0);

    draw_line(0, y, x, 0, s, c);
  }

  
  //display(s);
  save_extension(s, "lines.png");
}
