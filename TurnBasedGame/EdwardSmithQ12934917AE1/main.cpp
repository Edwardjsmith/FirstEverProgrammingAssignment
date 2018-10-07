#include <iostream> //Includes the input and output library

#include <cstdlib> //Contains rand() which allows for random numbers to be generated

#include <ctime> //Allows the program access to current date and time

#include <string> //Allows for strings

#include <windows.h> //Included to allow text colour to change

using namespace std;

int main()

{
	int herohealth = 100;

	int monsterhealth = 100;

	int normalattack;

	int heavyattack;

	int defend;

	int counterattack = 1;

	int monstercounterattack = 1;

	int useamulet = 1;

	int monsteramulet = 1;

	int attackchoice;

	int randomnumber = 0;

	string name;

	char choice;

	HANDLE colour = GetStdHandle(STD_OUTPUT_HANDLE); //Allows text colour to change

	{	SetConsoleTextAttribute(colour, FOREGROUND_INTENSITY); //Edits text colour, this applies it to whole program

	cout << "Hello adventurer! What is your name?" << endl << endl << endl;

	cin >> name;

	cout << endl << endl << endl << "A pleasure to meet you " << name << ", " << "Our town has come under attack from a monster! will you help? y/n" << endl << endl << endl;

	cin >> choice;

	while (choice != 'y') //Will loop until y is chosen

	{
		if (choice == 'y')

		{
			cout << endl << endl << endl << "Thank you brave adventurer! please select an attack." << endl << endl << endl;
		}

		else if (choice == 'n') {

			cout << "Oh, okay... Bye!" << endl << endl << endl;

			system("pause");

			return 0; //Allows the user to quit if they choose n.

		}

		else { //will display a message if anything other than y/n is chosen

			cout << "Sorry " << name << "," << " I didn't quite catch that. y/n?" << endl << endl << endl;

			cin >> choice;

			if (choice == 'y')

			{
				cout << endl << endl << endl << "Okay I heard that, please select an attack." << endl << endl << endl;
			}
		}
	}

	randomnumber = rand() % 100 + 1; //Sets rand to generate numbers between 1 and 100 

	while ((herohealth > 0 && monsterhealth > 0)) //The game will loop as long as each players health is greater than 0

	{
		SetConsoleTextAttribute(colour, FOREGROUND_INTENSITY); //Sets colour to grey

		cout << "For a normal attack, press 1" << endl << endl << endl

			<< "For a heavy attack, press 2" << endl << endl << endl

			<< "To defend, press 3" << endl << endl << endl

			<< "To use your amulet , press 4. (single use only)" << endl << endl << endl

			<< "To counter attack, press 5" << endl << endl << endl; //Gives the human player an option of 5 attacks.

	label:	cin >> attackchoice;

		system("cls"); //Clears the screen each loop so the UI is less cluttered

		switch (attackchoice)

		{
			if (useamulet == 0)

			{
				useamulet = -1; //Takes 1 off value of amulet when it is 0 to stop amulet being used again
			}

		case 1: //Normal attack

			cout << "You throw a normal attack!" << endl << endl << endl;

			if (normalattack = (randomnumber) <= 80) //Sets the limit of the random number beteen 1 - 100 
			{												  //and as long as the number is above 20, the attack will land. 80% of hit.

				SetConsoleTextAttribute(colour, FOREGROUND_GREEN); //Sets text to green when attack hits


				if (useamulet == 0)

				{
					monsterhealth -= 10 * 1.5;

					cout << "Your attack, charged by the amulets power, lands! The monsters health is now " << monsterhealth << endl << endl << endl;

					useamulet--; //Puts the value of useamulet to below zero so it gets rid of the effect.
				}

				else {
					monsterhealth -= 10; //Does 10 damage to monster
					cout << "Your attack lands! The monsters health is now " << monsterhealth << endl << endl << endl;
				}
			}

			else

				if (useamulet == 0)

				{
					cout << "The monster blocked the hit." << endl << endl << endl;
				}
				else
			{
				cout << "The monster blocked the hit." << endl << endl << endl;
			}

			break;

		case 2: //Heavy attack

			cout << "You throw a heavy attack!" << endl << endl << endl;

			if (heavyattack = (randomnumber) >= 50) //Same limit as normal attack but will only land 
			{												//if equal to or less than 50 giving 50% chance of hit.
				SetConsoleTextAttribute(colour, FOREGROUND_GREEN);

				if (useamulet == 0)

				{
					monsterhealth -= 20 * 1.5; //Attack does 1.5 times more damage when amulet is used

					cout << "Your heavy attack, charged by the amulets power, lands! The monsters health is now " << monsterhealth << endl << endl << endl;

					useamulet--; //Puts value of amulet below 0 so the effects wear off

				}

				else {
					monsterhealth -= 20;  //Attack does 20 damage



					cout << "The monster buckles under your heavy attacks force! it's health is now " << monsterhealth << endl << endl << endl;
				}
			}

			else //If randomnumber value is less than 50 a message saying the attack missed will display

				if (useamulet == 0)
				{
					cout << "The monster managed to avoid your slow but powerful attack." << endl << endl << endl;
				}


				else{
				cout << "The monster managed to avoid your slow but powerful attack." << endl << endl << endl;
			}

			break;



		case 3: //Defend

			if (herohealth == 100) //If the players health is at max, there is no health increase.

			{
				SetConsoleTextAttribute(colour, FOREGROUND_GREEN);

				randomnumber = rand() % 130 + 1; //Improves chance of opponent missing by 30%

				cout << "You adopt a defensive stance." << endl << endl << endl;


			}

			else {
				herohealth += 5; //Should the player pick defend when they have lost health, they will regain 5 health.

				SetConsoleTextAttribute(colour, FOREGROUND_GREEN); //Sets text to green

				randomnumber = rand() % 130 + 1; //Increases the range of random numbers, increasing the chance of a miss by 30%

				cout << "You adopt a defensive stance, preparing for an attack! Your health also increases by 5 points. It is now " << herohealth << endl << endl << endl;
			}

			break;

		case 4:

			if (useamulet == 1) //Allows the use of amulet once

			{
				useamulet--; //Sets amulet to 0, allowing for it's effects to take place and stop it being used

				cout << "You use your amulet, your damage for this turn increases by a factor of 1.5!" << endl << endl << endl;

				goto label; //Allows player to select another attack in the same turn


			}


			else { //If the player tries to use the amulet again, a message will display and they will be asked to chose another attack

				cout << "Sorry, you've used your amulet, please use another attack" << endl << endl << endl;

				goto label;

				
			}
			
			break;

		case 5: counterattack;

			cout << "You prepare to counter attack" << endl << endl << endl;

			counterattack--; //Sets value to 0 for an if statement later on

			break;

		default: cout << "Please enter 1 for normal attack, 2 for heavy attack, 3 to defend, 4 for the amulet or 5 for a counter attack " << endl; //If wrong input, this message will display

			goto label; //Will allow the player to select another attack
		}

		{
			SetConsoleTextAttribute(colour, FOREGROUND_INTENSITY); //Resets colour so monsters moves aren't in green

			int srand((time(NULL))); //Seeds rand() with current time and date meaning generated numbers are different





			int monsterattackchoice = (rand() % 5) + 1; //Allows the monster to have a choice by generating a number between 1-5



			if (monsterhealth <= 0) //If the player wins, message will display.

			{
				SetConsoleTextAttribute(colour, FOREGROUND_GREEN); //Changes text to green

				cout << "You triumphed in battle over the monster! Well done " << name << "! " << "Our town is safe for another day." << endl << endl << endl;

				SetConsoleTextAttribute(colour, FOREGROUND_INTENSITY); //Changes colour back to grey

				system("pause"); //Allows the player to press any key to exit

				return 0;
			}


			switch (monsterattackchoice)

			{
			case 1: cout << "The monster throws a normal attack!" << endl << endl << endl;

				if (normalattack = (randomnumber) <= 80) //Gives the monster 80% to hit with normal attack.
				{
					SetConsoleTextAttribute(colour, FOREGROUND_RED); //Changes text to red

					if (monsteramulet == 0) //If the amulet is used, the attack does extra damage

					{
						monsteramulet--; //Puts the value to below 0 to stop the effects

						herohealth -= 10 * 1.5; 

						cout << "The monster attacks with a normal attack charged with the power of it's amulet! your health is now " << herohealth << endl << endl << endl;
					}

					else {
						herohealth -= 10; //Normal damage without amulet

						cout << "The monsters attack lands! your health is now " << herohealth << endl << endl << endl;
					}
				}

				else

				{
					SetConsoleTextAttribute(colour, FOREGROUND_GREEN); //Changes text to green

					cout << "You blocked the hit." << endl << endl << endl;
				}

				break;

			case 2: cout << "The monster throws a heavy attack!" << endl << endl << endl;

				if (heavyattack = (randomnumber) >= 50) //50% chance of hitting with heavy attack.
				{


					SetConsoleTextAttribute(colour, FOREGROUND_RED);

					if (monsteramulet == 0) //Allows higher damage when amulet has been used

					{
						monsteramulet--; //Sets monsteramulet to below 0 to stop the effects

						herohealth -= 20 * 1.5;

						cout << "The monster attacks with the power of it's amulet! your health is now " << herohealth << endl << endl << endl;
					}

					else {
						herohealth -= 20; //Normal damage


						cout << "You are struck hard, your health is now " << herohealth << endl << endl << endl;

					}
				}

				else

				{
					SetConsoleTextAttribute(colour, FOREGROUND_GREEN);


					cout << "You managed to avoid the slow but powerful attack." << endl << endl << endl;
				}

				break;

			case 3:

				if (monsterhealth == 100)

				{
					SetConsoleTextAttribute(colour, FOREGROUND_RED);

					randomnumber = rand() % 130 + 1; //Increases chance of player missing when defend is selected

					cout << "The monster adopts a defensive stance." << endl << endl << endl;
				}

				else

				{
					SetConsoleTextAttribute(colour, FOREGROUND_RED);

					randomnumber = rand() % 130 + 1;

					monsterhealth += 5; //Monster regains 5 health if it chooses defend and has less than max health.

					cout << "The monster adopts a defensive stance, anticipating your move! It's health also increases by 5. It's health is now " << monsterhealth << endl << endl << endl;
				}
				break;

			case 4: if (monsteramulet == 1)

			{
				monsteramulet--; //Sets amulet to 0 to allow it's effects

				cout << "The monster uses it's amulet, increasing it's attack by a factor of 1.5!" << endl << endl << endl;

				randomnumber = rand() % 2 + 1; //Allows the monster to attack after choosing the amulet

				if (randomnumber = 1) //Normal attack

				{

					if (normalattack = (randomnumber) <= 80)
					{
						SetConsoleTextAttribute(colour, FOREGROUND_RED);

						monsteramulet--; //Stops the amulet being used again

						herohealth -= 10 * 1.5; //Increases damage output

						cout << "The monster attacks with an amulet charged normal attack! Your health is now " << herohealth << endl << endl << endl;
					}

					else

						cout << "You managed to block it's attack." << endl << endl << endl;
				}


				else { //Heavy attack

					if (heavyattack = (randomnumber) <= 50)

					{
						SetConsoleTextAttribute(colour, FOREGROUND_RED);

						monsteramulet--;

						herohealth -= 20 * 1.5;

						cout << "You are struck hard by an amulet ewmpowered heavy attack! Your health is now " << herohealth << endl << endl << endl;
					}

					else

					{
						cout << "The monsters charged heavy attack misses!" << endl << endl << endl;

					}

					break;

			case 5:
				monstercounterattack;

				cout << "The monster counters!" << endl << endl << endl;

				monstercounterattack--; //Sets the value to 0 allowing for the monster to counter


				}

			}

					SetConsoleTextAttribute(colour, FOREGROUND_RED);



			}


			if (monstercounterattack == 0) //Monster counter attack

			{
				if (randomnumber > 35) //Sets chance of hit to 65%

				{
					SetConsoleTextAttribute(colour, FOREGROUND_RED);

					randomnumber = rand() % 120 + 1; //Raises chance of opponent mising 

					herohealth -= 6; //Damage done

					monstercounterattack++; //Resets to 1 so the monster can counter again

					cout << "The monster launches it's counter, your health is now " << herohealth << endl << endl << endl;
				}

				else { cout << "The monsters counter misses!" << endl << endl << endl; }


			}

			if (counterattack == 0)

			{
				counterattack++; //Resets counter attack to 1 allowing it to be used again

				if (randomnumber > 35) //Sets chance to 65%

				{
					SetConsoleTextAttribute(colour, FOREGROUND_GREEN);

					randomnumber = rand() % 120 + 1; //Increases the chance of opponent missing

					monsterhealth -= 6; //Does 6 damage if it hits



					cout << "You launch your counter attack! The monsters health is now " << monsterhealth << endl << endl << endl;
				}

				else { cout << "Your counter misses..." << endl << endl << endl; }


			}
			

		}

		if (herohealth <= 0) //Should the player lose, a defeat message will display.

		{
			SetConsoleTextAttribute(colour, FOREGROUND_RED); //Changes text to red

			cout << "You fall in battle against the monster. You will live on in the songs of your bravery, " << name << "." << endl << endl << endl;
		}




	}	SetConsoleTextAttribute(colour, FOREGROUND_INTENSITY); //Changes text to grey

	system("pause"); //Allows the player to exit when one of the while conditions are met
	}



}