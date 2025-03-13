/*
 * Slavomir Svorada
 * xsvora02
 * 30.11.2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ERROR -1

typedef struct {
	int rows;
	int cols;
	unsigned char *cells;
	} Map;

bool isborder(Map *map, int r, int c, int border);
int start_border(Map *map, int r, int c, int leftright);


int main(int argc, char *argv[])
{
	if (argc == 2)
	{
		if (strstr(argv[1],"--help") != 0)
		{
			fprintf(stderr, "* --test pouze zkontroluje, že soubor daný druhým argumentem programu obsahuje řádnou definici mapy bludiště.\n   "
                            "V případě, že formát obrázku odpovídá definici (viz níže), vytiskne Valid.\n   V opačném případě (např. ilegálních znaků, chybějících údajů nebo špatných hodnot) program tiskne Invalid.\n\n"
                            "* --rpath hledá průchod bludištěm na vstupu na řádku R a sloupci C.\n   Průchod hledá pomocí pravidla pravé ruky (pravá ruka vždy na zdi).\n\n"
                            "* --lpath hledá průchod bludištěm na vstupu na řádku R a sloupci C, ale za pomoci pravidla levé ruky.\n\n"
                            "* --shortest (prémiové řešení) hledá nejkratší cestu z bludiště při vstupu na řádku R a sloupci C.\n");
			return ERROR;
		}
	}
	if (argc == 3)
    {
	    if (strstr(argv[1], "--test") != 0)
        {
	        FILE *f;
	        f = fopen(argv[2], "r");
	        if (f == NULL)
            {
	            fprintf(stderr, "Nepodarilo sa otvorit subor.\n");
                return ERROR;
            }
        }
    }
	return 0;
}









