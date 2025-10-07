#include "object_world.h"
#include "scene.h"
void ObjectWorld::setPosition(const glm::vec2 &pos)
{
    position_=pos;
    render_position_=game_.getCurrentScene()->WorldToScreen(position_);

}

void ObjectWorld::setRenderPosition(const glm::vec2 &pos)
{
    render_position_=pos;
    position_=game_.getCurrentScene()->ScreenToWorld(render_position_);
}

void ObjectWorld::update(float dt)
{
    ObjectScreen::update(dt);
    render_position_=game_.getCurrentScene()->WorldToScreen(position_);//更新渲染（屏幕）坐标
}
