//
//  Classes.cpp
//  Blob
//
//  Created by Vera Makarova on 21.11.2021.
//

#include "Classes.hpp"

Blob::Blob()//CHANGE LATER; SO DOESNT SPAWN ON WALL
{

    life = true;
    energy = 10; //20 is max, 0 is min
    
    is_make();
    js_make();
    
}

Blob::~Blob()
{};

void Blob::moves(int len)
{
    if(len%2 == 0) //so every 2 steps
    {
        if (energy >0)
        {
            energy = energy-1;
        }
        else
        {
            life = false;
        }
    }
}
bool Blob::alive()
{
    return this->life;
}
void Blob::feed(Food x)
{
    if (x.goaly)
    {
        energy = 10;
    }
    if(energy<20)
    {
        if(energy + x.nutrition<20)
        {
            energy = energy + x.nutrition;
        }
        else
        {
            energy = 20;
        }
    }
    
}

vector<int> client_walls(vector<int> choices)
{
    //choices is a vector of length 0 to 3
    
    vector <int> walls(height*width);
    
    //defaulting
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i==0 || i == height -1 || j==0 || j == width-1)
                {
                    walls[i*height +j] = 0;
                }
                else
                {
                    walls[i*height +j] = 1;
                }
                    
            }
        }
    
    //walls
    for (int k = 0; k<choices.size();k++) //going through choices
    {
        int op = choices[k];
        
        if (op ==1) //zigzag
        {
            for (int i = 0+3; i<6+3; i++)
            {
                if (i<2+3)
                {
                    for (int j = 0; j<11; j++)
                    {
                        if(j<8)
                        {
                            walls[i*height +j] = 0;
                        }
//                        else
//                        {
//                            cout<<" ";
//                        }
                    }
                }
                if (i==2+3 || i ==3+3)
                {
                    for (int j = 0; j<11; j++)
                    {
//                        if(j<5)
//                        {
//                            cout<<" ";
//                        }
                        if (j<8 && j>=5)
                        {
                            walls[i*height +j] = 0;
                        }
                        
                    }
                }
                if(i>3+3)
                {
                    for (int j = 0; j<11; j++)
                    {
//                        if(j<5)
//                        {
//                            cout<<" ";
//                        }
                        if (j>=5)
                        {
                            walls[i*height +j] = 0;
                        }
                        
                    }
                }

            }
        }
        
        if (op ==2) //verical
        {
            for (int i = 0; i<9; i++)
            {
                for (int j = 0+15; j<2+15; j++)
                {
                    walls[i*height +j] = 0;
                }
            }
        }
        if (op ==3) //arc
        {
            for (int i = 0+14; i<height; i++)
            {
                if (i<1+14)
                {
                    for (int j = 3; j<10; j++)
                    {
                        
                        walls[i*height +j] = 0;
                    }
                }
                else
                {
                    for (int j = 3; j<10; j++)
                    {
                        if(j==3 || j == 9)
                        {
                            walls[i*height +j] = 0;
                        }
                            
                    }
                }
            }
        }
    }
    
    return walls;
}


void Blob::set_walls(vector<int> walls)
{
    //vector<int> walls = wall_maker_line();
    this->graph = walls;
    
    
    int x = rand() % (MAXX-1) +1;
    int y = rand() % (MAXY-1) +1;
    
    while (!graph[y*height + x]) //if graph is 0 its a wall
    {
        x = rand() % (MAXX-1) +1;
        y = rand() % (MAXY-1) +1;
    }
    
    posx = x;
    posy = y;
}

void Food::set_walls(vector<int> walls)
{
    this->graph = walls;
    int x = rand() % (MAXX-1) +1;
    int y = rand() % (MAXY-1) +1;
    
    while (!graph[y*height + x]) //if graph is 0 its a wall
    {
        x = rand() % (MAXX-1) +1;
        y = rand() % (MAXY-1) +1;
    }
    
    posx = x;
    posy = y;
}



void Blob::is_make()
{
    vector <int> is(height*width);

    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                
                is[i*height +j] = i;
            }
        }
    
    this->is = is;
}

void Blob::js_make()
{
    vector <int> js(height*width);

    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                
                js[i*height +j] = j;
            }
        }
    
    this->js = js;
}

void Blob::choose_goal(Food x)
{
    path_length = x.path.size()-1;
}
Food Blob::choose(Food x, Food y, Food z)
{
    vector< Food> possibilities;
    possibilities.push_back(x);
    possibilities.push_back(y);
    possibilities.push_back(z);
    
    Food pick;
    
    int smallest = 10000;
    
    for (int i = 0; i<3; i++)
    {
        if(possibilities[i].path.size()
           < smallest) //so we multiply length by weight
        {
            smallest = possibilities[i].path.size();
            pick = possibilities[i];
        }
    }
    
    path_length = pick.path.size()-1; //-1, but we added one unneccesary at the end
    possibilities.clear();
    return pick;
        
    
}

void Food::whatpath(vector <int> input)
{
    this->path = input;
    //assigns path
}


vector <int> Blob::get_path(int foodx, int foody)
{
    vector <int> shortest_way;
    
    //WIDTH = HEIGHT for now!!!!
    //so posx = posy!!!

    
    queue <int> road;
    vector <bool> lit(height*width);
    vector <int> distance(height*width);
    vector <int> previous(height*width);
    

    int begin = this->posy*height + this->posx;
    int end = foody*height + foodx;
    
    
    road.push(begin);
    lit[begin] = true;
    previous[begin] = -1;
    
    int u = 0;
    
    while (!road.empty()) //while the queue is NOT empty
    {
        u++;
        int current = road.front(); //getting out our current vertex
        road.pop(); //deleting the vertex from our queue
        
//                    N.W   N   N.E
//                      \   |   /
//                       \  |  /
//                    W----Cell----E
//                         / | \
//                       /   |  \
//                    S.W    S   S.E
//
//                Cell-->Popped Cell (i, j)
        
//                N -->  North       (i-1, j)
//                S -->  South       (i+1, j)
//                E -->  East        (i, j+1)
//                W -->  West        (i, j-1)
//                N.E--> North-East  (i-1, j+1)
//                N.W--> North-West  (i-1, j-1)
//                S.E--> South-East  (i+1, j+1)
//                S.W--> South-West  (i+1, j-1)
        //LIMITS!????
        int i = is[current];
        int j = js[current];
        //cout<< i<< " "<<j<<endl;
        //for (int k = 0; k< 8; k++)
        {
            //if (i-1>0 && j-1>0 && i+1<height && j+1< width)
            {
                //(i-1, j)
                if (graph[(i-1)*height +j] == 1 && !lit[(i-1)*height +j])
                {
                    lit[(i-1)*height +j] = true;
                    road.push((i-1)*height +j);
                    distance[(i-1)*height +j] = distance[current]+1;
                    previous[(i-1)*height +j] = current;
                }
               
                //(i+1, j)
                if (graph[(i+1)*height +j] == 1 && !lit[(i+1)*height +j])
                {
                    lit[(i+1)*height +j] = true;
                    road.push((i+1)*height +j);
                    distance[(i+1)*height +j] = distance[current]+1;
                    previous[(i+1)*height +j] = current;
                }
                
                //(i, j+1)
                if (graph[i*height +j+1] == 1 && !lit[i*height +j+1])
                {
                    lit[i*height +j+1] = true;
                    road.push(i*height +j+1);
                    distance[i*height +j+1] = distance[current]+1;
                    previous[i*height +j+1] = current;
                }
                
                //(i, j-1)
                if (graph[i*height +j-1] == 1 && !lit[i*height +j-1])
                {
                    lit[i*height +j-1] = true;
                    road.push(i*height +j-1);
                    distance[i*height +j-1] = distance[current]+1;
                    previous[i*height +j-1] = current;
                }
                
                //(i-1, j+1)
                if (graph[(i-1)*height +(j+1)] == 1 && !lit[(i-1)*height +(j+1)])
                {
                    lit[(i-1)*height +(j+1)] = true;
                    road.push((i-1)*height +(j+1));
                    distance[(i-1)*height +(j+1)] = distance[current]+1;
                    previous[(i-1)*height +(j+1)] = current;
                }
                
                //(i-1, j-1)
                if (graph[(i-1)*height +(j-1)] == 1 && !lit[(i-1)*height +(j-1)])
                {
                    lit[(i-1)*height +(j-1)] = true;
                    road.push((i-1)*height +(j-1));
                    distance[(i-1)*height +(j-1)] = distance[current]+1;
                    previous[(i-1)*height +(j-1)] = current;
                }
                
                //(i+1, (j+1)
                if (graph[(i+1)*height +(j+1)] == 1 && !lit[(i+1)*height +(j+1)])
                {
                    lit[(i+1)*height +(j+1)] = true;
                    road.push((i+1)*height +(j+1));
                    distance[(i+1)*height +(j+1)] = distance[current]+1;
                    previous[(i+1)*height +(j+1)] = current;
                }
                
                //(i+1, j-1)
                if (graph[(i+1)*height +(j-1)] == 1 && !lit[(i+1)*height +(j-1)])
                {
                    lit[(i+1)*height +(j-1)] = true;
                    road.push((i+1)*height +(j-1));
                    distance[(i+1)*height +(j-1)] = distance[current]+1;
                    previous[(i+1)*height +(j-1)] = current;
                }
                
                //cout<<u<<endl;
            }
        }
    }
    
    //cout<< ";";
    if (!lit[end]) //could not reach goal!!!
    {
        path_length = -1;
    }
    
    else
    {
        for (int c = end; c!= -1; c = previous[c])
        {
            //cout<<c<<endl;
            shortest_way.push_back(c); //the ABS numbers of vertices on the way there
        }
        
        //cout<<shortest_way.size();
        
        if (shortest_way.size()==1)
        {
            cout << 0 << endl;
        }
        else
        {
            //cout << shortest_way.size()-1 << endl;
//            for (int c = shortest_way.size()-1; c >=0 ; c--)
//            {
//                cout << shortest_way[c] <<endl;
//            }
        }
    }
    
    //path_length = shortest_way.size()-1;//first index of our array
    
    return shortest_way;
}


vector<int> Blob::next_move_plan(vector <int> shortest_way)
//returns the ABS num of next destination
{
    
    
    vector<int> coords(2);
    int next = shortest_way[path_length];
    coords[0] = is[next];
    coords[1] = js[next];
    return coords;
}



void Blob::move_it_there(vector<int> coords)
{
    posx = coords[1];
    posy = coords[0];
    path_length--;
}


int Blob::get_x()
{
    return posx;
}
int Blob::get_y()
{
    return posy;
}

bool Blob::ate(int fx, int fy)
{
    if ((fx == this->posx) && (fy == this->posy))
    {
        return true;
    }
    else
    {
        return false;
    }
}



Food::Food() //inherited class of FOOD - by nutritional value!!!
{
    vector<int> g(height*width);
    this->graph = g;
    
    for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (i==0 || i == height -1 || j==0 || j == width-1)
                {
                    graph[i*height +j] = 0;
                }
                else
                {
                    graph[i*height +j] = 1;
                }

            }
        }
    give_food();
    goaly = false;
}

Food::~Food()
{};

void Food::give_nutrition()
{
    if(goaly)
    {
        nutrition = 0; //EEEE
    }
    else
    {
        nutrition = rand() % 10;
    }
}
void Food::give_food()
{
    //graph = wall_maker(); FIXXXX
    
    
    int x = rand() % (MAXX-1) +1;
    int y = rand() % (MAXY-1) +1;
    //cout<<posx<<endl;
    //cout<<posy<<endl;
    while (!graph[y*height + x]) //if graph is 0 its a wall
    {
        x = rand() % (MAXX-1) +1;
        y = rand() % (MAXY-1) +1;
    }
    posx = x;
    posy = y;
    
}
void Food::give_goal(int x, int y)
{
    posx = x;
    posy = y;
    
}


int Food::get_x()
{
    return posx;
}
int Food::get_y()
{
    return posy;
}
