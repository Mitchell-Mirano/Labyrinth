#include "../headers/GameMap.h"
#include <iostream>
#include <fstream>


using namespace std;

GameMap::GameMap()
    {   
        IsGameOver=false;
        PlayerCell=NULL;
        LoadMapFromFile();
        SetPlayerCell(1,1);
    }



void GameMap::DrawIntro()
    {
        string line;
        ifstream Myfile("designs/intro.txt");

        if (Myfile.is_open())
            {
                while (getline(Myfile, line))
                    {
                        cout <<line <<endl;
                    }
                    cin>>line;
            }
        else
            {
                cout<<"fatal error intro not loaded" <<endl;
            }
    }
void GameMap::DrawTreasure()
    {
        string line;
        ifstream Myfile("designs/treasure.txt");

        if (Myfile.is_open())
            {
                while (getline(Myfile, line))
                    {
                        cout <<line <<endl;
                    }
            }
        else
            {
                cout<<"fatal error treasure not loaded" <<endl;
            }
    }

void GameMap::Draw()
    {
        for (int x = 0; x < 15; x++)
        {
            for (int y = 0; y <15; y++)
            {
              cout<<cells[x][y].id;
            }
            cout<<endl;
        }  
    }

string GameMap::SetPlayerCell(int Playerx, int Playery)
    {
        if(cells[Playery][Playerx].isBlocked()==false)
            {
                if(cells[Playery][Playerx].isTreasure()==true)
                    {
                        DrawTreasure();
                        IsGameOver=true;
                        return "Treasure";
                    }
                else
                    {
                         if (PlayerCell!=NULL)
                            {
                                PlayerCell->id=' ';
                            }
                        PlayerCell=&cells[Playery][Playerx];
                        PlayerCell->id='H';
                        return "NotBlocked";
                    }
            }
        else 
            {
                return "IsBlocked";
            }
    }

void GameMap::LoadMapFromFile()
    {
        string line;
        ifstream Myfile("designs/map.txt");
        int row=0;
        if (Myfile.is_open())
            {
                while (getline(Myfile, line))
                    {
                        for (int i = 0; i <line.length(); i++)
                            {
                                if (line[i]=='0')
                                    {
                                        cells[row][i].id=' ';  
                                    }
                                else
                                    {
                                        cells[row][i].id=line[i];
                                    }
                            }
                        row++;
                    }
            }
        else
            {
                cout<<"fatal error the map was not loaded" <<endl;
            }

    }