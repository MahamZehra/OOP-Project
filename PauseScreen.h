class PauseScreen : public Screen
{
private:
    SDL_Rect screen;

protected:

public:
    PauseScreen(LTexture*);
    ~PauseScreen();
    void Render(SDL_Renderer*);

};
