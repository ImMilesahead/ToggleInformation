#include <SFML/Graphics.hpp>

#define WIDTH 1920
#define HEIGHT 1080

class Main {
private:
    sf::RenderWindow *app;
    sf::Clock clock;
    bool visible = false;
    sf::Text myText;
    sf::Font myFont;
public:
    Main();
    Main(sf::RenderWindow *app){
        this -> app = app;
        (*app).setPosition(sf::Vector2i(0, 0));
        if(!myFont.loadFromFile("arial.ttf")){}else{
            myText.setFont(myFont);
            myText.setString("Hello World!");
            myText.setCharacterSize(72);
            myText.setColor(sf::Color::Red);
            myText.setStyle(sf::Text::Bold | sf::Text::Underlined);
        }
    }
    void update();
    bool toggleWindow();
};

void Main::update(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
        this -> toggleWindow();
    }
    if (visible){
        (*app).draw(myText);
    }
}

bool Main::toggleWindow(){
    sf::Time time = clock.restart();
    if (time.asSeconds() >= 0.1f){
        visible = !visible;
        (*app).setVisible(visible);
        (*app).setPosition(sf::Vector2i(0, 0));
    }
    return true;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hello World!", sf::Style::None);     // Create and initialize the main window
    Main mainLoop(&window);
    while (window.isOpen()){     // Start the game loop
        window.clear(sf::Color::White);  // Clear the screen and set the background color
        mainLoop.update();
        window.display();   // Update the window
    }
    return EXIT_SUCCESS;
}
