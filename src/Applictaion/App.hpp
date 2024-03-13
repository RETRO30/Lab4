#pragma once
#include <string>
#include "Text.hpp"

namespace app
{
        class App
        {
        private:
                sf::RenderWindow *window;
                float windowWidth;
                float windowHeight;
                std::string windowTitle;
                text::MyText *TextObject;
                bool SoundPlayed = false;

        public:
                App(float windowWidth = 600, float windowHeight = 100, std::string windowTitle = "Lab4");
                ~App();
                void run();
        };
}