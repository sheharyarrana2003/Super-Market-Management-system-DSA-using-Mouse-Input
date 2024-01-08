#include"Classes.h"
int main() {
    int x = 130, y = 5;
    int height = 3, width = 25;
    int xCenter = 5;
    int xMid = (x - width) / 2;
    int yMid = (y - height) / 2;
    int bheight = yMid + height / 2;
    int bwidth = (xMid - xCenter) + width / 2;
    Boards b(xMid, yMid, height, width, bwidth, bheight);
    b.MainMenu(bwidth, bheight, xMid, yMid, height, width);
    return 0;
}