#include "../headers/MapCell.h"
#include <iostream>
using namespace std;

MapCell::MapCell()
    {
        id=0;
    }

bool MapCell::isBlocked()
    {
        if(id=='1')
            {
                return true;
            }
        else
            {
                return false;
            }
    }

bool MapCell::isTreasure()
    {
        if (id=='$')
            {
                return true;
            }
        else
            {
                return false;
            }
    }
