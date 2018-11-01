class Gutter
{
private:
    SDL_Rect mover;
    SDL_Texture* image;
public:
    Gutter();
    ~Gutter();
    void Draw(SDL_Renderer* gRenderer);
};

