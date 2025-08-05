#include "terstys.h"


static inline void buff_check(char *buffer, size_t buf_size){
    memset(buffer, 0, buf_size);
    assert(buf_size >= 0x10);  
}

char *bg_256_color(int value, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert(value >= 0 && value <= 255);
    sprintf(buffer, "\033[48;5;%dm", value);
    return buffer;
}
char *fg_256_color(int value, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert(value >= 0 && value <= 255);
    sprintf(buffer, "\033[38;5;%dm", value);
    return buffer;
}
char *fg_true_color(int r, int g, int b, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
    sprintf(buffer, "\033[38;2;%d;%d;%dm", r, g, b);
    return buffer;
}
char *bg_true_color(int r, int g, int b, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert(r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255);
    sprintf(buffer, "\033[48;2;%d;%d;%dm", r, g, b);
    return buffer;
}

char *bg_color(int value, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert((value >= 40 && value <= 47) || value == 49);
    sprintf(buffer, "\033[%dm", value);
    return buffer;
}
char *fg_color(int value, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert((value >= 30 && value <= 37) || value == 39);
    sprintf(buffer, "\033[%dm", value);
    return buffer;

}
char *text_style(int value, char *buffer, size_t buf_size){
    buff_check(buffer, buf_size);
    assert((value >= 1 && value <= 5) || value == 8);
    sprintf(buffer, "\033[%dm", value);
    return buffer;

}

void test_256_colors() {
    for (int i = 0; i < 256; i++) {
        printf("\033[48;5;%dm %3d ", i, i);
        if ((i + 1) % 0x10 == 0) printf("\033[0m\n");
    }
    printf("\033[0m\n");
}

void color_panel(int interval) {
    assert(interval >= 0 && interval <= 255);
    for (int r = 0; r <= 255; r += interval) {
        for (int g = 0; g <= 255; g += interval) {
            for (int b = 0; b <= 255; b += interval) {
                printf("\033[48;2;%d;%d;%dm%3d %3d %3d \033[0m ", r, g, b, r ,g ,b);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void test_truecolor(int value) {
    color_panel(value);
}
