#ifndef BUSCA_H
#define BUSCA_H

typedef struct
{
    int indice;
    long long inspecoes;
} ResultadoBusca;

ResultadoBusca busca_sequencial(const int v[], int n, int chave);

ResultadoBusca busca_binaria_recursiva(const int v[], int inicio, int fim,
                                       int chave);

// #########################
// Macros para cores de logs
// #########################

/* Reset de formatação */
#define COLOR_RESET "\033[0m"

/* Estilos de texto */
#define STYLE_BOLD "\033[1m"
#define STYLE_DIM "\033[2m"
#define STYLE_ITALIC "\033[3m"
#define STYLE_UNDERLINE "\033[4m"
#define STYLE_BLINK "\033[5m"

/* Cores da fonte (Foreground) */
#define FONT_BLACK "\033[30m"
#define FONT_RED "\033[31m"
#define FONT_GREEN "\033[32m"
#define FONT_YELLOW "\033[33m"
#define FONT_BLUE "\033[34m"
#define FONT_MAGENTA "\033[35m"
#define FONT_CYAN "\033[36m"
#define FONT_WHITE "\033[37m"

/* Cores Claras/Brilhantes (Foreground) */
#define FONT_GRAY "\033[90m"
#define FONT_LIGHT_RED "\033[91m"
#define FONT_LIGHT_GREEN "\033[92m"
#define FONT_LIGHT_YELLOW "\033[93m"
#define FONT_LIGHT_BLUE "\033[94m"
#define FONT_LIGHT_MAGENTA "\033[95m"
#define FONT_LIGHT_CYAN "\033[96m"

/* RGB Customizado (Foreground) */
#define FONT_ORANGE "\033[38;2;255;165;0m"

/* Cores de fundo (Background) */
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

/* Cores de Fundo Claras */
#define BG_GRAY "\033[100m"
#define BG_LIGHT_RED "\033[101m"

/* RGB Customizado (Background) */
#define BG_ORANGE "\033[48;2;255;165;0m"

#endif
