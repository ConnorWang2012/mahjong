/*******************************************************************************
@ copyright(C), 2015-2020, ConnorAndHisFriendsCompany.Inc
@ filename:	    blur_sprite.h
@ author:	    Connor
@ version:	    1.0.0
@ date:		    2016-03-10
@ description:  blur sprite.
@ others:
@ history:
1.date:
author:
modification:
********************************************************************************/

#ifndef CONNOR_GAME_SRC_SPRITE_BLUR_H_
#define CONNOR_GAME_SRC_SPRITE_BLUR_H_

#include "cocos/cocos2d.h"
#include "macros.h"

namespace gamer 
{

class BlurSprite : public cocos2d::Sprite
{
public:
    ~BlurSprite();

    static BlurSprite* create(const char* file_name);

    bool initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Rect&  rect);
    void initGLProgram();

    void setBlurRadius(float radius);
    void setBlurSampleNum(float num);

protected:
    float blur_radius_;
    float blur_sample_num_;
};

} // namespace gamer

#endif // CONNOR_GAME_SRC_SPRITE_BLUR_H_

