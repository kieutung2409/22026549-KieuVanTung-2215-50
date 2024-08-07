#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <cstdlib> // Để sử dụng rand()

// Kích thước cửa sổ
const int WINDOW_WIDTH = 1380;
const int WINDOW_HEIGHT = 773;

// Kích thước máy bay
const int PLANE_WIDTH = 50;
const int PLANE_HEIGHT = 50;

// Tốc độ di chuyển ban đầu của tảng đá
const int INITIAL_ROCK_SPEED = 3;

// Tốc độ tối đa của tảng đá
const int MAX_ROCK_SPEED = 10;

// Tốc độ tăng dần của tảng đá
const int ROCK_SPEED_INCREMENT = 1;

// Số lượng tảng đá di chuyển
const int NUM_ROCKS = 5;

// Tốc độ di chuyển của máy bay điều khiển
const int CONTROL_PLANE_SPEED = 10;

struct Plane {
    SDL_Rect rect;
    int speed;
};

bool checkCollision(const SDL_Rect &a, const SDL_Rect &b) {
    return SDL_HasIntersection(&a, &b);
}

int main(int argc, char* argv[]) {
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
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

    // Tải hình ảnh tảng đá mới
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

    // Vị trí máy bay điều khiển
    SDL_Rect myPlaneRect = { (WINDOW_WIDTH - PLANE_WIDTH) / 2, (WINDOW_HEIGHT - PLANE_HEIGHT) / 2, PLANE_WIDTH, PLANE_HEIGHT };

    // Tạo các tảng đá di chuyển
    std::vector<Plane> movingRocks;
    for (int i = 0; i < NUM_ROCKS; ++i) {
        Plane rock;
        rock.rect = { WINDOW_WIDTH + i * 200, rand() % (WINDOW_HEIGHT - PLANE_HEIGHT), PLANE_WIDTH, PLANE_HEIGHT };
        rock.speed = INITIAL_ROCK_SPEED;
        movingRocks.push_back(rock);
    }

    // Vòng lặp trò chơi
    bool quit = false;
    SDL_Event e;

    // Thay đổi tốc độ theo khung hình
    int frameCount = 0;
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN) {
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

        // Giới hạn biên của máy bay
        myPlaneRect.y = std::max(0, std::min(myPlaneRect.y, WINDOW_HEIGHT - PLANE_HEIGHT));
        myPlaneRect.x = std::max(0, std::min(myPlaneRect.x, WINDOW_WIDTH - PLANE_WIDTH));

        // Cập nhật vị trí và tốc độ các tảng đá di chuyển
        for (auto& rock : movingRocks) {
            rock.rect.x -= rock.speed;
            // Nếu tảng đá ra ngoài màn hình, đặt lại vị trí và tăng tốc độ
            if (rock.rect.x < -PLANE_WIDTH) {
                rock.rect.x = WINDOW_WIDTH;
                rock.rect.y = rand() % (WINDOW_HEIGHT - PLANE_HEIGHT);
                
                // Tăng tốc độ của tảng đá, nhưng không vượt quá tốc độ tối đa
                if (rock.speed < MAX_ROCK_SPEED) {
                    rock.speed += ROCK_SPEED_INCREMENT;
                }
            }
        }

        // Kiểm tra sự va chạm
        for (const auto& rock : movingRocks) {
            if (checkCollision(myPlaneRect, rock.rect)) {
                // Xử lý sự va chạm (kết thúc trò chơi, giảm máu, v.v.)
                quit = true;
                break;
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

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);

        // Đặt độ trễ để làm chậm vòng lặp
        SDL_Delay(16);

        // Tăng frame count
        frameCount++;
    }

    // Giải phóng tài nguyên
    SDL_DestroyTexture(rockTexture);
    SDL_DestroyTexture(myPlaneTexture);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}