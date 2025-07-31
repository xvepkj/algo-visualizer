#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "algorithms/bubble_sort.hpp"
#include "algorithms/selection_sort.hpp"
#include "algorithms/insertion_sort.hpp"
#include "algorithms/merge_sort.hpp"
#include "algorithms/normal_search.hpp"
#include "algorithms/binary_search.hpp"
#include "bar_draw.hpp"
#include <thread>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simple Visualizer");

    const int numBars = 50;
    std::vector<int> values(numBars);
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (int &v : values) v = std::rand() % 500 + 50;

    bool ran = false;

    BinarySearch searcher;

    while(window.isOpen()) {
        if(!ran) searcher.binarySearch(window, values, 300); // Example target value 
        ran = true;
    }
    
    //bool running = true;

    //while (window.isOpen()) {
        // Control the speed of sorting
        // if (running) {
        //     //running = sorter.step(values);

        //     // Draw the bars
        //     window.clear();
        //     //drawFunc(window, values, sorter.getLeft(), sorter.getMid(), sorter.getRight(), sorter.getCurrentIndex());
        //     window.display();
        //     //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        // }
    //}
}
