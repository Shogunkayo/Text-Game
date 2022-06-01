#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "dec.h"


void initialize_player(player *p){
    print_text("Enter your name: ");
    fgets(p->name, 20, stdin);
    p->age = 27;
    p->alive = 1;
    p->room_no = 0;
    p->can_sleep = 0;
    strcpy(p->objective,"Meet with Phantom");
    strcpy(p->occupation,"Employee, Liurna Department Store");
    strcpy(p->position,"Home, Northeast Section of Morioh");
}

void initialize_room(room *r, int no, char *desc, char *right, char *left, char *front, char *back, int b0, int b1, int b2, int b3, char *m0, char *m1, char *m2, char *m3){
    r->no = no;
    strcpy(r->description,desc);
    
    strcpy(r->right,right);
    strcpy(r->left,left);
    strcpy(r->front,front);
    strcpy(r->back,back);

    r->d[0].blocked = b0;
    r->d[1].blocked = b1;
    r->d[2].blocked = b2;
    r->d[3].blocked = b3;

    strcpy(r->d[0].message,m0);
    strcpy(r->d[1].message,m1);
    strcpy(r->d[2].message,m2);
    strcpy(r->d[3].message,m3);
}

void print_text(char *p){
    for(int i = 0; i < strlen(p); i++){
        usleep(0.08*1000*1000);
        putchar(p[i]);
        fflush(stdout);
    }
    sleep(1);
}

void create_space(int n){
    for(int i = 0; i<n; i++){
        usleep(0.03 * 1000 * 1000);
        printf("\n");
    }
}

void draw_logo(){
    printf("|\\ ___________________________________ /| \n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n\n\n",
"| | _                               _ | |",
"| |(+)        _           _        (+)| |",
"| | ~      _--/           \\--_      ~ | |",
"| |       /  /             \\  \\       | |",
"| |      /  |               |  \\      | |",
"| |     /   |               |   \\     | |",
"| |     |   |    _______    |   |     | |",
"| |     |   |    \\     /    |   |     | |",
"| |     \\    \\_   |   |   _/    /     | |",
"| |      \\     -__|   |__-     /      | |",
"| |       \\_                 _/       | |",
"| |         --__         __--         | |",
"| |             --|   |--             | |",
"| |               |   |               | |",
"| |                | |                | |",
"| |                 |                 | |",
"| |                                   | |",
"| |        Nos Mundi Vigilamus        | |",
"| | _                               _ | |",
"| |(+)                             (+)| |",
"| | ~                               ~ | |",
"|/ ----------------------------------- \\|",
" ---------------------------------------");
}


void print_character_intro(player *p){
    print_text("Name: ");
    print_text(p->name);
    print_text("Age: ");
    printf("%d\n",p->age);
    print_text("Occupation: ");
    print_text(p->occupation);
    printf("\n");
    print_text("Objective: ");
    print_text(p->objective);
    printf("\n");
    print_text("Position: ");
    print_text(p->position);
    printf("\n");
}

void movement(){
    printf("\n1. Go right\n2. Go left\n3. Go front\n4. Go back\n");
}

int use_door(int *room, int *num, int*blocked){
    scanf("%d", room);
    sleep(2);
    if(*room == *num){
        if(*blocked){
            print_text("Door is locked\n");
            return 0;
        }
        else{
            print_text("Entering\n\n\n");
        }
        return 1;
    }
    else{
        print_text("That is not the right door!\n");
        return 0;
    }
}


void entered_room(player *p, room *r){
    system("clear");
    p->room_no = r->no;
    print_text(r->description);
    movement();
}
