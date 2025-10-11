#ifndef OBJECT_AFFILIATE_H
#define OBJECT_AFFILIATE_H

#include "object_screen.h"
//附属物，附属于某个主物体，比如角色的装备、UI元素等
class ObjectAffiliate:public ObjectScreen{
public:
    void setParrent(ObjectScreen* parrent){parrent_=parrent;}
    ObjectScreen* getParrent()const{return parrent_;}
    void setOffset(const glm::vec2& offset){offset_=offset;}
    glm::vec2 getOffset()const{return offset_;}
    void setSize(const glm::vec2& size){size_=size;}
    glm::vec2 getSize()const{return size_;}

protected:
    glm::vec2 offset_=glm::vec2(0.0f);//附属物相对于主物体的偏移
    ObjectScreen* parrent_=nullptr;//附属物的主物体
    glm::vec2 size_=glm::vec2(0.0f);//附属物大小
};






#endif