#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"dec.h"

int main(){
        
    menu();
    
    player p1;
    initialize_player(&p1);

    system("clear");
    create_space(2);
    print_text("September 21 2014");
    create_space(5);
    draw_logo();
    print_character_intro(&p1);
    sleep(2);
        
    create_space(3);
    system("clear");

    print_text("You wake up.\n");

    p1.room_no = 1;
    room home[5];
    npc n1 = {"Yuria",3,"'Good morning, master. You must be feeling hungry. You should eat something before going to your meeting today.'"};
    initialize_room(&home[1],1,"You get up from your bed. It was a sunny morning. You remember you had a meeting with Phantom that morning. You look at the clock.'07:10'. The meeting was scheduled at 8.","There is a table next to your bed. On top of it is a blurred photo of three people standing in front of a worn down building. You do not recognize them. There is sign on the building which reads Spat- the rest of it is cut-off","You look outside the window. Nothing worth noting.","You wear the clothes lying on the floor and exit your room. You climb down the stairs.","Theres a wall behind you.",1,1,0,1,"","","\nEntering living room.\n","");
    initialize_room(&home[2],2,"To the right is the door to exit your house. Next to it is a coat hanger. To the left is the entrance to the kitchen. You hear Yuria inside. To the front is the door to the basement.","","","","You climb up the stairs.",0,0,0,0,"","\nEntering kitchen.\n","\nEntering basement.\n","\nEntering bedroom.\n");
    initialize_room(&home[3],3,"Your maid, Yuria is cleaning the dishes.","There is a bowl of fruits on the counter. You grab an apple and eat it.","You go towards the fridge. Yuria says 'Master, the fridge is empty. We used everything for the party last night. I will go shopping today afternoon.'","You look outside the window, into your backyard. Your dog, Ruffard is playing with his ball.","",1,1,1,0,"","","","\nEntering living room.\n");   
    initialize_room(&home[4],4,"You climb down the stairs into your basement.","There is a washing machine running. Yuria must be doing the laundry.","There is a shelf with a bunch of hardware tools.","There is a wall in front of you.","You climb up the stairs.\n",1,1,1,0,"","","","\nEntering living room.\n");

    room hq[4];
    npc n2 = {"Helen",10};
    npc n3 = {"Phantom",30,"Ah you must be the new recruit! I have been waiting for you."};

    initialize_room(&hq[1],10,"You enter the headquarters. At the front desk is a woman.\n","There is a lounge - a couple of sofas and newspapers on the tables. The headline reads 'CEASEFIRE BETWEEN THE EAST AND WEST'. You go throught the article.","There is a locked door. Unfortunately, you do have have authorization to enter.","You go past the security scanner and see a door in front of you.","Your objective is not done yet. Cannot leave the premises.",1,1,0,1,"","","\nEntering training room\n","");
    initialize_room(&hq[2],20,"The doors shut behind you.","You see a bunch of symbols etched on the wall. Each symbol has a length of 4 characters.\n.__ \n_...\n_._.\n _..\n.,,, \n.._.\n__. \n....\n..,, \n.___\n_._ \n._..\n__,, \n_.,, \n___ \n.__.\n__._\n._., \n..., \n_,,, \n.._, \n..._ \n.__ \n_.._ \n_.__ \n__.. \n","You see a list of alphabets etched on the wall. Maybe there is some relation to the symbols on the right.","There is a computer screen with a keyboard connected to the door in front.It is displaying 'Enter the name of the city where the Academy is located' and blanks below it. The keyboard was only three keys - a dot,an underscore and a comma.","You try to open the door which you came from, but fail. The room has been sealed shut.",1,1,1,1,"","","","");
    initialize_room(&hq[3],30,"WORKING\n","There is a lounge - a couple of sofas and newspapers on the tables. The headline reads 'CEASEFIRE BETWEEN THE EAST AND WEST'. You go throught the article","There is a locked door. Unfortunately, you do have have authorization to enter.","You go past the security scanner and see a door in front of you.","Your objective is not done yet. Cannot leave the premises.",1,1,0,1,"","","\nEntering training room\n","");


    while(p1.room_no < 5){
        movement(&p1, &home[p1.room_no], &n1); 
    }
    
    print_text("You wear your brown coat and fedora.\nExiting house.\n\n\n");
    system("clear");
    print_text("A black limo is parked at your curb. You get into it and see a familiar face at the wheel.\n\n\n");
    system("clear");
    strcpy(p1.position, "The Academy, Morioh");
    print_character_intro(&p1);
    system("clear");

    while(p1.room_no/10 < 4){
        if(!p1.quests[3]){
            strcpy(n2.speech, "Welcome to the Academy! My name is Helen. We have been expecting you. But first, you must prove yourself. Proceed through the security scanner when you are ready. I'd sugesst you look around.");
        }
        else{
            strcpy(n2.speech, "Welcome to the Academy! Hope you find what you are searching for.");
        }
        if(!p1.quests[2]){
            strcat(n3.speech, "\nOh you dont know what has happened. I would expect a spy to know the latest events. No matter, I'll explain it to you.");
        }
        else{
            strcat(n3.speech, "\nAh I see you already know. Typical for a spy of your caliber.");
        }
        
        if(p1.room_no/10 < 3){
            movement(&p1, &hq[p1.room_no/10], &n2);
        }
        else{
            movement(&p1, &hq[p1.room_no/10], &n3);
        }
    }

    return 0;
}
