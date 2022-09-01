//
//  Classes.hpp
//  Blob
//
//  Created by Vera Makarova on 21.11.2021.
//

#ifndef Classes_hpp
#define Classes_hpp

#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>


using namespace std;




//#define width 50
//#define height 25
//
//#define MAXX 49
//#define MAXY 24

#define width 20 //20 is optimal
#define height 20

#define MAXX 19
#define MAXY 19

class Food{
    
private:
    int posx, posy;
    
public:
    Food();
    ~Food();

    bool goaly;
    vector <int> graph;
    vector <int> path;
    void give_food();
    //void give_food(vector<int> choices);
    int get_x();
    int get_y();
    int distance;
    void whatpath(vector <int> input);
    void set_walls(vector<int> walls);
    int nutrition;
    void give_nutrition();
    void give_goal(int x, int y);
};

//on-the-way food
//boundaries with different difficulty values (boloto?)
//optimal path picking -- A*
//more goals
//different blobs w/two diff strategies and make a race
//Qt graphics


class Blob{
    
private:
    bool life; //represents alive/dead
    //hunger level

    
    int posx, posy;
    //Coordinate position;
    
    //Coordinate food; //??
    //vector <int> graph;
    vector <int> is;
    vector <int> js;
    
public:
    Blob();
    ~Blob();
    
    int energy;
    vector <int> graph;
    void graph_make();
    void is_make();
    void js_make();
    bool alive();
    
    
    void next_move(int dir);
    void move_it();
    int path_length;
    
    int get_x();
    int get_y();
    
    void moves(int len);
    void feed(Food x);
    
    bool ate(int fx, int fy);
    
    vector<int> next_move_plan(vector <int> shortest_way);
    vector <int> get_path(int foodx, int foody);
    void move_it_there(vector<int> coords);
//    vector<int> choose_closest(vector<int> food1, vector<int> food2, vector<int> food3);
    Food choose(Food x, Food y, Food z);
   
    void set_walls(vector<int> walls);
    
    void choose_goal(Food x);

    
    
    
};





#endif /* Classes_hpp */
