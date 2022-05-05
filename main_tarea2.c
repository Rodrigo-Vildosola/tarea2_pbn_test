#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>


#include "funciones_t2.h"

#define MAX_NAME_SZ 256

int main(int argc, char *argv[]){
    double t = clock();
    FILE * heroes;
    heroes = fopen("data.txt", "r");
    int data_size = 0, name_length = 40;
    char *file_line, *token, *name; 
    file_line = (char*) malloc(2200 * sizeof(char));
    while (fgets(file_line, 2200, heroes) != NULL) data_size += 1; // Consiguiendo file length
    fseek(heroes, 0, SEEK_SET);

    hero *hero_data;
    hero_data = malloc(data_size * sizeof(hero));

    for (int i = 0; i < data_size; i++){ // Ingresando los datos a el arreglo de estructuras
        if (fgets(file_line, 2200, heroes) != NULL){
            token = strtok(file_line, ";");
            for (int j = 0; j < 8; j ++){
                if (j == 1){
                    hero_data[i].hero_name = malloc(name_length * sizeof(char));
                    if (token[strlen(token) - 1] == ' ')
                        token[strlen(token) - 1] = '\0';
                    strcpy(hero_data[i].hero_name, token);
                }
                if (j == 2) hero_data[i].intel = atoi(token);
                if (j == 3) hero_data[i].str = atoi(token);
                if (j == 4) hero_data[i].spd = atoi(token);
                if (j == 5) hero_data[i].dur = atoi(token);
                if (j == 6) hero_data[i].pwr = atoi(token);
                if (j == 7) hero_data[i].cmb = atoi(token);

		        token = strtok(NULL, ";");
	        }
        }
    }

    if (argc == 2){  // Metodo por standard input
        while (strcmp(argv[1], "-terminal") == 0){  
            printf("¿Que quieres hacer? \nEl formato es el siguiente:\n\n1) tophero {categoria} {nombre}\n2) topvalue {categoria} {valor}\n3) hero {nombre}\n4) salir\n: ");
            char *response = (char*) malloc(60 * sizeof(char)), *function_name, *category , *name_part;
            fgets(response, 60, stdin);
            printf("\n");
            int num = num_words(response);
            function_name = strtok(response, " ");
            if (strcmp(function_name, "salir\n") == 0) break;
            
            category = strtok(NULL, " ");
            if (num == 2) category[strlen(category) - 1] = '\0';

            if (num < 2) {
                printf("No hay suficientes datos para realizar una busqueda.\n"); 
                goto label_1;
            }

            if (strcmp(function_name, "tophero") == 0){
                sort_by_cat(hero_data, data_size, category);
                //show_data(hero_data, data_size);
                if (num >= 4){
                    name = (char*) malloc(name_length * sizeof(char));
                    name_part = strtok(NULL, " ");
                    strcpy(name, name_part);
                    for(int i = 3; i < num; i++){
                        strcat(name, " ");
                        name_part = strtok(NULL, " ");
                        strcat(name, name_part);
                    }
                    name[strlen(name) - 1] = '\0';
                    tophero(hero_data, data_size, name, category);
                    free(name);
                }

                else if (num == 3) {
                    name_part = strtok(NULL, " ");
                    name_part[strlen(name_part) - 1] = '\0';
                    tophero(hero_data, data_size, name_part, category);
                }
                printf("\n");

                printf("De que superheroe desea ver su infromacion? (escribe quit si no quieres ver ninguno)\n: ");
                name = (char*) malloc(name_length * sizeof(char));
                fgets(name, MAX_NAME_SZ, stdin);
                if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
                    name[strlen (name) - 1] = '\0';

                hero_pos(hero_data, name, data_size);
                free(name);
            }

            else if (strcmp(function_name, "topvalue") == 0){
                int number;
                sort_by_cat(hero_data, data_size, category);
                //show_data(hero_data, data_size);
                printf("\n");
                number = atoi(strtok(NULL, " "));
                topvalue(hero_data, data_size, number, category);
                printf("\n");

                printf("De que superheroe desea ver su infromacion? (escribe quit si no quieres ver ninguno)\n: ");
                name = (char*) malloc(name_length * sizeof(char));
                fgets(name, MAX_NAME_SZ, stdin);
                if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
                    name[strlen (name) - 1] = '\0';

                hero_pos(hero_data, name, data_size);
                free(name);

            }

            else if (strcmp(function_name, "hero") == 0){
                //show_data(hero_data, data_size);
                printf("\n");
                if (num >= 3){
                    name = (char*) malloc(name_length * sizeof(char));
                    strcpy(name, category);
                    for(int i = 2; i < num; i++){
                        strcat(name, " ");
                        name_part = strtok(NULL, " ");
                        strcat(name, name_part);
                    }
                    name[strlen(name) - 1] = '\0';
                    hero_pos(hero_data, name, data_size);
                    free(name);
                }

                else if (num == 2) hero_pos(hero_data, category, data_size);
                printf("\n");
            }

            else printf("No existe la funcion %s\n\n", response);
            label_1:
            free(response); 
        }
    }

    if (argc > 2){  // Metodo por argumentos de linea de comandos

        if (strcmp(argv[1], "-tophero") == 0){
            sort_by_cat(hero_data, data_size, argv[2]);
            //show_data(hero_data, data_size);
            
            if (argc > 4){
                name = (char*) malloc(name_length * sizeof(char));
                strcpy(name, argv[3]);
                for (int i = 4; i < argc; i++){
                    strcat(name, " ");
                    strcat(name, argv[i]);
                }
                tophero(hero_data, data_size, name, argv[2]);
                free(name);
            }
            
            if (argc == 4) tophero(hero_data, data_size, argv[3], argv[2]);
            printf("\n");

            printf("De que superheroe desea ver su infromacion? (escribe quit si no quieres ver ninguno)\n: ");
            name = (char*) malloc(name_length * sizeof(char));
            fgets(name, MAX_NAME_SZ, stdin);
            if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
                name[strlen (name) - 1] = '\0';

            hero_pos(hero_data, name, data_size);
            free(name);
        }

        else if (strcmp(argv[1], "-topvalue") == 0){
            sort_by_cat(hero_data, data_size, argv[2]);
            //show_data(hero_data, data_size);
            printf("\n");
            topvalue(hero_data, data_size, atoi(argv[3]), argv[2]);
            printf("\n");

            printf("De que superheroe desea ver su infromacion? (escribe quit si no quieres ver ninguno)\n: ");
            name = (char*) malloc(name_length * sizeof(char));
            fgets(name, MAX_NAME_SZ, stdin);
            if ((strlen(name) > 0) && (name[strlen (name) - 1] == '\n'))
                name[strlen (name) - 1] = '\0';

            hero_pos(hero_data, name, data_size);
            free(name);

        }

        else if (strcmp(argv[1], "-hero") == 0){
            //show_data(hero_data, data_size);
            printf("\n");

            if (argc > 3){
                //int n = strlen(argv[3]) + strlen(argv[4]);
                name = (char*) malloc(name_length * sizeof(char));
                strcpy(name, argv[2]);
                for (int i = 3; i < argc; i++){
                    strcat(name, " ");
                    strcat(name, argv[i]);
                }
                hero_pos(hero_data, name, data_size);
                free(name);
            }
            
            if (argc == 3) hero_pos(hero_data, argv[2], data_size);
            printf("\n");
        }

        else printf("Funcion no reconocida");
        printf("\n");
    }

    for (int i = 0; i < data_size; i++) free(hero_data[i].hero_name);
    free(hero_data);
    free(file_line);
    fclose(heroes);

    // ######### Timer and memory ######### //
    printf("\n");
    t = (clock() - t) /CLOCKS_PER_SEC;
    printf("Runtime: %lf s\n", t);
    printf("Memory: %.2lf KB\n", memory());
    return 0;
}
