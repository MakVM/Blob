//
//  main.cpp
//  Blob
//
//  Created by Vera Makarova on 21.11.2021.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <unistd.h>
#include "Classes.hpp"

#include <ncurses.h>
#include <curses.h>

#include <time.h>
#include <unistd.h>

#include "Classes.cpp" //for execution in terminal

//#define width 50
//#define height 25


using namespace std;

Blob blobie;
Food apple;
Food pear;
Food pizza;
Food goal;

void Build_Map()
{
    int bx = blobie.get_x();
    int by = blobie.get_y();

    for (int i = 0; i<height; i++) //from 0 to 25
    {
        cout << "0";
        for (int j = 1; j<width-1; j++)
            //from 0 to 47, cuz we have already printed 2
        {
            if ( i==0 || i==height -1) //border
            {
                cout << "0";
            }
            else if (!blobie.graph[i*height +j])
            {
                cout << "0";
            }
            else if (bx == j && by == i) //blob
            {
                cout << "ö";
            }
            else //space
            {
                cout << " ";
            }
            
        }
        cout << "0\n";
    }
}

void Build_Map_Goal(int xcord, int ycord)
{
    int bx = blobie.get_x();
    int by = blobie.get_y();

    for (int i = 0; i<height; i++) //from 0 to 25
    {
        cout << "0";
        for (int j = 1; j<width-1; j++)
            //from 0 to 47, cuz we have already printed 2
        {
            if ( i==0 || i==height -1) //border
            {
                cout << "0";
            }
            else if (!blobie.graph[i*height +j])
            {
                cout << "0";
            }
            else if (bx == j && by == i) //blob
            {
                cout << "ö";
            }
            else if (xcord == j && ycord == i) //blob
            {
                cout << "!";
            }
            else //space
            {
                cout << " ";
            }
            
        }
        cout << "0\n";
    }
}

void Map_with_goal(int gx, int gy)
{
    int bx = blobie.get_x();
    int by = blobie.get_y();
    
    int applex = apple.get_x();
    int appley = apple.get_y();
    
    int pearx = pear.get_x();
    int peary = pear.get_y();
    
    int pizzax = pizza.get_x();
    int pizzay = pizza.get_y();
    
    for (int i = 0; i<height; i++) //from 0 to 25
    {
        cout << "0";
        for (int j = 1; j<width-1; j++)
            //from 0 to 47, cuz we have already printed 2
        {
            if ( i==0 || i==height -1) //border
            {
                cout << "0";
            }
            else if (bx == j && by == i) //blob
            {
                cout << "ö";
            }
            
            
            
            else if ((applex == j && appley == i))
            {
                cout << "Ω";
            }
            else if ((pearx == j && peary == i))
            {
                cout << "∂";
            }
            else if ((pizzax == j && pizzay == i))
            {
                cout << "∆";
            }
            
            else if ((gx == j && gy == i))
            {
                cout << "!";
            }
            
            
            else if (!blobie.graph[i*height +j])
            {
                cout << "0";
            }
            
            
            else //space
            {
                cout << " ";
            }
            
        }
        cout << "0\n";
    }
    cout<<endl;
    cout<<"NUTRIONAL VALUES:"<<endl;
    
    //CHANGE
    cout<<"∂ -> "<< pear.nutrition <<endl;
    cout<<"∆ -> "<< apple.nutrition <<endl;
    cout<<"Ω -> "<< pizza.nutrition <<endl;
    
    cout<<endl;
    cout<<"LIFE BAR:"<<endl;
    cout<<"[";
    int i = 0;
    int k = 0;
    while(i<20)
    {
        if(k<blobie.energy) //chnageg!!!! based on blob info
        {
            cout<<"=";
            k++;
        }
        else
        {
            cout<<" ";
        }
        i++;
    }
    cout<<"]";
    cout<<endl;
}

    
void Map()
{
    int bx = blobie.get_x();
    int by = blobie.get_y();
    
    int applex = apple.get_x();
    int appley = apple.get_y();
    
    int pearx = pear.get_x();
    int peary = pear.get_y();
    
    int pizzax = pizza.get_x();
    int pizzay = pizza.get_y();
    
    for (int i = 0; i<height; i++) //from 0 to 25
    {
        cout << "0";
        for (int j = 1; j<width-1; j++)
            //from 0 to 47, cuz we have already printed 2
        {
            if ( i==0 || i==height -1) //border
            {
                cout << "0";
            }
            else if (bx == j && by == i) //blob
            {
                cout << "ö";
            }
            
            
            
            else if ((applex == j && appley == i))
            {
                cout << "Ω";
            }
            else if ((pearx == j && peary == i))
            {
                cout << "∂";
            }
            else if ((pizzax == j && pizzay == i))
            {
                cout << "∆";
            }
            
            
            
            
            else if (!blobie.graph[i*height +j])
            {
                cout << "0";
            }
            
            
            else //space
            {
                cout << " ";
            }
            
        }
        cout << "0\n";
    }
    
    cout<<endl;
    cout<<"NUTRIONAL VALUES:"<<endl;
    
    //CHANGE
    cout<<"∂ -> "<< pear.nutrition <<endl;
    cout<<"∆ -> "<< apple.nutrition <<endl;
    cout<<"Ω -> "<< pizza.nutrition <<endl;
    
    cout<<endl;
    cout<<"LIFE BAR:"<<endl;
    cout<<"[";
    int i = 0;
    int k = 0;
    while(i<20)
    {
        if(k<blobie.energy) //chnageg!!!! based on blob info
        {
            cout<<"=";
            k++;
        }
        else
        {
            cout<<" ";
        }
        i++;
    }
    cout<<"]";
    cout<<endl;
}


int main() {
    
    cout<<"Here are your wall options:"<<endl;
    
    cout<<"_1_"<<endl;
    cout<<endl;
    
    //ZIG
    for (int i = 0; i<6; i++)
    {
        if (i<2)
        {
            for (int j = 0; j<14; j++)
            {
                if(j<8)
                {
                    cout<<"0";
                }
                else
                {
                    cout<<" ";
                }
            }
        }
        if (i==2 || i ==3)
        {
            for (int j = 0; j<14; j++)
            {
                if(j<5)
                {
                    cout<<" ";
                }
                if (j<8 && j>=5)
                {
                    cout<<"0";
                }
                
            }
        }
        if(i>3)
        {
            for (int j = 0; j<14; j++)
            {
                if(j<5)
                {
                    cout<<" ";
                }
                if (j>=5)
                {
                    cout<<"0";
                }
                
            }
        }
        cout<<endl;
    }
    
    cout<<"_2_"<<endl;
    cout<<endl;
    
    //VERtiCAL
    for (int i = 0; i<9; i++)
    {
        for (int j = 0; j<2; j++)
        {
            cout<<"0";
        }
        cout<<endl;
    }
    
    cout<<"_3_"<<endl;
    cout<<endl;
    
    //Arc
    for (int i = 0; i<8; i++)
    {
        if (i<1)
        {
            for (int j = 0; j<10; j++)
            {
                
                    cout<<"0";
            }
        }
        else
        {
            for (int j = 0; j<10; j++)
            {
                if(j==0 || j == 9)
                {
                    cout<<"0";
                }
                else
                {
                    cout<<" ";
                }
                    
            }
        }
        
        cout<<endl;
    }
    
    

    cout<<"Please specify the how many walls you want to build:"<<endl;
    int num;
    cin>> num;
    vector<int> choices;
    while (num!= 0)
    {
        cout<<"Please specify the kind of wall that you want: (1/2/3)"<<endl;
        int kind;
        cin>> kind;
        choices.push_back(kind);
        num--;
    }
    
    //builds the matrix of walls
    vector<int> walls = client_walls(choices);
    
    blobie.set_walls(walls); //assigns to blobie's graph our walls & picks its starting position
    apple.set_walls(walls);
    pear.set_walls(walls);
    pizza.set_walls(walls);

    cout<<"Here's your final map:"<<endl;
    //showing the results
    Build_Map();
    
    
    
    
while(blobie.alive())
{
    cout<<"Do you want to set a goal point [1], quit [0] or watch undisturbed mode? [any other key]"<<endl;
    cin>> num;
    
    if (num ==0) //quit
    {
        return 0;
    }
    if (num == 1)
    {
        cout<<"Specify the coordinates of your goal point (within boundaties of 0 to 20):"<<endl;
        cout<<"X:"<<endl;
        int xcord;
        cin>>xcord;
        cout<<"Y:"<<endl;
        int ycord;
        cin>>ycord;
        
        //check for wall
        while(!blobie.graph[ycord*height +xcord] || (xcord == blobie.get_x() && ycord == blobie.get_y()) )
        {
            cout<<"That's a wall! Try again:"<<endl;
            cout<<"X:"<<endl;
            cin>>xcord;
            cout<<"Y:"<<endl;
            cin>>ycord;
        }
        
        cout<<"Here's your final map:"<<endl;
        Build_Map_Goal(xcord, ycord);
        cout<<"Continue? (to quit: [0])"<<endl;
        cin>>num;
        if (num==0)
        {
            return 0;
        }
        
//        Food goal;
        goal.goaly = true;
        goal.set_walls(walls);
        goal.give_goal(xcord, ycord);
        
        
        goal.give_nutrition();
        apple.give_nutrition();
        pear.give_nutrition();
        pizza.give_nutrition();
        
        goal.whatpath(blobie.get_path(goal.get_x(), goal.get_y()));
        
        apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
        pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
        
        pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
        
        Food next = blobie.choose(apple, pear, pizza);

        while ((goal.path.size() > blobie.energy) && blobie.alive())
        {
            //do the exact same thing as with food
                system("clear");
                Map_with_goal(goal.get_x(), goal.get_y());
                
                if (blobie.ate(apple.get_x(), apple.get_y()))
                {
                    
                    blobie.feed(apple);
                    apple.give_food(); //moving it to another place
                    apple.give_nutrition();
                    
                    goal.whatpath(blobie.get_path(goal.get_x(), goal.get_y()));
                    apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
                    pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
                    pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));

                    next = blobie.choose(apple, pear, pizza);
                }
                
                if (blobie.ate(pear.get_x(), pear.get_y()))
                {
                    
                    blobie.feed(pear);
                    pear.give_food();
                    pear.give_nutrition();
                    
                    goal.whatpath(blobie.get_path(goal.get_x(), goal.get_y()));
                    apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
                    pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
                    pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
          
                    next = blobie.choose(apple, pear, pizza);
                }
                
                if (blobie.ate(pizza.get_x(), pizza.get_y()))
                {
                    
                    
                    blobie.feed(pizza);
                    pizza.give_food(); //moving it to another place
                    pizza.give_nutrition();
                    
                    goal.whatpath(blobie.get_path(goal.get_x(), goal.get_y()));
                    apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
                    pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
                    pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
                    
                    next = blobie.choose(apple, pear, pizza);
                }
                
                
                if (blobie.path_length>=0) //uses the last created thing===???
                {
            
                    vector<int> c = blobie.next_move_plan(next.path);

                    blobie.move_it_there(c);
                    blobie.moves(blobie.path_length);
                }
                
                
                else
                {
                        if(next.get_y() == apple.get_y() && next.get_x() == apple.get_x())
                        {
                            apple.give_food();
                            apple.give_nutrition();
                        }
                        if(next.get_y() == pear.get_y() && next.get_x() == pear.get_x())
                        {
                            pear.give_food();
                            pear.give_nutrition();
                        }
                        if(next.get_y() == pizza.get_y() && next.get_x() == pizza.get_x())
                        {
                            pizza.give_food();
                            pizza.give_nutrition();
                        }
                        
                    goal.whatpath(blobie.get_path(goal.get_x(), goal.get_y()));
                    apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
                    pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
                    pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
                    //next = blobie.choose_closest(apple.path, pear.path, pizza.path);
                    next = blobie.choose(apple, pear, pizza);
                    //continue;
                }

                usleep(100000*2); //1000000 - 1 second
            
        } //closing while goal
        
        //cout<< "HAHAAH"<<endl;
        next = goal;
        blobie.choose_goal(next);
        
        while(!blobie.ate(goal.get_x(), goal.get_y()) && blobie.alive())
        {
            system("clear");
            Map_with_goal(goal.get_x(), goal.get_y());
            
            if (blobie.ate(apple.get_x(), apple.get_y()))
            {
                
                blobie.feed(apple);
                apple.give_food(); //moving it to another place
                apple.give_nutrition();
                
            }
            
            if (blobie.ate(pear.get_x(), pear.get_y()))
            {
                
                blobie.feed(pear);
                pear.give_food();
                pear.give_nutrition();
                
            }
            
            if (blobie.ate(pizza.get_x(), pizza.get_y()))
            {
                
                
                blobie.feed(pizza);
                pizza.give_food(); //moving it to another place
                pizza.give_nutrition();
                
            }
            
            
            if (blobie.path_length>=0) //uses the last created thing===???
            {
        
                vector<int> c = blobie.next_move_plan(next.path);

                blobie.move_it_there(c);
                blobie.moves(blobie.path_length);
            }
            else
            {
                cout<< "Goal can't be reached!:("<<endl;
                break;
            }
            usleep(100000*2);
//
        }
        
        if (blobie.ate(goal.get_x(), goal.get_y()))
        {
            system("clear");
            Map_with_goal(goal.get_x(), goal.get_y());
            blobie.feed(goal);
            //cout<<blobie.energy<<endl;
            cout<<"Goal reached! Congrats!"<<endl;
        }
                
    }//closing num = 1 for goal
    
else
{
    apple.give_nutrition();
    pear.give_nutrition();
    pizza.give_nutrition();
    
    apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));

    pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
    
    pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
    
    Food next = blobie.choose(apple, pear, pizza);

    
    while(blobie.alive())
    {
        system("clear");
        Map();
        
        if (blobie.ate(apple.get_x(), apple.get_y()))
        {
            
            blobie.feed(apple);
            apple.give_food(); //moving it to another place
            apple.give_nutrition();
            

            apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
            pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
            pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));

            next = blobie.choose(apple, pear, pizza);
        }
        
        if (blobie.ate(pear.get_x(), pear.get_y()))
        {
            
            blobie.feed(pear);
            pear.give_food();
            pear.give_nutrition();
            
            apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
            pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
            pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
  
            next = blobie.choose(apple, pear, pizza);
        }
        
        if (blobie.ate(pizza.get_x(), pizza.get_y()))
        {
            
            
            blobie.feed(pizza);
            pizza.give_food(); //moving it to another place
            pizza.give_nutrition();
            
            apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
            pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
            pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
            
            next = blobie.choose(apple, pear, pizza);
        }
        
        
        if (blobie.path_length>=0) //uses the last created thing===???
        {
    
            vector<int> c = blobie.next_move_plan(next.path);

            blobie.move_it_there(c);
            blobie.moves(blobie.path_length);
        }
        
        
        else
        {
            
            
            
//            cout<< "Goal can't be reached!:("<<endl;
//            cout<< "Do you want to continue?"<<endl;
//            int num;
//            cin>> num;
//            if (num ==1)
//            {
                
                //DO SMTH ELSE
                //try again (generates food in a different place)
                if(next.get_y() == apple.get_y() && next.get_x() == apple.get_x())
                {
                    apple.give_food();
                    apple.give_nutrition();
                }
                if(next.get_y() == pear.get_y() && next.get_x() == pear.get_x())
                {
                    pear.give_food();
                    pear.give_nutrition();
                }
                if(next.get_y() == pizza.get_y() && next.get_x() == pizza.get_x())
                {
                    pizza.give_food();
                    pizza.give_nutrition();
                }
                
                apple.whatpath(blobie.get_path(apple.get_x(), apple.get_y()));
                pear.whatpath(blobie.get_path(pear.get_x(), pear.get_y()));
                pizza.whatpath(blobie.get_path(pizza.get_x(), pizza.get_y()));
                //next = blobie.choose_closest(apple.path, pear.path, pizza.path);
                next = blobie.choose(apple, pear, pizza);
//                continue;
//            }
//            else
//            {
//                break;
//            }
        }
        
        
        usleep(100000*2); //1000000 - 1 second
    
    }
        
}//closed num
}//closed while alive
    
    return 0;
}
