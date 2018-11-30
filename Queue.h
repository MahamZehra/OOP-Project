#pragma once
#include"Node.h"

class Queue
{
private:
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Obstacle*);
    void Clean();
    void Render(SDL_Renderer* gRenderer);
    void Move();
};
