#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "dec.h"


void menu(){
    printf("  ----- >>                                                  <<----         \n");
    printf("  |                                                               |        \n\n\n\n");

    printf("                          1)  NEW GAME                                     \n");
    printf("                          2)  INSTRUCTIONS                                 \n");
    printf("                          3)  EXIT GAME                                    \n\n\n\n");
    printf("  |                                                               |        \n");
    printf("  ------ >>                                                  <<----        \n");

    int c; 
    scanf("%d",&c);
    fflush(stdin);
    switch(c){
        case 1: printf("WORKING"); break;
        case 2: break;
        case 3: system("exit"); break;
        default: printf("Invalid choice\n"); menu(); break;
    }
}

void initialize_player(player *p){
    print_text("Enter your name: ");
    fgets(p->name, 20, stdin);
    p->age = 27;
    p->alive = 1;
    p->prev_room = -1;
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
        usleep(0.04*1000*1000);
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

void use_door(room *r, int choice){
    if(r->d[choice-1].blocked){
        print_text("Blocked\n");
    }
    else{
        print_text(r->d[choice-1].message);
    }
}

void entered_room(player *p, room *r){
    p->prev_room = p->room_no;
    create_space(3);
    print_text(r->description);
}

void change_rooms(player *p, int choice){
    if(p->room_no == 1){
        if(choice == 3){
            p->room_no = 2;
        }
    }
    else if(p->room_no == 2){
        if(choice == 1){
            p->room_no = 5;
        }
        else if(choice == 2){
            p->room_no = 3;
        }
        else if(choice == 3){
            p->room_no = 4;
        }
        else if(choice == 4){
            p->room_no = 1;
        }
    }
    else if(p->room_no == 3){
        if(choice == 4){
            p->room_no = 2;
        }
    }
    else if(p->room_no == 4){
        if(choice == 4){
            p->room_no = 2;
        }
    }
}   

void movement(player *p, room *r){
    int choice;
    if(p->prev_room != p-> room_no){
        entered_room(p,r);
    }
    printf("\n1. Go right\n2. Go left\n3. Go front\n4. Go back\n\n");
    scanf("%d",&choice);
    switch(choice){
        case 1: print_text(r->right);   use_door(r, choice);    break;
        case 2: print_text(r->left);    use_door(r, choice);    break;
        case 3: print_text(r->front);   use_door(r, choice);    break;
        case 4: print_text(r->back);    use_door(r, choice);    break;
        default: printf("Invalid option\n");
        }
        change_rooms(p, choice);    
    }
 