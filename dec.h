typedef struct player{
    char name[20];
    int age;
    int alive;
    int prev_room;
    int room_no;
    int can_sleep;
    char objective[100];
    char position[100];
    char status[100];
    char occupation[100];
}player;

typedef struct npc{
    char name[100];
    int room_no;
    int quest_done;
    char speech[1000];
}npc;

typedef struct door{
    int blocked;
    char message[100];
}door;

typedef struct room{
    int no;
    char description[200];
    char left[100];
    char right[100];
    char front[100];
    char back[100];
    door d[4];
}room;

void menu();

void initialize_player(player *p);
void initialize_room(room *r, int no, char *desc, char *right, char *left, char *front, char *back, int b0, int b1, int b2, int b3, char *m0, char *m1, char *m2, char *m3);

void print_text(char *p);
void create_space(int n);
void draw_logo();
void print_character_intro(player *p);

int is_alive(int *hp, int *alive);

void use_door(room *r, int choice);
void entered_room(player *p, room *r);
void movement(player *p, room *r);
void change_rooms(player *p, int choice);