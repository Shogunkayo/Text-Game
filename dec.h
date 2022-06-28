typedef struct player{
    char name[20];
    int prev_room;
    int room_no;
    int quests[10];
    char objective[100];
    char position[100];
    char status[100];
    char occupation[100];
}player;

typedef struct npc{
    char name[20];
    int room_no;
    char speech[1000];
}npc;

typedef struct door{
    int blocked;
    char message[100];
}door;

typedef struct room{
    int no;
    char description[500];
    char left[500];
    char right[500];
    char front[500];
    char back[500];
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
void entered_room(player *p, room *r, npc *n);
void movement(player *p, room *r, npc *n);
void change_rooms(player *p, int choice, npc *n, room *r);

void locked_room(player *p, room *r);
void name_check(player *p, room *r);
void crack_safe(player *p, room*r);
