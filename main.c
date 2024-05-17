#include <stdio.h>
#include <sys/ioctl.h> // Needed for ioctl() inside getTerminalSize
#include <unistd.h> // Needed for STDOUT_FILENO inside getTerminalSize
#include <stdlib.h>

int terminalHeight = 0; // For getTerminalSize
int terminalWidth = 0;  // For getTerminalSize

void getTerminalSize(int* rows, int* cols)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *rows = w.ws_row;
    *cols = w.ws_col;
}




void drawScrn() {
        int mao = 1;
        while(mao < 2) {
        mao++;
        getTerminalSize(&terminalHeight, &terminalWidth);
        int terminalContent [terminalWidth][terminalHeight];

        //printf("tw: %d h: %d", terminalWidth, terminalHeight);

        for (int x = 0; x < terminalWidth; x++){
            for (int y = 0; y < terminalHeight; y++) {
                terminalContent[x][y] = 0;
                //printf("debug x: %d, y: %d\n",x ,y);
            }
        }

        for (int x = 0; x < terminalWidth; x++){
            //printf("debug2: x: %d\n", x);
            for (int y = 0; y < terminalHeight; y++) {
                //printf("tc: %d\n", terminalContent[x][y]);
                 switch (terminalContent[x][y]) {
                     case 0:
                         printf(" ");
                         break;
                     case 1:
                         printf(".");
                         break;
                     default:
                         printf("?");
                 }

            }
        }
        //system("clear");
    }
}


int main() {

    drawScrn();

    return 0;
}
