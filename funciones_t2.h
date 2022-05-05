
double memory();

typedef struct{ 
    char *hero_name;
    int intel, str, spd, dur, pwr, cmb, pos_intel, pos_str, pos_spd, pos_dur, pos_pwr, pos_cmb;
} hero;

void show_data(hero *hero_data, int data_size);

void tophero(hero *hero_data, int data_size, char *name, char *category);

void topvalue(hero *hero_data, int data_size, int value, char *category);

void sort_by_cat(hero *hero_data, int data_size, char *category);

void hero_pos(hero *hero_data, char *name, int data_size);

int num_words(char *string);
