#include "../headers/GameMap.h"
#include <iostream>
#include <fstream>



using namespace std;

GameMap::GameMap()
    {   
        PlayerCell=NULL;
        LoadMapFromFile();
    }



void GameMap::DrawIntro()
    {
        string line;
        ifstream Myfile("intro.txt");

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


void GameMap::Draw()
    {
        for (int x = 0; x < 15; x++)
        {
            for (int y = 0; y <10; y++)
            {
              cout<<cells[x][y].id;
            }
            cout<<endl;
        }  
    }

bool GameMap::SetPlayerCell(int Playerx, int Playery)
    {
        if(cells[Playery][Playerx].isBlocked()==false)
            {
                if (PlayerCell!=NULL)
                    {
                        PlayerCell->id=' ';
                    }

                PlayerCell=&cells[Playery][Playerx];
                PlayerCell->id='H';
                return true;
            }
        else 
            {
                return false;
            }
    }

void GameMap::LoadMapFromFile()
    {
        string line;
        ifstream Myfile("map.txt");
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