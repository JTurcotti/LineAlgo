#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int abs(int a) {
  return a >= 0? a: -1 * a;
}

void draw_shallow(int x0, int y0, int x1, int y1, screen s, color c) {
  int dx = x1 - x0;

  //ternary operators account for both positive and negative slopes
  int dy = abs(y0 - y1);
  int ddy =  (y1 >= y0)? 1: -1;
	    
  int line_sum = 2 * dy - dx;
  int y = y0;

  int x = x0 - 1;
  while (++x <= x1) {
    plot(s, c, x, y);

    if (line_sum > 0) {
      y += ddy;
      line_sum -= 2 * dx;
    }

    line_sum += 2 * dy;
  }
}

void draw_steep(int x0, int y0, int x1, int y1, screen s, color c) {
  //x and y switched from abovex
  int dx = abs(x0 - x1);
  int dy = y1 - y0;
  int ddx = (x1 >= x0)? 1: -1;
	    
  int line_sum = 2 * dx - dy;
  int x = x0;

  int y = y0 - 1;
  while (++y <= y1) {
    plot(s, c, x, y);
    
    if (line_sum > 0) {
      x += ddx;
      line_sum -= 2 * dy;
    }
    
    line_sum += 2 * dx;
  }
}

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x1 < x0) {
    int temp = x1;
    x1 = x0;
    x0 = temp;
  }

  if (y1 < y0) {
    int temp = y1;
    y1 = y0;
    y0 = temp;
  }
  
  if (abs(y1 - y0) < abs(x1 - x0))
    draw_shallow(x0, y0, x1, y1, s, c);
  else
    draw_steep(x0, y0, x1, y1, s, c);
}
