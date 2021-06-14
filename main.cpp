#include <iostream>
#include "src/Player.cpp"
#include "src/MapCell.cpp"
#include "src/GameMap.cpp"
using namespace std;

int main()
    {
        bool isGameOver=false;
        GameMap map;
        Player hero;
        map.DrawIntro();
        cout<<"Inicia el juego!!"<<endl;
        map.Draw();
        while (isGameOver==false)
            {
                hero.ImputPlayer();
                if(map.SetPlayerCell(hero.x, hero.y))
                    {
                        map.Draw();
                    }
                else
                    {
                        hero.ResetPosition();
                        map.Draw();
                    }

            }
      
    }