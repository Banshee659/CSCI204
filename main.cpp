/*------------------------------------------------------
Student's Name: Minh Thang Dau
Student's email address: mtd659@uowmail.edu.au
Laboratory group (group code and time): CL/03 Wednesday 17:30pm
Purpose of this assignment: Produce a Championship based on a round robin basis. The program will prompt and accept the league type and number of teams as input then generate a Championship. In the Championship, a total ½*n*(n – 1) games played will be implemented. The output of the program will be the result of each games played as well as a ranking table that shows a team's position, points, goal scored, goal against...Concept of C++ classes, constructors, destructors, operators, inheritance, composition, polymorphism will be taken into practice in this assignment.
-------------------------------------------------------*/
#include<cstring>
#include"classes.h"
using namespace std;
int main(int argc, char* argv[])
{
    //Championship tournament;
    char league[20];
    int number_team;


    /*if(strcmp(argv[1], "soccer") == 0 || strcmp(argv[1], "hockey") == 0 || strcmp(argv[1], "handball") == 0)
    {
        strcpy(league, argv[1]);
    }
    else return -1;
    if (argc >= 2)
    {
        temp = atoi(argv[2]);
        number_team = argc;
    }
    else return -1;*/

    cout << "What is the name of the league" << endl;
    cin >> league;
    cout << "Number of team" << endl;
    cin >> number_team;
    Championship tournament(league, number_team);
    Team *one_team ;
    Game *one_game ;
    tournament.run_championship(one_team, one_game);
    tournament.print();
}
