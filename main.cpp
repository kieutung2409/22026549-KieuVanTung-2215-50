#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <vector>
#include <cstdlib> // Để sử dụng rand()
#include <string>

// Kích thước cửa sổ
const int WINDOW_WIDTH = 1380;
const int WINDOW_HEIGHT = 773;

// Kích thước máy bay
const int PLANE_WIDTH = 60;
const int PLANE_HEIGHT = 60;

// Tốc độ di chuyển ban đầu của tảng đá
const int INITIAL_ROCK_SPEED = 3;

// Tốc độ tối đa của tảng đá
const int MAX_ROCK_SPEED = 15;

// Tốc độ tăng dần của tảng đá
const int ROCK_SPEED_INCREMENT = 1;

// Số lượng tảng đá di chuyển
const int NUM_ROCKS = 6;

// Tốc độ di chuyển của máy bay điều khiển
const int CONTROL_PLANE_SPEED = 15;

// Kích thước nút
const int BUTTON_WIDTH = 200;
const int BUTTON_HEIGHT = 50;

struct Plane {
    SDL_Rect rect;
    int speed;
};

// Các biến toàn cục
SDL_Rect myPlaneRect;
std::vector<Plane> movingRocks;
bool gameOver = false;
Uint32 startTime;
Uint32 endTime;
Mix_Chunk* crashSound = nullptr; // Biến cho âm thanh va chạm

// Hàm để vẽ văn bản lên màn hình
void renderText(SDL_Renderer* renderer, TTF_Font* font, const std::string &text, int x, int y) {
    SDL_Color White = {255, 255, 255}; 
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text.c_str(), White); 
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surfaceMessage); 
    SDL_Rect message_rect; 
    message_rect.x = x;  
    message_rect.y = y; 
    message_rect.w = surfaceMessage->w; 
    message_rect.h = surfaceMessage->h; 
    SDL_RenderCopy(renderer, message, NULL, &message_rect); 
    SDL_DestroyTexture(message);
    SDL_FreeSurface(surfaceMessage);
}

// Hàm để vẽ nút lên màn hình
void renderButton(SDL_Renderer* renderer, TTF_Font* font, const std::string &text, SDL_Rect buttonRect) {
    SDL_Color White = {255, 255, 255}; 
    SDL_Color Black = {0, 0, 0}; 
    SDL_Surface* surfaceButton = SDL_CreateRGBSurface(0, buttonRect.w, buttonRect.h, 32, 0xFF0000, 0x00FF00, 0x0000FF, 0xFF000000);
    SDL_FillRect(surfaceButton, NULL, SDL_MapRGB(surfaceButton->format, 0, 0, 0)); 
    SDL_Texture* buttonTexture = SDL_CreateTextureFromSurface(renderer, surfaceButton);
    SDL_FreeSurface(surfaceButton); 
    SDL_RenderCopy(renderer, buttonTexture, NULL, &buttonRect);
    SDL_DestroyTexture(buttonTexture);

    renderText(renderer, font, text, buttonRect.x + 10, buttonRect.y + 10);
}

// Hàm kiểm tra va chạm
bool checkCollision(const SDL_Rect& a, const SDL_Rect& b) {
    return (a.x < b.x + b.w &&
            a.x + a.w > b.x &&
            a.y < b.y + b.h &&
            a.y + a.h > b.y);
}

// Hàm kiểm tra sự kiện nhấp chuột trên nút
bool isMouseInsideButton(int mouseX, int mouseY, const SDL_Rect& buttonRect) {
    return (mouseX >= buttonRect.x && mouseX <= buttonRect.x + buttonRect.w &&
            mouseY >= buttonRect.y && mouseY <= buttonRect.y + buttonRect.h);
}

int main(int argc, char* argv[]) {
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Khởi tạo SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init: %s\n" << TTF_GetError();
        SDL_Quit();
        return 1;
    }

    // Khởi tạo SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("SDL Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Tải hình ảnh nền
    SDL_Surface* backgroundSurface = SDL_LoadBMP("backgroundgame.bmp");
    if (backgroundSurface == nullptr) {
        std::cerr << "Unable to load background image! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Tạo texture từ hình ảnh nền
    SDL_Texture* backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    // Tải hình ảnh máy bay điều khiển
    SDL_Surface* myPlaneSurface = SDL_LoadBMP("myplane.bmp");
    if (myPlaneSurface == nullptr) {
        std::cerr << "Unable to load my plane image! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Tạo texture từ hình ảnh máy bay điều khiển
    SDL_Texture* myPlaneTexture = SDL_CreateTextureFromSurface(renderer, myPlaneSurface);
    SDL_FreeSurface(myPlaneSurface);

    // Tải hình ảnh tảng đá
    SDL_Surface* rockSurface = SDL_LoadBMP("rock.bmp");
    if (rockSurface == nullptr) {
        std::cerr << "Unable to load rock image! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyTexture(myPlaneTexture);
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Tạo texture từ hình ảnh tảng đá
    SDL_Texture* rockTexture = SDL_CreateTextureFromSurface(renderer, rockSurface);
    SDL_FreeSurface(rockSurface);

    // Tải phông chữ
    TTF_Font* font = TTF_OpenFont("Open_Sans/OpenSans-Regular.ttf", 24); 
    if (font == nullptr) {
        std::cerr << "Failed to load font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        SDL_DestroyTexture(rockTexture);
        SDL_DestroyTexture(myPlaneTexture);
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Tải âm thanh nền
    Mix_Music* backgroundMusic = Mix_LoadMUS("background_music.mp3");
    if (backgroundMusic == nullptr) {
        std::cerr << "Failed to load background music! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_DestroyTexture(rockTexture);
        SDL_DestroyTexture(myPlaneTexture);
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    // Tải âm thanh va chạm
    crashSound = Mix_LoadWAV("crash_sound.wav");
    if (crashSound == nullptr) {
        std::cerr << "Failed to load crash sound effect! SDL_mixer Error: " << Mix_GetError() << std::endl;
        Mix_FreeMusic(backgroundMusic);
        SDL_DestroyTexture(rockTexture);
        SDL_DestroyTexture(myPlaneTexture);
        SDL_DestroyTexture(backgroundTexture);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        Mix_CloseAudio();
        TTF_Quit();
        SDL_Quit();
        
        return 1;
    }

    // Phát âm thanh nền
    Mix_PlayMusic(backgroundMusic, -1);

    // Hàm khởi tạo trò chơi
    auto initializeGame = [&]() {
        myPlaneRect = { (WINDOW_WIDTH - PLANE_WIDTH) / 2, (WINDOW_HEIGHT - PLANE_HEIGHT) / 2, PLANE_WIDTH, PLANE_HEIGHT };
        movingRocks.clear();
        for (int i = 0; i < NUM_ROCKS; ++i) {
            Plane rock;
            rock.rect = { WINDOW_WIDTH + i * 200, rand() % (WINDOW_HEIGHT - PLANE_HEIGHT), PLANE_WIDTH, PLANE_HEIGHT };
            rock.speed = INITIAL_ROCK_SPEED;
            movingRocks.push_back(rock);
        }
        gameOver = false;
        startTime = SDL_GetTicks();
    };

    // Khởi tạo trò chơi
    initializeGame();

    // Khai báo nút
    SDL_Rect replayButtonRect;
    SDL_Rect exitButtonRect;

    // Vòng lặp trò chơi
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
                if (!gameOver) {
                    switch (e.key.keysym.sym) {
                        case SDLK_UP:
                            myPlaneRect.y -= CONTROL_PLANE_SPEED;
                            break;
                        case SDLK_DOWN:
                            myPlaneRect.y += CONTROL_PLANE_SPEED;
                            break;
                        case SDLK_LEFT:
                            myPlaneRect.x -= CONTROL_PLANE_SPEED;
                            break;
                        case SDLK_RIGHT:
                            myPlaneRect.x += CONTROL_PLANE_SPEED;
                            break;
                    }
                }
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && gameOver) {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (isMouseInsideButton(mouseX, mouseY, replayButtonRect)) {
                    initializeGame();
                }
                else if (isMouseInsideButton(mouseX, mouseY, exitButtonRect)) {
                    quit = true;
                }
            }
        }

        // Giới hạn biên của máy bay
        myPlaneRect.y = std::max(0, std::min(myPlaneRect.y, WINDOW_HEIGHT - PLANE_HEIGHT));
        myPlaneRect.x = std::max(0, std::min(myPlaneRect.x, WINDOW_WIDTH - PLANE_WIDTH));

        if (!gameOver) {
            // Cập nhật vị trí và tốc độ các tảng đá di chuyển
            for (auto& rock : movingRocks) {
                rock.rect.x -= rock.speed;
                if (rock.rect.x < -PLANE_WIDTH) {
                    rock.rect.x = WINDOW_WIDTH;
                    rock.rect.y = rand() % (WINDOW_HEIGHT - PLANE_HEIGHT);
                    
                    if (rock.speed < MAX_ROCK_SPEED) {
                        rock.speed += ROCK_SPEED_INCREMENT;
                    }
                }
                // Kiểm tra va chạm
                if (checkCollision(myPlaneRect, rock.rect)) {
                    gameOver = true;
                    endTime = SDL_GetTicks(); // Lưu thời điểm kết thúc
                    Mix_PlayChannel(-1, crashSound, 0); // Phát âm thanh va chạm
                    Mix_HaltMusic(); // Dừng âm thanh nền khi trò chơi kết thúc
                    break;
                }
            }
        }

        // Xóa màn hình
        SDL_RenderClear(renderer);

        // Vẽ nền
        SDL_Rect destRect = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
        SDL_RenderCopy(renderer, backgroundTexture, nullptr, &destRect);

        // Vẽ các tảng đá di chuyển
        for (const auto& rock : movingRocks) {
            SDL_RenderCopy(renderer, rockTexture, nullptr, &rock.rect);
        }

        // Vẽ máy bay điều khiển
        SDL_RenderCopy(renderer, myPlaneTexture, nullptr, &myPlaneRect);

        // Hiển thị điểm
        Uint32 elapsedTime = gameOver ? (endTime - startTime) : (SDL_GetTicks() - startTime);
        renderText(renderer, font, "Score: " + std::to_string(elapsedTime / 1000), 10, 10);

        if (gameOver) {

            Uint32 finalTime = elapsedTime;
            // Vẽ bảng thông báo
            renderText(renderer, font, "Score: " + std::to_string(elapsedTime / 1000), WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 60);

            // Vẽ nút chơi lại
            replayButtonRect = { WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 + 10, BUTTON_WIDTH, BUTTON_HEIGHT };
            renderButton(renderer, font, "Play Again", replayButtonRect);

            // Vẽ nút thoát
            exitButtonRect = { WINDOW_WIDTH / 2 - BUTTON_WIDTH / 2, WINDOW_HEIGHT / 2 + 70, BUTTON_WIDTH, BUTTON_HEIGHT };
            renderButton(renderer, font, "Exit", exitButtonRect);
        }

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);

        // Đặt độ trễ để làm chậm vòng lặp
        SDL_Delay(16);
    }

    // Giải phóng tài nguyên
    Mix_FreeMusic(backgroundMusic);
    Mix_FreeChunk(crashSound); // Giải phóng âm thanh
    Mix_CloseAudio(); // Đóng audio
    TTF_CloseFont(font);
    SDL_DestroyTexture(rockTexture);
    SDL_DestroyTexture(myPlaneTexture);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();

    return 0;
}