#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include"dec.h"

int main(){
        
    menu();
    
    player p1;
    initialize_player(&p1);

    room home[5];
    npc n1 = {"Yuria",3,"'Good morning, master. You must be feeling hungry. You should eat something before going to your meeting today.'"};
    initialize_room(&home[1],1,"You get up from your bed. It was a sunny morning. You remember you had a meeting with Phantom that morning. You look at the clock.'07:10'. The meeting was scheduled at 8.","There is a table next to your bed. On top of it is a blurred photo of three people standing in front of a worn down building. You do not recognize them. There is sign on the building which reads Spat- the rest of it is cut-off","You look outside the window. Nothing worth noting.","You wear the clothes lying on the floor and exit your room. You climb down the stairs.","Theres a wall behind you.",1,1,0,1,"","","\nEntering living room.\n","");
    initialize_room(&home[2],2,"To the right is the door to exit your house. Next to it is a coat hanger. To the left is the entrance to the kitchen. You hear Yuria inside. To the front is the door to the basement.","","","","You climb up the stairs.",0,0,0,0,"","\nEntering kitchen.\n","\nEntering basement.\n","\nEntering bedroom.\n");
    initialize_room(&home[3],3,"Your maid, Yuria is cleaning the dishes.","There is a bowl of fruits on the counter. You grab an apple and eat it.","You go towards the fridge. Yuria says 'Master, the fridge is empty. We used everything for the party last night. I will go shopping today afternoon.'","You look outside the window, into your backyard. Your dog, Ruffard is playing with his ball.","",1,1,1,0,"","","","\nEntering living room.\n");   
    initialize_room(&home[4],4,"You climb down the stairs into your basement.","There is a washing machine running. Yuria must be doing the laundry.","There is a shelf with a bunch of hardware tools.","There is a wall in front of you.","You climb up the stairs.\n",1,1,1,0,"","","","\nEntering living room.\n");

    room hq[4];
    npc n2 = {"Helen",10};
    npc n3 = {"Phantom",30};
    initialize_room(&hq[1],10,"You enter the headquarters. At the front desk is a woman.\n","There is a lounge - a couple of sofas and newspapers on the tables. The headline reads 'CEASEFIRE BETWEEN THE EAST AND WEST'. You go throught the article.","There is a locked door. Unfortunately, you do have have authorization to enter.","You go past the security scanner and see a door in front of you.","Your objective is not done yet. Cannot leave the premises.",1,1,0,1,"","","\nEntering training room\n","");
    initialize_room(&hq[2],20,"The doors shut behind you.","You see a bunch of symbols etched on the wall. Each symbol has a length of 4 characters.\n.__, \n_...\n_._.\n,_..\n.,,, \n.._.\n__., \n....\n..,, \n.___\n_._, \n._..\n__,, \n_.,, \n___, \n.__.\n__._\n._., \n..., \n_,,, \n.._, \n..._ \n.__, \n_.._ \n_.__ \n__.. \n","You see a list of alphabets etched on the wall. Maybe there is some relation to the symbols on the right.","There is a computer screen with a keyboard connected to the door in front.It is displaying 'Enter the name of the city where the Academy is located' and blanks below it. The keyboard was only three keys - a dot,an underscore and a comma.","You try to open the door which you came from, but fail. The room has been sealed shut.",1,1,1,1,"","","","");
    initialize_room(&hq[3],30,"A man in a black suit says 'Ah you must be the new recruit! I have been waiting for you.'\n","There are windows which overlooks an indoor swimming pool. Must be another training room.\n","There is a bookshelf with a ton of espionage related material.\n","The chief is sitting behind the desk. He gives you a breifcase. You leave the headquarters and travel to Westalis\n","\nExiting chiefs room\n",1,1,1,0,"","","","");

    room lab[5];
    npc n4 = {"Security guard",100,"Hello! May I see your papers please.\nHmm they seem to be fine. You may proceed"};
    npc n5 = {"Selino",200,"Good morning! My name is Selino and I am a receptionist. You seem to be new here. Please tell your last name so I can cross check with the database"};
    initialize_room(&lab[1],100,"You arrive at the military compound surrounding the laboratory. A security guard approaches you.\n","There are 5 military tanks parked.The security guard stops you from going further.\n","You see a running track and few shacks. Must be a training area.The security guard stops you from going further.\n","The security guard escorts you into the facility.","You look back. The gate to the compound was closed.Your objective is not done yet. Cannot leave the premises.\n",1,1,0,1,"","","\nEntering laboratory\n","");
    initialize_room(&lab[2],200,"The interior is huge. There are multiple hallways and the place is packed with people in military gear and labcoats.\n","You go to a hallway marked as 'Research'. There are a bunch of doors leading to various laborataries. After walking for a few minutes, you find the laboratory with a board 'Nuclear Research'. This seems to be the one where am supposed to go.","You see a room with a sign saying 'MILITARY PERSONNEL ONLY'. You try to peek inside.\nA guard yells at you'HEY! Where do you think you are going?! You are not allowed to go in there.\n","You see Selino working. She smiles as she sees you looking.\nYou wave at Selino. She returns to her work.\n","You walk out of the revoling doors into the military compound outside.",0,1,1,0,"\nEntering room\n","","","\nExiting the faciity\n");
    initialize_room(&lab[3],300,"You see a huge glass window seperating the room into two halfs, one containing an office and on the opposite side is a laboratory.","There are a few tables and sofas lying about.\n","There is a huge safe.","You look at the opposite side of the glass windows.\nThere is a huge nuclear reactor and various equipments.\n","You exit the room",1,0,1,0,"","\nIt is locked, but there is a sheet of paper on the table beside it\n","","\nEntering Lobby\n");


    // START OF GAME
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

    while(p1.room_no < 5){
        movement(&p1, &home[p1.room_no], &n1); 
    }
    
    print_text("You wear your brown coat and fedora.\nExiting house.\n\n\n");
    system("clear");
    print_text("A black limo is parked at your curb. You get into it and see a familiar face at the wheel.\n\n\n");
    system("clear");
    strcpy(p1.position, "The Academy, Morioh");
    print_character_intro(&p1);
    sleep(2);
    system("clear");

    while(p1.room_no/10 < 4){
        if(!p1.quests[3]){
            strcpy(n2.speech, "Welcome to the Academy! My name is Helen. We have been expecting you. But first, you must prove yourself. Proceed through the security scanner when you are ready. I'd sugesst you look around.");
        }
        else{
            strcpy(n2.speech, "Welcome to the Academy! Hope you find what you are searching for.");
        }
        if(!p1.quests[2]){
            strcpy(n3.speech, "'Oh you dont know what has happened. I would expect a spy to know the latest events. No matter, I'll explain it to you. There has been a ceasefire between our country and Westalis. You will be tasked with Operation Strix,a mission to maintain the peace between the two countries of Westalis. You will have to infiltrate their laboratory. Your cover is a professor under the name Loid Forger. The relevant documents will be mailed to you. May you succeed.'");
        }
        else{
            strcpy(n3.speech, "'Ah I see you already know. Typical for a spy of your caliber. You will be tasked with Operation Strix,a mission to maintain the peace between the two countries of Westalis. You will have to infiltrate their laboratory. Your cover is a professor under the name Loid Forger. The relevant documents will be mailed to you. May you succeed.'");
        }
        
        if(p1.room_no/10 < 3){
            movement(&p1, &hq[p1.room_no/10], &n2);
        }
        else{
            movement(&p1, &hq[p1.room_no/10], &n3);
        }
    }

    system("clear");
    strcpy(p1.name, "Loid Forger");
    strcpy(p1.position, "Nuclear Research Laboratory, Westalis");
    strcpy(p1.objective, "Infiltrate the laboratory");
    strcpy(p1.occupation, "Professor");
    create_space(2);
    print_text("September 26 2014");
    create_space(5);
    draw_logo();
    print_character_intro(&p1);
    sleep(2);
    system("clear");
 
    while(p1.room_no/100 < 4){
        if(p1.quests[4]){

        }
        if(p1.room_no/100 == 1){
            movement(&p1, &lab[p1.room_no/100], &n4);
        }
        else{
            movement(&p1, &lab[p1.room_no/100], &n5);
        }
    }

    return 0;
}
    
