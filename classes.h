/*------------------------------------------------------
Student's Name: Minh Thang Dau
Student's email address: mtd659@uowmail.edu.au
Laboratory group (group code and time): CL/03 Wednesday 17:30pm
Purpose of this assignment: Produce a Championship based on a round robin basis. The program will prompt and accept the league type and number of teams as input then generate a Championship. In the Championship, a total ½*n*(n – 1) games played will be implemented. The output of the program will be the result of each games played as well as a ranking table that shows a team's position, points, goal scored, goal against...Concept of C++ classes, constructors, destructors, operators, inheritance, composition, polymorphism will be taken into practice in this assignment.
-------------------------------------------------------*/
#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include<iostream>
#include<string>
#include<cstring>
#include<sstream>

class Team {
    friend class Championship;
private:
    std::string team_name;
    //char team_name[20];
    int total_points; //total points
    int goal_for;
    int goal_against;
    int position;
public:
    Team();
    ~Team();
    //void set_name(char name[]){ strcpy(team_name, name);}
    void set_name(std::string team_name)
{this->team_name = team_name; }
    std::string get_name() const {return team_name;}
    //void set_point(int new_point); //update the points of each team after a game played
    void set_point(int new_point) { total_points += new_point;}
    int get_points() const { return total_points;}
    int goal_difference() const;
    int set_goal_for(int score) {return goal_for += score;}
    int set_goal_against(int score){return goal_against +=score;}
    int get_goal_for() const {return goal_for;}
    int get_goal_against() const{ return goal_against;}


    /*friend bool operator<(const Team& red, const Team& blue) const;
    friend bool operator>(const Team& red, const Team& blue) const;
    friend bool operator==(const Team& red, const Team& blue) const;
    friend bool operator!=(const Team& red, const Team& blue) const;*/
    };
class Game {
    friend class Championship;
private:
    int goal_home;
    int goal_guest;
    Team *home_team, *guest_team;
public:
    Game();
    ~Game();
    void create_game(Team home, Team guest);
    int get_home_goal() const { return goal_home;}
    int get_guest_goal() const { return goal_guest;}

};
class Championship{

private:
    char league_type[20];
    int num_of_team;
    Team *a_team; //dynamic memory
	Game *a_game;
public:
    Championship();
    virtual ~Championship();
    Championship(char* league, int num);
	void run_championship(Team *one_team, Game *one_game);

    int get_num_team();
    void print() const;
    };
#endif // CLASSES_H_INCLUDED
