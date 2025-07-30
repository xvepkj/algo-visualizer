#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "algorithms/bubble_sort.hpp"
#include "algorithms/selection_sort.hpp"
#include "algorithms/insertion_sort.hpp"
#include "algorithms/merge_sort.hpp"
#include "bar_draw.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple Bubble Sort Visualizer");

    const int numBars = 50;
    std::vector<int> values(numBars);

    // Random values
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int &v : values) v = std::rand() % 500 + 50;

    MergeSortStepper sorter(numBars);
    MergeDrawFunc drawFunc = drawMergeBars;
    
    bool running = true;
    int frameCount = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        frameCount++;
        // Control the speed of sorting
        if (frameCount % 100000 == 0) {
            if (running)
                running = sorter.step(values);

            // Draw the bars
            window.clear();
            drawFunc(window, values, sorter.getLeft(), sorter.getMid(), sorter.getRight(), sorter.getCurrentIndex());
            window.display();
        }
    
    }
}
