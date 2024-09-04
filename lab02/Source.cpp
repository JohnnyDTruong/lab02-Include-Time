/*
Jonathan Truong
CPSC 121-19
02/05/20
Lab 02 - Functions
*/

#include <iostream>
#include <time.h>
using namespace std;

char menu();
void takeHit(int &playerHP);
int makeAttack(int enemyHP);

int main()
{
	srand(time(0));
	cout << "Starting the RPG!" << endl;
	cout << "You spawned with 20 health!" << endl;

	int playerHP = 20;
	int enemyHP = 10;
	char choice;
	//this loops the function above to play the game
	//the loop finishes when either player or enemy reach 0 HP
	//or when the player chooses to run away

	// choice = menu()
	do
	{
		choice = menu();
		if (choice == 'a') 
		{
		takeHit(playerHP);
		enemyHP = makeAttack(enemyHP);

		}
		else
		{
			cout << "You quickly ran away!" << endl;
		}

	} 
	while (playerHP > 0 && enemyHP > 0 && choice != 'b');
	cout << "Your GAME is OVER!" << endl;

}
//this function allows the users to bring up the menu and
//gives the user the options to either attack or run
char menu()
{
	char choice;
	cout << "An enemy lies before you, what will you do?" << endl;
	cout << " \'a\'  attack, \'b\' run \n" << endl;
	cin >> choice;
	return choice;
}

//this function calculates the total amount of damage
//the player will receive from the enemy
void takeHit(int &playerHP)
{
	int enemyAttack(rand() % 5 + 1);
	playerHP = playerHP - enemyAttack;
	cout << "The enemy strikes you for " << enemyAttack << " damage" << endl;
	
	if (playerHP > 0)
	{
		cout << playerHP << " HP remains!" << endl;
	}
	else
	{
		cout << "You have been demolished!!" << endl;
	}
}

//this function calculates the amount of damage
//the enemy receives from the player's attack
int makeAttack(int enemyHP)
{
	int playerAttack = (rand() % 3 + 1);
	int newenemyHP = enemyHP - playerAttack;
	cout << "You strike your foe for " << playerAttack << " damage" << endl;

	//this part changes the text depending on the enemy's HP
	if (newenemyHP > 0)
	{
		cout << newenemyHP << " enemy HP remains!" << endl;
	}

	return newenemyHP;
}

/*
Starting the RPG!
You spawned with 20 health!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 2 damage
18 HP remains!
You strike your foe for 2 damage
8 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 5 damage
13 HP remains!
You strike your foe for 3 damage
5 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 4 damage
9 HP remains!
You strike your foe for 1 damage
4 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 1 damage
8 HP remains!
You strike your foe for 3 damage
1 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 2 damage
6 HP remains!
You strike your foe for 3 damage
Your GAME is OVER!
*/

/*
Starting the RPG!
You spawned with 20 health!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 1 damage
19 HP remains!
You strike your foe for 2 damage
8 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

a
The enemy strikes you for 2 damage
17 HP remains!
You strike your foe for 2 damage
6 enemy HP remains!
An enemy lies before you, what will you do?
 'a'  attack, 'b' run

b
You quickly ran away!
Your GAME is OVER!
*/