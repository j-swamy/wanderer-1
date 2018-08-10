#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

/* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* This is not the full game. This is merely a prototype, so to speak. Main goal is testing  *
* how to implement this in ncurses so that we can have a fun terminal game to play,         *
* and also so we can utilize the keyboard to play.                                          *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*/

int main(){
	char* items[10];
	items[0] = "staff";
	initscr();
	keypad(stdscr, TRUE);
	raw();
	nonl();
	noecho();
	scrollok(stdscr, TRUE);

	int ch = 0;
	clear();
	printw("----------------------------------------------\n"); 
  	printw("__      ____ _ _ __   __| | ___ _ __ ___ _ __ \n\\ \\ /\\ / / _` | '_ \\ / _` |/ _ \\ '__/ _ \\ '__|\n \\ V  V / (_| | | | | (_| |  __/ | |  __/ |   \n  \\_/\\_/ \\__,_|_| |_|\\__,_|\\___|_|  \\___|_|   \n"); 
  	printw("----------------------------------------------\nPress enter to continue: "); 

	while (1) {
		ch = getch();
		if (ch == 13) {
			printw("\n> ...\n"); 
	  		sleep(1); 
	  		printw("> ........\n"); 
	  		sleep(1); 
	  		printw("> ...............................\n"); 
	  		sleep(1); 
	  		printw("> ...Oh! Hello! Pardon my manners... it has been so long since anyone has come to these parts.\n");
			sleep(1);
			printw("> That said... what could you be doing here? There isn't much to see, or do.\n");
			sleep(1);
			printw("> Still, you still insist on going forward? Interesting.... you have piqued my interest, wanderer.\n");
			sleep(1);
			printw("> I like your moxie. For giving me some entertainment, you may have one of these items.\n");
			printw("(Use 1, 2, or 3 keys to make a selection.)\n");
			printw("You pick the:\n\t1. purple gem.\n\t2. shimmery cloak\n\t3. dusty tome\n");   
			ch = getch();
			if (ch == 49) {
				printw("Ah, it's a pretty thing, isn't it? I'm not sure it serves much purpose other than being pretty, though.\n");
				sleep(1);
				printw("(Obtained purple gem.)\n");
				sleep(1);
				printw("(... It's pretty heavy for being so small.)\n");
				items[1] = "purple gem";			
			}
			
			else if (ch == 50) { 
				printw("> I must say, I'm glad you picked that. It didn't match with any of my clothes.\n");
				sleep(1);
				printw("(Obtained shimmery cloak.)\n");
				sleep(1);
				printw("(... It's kind of itchy.)\n");
				items[1] = "shimmery cloak";
			}
			
			else if (ch == 51) {
				printw("> My debut work! I can't say it sold very well though... it didn't even get good reviews...\n");
				sleep(1);
				printw("(Obtained dusty tome.)\n");
				sleep(1);
				printw("(...Ah-choo!)\n");
				items[1] = "dusty tome";
			}

			sleep(3);
			printw("(Press enter to continue.)\n");

			ch = getch();
			
			if (ch == 13) {
				sleep(3);
				printw("> Well, wanderer. I think you should be on your way. The world is a big place, and there's plenty of adventure to be found if that's what you seek.\n");
				sleep(3);
				printw("> Well, then, here's where I leave you! I wish you all the best!\n");
				sleep(3);
				printw("\n> ...\n"); 
				sleep(3); 
				printw("> ........\n"); 
				sleep(3); 
				printw("> ...............................\n"); 

			}

			sleep(3);
			printw("(Press enter to continue.)\n");

			ch = getch();
			if (ch == 13) {
				printw("> You have been walking for quite a while.\n");
				sleep(3);
				printw("> ...Ah. It seems that there is a fork in the road.\n");
				sleep(3);
				printw("> You should choose a path.\n");
				sleep(2);
				printw("(Use 1, 2, or 3 keys to make a selection.)\n");
				printw("\t1. Left. You catch a faint hint of an ocean breeze.\n\t2. Straight. You see the roofs of houses in the distance.\n\t3. Right. The road ahead seems difficult, with sharp thorns and imposing boulders.\n");
				ch = getch();
				/*
				Ocean Route
				*/
				if (ch == 49) {
					printw("> You went to the left.\n");
					sleep(3);
					printw("> The road slopes down gently, and the air smells saltier as you progress.\n");
					sleep(3);
					printw("> The road is becoming sandier and sandier.... oh? What's this?\n");
					sleep(3);
					printw("> On the ground is a shell, shaped like a conch. It's smooth, probably from rolling in ocean waves. You might be able to play it.\n");
					sleep(1);
					printw("> Pick up the shell?\n(Press 'y' for yes, and 'n' for no.)\n");
					ch = getch();
					if (ch == 121) {
						printw("(Obtained a conch shell.)\n");
						items[2] = "shell";
					}
					else {
						printw("> You left the shell alone.\n");
					}
					
					sleep(3);
					printw("\n> ...\n "); 
					sleep(3); 
					printw("> ........\n"); 
					sleep(3); 
					printw("> You've reached the ocean!\n");
					sleep(3);
					printw("> Wait... what's that noise...?\n");
					sleep(2);
					printw("> Suddenly, a giant sea dragon leaps out of the water!\n");
					sleep(2);
					printw("> You have no choice but to fight!\n");
					sleep(3);
					printw("To be continued...\n");
					printw("The game has ended... for now. Press the down key to exit.\n");
				}
				else if (ch == 50) {
					printw("> You continued straight.\n");
					sleep(3);
					printw("> The smell of freshly baked bread is coming from the direction of the town ahead, and you can hear some faint laughter in the distance.\n");
					sleep(3);
					printw("> There are trees all around you, but there is a clear path in the middle.\n");
					sleep(3);
					printw("> There's a large puddle of mud in front of you... it seems like something is sparkling in there.\n");
					sleep(1);
					printw("Will you fish the item out of the mud?\n(Press 'y' for yes, and 'n' for no.)\n");
					ch = getch();
					if (ch == 121) {
						printw("> You fished the item out of the mud. It looks like a pair of glasses...they have gold frames and crystal lenses!\n");
						printw("(Obtained glasses.)\n");
						items[2] = "glasses";
						printw("> You hear a voice coming from afar. Is someone yelling...?\n");
						sleep(3);
						printw("Voice: ..ief...es...\n");
						sleep(2);
						printw("> You see an enormous man running towards you! He stops and glares at you.\n");
						sleep(3);
						printw("Strange Man: Those are MY glasses! Thief! You'll pay for this!\n");
					}
					
					else {
						printw("> You just stare at the glasses as they sink deeper into the mud.\n");
						printw("> You hear a voice coming from afar. Is someone yelling...?\n");
						sleep(3);
						printw("Voice: ...no...\n");
						sleep(3);
						printw("> You see an enormous man running towards you! He stops and glares at you.\n");
						sleep(3);
						printw("Strange Man: What... what are you doing!? My glasses... MY GLASSES! Get them back, now!\n");
					}
					
					sleep(3);
					printw("> He seems quite agitated... will you try to reason with him?\n(Press 'y' for yes, and 'n' for no.)\n");
					ch = getch();
					if (ch == 121) {
						printw("> You attempt to reason with the man... ");
						if (strcmp(items[2], "glasses") == 0){
							printw("after all, you didn't know they were his glasses. You'll gladly give them back.\n");
						}
						else{
							printw("the glasses are sunk way too deep in the mud to even try getting them back.\n");
						}
					}
					
					else {
						printw("> You yell right back at the strange, giant man. After all, no one can speak so rudely to you and get away with it!\n");
						sleep(3);
						printw("Strange Man: H-how insolent! You DARE speak to me like that?\n");
					}
					
					sleep(3);
					printw("> ...Well, whatever you're doing, it doesn't seem to be working. He still looks livid.\n");
					sleep(3);
					printw("> Why don't you offer him something?\n");
					sleep(3);
					printw("(Press 1 to offer him the %s and press 2 to offer him his glasses.)\n", items[1]);
					ch = getch();
					if (ch == 49){
						if (strcmp(items[1], "purple gem") == 0) {
							printw("Strange Man: Huh... that's kinda pretty...\n");
							sleep(1);
							printw("Strange Man: I'm GUESSING this gem can also help my eyesight.\n");
							sleep(1);
							printw("Strange Man: ...'Probably not?' This gem is pretty, but it ain't a diamond or anything-- it's not gonna sell for a good price anywhere.\n");
							sleep(2);
							printw("(...He's picky.)\n");
							
						}
						
						else if (strcmp(items[1], "shimmery cloak") == 0) {
							printw("Strange Man: ... What is this? Is this to replace my glasses or something?\n");
							sleep(1);
							printw("Strange Man: This.... is the UGLIEST thing I have ever laid eyes upon! Who in their right mind would WEAR this?!\n");
							sleep(2);
							printw("(....Honestly, he isn't wrong...)\n");
						}
						
						else {
							printw("Strange Man:... Wait. I've read this before.\n");
							sleep(1);
							printw("Strange Man: This novel... is TERRIBLE. There's no coherency, the characters stink... how did this even get published?!\n");
							sleep(2);
							printw("(Is it really that bad...?\n");
							
						}
					}
					else {
						if (strcmp(items[2], "glasses") == 0){
							printw("Strange Man: My... glasses? They're CAKED with mud! You... this is YOUR doing!\n");
							sleep(2);
							printw("(...Just wipe the dirt off...)\n");
						}
						
						else{
							printw("> Unfortunately, you don't have his glasses... and you are loath to give him any of your other treasures.\n");
							sleep(2);
							printw("(This probably won't end well.)\n");
						}
						
					}
					
					sleep(2);
					printw("Strange Man: You.... You're awful... I feel my rage building...\n");
					sleep(3);
					printw("It seems you can't avoid a fight...!\n");
					printw("To be continued...\n");
					printw("The game has ended... for now. Press the down key to exit.\n");
					

				}
				else {

				}

			}

		}

		else if (ch == KEY_DOWN) { 
			endwin();
			return 0;
		}
	}
	


	return 0;
}
