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
        
    room home_1;
    initialize_room(&home_1,1,"Towards the right you see a clock hanging on the wall. '7:10'.\nTowards the left you see a window. A sunny morning.\nIn front of you are clothes lying on the floor and the door to exit your room.\n","Theres a table lying next to your bed. You find a photo of three people standing in front of a church.","You look outside the window. Nothing worth noting.","You wear the clothes lying on the floor and approach the door","Theres a wall behind you.",1,1,0,1,"","","Entering living room","");
    entered_room(&p1, &home_1);
   
    return 0;
}
