class StartScreen : public Screen
{
private:
    LTexture* button;
    LTexture* font;

protected:

public:
    StartScreen(LTexture*, LTexture*, LTexture*);
    ~StartScreen();
    void Render(SDL_Renderer*);
    void LoadData();

};
