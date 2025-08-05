#ifndef TERSTYS_H
#define TERSTYS_H
#include <string.h>
#include <assert.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef TERSTYS_EXPORTS
    #define TERSTYS_API __declspec(dllexport)
  #else
    #define TERSTYS_API __declspec(dllimport)
  #endif
#else
  #define TERSTYS_API __attribute__((visibility("default")))
#endif

#define DEFINE_BG_COLOR(name, value) \
    static const char *BG_##name = "\033[" #value "m"

#define DEFINE_FG_COLOR(name, value) \
    static const char *FG_##name = "\033[" #value "m"

#define DEFINE_TEXT_STYLE(name, value) \
    static const char *TXT_##name = "\033[" #value "m"

#define FG_TRUE_COLOR(R, G, B)\
    "\033[38;2;" #R ";" #G ";" #B "m"

#define BG_TRUE_COLOR(R, G, B)\
    "\033[48;2;" #R ";" #G ";" #B "m"

#define BG_256_COLOR(value) \
    "\033[48;5;" #value "m"

#define FG_256_COLOR(value) \
    "\033[38;5;" #value "m"


DEFINE_BG_COLOR(BLACK,  40);
DEFINE_BG_COLOR(RED,    41);
DEFINE_BG_COLOR(GREEN,  42);
DEFINE_BG_COLOR(YELLOW, 43);
DEFINE_BG_COLOR(BLUE,   44);
DEFINE_BG_COLOR(MAGENTA,45);
DEFINE_BG_COLOR(CYAN,   46);
DEFINE_BG_COLOR(WHITE,  47);
DEFINE_BG_COLOR(RESET,  49);

DEFINE_FG_COLOR(BLACK,   30);
DEFINE_FG_COLOR(RED,     31);
DEFINE_FG_COLOR(GREEN,   32);
DEFINE_FG_COLOR(YELLOW,  33);
DEFINE_FG_COLOR(BLUE,    34);
DEFINE_FG_COLOR(MAGENTA, 35);
DEFINE_FG_COLOR(CYAN,    36);
DEFINE_FG_COLOR(WHITE,   37);
DEFINE_FG_COLOR(RESET,   39);

// text style
DEFINE_TEXT_STYLE(BOLD, 1);
DEFINE_TEXT_STYLE(DIM, 2);
DEFINE_TEXT_STYLE(ITALIC, 3);
DEFINE_TEXT_STYLE(UNDERLINE, 4);
DEFINE_TEXT_STYLE(BLINK, 5);
DEFINE_TEXT_STYLE(INVISABLE, 8);


TERSTYS_API char *bg_256_color(int value, char *buffer, size_t buf_size);
TERSTYS_API char *fg_256_color(int value, char *buffer, size_t buf_size);
TERSTYS_API char *fg_true_color(int r, int g, int b, char *buffer, size_t buf_size);
TERSTYS_API char *bg_true_color(int r, int g, int b, char *buffer, size_t buf_size);
TERSTYS_API 
TERSTYS_API char *bg_color(int value, char *buffer, size_t buf_size);
TERSTYS_API char *fg_color(int value, char *buffer, size_t buf_size);
TERSTYS_API char *text_style(int value, char *buffer, size_t buf_size);
TERSTYS_API 
TERSTYS_API void test_256_colors();
TERSTYS_API void test_truecolor(int value);
TERSTYS_API void color_panel(int interval);

#define RESET_ALL "\033[0m"
#define REVERSE_COLOR "\033[7m"


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TERSTYS_H