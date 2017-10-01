// Inicialitzar un array
int array[2][2] =
{
	{0, 1},
	{2, 4}
};

// Inicialitzar un struct
typedef struct my_data {
	int a;
	const char *name;
	double x;
} my_data;

my_data data[2] =
{
	{0, "Arnau", 3.2},
	{.name = "Lluís", .a = 3, .x = 0}
};

// Fer anar un enum
// https://stackoverflow.com/questions/3344721/how-to-use-enum-within-a-struct-in-ansi-c
// https://stackoverflow.com/questions/15079954/how-to-use-enum-in-c
enum status {CALL, WAIT};

struct SomeItem
{
	enum {MOVIE, MUSIC} itemType;	// Opció 1
	enum status my_status;		// Opció 2
};

// Extret de dmenu: https://tools.suckless.org/dmenu/
enum { SchemeNorm, SchemeSel, SchemeOut, SchemeLast };

char *colors[SchemeLast][2] = {
        /*     fg         bg       */
        [SchemeNorm] = { "#bbbbbb", "#222222" },
        [SchemeSel] = { "#eeeeee", "#005577" },
        [SchemeOut] = { "#000000", "#00ffff" },
};


int main (){return 0;}
