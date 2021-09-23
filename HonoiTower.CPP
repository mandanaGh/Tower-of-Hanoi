#include <graphics.h>

#include <conio.h>

#include <iostream.h>

#include <dos.h>

#define max 7

class tower {
  public:
    int x;
  int stack[max];
  int tos;
  tower() {
    tos = 0;
  }
  void push(int i);
  int pop();
};
//************************************
void tower::push(int i) {
  stack[tos] = i;
  tos++;
}
//************************************
int tower::pop() {
  tos--;
  return stack[tos];
}
//************************************
void honoi(tower * A, tower * B, tower * C, int n);
void move(tower * , tower * );

int main(void) {
  int i, x, y, x1, n;
  clrscr();
  cout << "Enter the number of disks to be moved(n<=7):";
  cin >> n;

  int driver, mode;
  driver = DETECT;
  mode = 0;
  initgraph( & driver, & mode, "c:\\tc\\bgi");

  tower a, b, c;
  a.x = 150;
  b.x = 300;
  c.x = 450;
  for (i = 1; i <= n; i++)
    a.push(i);
  setbkcolor(BLUE);
  setcolor(WHITE);
  setlinestyle(0, 0, 3);
  line(150, 150, 150, 420);
  line(300, 150, 300, 420);
  line(450, 150, 450, 420);

  setlinestyle(0, 0, 0);
  rectangle(100, 421, 502, 440);
  setfillstyle(SOLID_FILL, BROWN);
  floodfill(200, 425, WHITE);

  setcolor(LIGHTGREEN);
  for (i = 1; i <= n; i++) {
    x = 95 + (i * 5);
    x1 = 205 - (i * 5);
    y = 420 - (i * 20);
    rectangle(x, y, x1, y + 19);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(150, y + 10, LIGHTGREEN);
  }
  honoi( & a, & b, & c, n);
  getch();
  restorecrtmode();
  return 0;
}
//***********************************************
void honoi(tower * A, tower * B, tower * C, int n) {
  if (n == 1) move(A, C);
  else {
    honoi(A, C, B, n - 1);
    move(A, C);
    honoi(B, A, C, n - 1);
  }
}
//*************************************************
void move(tower * m, tower * n) {
  int i, a, b, c, d, x, x1, y;

  c = m -> tos;
  a = m -> pop();
  b = m -> x;
  d = n -> x;
  x = b - 55 + (a * 5);
  x1 = b + 55 - (a * 5);
  y = 420 - (c * 20);
  for (i = y - 2; i >= 129; i--) {
    setcolor(GREEN);
    rectangle(x, i, x1, i + 18);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(x + 5, i + 10, GREEN);
    delay(10);

    setcolor(BLUE);
    if (y == 400) rectangle(x, i, x1, i + 21);
    else rectangle(x, i, x1, i + 20);
    setfillstyle(SOLID_FILL, BLUE);
    floodfill(x + 5, i + 10, BLUE);

    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    line(b, i + 21, b, y + 20);
  }

  setlinestyle(0, 0, 0);
  if (m -> x < n -> x)
    for (i = x + 1; i <= d - 55 + (a * 5); i++) {
      setcolor(GREEN);
      rectangle(i, 129, i + 100 - (2 * (a - 1) * 5), 149);
      setfillstyle(SOLID_FILL, GREEN);
      floodfill(i + 5, 140, GREEN);
      delay(10);

      setcolor(BLUE);
      rectangle(i - 1, 129, i + 99 - (2 * (a - 1) * 5), 149);
      setfillstyle(SOLID_FILL, BLUE);
      floodfill(i + 5, 140, BLUE);
    }

  if (m -> x > n -> x)
    for (i = x - 1; i >= d - 55 + (a * 5); i--) {
      setcolor(GREEN);
      rectangle(i, 129, i + 100 - (2 * (a - 1) * 5), 149);
      setfillstyle(SOLID_FILL, GREEN);
      floodfill(i + 5, 140, GREEN);
      delay(10);
      setcolor(BLACK);
      rectangle(i + 1, 129, i + 101 - (2 * (a - 1) * 5), 149);
      setfillstyle(SOLID_FILL, BLACK);
      floodfill(i + 5, 140, BLACK);
    }
  c = n -> tos;
  x = d - 55 + (a * 5);
  x1 = d + 55 - (a * 5);
  y = 420 - (c * 20);

  for (i = 130; i <= y - 20; i++) {

    setcolor(GREEN);
    rectangle(x, i, x1, i + 19);
    setfillstyle(SOLID_FILL, GREEN);
    floodfill(x + 5, i + 10, GREEN);
    delay(10);

    setcolor(BLACK);
    rectangle(x, i - 1, x1, i + 19);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(x + 5, i + 10, BLACK);
    setcolor(WHITE);
    setlinestyle(0, 0, 3);
    if (i >= 150) line(d, 150, d, i);
  }
  setcolor(GREEN);
  rectangle(x, i - 1, x1, i + 18);
  setfillstyle(SOLID_FILL, GREEN);
  floodfill(x + 5, i + 10, GREEN);

  n -> push(a);
}