#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"dec.h"

int main(){

    int choice = 0;
    player p1;
    initialize_player(&p1);

    system("clear");
    create_space(2);
    print_text("September 21 2014");
    create_space(5);
    draw_logo();
    print_character_intro(&p1);
    sleep(3);
        
    create_space(3);
    system("clear");

    print_text("You wake up.\n");
    printf("1. Look Around\n");
    scanf("%d",&choice);
    if(choice != 1){
        print_text("You remember that you have a meeting that morning. 'This is no time to sleep!'");
    }
    
    p1.room_no = 1;
    room home[5];
    initialize_room(&home[1],1,"Towards the right you see a clock hanging on the wall. '7:10'.\nTowards the left you see a window. A sunny morning.\nIn front of you are clothes lying on the floor and the door to exit your room.\n","There is a table next to your bed. On top of it is a blurred photo.\n","You look outside the window. Nothing worth noting.\n","You wear the clothes lying on the floor and approach the door.\n","Theres a wall behind you.\n",1,1,0,1,"","","Entering living room\n","");
    initialize_room(&home[2],2,"There is a door leading outside on the right.\nGoing left takes you to the kitchen.\nIn front of you is the door to the basement\n","You hear a car stopping outside as you approach the door.\n","","","",0,0,0,0,"Exiting house\n","Entering kitchen\n","Entering basement\n","Entering bedroom\n");
    initialize_room(&home[3],3,"You see a counter with a bowl of fruits on the right.\nTheres a fridge to the left.\nIn front is the backdoor\n","You grab an apple and eat it.\n","The fridge is empty.\n","You look outside, into your backyard. Nothing worth noting\n","",1,1,1,0,"","","","Entering living room\n");
    initialize_room(&home[4],4,"You climb down the stairs into your basement.\nTheres a washing machine to the right.\n","","","","",1,1,1,0,"","","","Entering living room\n");

    while(p1.room_no < 5){
        movement(&p1, &home[p1.room_no]); 
    }
    system("clear");

    return 0;
}
