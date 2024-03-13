#include "App.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/SoundBuffer.hpp"
#include <iostream>

app::App::App(float windowWidth, float windowHeight, std::string windowTitle)
{
        this->windowWidth = windowWidth;
        this->windowHeight = windowHeight;
        this->windowTitle = windowTitle;
        this->window = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), this->windowTitle);
}

app::App::~App()
{
        delete this->window;
        delete this->TextObject;
}

void app::App::run()
{
        std::cout << "Enter text: " << std::endl;
        std::string input;

        char c;
        while (std::cin.get(c) && c != '\n')
        {
                input += c;
        }

        TextObject = new text::MyText(input);

        while (this->window->isOpen())
        {
                sf::Event event;
                while (this->window->pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                this->window->close();
                }
                if (TextObject->isShowedText() && !this->SoundPlayed)
                {
                        sf::SoundBuffer buffer;
                        buffer.loadFromFile("sound.wav");
                        sf::Sound sound(buffer);
                        sound.play();
                        while (sound.getStatus() == sf::Sound::Playing)
                        {
                        }
                        this->SoundPlayed = true;
                }
                this->window->clear();
                TextObject->update(*this->window);
                this->window->display();
        }
}