#include "terstys/terstys.h"
#include <stdio.h>

int main(){
    test_truecolor(40);
    test_256_colors();
    char s[] = "This is a c-example using terstys.";
    char buf[256];
    for(size_t i = 0; i < sizeof(s); i++){
        printf("%s%c%s",bg_true_color(10 * i % 256, 20 * i % 256, 30 * i % 256, buf, 256), s[i], RESET_ALL);
    }
    printf("\n");
    printf(
        "%s%sHello %sWorld!%s %s%sHello %sWorld!%s%s\n", 
        TXT_BOLD,
        BG_BLUE, 
        BG_RED, 
        BG_RESET,
        BG_GREEN,
        FG_YELLOW,
        BG_MAGENTA,
        BG_RESET,
        FG_RESET
    );
    printf(
        "%sconst %schar %s*restrict format, ...\n",
        TXT_BOLD,
        TXT_DIM,
        TXT_ITALIC
    );
    printf(
        "%sconst char %s*underline %sformat%s, ...\n",
        RESET_ALL,
        TXT_UNDERLINE,
        TXT_INVISABLE,
        RESET_ALL
    );
    return 0;
}