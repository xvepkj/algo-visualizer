#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

class BinarySearch {
public:
    static int binarySearch(sf::RenderWindow& window, const std::vector<int>& values, int target) {
        int left = 0;
        int right = static_cast<int>(values.size()) - 1;    
        while (left <= right) {
            int mid = left + (right - left) / 2;

            drawSearch(window, values, target, mid, left, right);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            if (values[mid] == target) {
                return mid; 
            } else if (values[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1; // Return -1 if the target is not found
    }

    static void drawSearch(sf::RenderWindow& window, const std::vector<int>& values, int target, int currentIndex, int left = -1, int right = -1) {
        window.clear();
        
        /*
            I want to draw the two sides of mid which current mid at middle and target 

        */

        int barWidth = 15, barSpacing = 16, windowHeight = 600;
        int numBars = values.size();
        // Draw the target bar at the far right
        sf::RectangleShape targetBar(sf::Vector2f(barWidth, target));
        targetBar.setPosition(window.getSize().x - barWidth - 10, windowHeight - target);
        targetBar.setFillColor(sf::Color::Yellow);
        window.draw(targetBar);


        // Draw the values array
        for (int k = left; k <= right; ++k) {
            sf::RectangleShape bar(sf::Vector2f(barWidth, values[k]));
            bar.setPosition(k * barSpacing, windowHeight - values[k]);
            if (k == currentIndex)
                bar.setFillColor(sf::Color::Red); // Highlight current index
            else if (k < currentIndex)
                bar.setFillColor(sf::Color::Blue); // Left side of mid
            else if (k > currentIndex)  
                bar.setFillColor(sf::Color::Magenta); // Right side of mid
            else
                bar.setFillColor(sf::Color::Green); // Normal bars
            window.draw(bar);
        }

        window.display();
    }

};    

