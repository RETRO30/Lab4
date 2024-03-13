#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace text
{
        class MyText
        {
        private:
                int Size;
                std::string text;
                std::string printedText;
                bool isShowed = false;
                sf::Clock intervalTimer;
                sf::Clock timer;
                sf::Time ShowTime;
                sf::Text *sfText;
                sf::Font *font;
                const std::string volwes = "aeiouy";

        public:
                MyText(std::string text = "Default Text");
                ~MyText();
                void update(sf::RenderWindow &window);
                void verbAnimationText();
                void runTimers();
                bool isShowedText();
        };
}