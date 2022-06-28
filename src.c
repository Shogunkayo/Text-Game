#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include "dec.h"

void menu(){
    printf("  ----- >>                                                  <<----         \n");
    printf("  |                                                               |        \n\n\n\n");
    printf("                          1)  NEW GAME                                     \n");
    printf("                          2)  EXIT GAME                                    \n\n\n\n");
    printf("  |                                                               |        \n");
    printf("  ------ >>                                                  <<----        \n");
    int c; 
    scanf("%d",&c);
    switch(c){
        case 1: system("clear"); break;
        case 2: system("clear"); exit(0);
        default: printf("Invalid choice\n"); menu(); break;
    }
}

void initialize_player(player *p){
    print_text("Enter your name: ");
    char garbage[20];
    scanf("%s",garbage);
    fgets(p->name, 20, stdin);
    strcpy(p->name,garbage);
    p->prev_room = -1;
    p->room_no = 0;
    for(int i=0;i<10;i++){
        p->quests[i] = 0;
    }
    strcpy(p->objective,"Meet with Phantom");
    strcpy(p->occupation,"Employee, Morioh Department Store");
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
    create_space(1);
    print_text("Occupation: ");
    print_text(p->occupation);
    create_space(1);
    print_text("Objective: ");
    print_text(p->objective);
    create_space(1);
    print_text("Position: ");
    print_text(p->position);
    create_space(1);
}

void use_door(room *r, int choice){
    if(!r->d[choice-1].blocked){
        print_text(r->d[choice-1].message);
    }
}

void entered_room(player *p, room *r, npc*n){
    p->prev_room = p->room_no;
    create_space(3);
    print_text(r->description);
    if(n->room_no == p->room_no){
        print_text(n->speech);
    }
}

void locked_room(player *p, room *r){
    print_text("\nType the answer: ");
    char ans_in[50];
    char ans[50] = "--,,---,.-.,..,,---,....";
    int correct = 1;
    scanf("%s",ans_in);
    for(int i=0; i<20; i++){
        if(ans_in[i]!=ans[i]){
            correct = 0;
            print_text("\nIncorrect\n");
            break;
        }
    }
    if(correct){
        print_text("\nCongratulations! You solved the puzzle!\n");
        
        p->quests[3] = 1;
        r->d[2].blocked = 0; 
        r->d[3].blocked = 0;

        strcpy(r->description,"You enter the room where you solved your first puzzle. The etchings on the wall are intact. Must be for newer recruits");
        strcpy(r->front,"The door is unlocked.");
        strcpy(r->back, r->front);
        strcpy(r->d[2].message,"\nEntering the chief's room\n");
        strcpy(r->d[3].message,"\nEntering the lobby\n");
    }
}


void name_check(player *p, room *r){
    char ans_in[50] = " ";
    char ans[50] = "Forger";
    print_text("\n\nType your name\n");
    scanf("%s",ans_in);
    while(strcmp(ans_in,ans)){
        print_text("Selino says 'Uhmm, there is no name like that in the register.'\n");
        scanf("%s",ans_in);
    }
    p->quests[4] = 1;
    print_text("\nSelino says 'Welcome to the Nuclear Research Laboratory, Professor'\n");
    
}

void crack_safe(player *p, room *r){
    int ans = 3271;
    int ans_in;
    print_text("\nYou read the message written on the sheet.\n");
    print_text("\n\n           CRACK THE CODE TO CONTINUE!!!!!!!          \n -------    I AM A 4 DIGIT ODD NUMBER        -------- \n-------- 4th DIGIT IS ODD AND  IS LESS THAN 3 --------\n-------- 1st DIGIT IS MORE THAN 4TH DIGIT     --------\n-------- 2nd DIGIT IS THE SMALLEST PRIME NUMBER ------\n--------  SUM OF FIRST THREE DIGITS IS  12     -------\n========== GUESS THE CORRECT ANSWER ==================\n              4271                                  \n              3272                                  \n              3271                                  \n              4252                                  \n");
    
    scanf("%d",&ans_in);
    while(ans!=ans_in){
        print_text("You enter the code and try to open the safe. Its still locked.\n");
        scanf("%d",&ans_in);
    }

    print_text("You enter the code and try to open the safe. The door pops out.\n");
    p->quests[5] = 1;
    print_text("There are tons of research papers in the safe. They seem to be important. You put all of them into your bag\n");
    strcpy(r->left, "There is the safe you opened.");
    strcpy(r->d[1].message, "\nThe safe is empty\n");

}


void change_rooms(player *p, int choice, npc *n, room *r){
    if(p->room_no == 1){
        if(choice == 3){
            p->room_no = 2;
        }
    }
    else if(p->room_no == 2){
        if(choice == 1){
            if(p->quests[1]){
                p->room_no = 10;
            }
            else{
                print_text("Your stomach rumbles as you approach the door. You havent eaten anything yet!\n");
            }
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
        else if(choice == 1){
            p->quests[1] = 1;
        }
    }
    else if(p->room_no == 4){
        if(choice == 4){
            p->room_no = 2;
        }
    }
    else if(p->room_no == 10){
        if(choice == 1){
            p->quests[2] = 1;
        }
        else if(choice == 3){
            p->room_no = 20;
        }
    }
    else if(p->room_no == 20){
        if(choice == 3){
            if(p->quests[3]){
                p->room_no = 30;
            }
            else{
                locked_room(p,r);
            }
        }
    }
    else if(p->room_no == 30){
        p->quests[3] = 1;
        if(choice == 4){
            p->room_no = 20;
        }
        else if(choice == 3){
            p->room_no = 100;
        }
    }

    else if(p->room_no == 100){
        if(choice == 3){
            p->room_no = 200;
        }
    }

    else if(p->room_no == 200){
        if(p->quests[4]){
            if(choice == 1){
                p->room_no = 300;
            }
            if(choice == 4){
                p->room_no = 100;
            }
        }
        else{
            name_check(p,r);
        }
    }

    else if(p->room_no == 300){
        if(choice == 4){
            p->room_no = 200;
        }
        else if(choice == 2){
            if(!p->quests[5]){
                crack_safe(p,r);
            }
        }
    }
}   

void movement(player *p, room *r, npc *n){
    int choice;
    if(p->prev_room != p-> room_no){
        entered_room(p,r, n);
    }
    if(p->room_no == 200 && p->quests[4] == 0){
        change_rooms(p,choice,n,r);
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
    change_rooms(p, choice, n, r);    
}
