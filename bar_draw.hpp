#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using DrawFunc = void(*)(sf::RenderWindow&, const std::vector<int>&, const int currentIndex, const int comparisonIndex);

inline void drawBars(sf::RenderWindow& window, const std::vector<int>& values, const int currentIndex = -1, const int comparisonIndex = -1) {
    int barWidth = 15, barSpacing = 16, windowHeight = 600;
    int numBars = values.size();
    for (int k = 0; k < numBars; ++k) {
        sf::RectangleShape bar(sf::Vector2f(barWidth, values[k]));
        bar.setPosition(k * barSpacing, windowHeight - values[k]);
        if (k == currentIndex || k == comparisonIndex) {
            bar.setFillColor(sf::Color::Red); // Highlight the current bar
        } else {
            bar.setFillColor(sf::Color::Green); // Normal bars
        }
        window.draw(bar);
    }
}