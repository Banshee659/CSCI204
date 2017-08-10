
/*------------------------------------------------------
Student's Name: Minh Thang Dau
Student's email address: mtd659@uowmail.edu.au
Laboratory group (group code and time): CL/03 Wednesday 17:30pm
Purpose of this assignment: Produce a Championship based on a round robin basis. The program will prompt and accept the league type and number of teams as input then generate a Championship. In the Championship, a total ½*n*(n – 1) games played will be implemented. The output of the program will be the result of each games played as well as a ranking table that shows a team's position, points, goal scored, goal against...Concept of C++ classes, constructors, destructors, operators, inheritance, composition, polymorphism will be taken into practice in this assignment.
-------------------------------------------------------*/

/* what left
1. operator

4. copy constructor */

#include<iostream>
#include"classes.h"
#include<cstdlib>
#include<string>
#include<cstring>
#include<iomanip>
#include<sstream>
using namespace std;
Game::Game() {
	//a_team = new Team[2];
}
Game::~Game() {

}
void Game::create_game(Team home, Team guest) {
	home_team = home;
	guest_team = guest;
	goal_home = rand() % 10;
	goal_guest = rand() % 10;
}


Team::Team() {

}
Team::~Team() {
}

/*void Team::set_point(int new_point) {
	total_points = new_point;
}*/
int Team::goal_difference() const {
	return goal_for - goal_against;
}

/*bool Team::operator<(const Team red, const Team& blue) const
{
    if(red.total_points > blue.total_points) return false;
    else if(red.total_points < blue.total_points) return false;
    else if(red.total_points == blue.total_points)
       {
           if(red.goal_difference() > blue.goal_difference())
            return true;
           if(red.goal_difference() < blue.goal_difference())
            return false;
            if(red.goal_difference() == blue.goal_difference())
            {

            }
       }

}
bool Team::operator==(Team &compare, ) const
{
    if(red.total_points > blue.total_points) return false;
    else if(red.total_points < blue.total_points) return false;
    else if(red.total_points == blue.total_points)
       {
           if(red.goal_difference() > blue.goal_difference())
            return true;
           if(red.goal_difference() < blue.goal_difference())
            return false;
            if(red.goal_difference() == blue.goal_difference())
            {

            }
       }
}
bool Team::operator>(Team &red, Team&blue) const
{
    if(red.total_points > blue.total_points) return false;
    else if(red.total_points < blue.total_points) return false;
    else if(red.total_points == blue.total_points)
       {
           if(red.goal_difference() > blue.goal_difference())
            return true;
           if(red.goal_difference() < blue.goal_difference())
            return false;
            if(red.goal_difference() == blue.goal_difference())
            {

            }
       }
}*/

Championship::Championship()
{
	a_team = new Team[num_of_team];
	int temp = 0.5*num_of_team*(num_of_team-1);
	a_game = new Game[temp];
}
Championship::~Championship() {
	delete [] a_team;
	delete [] a_game;
}

Championship::Championship(char* league, int num) { //constructor with number of teams and league type received from input as parameters
	num_of_team = num;
	strcpy(league_type, league);
}
void Championship::run_championship(Team *one_team, Game *one_game) { // generate all possible ½*n*(n – 1) games played in a random order among the teams for the whole season
	int index_game = 0; //index points to each game generated
	int temp = num_of_team;
	int num_Of_Game = 0.5* num_of_team*(num_of_team-1);
	a_team = one_team;
	a_game = one_game;


	for(int i = 0; i<num_of_team; i++) { //create Teams Team1, Team2, Team3
		/*char temp[5] = "Team";
		char number[10] ;
		strcat(temp,itoa(i+1, number, 10));
		a_team[i].set_name(temp);*/
		string temp2;
		stringstream convert;
		convert << i+1 ;
		temp2 = convert.str();
		string temp1 = "Team";
		temp1 += temp2;
		a_team[i].set_name(temp1);

	}
	for(int i =0; i < temp -1; i++) {
		for(int j = i+1; j < temp; j++) {
			a_game[index_game]->create_game(a_team[i],a_team[j]);

			if(a_game[index_game]->goal_home > a_game[index_game]->goal_guest) {
				//a_team[i].set_point(a_team[i].get_points() +2);
				a_team[i]->set_point(2);

			}
			if(a_game[index_game]->goal_home == a_game[index_game]->goal_guest) {
				//a_team[i].set_point(a_team[i].get_points() +1);
				//a_team[j].set_point(a_team[j].get_points() +1);
				a_team[i]->set_point(1);
				a_team[j]->set_point(1);

			}
			if(a_game[index_game]->goal_home < a_game[index_game]->goal_guest) {
				//a_team[j].set_point(a_team[j].get_points() + 2);
				a_team[j]->set_point(2);

			}
			a_team[i]->set_goal_for(a_game[index_game]->goal_home);
			a_team[i]->set_goal_against(a_game[index_game]->goal_guest);
			a_team[j]->set_goal_for(a_game[index_game]->goal_guest);
			a_team[j]->set_goal_against(a_game[index_game]->goal_home);
			index_game++;
		}

	}
	delete a_team;
	delete a_game;
}


int Championship::get_num_team() {
	return num_of_team;
}
void Championship::print() const {
	int num_game =  0.5* num_of_team*(num_of_team-1);
	cout << "*** " << league_type <<" " <<" League Championship ***" << endl;
	cout << "- Participant list -" << endl;
	cout << "Number of team " << " " << num_of_team << endl;

	for(int i = 0; i<num_of_team; i++)
    {
		cout << a_team[i]->team_name;
		cout << endl;
	}
	cout << "- Games played -" << endl;
	for(int i= 0; i < num_game; i++)
	{
		cout << a_game[i]->home_team.get_name()<< " " << a_game[i]->guest_team.get_name()<< " " << a_game[i]->goal_home
		     << " " << a_game[i]->goal_guest;
		cout << endl;
	}

	cout << "- Championship table -" << endl;
	cout << "| Team | Points | GoalDiff | GoalsFor | GoalsAgainst" << endl;
	for(int i = 0;  i< num_of_team; i++)
    {
		cout << setw(9) << a_team[i]->team_name << setw(9) << a_team[i]->get_points() << setw(9)  << a_team[i]->goal_difference() << setw(9) << a_team[i]->get_goal_for() << setw(9)  << a_team[i]->get_goal_against() << endl;
	}

}
