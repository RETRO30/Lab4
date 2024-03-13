
#include "Text.hpp"
#include <iostream>
#include <cmath>

sf::Vector2f round(const sf::Vector2f vector)
{
        return sf::Vector2f{std::round(vector.x), std::round(vector.y)};
}

text::MyText::MyText(std::string text)
{
        this->text = text;
        this->printedText = "";
        this->font = new sf::Font();
        this->sfText = new sf::Text();
        this->Size = 50;
        this->font->loadFromFile("Ubuntu-Bold.ttf");
}

text::MyText::~MyText()
{
        delete this->sfText;
        delete this->font;
}

void text::MyText::update(sf::RenderWindow &window)
{
        this->sfText->setFont(*this->font);
        this->sfText->setString(this->printedText);
        this->sfText->setCharacterSize(this->Size);
        this->sfText->setFillColor(sf::Color::White);
        this->sfText->setStyle(sf::Text::Bold);
        auto center = this->sfText->getGlobalBounds().getSize() / 2.f;
        auto localBounds = center + this->sfText->getLocalBounds().getPosition();
        auto rounded = round(localBounds);
        this->sfText->setOrigin(rounded);
        this->sfText->setPosition(300, 50);
        this->verbAnimationText();
        window.draw(*this->sfText);
}

void text::MyText::runTimers()
{
        this->intervalTimer.restart();
        this->timer.restart();
}

bool text::MyText::isShowedText()
{
        return this->isShowed;
}

void text::MyText::verbAnimationText()
{
        if (this->printedText.size() < this->text.size())
        {
                if (this->intervalTimer.getElapsedTime().asSeconds() > 1)
                {
                        char next = this->text[this->printedText.size()];
                        if (this->volwes.find(next) != std::string::npos)
                        {
                                this->Size -= 5;
                        }
                        else
                        {
                                this->Size += 5;
                        }
                        this->printedText += this->text[this->printedText.size()];
                        this->sfText->setString(this->printedText);
                        this->intervalTimer.restart();
                }
        }
        else if (!this->isShowed)
        {
                this->ShowTime += this->timer.getElapsedTime();
                std::cout << "Time: " << this->ShowTime.asSeconds() << std::endl;
                this->isShowed = true;
        }
}