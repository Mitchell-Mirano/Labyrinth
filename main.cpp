#include <iostream>
#include "src/Player.cpp"
#include "src/MapCell.cpp"
#include "src/GameMap.cpp"
using namespace std;

int main()
    {
        GameMap map;
        Player hero;
        map.DrawIntro();
        cout<<"Inicia el juego!!"<<endl;
        map.Draw();
        while (map.IsGameOver==false)
            {
                hero.ImputPlayer();
                if(map.SetPlayerCell(hero.x, hero.y)=="NotBlocked")
                    { 
                        map.Draw();
                    }
                if (map.SetPlayerCell(hero.x, hero.y)=="IsBlocked")
        
                    {
                        hero.ResetPosition();
                        map.Draw();
                    }
                 if (map.SetPlayerCell(hero.x, hero.y)=="Treasure")
        
                    {
                        map.DrawTreasure();
                    }
            }
      
    }