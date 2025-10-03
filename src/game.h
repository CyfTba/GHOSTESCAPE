#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"
#include "SDL3_mixer/SDL_mixer.h"
#include "SDL3_ttf/SDL_ttf.h"
#include "glm/glm.hpp"

//单例模式
class Game{
private:
    //私有的构造函数
    Game(){};
    //禁用拷贝构造和赋值操作符
    Game(const Game&)=delete;
    Game& operator=(const Game&)=delete;
public:
    static Game& GetInstance(){
        static Game instance;
        return instance;
    }
};