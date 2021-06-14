#include "../headers/Player.h"
#include <iostream>
using namespace std;

Player::Player()
    {
        x=1;
        y=1;
    }

void Player::ImputPlayer()
{
    char imput;

    cin>>imput;
    switch(imput)
    {
        case 'w':
            beforey=y;
            y=y-1;
            break;
        case 's':
            beforey=y;
            y=y+1;
            break;
        case 'd':
            beforex=x;
            x=x+1;
            break;
        case 'a':
            beforex=x;
            x=x-1;
            break;
        
        default:
            break;
    }
}


void Player::ResetPosition()
    {
        x=beforex;
        y=beforey;
    }