#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    Blue,
    Jazz,
    Rock
} music_type;

typedef struct Music
{
    char* const name;
    unsigned int duration;
    music_type type;
} Music;

Music* initialize_music();
int transfer_input(char*);
void print_all_music_info(Music*);
void print_blue_info(Music*);
void print_jazz_info(Music*);
void print_rock_info(Music*);

int main()
{
    Music* music = initialize_music();

    while (1)
    {
        char input[25] = {};
        int option = 0;
        printf("Music manage system: 1) List 2)Exit\n");
        scanf("%24s", &input);
        fseek(stdin, 0, SEEK_END);

        option = transfer_input(input);

        switch (option)
        {
            case 1:
                print_all_music_info(music);
                break;
            case 2:
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
    
    return 0;
}

Music* initialize_music()
{
    Music* music = malloc(3 * sizeof(Music));
    (music + 2)->name = "If I Knew";
    (music + 2)->duration = 132;
    (music + 2)->type = Blue;

    (music + 1)->name = "The Lady is a Tramp";
    (music + 1)->duration = 198;
    (music + 1)->type = Jazz;

    music->name = "Something In Your Mouth";
    music->duration = 219;
    music->type = Rock;

    return music;
}

int transfer_input(char* target)
{
    int result = -1;

    if (isdigit(*target))
    {
        result = atoi(target);
    }

    return result;
}

void print_all_music_info(Music* music)
{
    for (int i = 0; i < 3; ++i)
    {
        Music* current_music = music + i;
        switch (current_music->type)
        {
            case Blue:
                print_blue_info(current_music);
                break;
            case Jazz:
                print_jazz_info(current_music);
                break;
            case Rock:
                print_rock_info(current_music);
                break;
            default:
                fprintf(stderr, "Unknown music type\n");
                break;
        }
    }
}

void print_blue_info(Music* blue)
{
    printf("Name: %-30s, Duration: %3ds, Type: Blue\n", blue->name, blue->duration);
}

void print_jazz_info(Music* jazz)
{
    printf("Name: %-30s, Duration: %3ds, Type: Jazz\n", jazz->name, jazz->duration);
}

void print_rock_info(Music* rock)
{
    printf("Name: %-30s, Duration: %3ds, Type: Rock\n", rock->name, rock->duration);
}
