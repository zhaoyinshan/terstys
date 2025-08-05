#include "terstys/terstys.h"
#include <cstddef>
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    char buf[256];
    test_truecolor(40);
    test_256_colors();
    char s[] = "This is a cpp-example using terstys.";
    for(size_t i = 0; i < sizeof(s); i++){
        std::cout << bg_true_color(10 * i % 256, 20 * i % 256, 30 * i % 256, buf, 256) << s[i] << RESET_ALL;
    }
    std::cout << std::endl << std::endl;
    std::cout << BG_TRUE_COLOR(255, 0, 0) << "Hello World!" << RESET_ALL << ' ';
    std::cout << BG_256_COLOR(200) << "Hello World!" << RESET_ALL << ' ';
    std::cout << bg_256_color(150, buf, 256) << "Hello World!" << RESET_ALL << ' ';

    std::cout << TXT_BOLD << TXT_ITALIC << "Hello World!" << RESET_ALL << ' ';
    std::cout << FG_TRUE_COLOR(0, 255, 128) << "Hello World!" << RESET_ALL << ' ';

    std::cout << fg_true_color(50, 150, 50, buf, 256) << "Hello World!" << RESET_ALL << std::endl;
    return 0;
}