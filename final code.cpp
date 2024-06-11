//#include <SFML/Graphics.hpp>
//#include<iostream>
//#include<time.h>
//#include <SFML/Graphics/Font.hpp>
//#include <SFML/Graphics/Text.hpp>
//#include<fstream>
//int score = 0;
//using namespace std;
//void loadHighScore(int& highScore) {
//    ifstream file("highscore.txt");
//    if (file.is_open()) {
//        file >> highScore;
//        file.close();
//    }
//}
//void saveHighScore(int highScore) {
//    ofstream file("highscore.txt");
//    if (file.is_open()) {
//        file << highScore;
//        file.close();
//    }
//}
//void swapvertical(int arr[8][8], int i, int j) {
//    while (i >= 2) {
//        arr[i + 2][j] = arr[i - 1][j];
//        i--;
//    }
//    arr[0][j] = (rand() % 5) + 1;
//    arr[1][j] = (rand() % 5) + 1;
//    arr[2][j] = (rand() % 5) + 1;
//}
//void swaphorizontal(int arr[8][8], int i, int j) {
//    while (i > 0) {
//        arr[i][j] = arr[i - 1][j];
//        arr[i][j + 1] = arr[i - 1][j + 1];
//        arr[i][j + 2] = arr[i - 1][j + 2];
//        i--;
//    }
//    arr[0][j] = (rand() % 5) + 1;
//    arr[0][j + 1] = (rand() % 5) + 1;
//    arr[0][j + 2] = (rand() % 5) + 1;
//}
//void sortcandies(int arr[8][8]) {
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 6; j++) {
//            if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2]) {
//                swaphorizontal(arr, i, j);
//            }
//        }
//    }
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 8; j++) {
//            if (arr[i][j] == arr[i + 1][j] && arr[i + 2][j] == arr[i + 1][j]) {
//                swapvertical(arr, i, j);
//            }
//        }
//    }
//}
//bool patternform(int arr[8][8]) {
//    for (int i = 0; i < 6; i++) {
//        for (int j = 0; j < 8; j++) {
//            if (arr[i][j] == arr[i + 1][j] && arr[i + 2][j] == arr[i + 1][j]) {
//                return true;
//            }
//            else if (arr[i][j] == arr[i][j + 1] && arr[i][j + 1] == arr[i][j + 2]) {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//void swap(int& a, int& b) {
//    int temp;
//    temp = a;
//    a = b;
//    b = temp;
//}
//
//int main() {
//    int highScore = 0;
//    loadHighScore(highScore);
//    int row, column;
//    int arr[8][8]; int random;
//    srand(time(0));
//    int selectedRow = 0;
//    int selectedColumn = 0;
//    Board Initialization
//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            random = (rand() % 5) + 1;
//            while (j >= 2 && arr[i][j - 2] == random && arr[i][j - 1] == random) {
//                random = (rand() % 5) + 1;
//            }
//            while (i >= 2 && arr[i - 2][j] == random && arr[i - 1][j] == random) {
//                random = (rand() % 5) + 1;
//            }
//            arr[i][j] = random;
//        }
//    }
//    int check = 2;
//    sf::RenderWindow window(sf::VideoMode(900, 600), "MENU", sf::Style::Close | sf::Style::Resize);
//
//
//    sf::Texture bg;
//    sf::Texture start;
//    sf::Texture exit;
//    sf::Texture arrow;
//
//
//    start.loadFromFile("startbutton.jpg");
//    exit.loadFromFile("exitbutton.jpg");
//    bg.loadFromFile("start.jpg");
//    arrow.loadFromFile("arrow.jpg");
//
//
//    sf::Sprite bgsprite;
//    sf::Sprite startsprite;
//    sf::Sprite exitsprite;
//    sf::Sprite arrowsprite;
//
//
//    arrowsprite.setTexture(arrow);
//    startsprite.setTexture(start);
//    exitsprite.setTexture(exit);
//    bgsprite.setTexture(bg);
//
//    float scale_factor = 0.5;
//    startsprite.setScale(scale_factor, scale_factor);
//    exitsprite.setScale(scale_factor, scale_factor);
//    arrowsprite.setScale(scale_factor / 8, scale_factor / 8);
//
//    startsprite.setPosition(450, 330);
//    exitsprite.setPosition(450, 430);
//    arrowsprite.setPosition(395, 340);
//
//    sf::Clock clock;
//    float timer = 0.0f;
//    sf::Time deltaTime;
//
//    const float maxTime = 60.0f; // Set the maximum time in seconds (1 minute in this case)
//
//    while (window.isOpen()) {
//        deltaTime = clock.restart();
//        timer += deltaTime.asSeconds();
//
//        sf::Event evnt;
//        while (window.pollEvent(evnt)) {
//            switch (evnt.type) {
//            case sf::Event::Closed:
//                window.close();
//                break;
//            case sf::Event::Resized:
//                cout << "new window height : " << evnt.size.height << " new width : " << evnt.size.width << endl;
//                break;
//            }
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && check % 2 == 0) {
//            arrowsprite.move(0, 100);
//            check++;
//        }
//        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && check % 2 == 1) {
//            arrowsprite.move(0, -100);
//            check++;
//        }
//
//        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
//             Reset score when entering the game mode
//            score = 0;
//            window.close();
//        }
//
//        window.clear();
//        window.draw(bgsprite);
//        window.draw(startsprite);
//        window.draw(exitsprite);
//        window.draw(arrowsprite);
//        window.display();
//    }
//    if (check % 2 == 0) {
//        sf::RenderWindow newwindow(sf::VideoMode(600, 600), "GAME", sf::Style::Close | sf::Style::Resize);
//        sf::Texture selectorTexture;
//        selectorTexture.loadFromFile("selector.png");
//        sf::Sprite selectorSprite;
//        selectorSprite.setTexture(selectorTexture);
//        selectorSprite.setScale(50.0 / selectorTexture.getSize().x, 50.0 / selectorTexture.getSize().y);
//
//        int selectorRow = 0;
//        int selectorColumn = 0;
//
//        sf::Texture newbg;
//        sf::Texture can1;
//        sf::Texture can2;
//        sf::Texture can3;
//        sf::Texture can4;
//        sf::Texture can5;
//
//        can1.loadFromFile("cand1.png");
//        can2.loadFromFile("cand2.png");
//        can3.loadFromFile("cand3.png");
//        can4.loadFromFile("cand4.png");
//        can5.loadFromFile("cand5.png");
//        newbg.loadFromFile("gamebackground.jpg");
//
//        sf::Sprite can1sprite;
//        can1sprite.setTexture(can1);
//        sf::Sprite can2sprite;
//        can2sprite.setTexture(can2);
//        sf::Sprite can3sprite;
//        can3sprite.setTexture(can3);
//        sf::Sprite can4sprite;
//        can4sprite.setTexture(can4);
//        sf::Sprite can5sprite;
//        can5sprite.setTexture(can5);
//        sf::Sprite gamebgsprite;
//        gamebgsprite.setTexture(newbg);
//         Set the position and scale to cover the entire window
//        gamebgsprite.setPosition(0, 0);
//        gamebgsprite.setScale(1.0 * newwindow.getSize().x / newbg.getSize().x, 1.0 * newwindow.getSize().y / newbg.getSize().y);
//
//        score = 0;
//
//        sf::Font font;
//        font.loadFromFile("SIXTY.ttf");  // Change "arial.ttf" to the actual font file name
//
//        sf::Text timerText;
//        timerText.setFont(font);
//        timerText.setCharacterSize(24);
//        timerText.setFillColor(sf::Color::White);
//        timerText.setPosition(newwindow.getSize().x - 150, 50); // Adjust position based on your requirements
//
//        sf::Clock gameClock;
//
//        while (newwindow.isOpen()) {
//            timer += deltaTime.asSeconds();
//
//            while (patternform(arr)) {
//                sortcandies(arr);
//            }
//            sf::Event evnt;
//            while (newwindow.pollEvent(evnt)) {
//                switch (evnt.type) {
//                case sf::Event::Closed:
//                    newwindow.close();
//                    break;
//                case sf::Event::Resized:
//                    cout << "new window height : " << evnt.size.height << " new width : " << evnt.size.width << endl;
//                    break;
//                }
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
//                if (selectorColumn < 7) {
//                    selectorColumn++;
//                    selectorSprite.move(50, 0);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
//                if (selectorColumn > 0) {
//                    selectorColumn--;
//                    selectorSprite.move(-50, 0);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
//                if (selectorRow < 7) {
//                    selectorRow++;
//                    selectorSprite.move(0, 50);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) {
//                if (selectorRow > 0) {
//                    selectorRow--;
//                    selectorSprite.move(0, -50);
//                }
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
//                if (selectorRow > 0) {
//                    swap(arr[selectorRow][selectorColumn], arr[selectorRow - 1][selectorColumn]);
//                    if (!patternform(arr)) {
//                        swap(arr[selectorRow][selectorColumn], arr[selectorRow - 1][selectorColumn]);
//                    }
//                    else {
//                         Increment the score when a match is made
//                        score += 250;
//                    }
//                    pattern checking logic 
//                    sortcandies(arr);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
//                if (selectorColumn > 0) {
//                    swap(arr[selectorRow][selectorColumn], arr[selectorRow][selectorColumn - 1]);
//                    if (!patternform(arr)) { swap(arr[selectorRow][selectorColumn], arr[selectorRow][selectorColumn - 1]);
//                    }
//                    else {
//                         Increment the score when a match is made
//                        score += 250;
//                    }
//                    pattern checking logic 
//                    sortcandies(arr);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
//                if (selectorRow < 7) {
//                    swap(arr[selectorRow][selectorColumn], arr[selectorRow + 1][selectorColumn]);
//                    if (!patternform(arr)) { swap(arr[selectorRow][selectorColumn], arr[selectorRow + 1][selectorColumn]); 
//                    }
//                    else {
//                         Increment the score when a match is made
//                        score += 250;
//                    }
//                    pattern checking logic 
//                    sortcandies(arr);
//                }
//            }
//            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
//                if (selectorColumn < 7) {
//                    swap(arr[selectorRow][selectorColumn], arr[selectorRow][selectorColumn + 1]);
//                    if (!patternform(arr)) { swap(arr[selectorRow][selectorColumn], arr[selectorRow][selectorColumn + 1]);
//                    }
//                    else {
//                         Increment the score when a match is made
//                        score += 250;
//                    }
//                    pattern checking logic 
//                    sortcandies(arr);
//                }
//            }
//
//            newwindow.clear();
//            newwindow.draw(gamebgsprite);
//
//            for (int i = 0; i < 8; i++) {
//                for (int j = 0; j < 8; j++) {
//                     Assuming candy textures are named can1, can2, can3, can4, can5
//                    sf::Sprite candySprite;
//                    string candyTextureName = "cand" + to_string(arr[i][j]) + ".png";
//                    sf::Texture candyTexture;
//                    candyTexture.loadFromFile(candyTextureName);
//                    candySprite.setTexture(candyTexture);
//                    candySprite.setScale(50.0 / candyTexture.getSize().x, 50.0 / candyTexture.getSize().y);
//                    candySprite.setPosition(j * 50, i * 50); // Adjust position based on your requirements
//                    newwindow.draw(candySprite);
//                }
//            }
//
//            selectorSprite.setPosition(selectorColumn * 50, selectorRow * 50);
//            newwindow.draw(selectorSprite);
//             Add this part to display the timer
//            float remainingTime = maxTime - gameClock.getElapsedTime().asSeconds();
//            if (remainingTime < 0.0f) {
//                 Ensure the timer doesn't display negative values
//                remainingTime = 0.0f; 
//                newwindow.close();
//            }
//
//            timerText.setString("Time: " + std::to_string(static_cast<int>(remainingTime)));
//            newwindow.draw(timerText);
//
//            sf::Font font;
//            font.loadFromFile("SIXTY.ttf"); 
//
//            sf::Text scoreText;
//            scoreText.setFont(font);
//            scoreText.setString("Score: " + std::to_string(score));
//            scoreText.setCharacterSize(24);
//            scoreText.setFillColor(sf::Color::White);
//            scoreText.setPosition(newwindow.getSize().x - 150, 20);
//
//            sf::Text highScoreText;
//            highScoreText.setFont(font);
//            highScoreText.setString("High Score: " + std::to_string(highScore));
//            highScoreText.setCharacterSize(24);
//            highScoreText.setFillColor(sf::Color::White);
//            highScoreText.setPosition(newwindow.getSize().x - 150, 80); 
//            newwindow.draw(highScoreText);
//
//            newwindow.draw(scoreText);
//            newwindow.display();
//
//            if (score > highScore) {
//                highScore = score;
//                saveHighScore(highScore);
//            }
//
//            if (timer >= maxTime) {
//            //     Close the game window after the specified time
//                newwindow.close();
//            }
//        }
//    }
//    else cout << "game exited";
//    return 0;
//}