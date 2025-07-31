#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

class NormalSearch {
public:
    static int linearSearch(sf::RenderWindow& window, std::vector<int>& values, int target) {
        for (int i = 0; i < values.size(); ++i) {
            if (values[i] == target) {
                return static_cast<int>(i); // Return the index of the found element
            }

            drawSearch(window, values, target, i);
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        return -1; // Return -1 if the target is not found
    }

        // Drawing function for visualization
    static void drawSearch(sf::RenderWindow& window, const std::vector<int>& values, int target, int currentIndex) {
        window.clear();
        
        int barWidth = 15, barSpacing = 16, windowHeight = 600;
        int numBars = values.size();

        // Draw the target bar at the far right
        sf::RectangleShape targetBar(sf::Vector2f(barWidth, target));
        targetBar.setPosition(window.getSize().x - barWidth - 10, windowHeight - target);
        targetBar.setFillColor(sf::Color::Yellow);
        window.draw(targetBar);

        // Draw the values array
        for (int k = 0; k < numBars; ++k) {
            sf::RectangleShape bar(sf::Vector2f(barWidth, values[k]));
            bar.setPosition(k * barSpacing, windowHeight - values[k]);
            if (k == currentIndex)
                bar.setFillColor(sf::Color::Red); // Highlight current index
            else
                bar.setFillColor(sf::Color::Green);
            window.draw(bar);
        }

        window.display();
    }
};