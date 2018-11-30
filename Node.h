#pragma once
#include"Obstacle.h"

struct Node
{
    Obstacle* unit;
    Node* next;
    Node* prev;

    ~Node()
    {
        delete unit;
    }
};

