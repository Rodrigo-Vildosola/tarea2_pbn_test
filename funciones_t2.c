#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/resource.h>

#include "funciones_t2.h"

double memory() {
    struct rusage r;
    getrusage(RUSAGE_SELF, &r);
    return r.ru_maxrss;
}

// Code //

void show_data(hero *hero_data, int data_size){  // Muestra el arreglo de estructuras con todas sus caracteristicas
    for (int i = 0; i < data_size; i++){
        printf("%-30s %-5d %-5d %-5d %-5d %-5d %-5d\n",
        hero_data[i].hero_name,
        hero_data[i].intel, 
        hero_data[i].str, 
        hero_data[i].spd, 
        hero_data[i].dur, 
        hero_data[i].pwr,
        hero_data[i].cmb);
    }
}

void tophero(hero *hero_data, int data_size, char *name, char *category){  // Busqueda por valor en caracteristica
    int count = 10;
    for(int i = 0; i < data_size; i++){
        if (strcmp(hero_data[i].hero_name, name) == 0){
            count = 0;
            printf("\n\n");
        }
        if(count < 10 && strcmp(category, "intelligence") == 0){
            printf("%2d) %-26s:  %d\n", count + 1, hero_data[i].hero_name, hero_data[i].intel);
            count += 1;
        }
        else if(count < 10 && strcmp(category, "strength") == 0){
            printf("%2d) %-26s:  %d\n", count + 1 , hero_data[i].hero_name, hero_data[i].str);
            count += 1;
        }
        else if(count < 10 && strcmp(category, "speed") == 0){
            printf("%2d) %-26s:  %d\n", count + 1,  hero_data[i].hero_name, hero_data[i].spd);
            count += 1;
        }
        else if(count < 10 && strcmp(category, "durability") == 0){
            printf("%2d) %-26s:  %d\n", count + 1, hero_data[i].hero_name, hero_data[i].dur);
            count += 1;
        }
        else if(count < 10 && strcmp(category, "power") == 0){
            printf("%2d) %-26s:  %d\n", count + 1, hero_data[i].hero_name, hero_data[i].pwr);
            count += 1;
        }
        else if(count < 10 && strcmp(category, "combat") == 0){
            printf("%2d) %-26s:  %d\n", count + 1, hero_data[i].hero_name, hero_data[i].cmb);
            count += 1;
        }
        //if () break;
    }
}

void topvalue(hero *hero_data, int data_size, int value, char *category){  // Busqueda por superheroe en caracteristica
    int check = 0;

    for(int i = 0; i < data_size; i++){
        if ((hero_data[i].intel == value && check == 0) && strcmp(category, "intelligence") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].intel); check = 1;
        }
        else if ((hero_data[i].str == value && check == 0) && strcmp(category, "strength") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].str); check = 1;
        }
        else if ((hero_data[i].spd == value && check == 0) && strcmp(category, "speed") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].spd); check = 1;
        }
        else if ((hero_data[i].dur == value && check == 0) && strcmp(category, "durability") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].dur); check = 1;
        }
        else if ((hero_data[i].pwr == value && check == 0) && strcmp(category, "power") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].pwr); check = 1;
        }
        else if ((hero_data[i].cmb == value && check == 0) && strcmp(category, "combat") == 0){
            for (int j = 0; j < 10; j++) printf("%2d) %-26s:  %d\n", j + 1, hero_data[i + j].hero_name, hero_data[i + j].cmb); check = 1;
        }
    }
    if (check == 0) printf("No existe un superheroe con %d de %s", value, category);
}

void sort_by_cat(hero *hero_data, int data_size, char *category){  // Reordena la lista de estructuras segun una categoria
    hero temp;
    for(int i = 0; i < data_size - 1; i++){
        for(int j = i + 1; j < data_size; j++){
            if ((hero_data[i].intel > hero_data[j].intel) && strcmp(category, "intelligence") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
            if ((hero_data[i].str > hero_data[j].str) && strcmp(category, "strength") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
            if ((hero_data[i].spd > hero_data[j].spd) && strcmp(category, "speed") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
            if ((hero_data[i].dur > hero_data[j].dur) && strcmp(category, "durability") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
            if ((hero_data[i].pwr > hero_data[j].pwr) && strcmp(category, "power") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
            if ((hero_data[i].cmb > hero_data[j].cmb) && strcmp(category, "combat") == 0){
                temp = hero_data[i]; hero_data[i] = hero_data[j]; hero_data[j] = temp;
            }
        }
    }
}

void hero_pos(hero *hero_data, char *name, int data_size){ // Obtiene la posicion relativa segun estadistica de cada superheroe
    sort_by_cat(hero_data, data_size, "intelligence");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_intel = data_size - i;
    sort_by_cat(hero_data, data_size, "strength");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_str = data_size - i;
    sort_by_cat(hero_data, data_size, "speed");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_spd = data_size - i;
    sort_by_cat(hero_data, data_size, "durability");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_dur = data_size - i;
    sort_by_cat(hero_data, data_size, "power");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_pwr = data_size - i;
    sort_by_cat(hero_data, data_size, "combat");
    for (int i = 0; i < data_size; i++) if (strcmp(name, hero_data[i].hero_name) == 0) hero_data[i].pos_cmb = data_size - i;

    for (int j = 0; j < data_size; j++) if (strcmp(name, hero_data[j].hero_name) == 0) {
        printf("\n\n%s: \n\n\t Intelligence:   %2d position: %d\n\t Strength:   %7d position: %d\n\t Speed:   %10d position: %d\n\t Durability:   %5d position: %d\n\t Power:   %10d position: %d\n\t Combat:   %9d position: %d\n", 
        hero_data[j].hero_name,
        hero_data[j].intel, hero_data[j].pos_intel,
        hero_data[j].str, hero_data[j].pos_str,
        hero_data[j].spd, hero_data[j].pos_spd,
        hero_data[j].dur, hero_data[j].pos_dur,
        hero_data[j].pwr, hero_data[j].pos_pwr,
        hero_data[j].cmb, hero_data[j].pos_cmb);
    }
}

int num_words(char *string){ // Cantidad de palabras en un string
    int count = 0;
    for (int i = 0;string[i] != '\0';i++) if (string[i] == ' ' && string[i+1] != ' ') count++;    
    return count + 1;
}
