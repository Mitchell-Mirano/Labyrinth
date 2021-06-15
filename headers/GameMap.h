#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
    {
        private:
            /* data */
        public:
            GameMap();
            bool IsGameOver;
            MapCell* PlayerCell;
            MapCell cells[15][10];
            void DrawIntro();
            void Draw();
            void DrawTreasure();
            string SetPlayerCell(int Playerx, int Playery);

        protected:
            void LoadMapFromFile();

    };

#endif //GameMap_H