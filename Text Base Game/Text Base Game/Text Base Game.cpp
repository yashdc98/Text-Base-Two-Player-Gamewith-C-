#include <iostream> 
#include <ctime> 
#include <cstdlib> 

using namespace std;

//This function is for generate random numbers
int Random(int max, int min)
{
	srand(time(NULL));

	int number = (rand() % (max - min + 1)) + min;
	return number;
}
class player
{
public:
	int P_Health, T_Damage, M_Heal, min_Heal, M_AddDamage, Min_AddDamage, MaxHealth, CurHealth; //all the varriable for the program
	bool isAlive;
	virtual void info() = 0; //function for player information

	void PlayerHealth()  //function for player health.
	{
		CurHealth = P_Health;
		isAlive = true;
	}

	void player_Damage()  //function for player damage.
	{
		P_Health -= T_Damage;
		CurHealth = P_Health;
		if (CurHealth <= 0)
		{
			cout << PlayerName() << " is dead !" << endl;
			isAlive = false;
		}
		else {

			cout << PlayerName() << " got damage by : " << T_Damage << endl;
			isAlive = true;
		}
	}
	void AddDamage() //functiomn for additional damage.
	{
		int A_Damage = Random(M_AddDamage, Min_AddDamage);
		CurHealth -= A_Damage;

		if (CurHealth <= 0)
		{
			cout << PlayerName() << " is dead !" << endl;
			isAlive = false;
			CurHealth = 0;
		}
		else
		{
			cout << PlayerName() << " got additional damage : " << A_Damage << endl;
			isAlive = true;
		}
	}

	void Damage_Player()
	{
		player_Damage();
		AddDamage();
	}

	void Healing()  //player health healing 
	{
		int Heal = Random(M_Heal, min_Heal);
		CurHealth += Heal;
		if (CurHealth >= MaxHealth)
		{
			CurHealth = MaxHealth;
			cout << PlayerName() << "You have full health you can't heal !" << endl;
		}
		else
		{
			cout << PlayerName() << "You healed by " << Heal << "points" << endl;
		}

	}
	void DisplayHealth()  //for displaying health in console.
	{
		if (CurHealth > 0)
		{
			cout << PlayerName() << " Health is :" << CurHealth << endl;
		}

	}
	bool Playeralive()
	{
		if (CurHealth <= 0)
		{
			return false;
		}

		else { return true; }
	}
	virtual string PlayerName()
	{
		return "Base player";
	}
	void GameRules()  //rules for the game.
	{
		cout << "#Rules------------------------------------------------------------"
			"------"
			<< endl
			<< "1. You have to select atleast Two player two start the game."
			<< endl
			<< "2. Each player have only one turn at the time." << endl
			<< "3. If the player health will 0, the player will die and game will "
			"be over."
			<< endl
			<< "4. Each and every player have their special ability to use, "
			"different health, different damage and different amount of "
			"healing power."
			<< endl
			<< "5. You have two controls in the game which is give damage to "
			"opposite player and other is to heal yourself."
			<< endl
			<< "6. You can give the damage by pressing 'D' and heal your self by "
			"pressing 'H'"
			<< endl;
	}
};

class Drax : public player
{
	//drax as the powerfull player

public:

	void info()
	{
		P_Health = 130;
		T_Damage = 30;
		M_Heal = 25;
		min_Heal = 15;
		M_AddDamage = 30;
		Min_AddDamage = 20;;
		MaxHealth = 130;


		cout << "Player Stats \n" << "Player name : " << PlayerName() << "\n" << "Player Health : " << P_Health << "\n Max damage : " << T_Damage << "\n Additional Damage : " << Min_AddDamage << "-" << M_AddDamage << " \n Healing power is :" << min_Heal << "-" << MaxHealth << endl;
	}

	string PlayerName()
	{
		return "Drax";
	}

};

class Cyborg : public player
{
	//Cyborg as the skillsull player

	void info()
	{
		P_Health = 100;
		T_Damage = 20;
		M_Heal = 20;
		min_Heal = 10;
		M_AddDamage = 20;
		Min_AddDamage = 10;;
		MaxHealth = 100;


		cout << "Player Stats \n" << "Player name : " << PlayerName() << "\n" << "Player Health : " << P_Health << "\n Max damage : " << T_Damage << "\n Additional Damage : " << Min_AddDamage << "-" << M_AddDamage << " \n Healing power is :" << min_Heal << "-" << MaxHealth << endl;
	}

	string PlayerName()
	{
		return "Cyborg";
	}
};

class Vecna : public player
{
	//Vecna as the Raged player
	void info()
	{
		P_Health = 80;
		T_Damage = 45;
		M_Heal = 30;
		min_Heal = 20;
		M_AddDamage = 30;
		Min_AddDamage = 20;;
		MaxHealth = 80;


		cout << "Player Stats \n" << "Player name : " << PlayerName() << "\n" << "Player Health : " << P_Health << "\n Max damage : " << T_Damage << "\n Additional Damage : " << Min_AddDamage << "-" << M_AddDamage << " \n Healing power is :" << min_Heal << "-" << MaxHealth << endl;
	}

	string PlayerName()
	{
		return "Vecna";
	}
};


player* Player_Selection()
{
	player* player;
	int num;
	cin >> num;
	if (num == 1)
	{
		cout << "You selected Drax For the battle ..." << endl;
		player = new Drax();
		player->info();
	}
	else if (num == 2)
	{
		cout << "You selected Cyborg for the battle..." << endl;
		player = new Cyborg();
		player->info();
	}
	else if (num == 3)
	{
		cout << "You selected Vecna for the battle..." << endl;
		player = new Vecna();
		player->info();
	}
	else {
		cout << "You entered wrong input... Enter the value again..." << endl;

		return Player_Selection();
	}
	return player;
}
void play(player* plr, player* enmy)
{
	char plrInput;
	cout << "\nPress D to damage and Press H to heal : ";
	cin >> plrInput;

	switch (plrInput)
	{
	case 'd':
		enmy->Damage_Player();
		enmy->DisplayHealth();
		break;

	case 'h':
		plr->Healing();
		plr->DisplayHealth();
		break;

	default:
		cout << "Please choose right input d & h";
	}
}
int main()
{
	cout << "Let's start the game..." << endl;
	system("pause");
	player* p;
	p = new Drax();

	p->GameRules(); //printing rules for the game...

	cout << "Select player 1 by enter the number from 1 to 3" << endl; //player 1 selection
	player* p1 = Player_Selection();

	cout << "Select player 2 by enter the number from 1 to 3" << endl; //player 2 selection
	player* p2 = Player_Selection();


	string player1;
	string player2;

	player1 = p1->PlayerName();
	player2 = p2->PlayerName();
	int Turn = 1;
	bool BattleisContinue = true;  //if player is not dead then this will work as a true condition.
	do
	{
		cout << "Player 1 " << player1 << "It's your turn" << endl;
		play(p1, p2);

		cout << "Player 2 " << player2 << "It's your turn" << endl;
		play(p2, p1);

		if (p1->Playeralive() && p2->Playeralive())
		{
			BattleisContinue = true;
		}
		else if (!p1->Playeralive())
		{
			cout << player2 << "smashed the" << player1 << " and " << player2 << " Won the match..." << endl;
			BattleisContinue = false;
		}
		else if (!p2->Playeralive())
		{
			cout << player1 << "smashed the" << player2 << " and " << player1 << " Won the match..." << endl;
			BattleisContinue = false;
		}

	} while (BattleisContinue);

}