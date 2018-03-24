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

#include "blur_sprite.h"

namespace gamer 
{

BlurSprite::~BlurSprite()
{
}

BlurSprite* BlurSprite::create(const char *file_name)
{
    BlurSprite* sp = new (std::nothrow) BlurSprite();
    if (sp)
    {
        bool result = sp->initWithFile("");
        cocos2d::log("Test call Sprite::initWithFile with bad file name result is : %s", result ? "true" : "false");
    }

    if (sp && sp->initWithFile(file_name))
    {
        sp->autorelease();
    }
    else
    {
        CC_SAFE_DELETE(sp);
    }

    return sp;
}

bool BlurSprite::initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Rect& rect)
{
    blur_radius_ = 0;
    if (Sprite::initWithTexture(texture, rect))
    {
#if CC_ENABLE_CACHE_TEXTURE_DATA
        auto listener = EventListenerCustom::create(EVENT_RENDERER_RECREATED, [this](EventCustom* event) {
            initGLProgram();
        });

        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
#endif

        initGLProgram();

        return true;
    }

    return false;
}

void BlurSprite::initGLProgram()
{
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    std::string fragSource = cocos2d::FileUtils::getInstance()->getStringFromFile(
        cocos2d::FileUtils::getInstance()->fullPathForFilename("shaders/example_Blur.fsh"));
#else
    std::string fragSource = FileUtils::getInstance()->getStringFromFile(
        FileUtils::getInstance()->fullPathForFilename("shaders/example_Blur_winrt.fsh"));
#endif
    auto program = cocos2d::GLProgram::createWithByteArrays(cocos2d::ccPositionTextureColor_noMVP_vert, fragSource.data());

    auto glProgramState = cocos2d::GLProgramState::getOrCreateWithGLProgram(program);
    setGLProgramState(glProgramState);

    auto size = getTexture()->getContentSizeInPixels();
    getGLProgramState()->setUniformVec2("resolution", size);
#if (CC_TARGET_PLATFORM != CC_PLATFORM_WINRT)
    getGLProgramState()->setUniformFloat("blurRadius", blur_radius_);
    getGLProgramState()->setUniformFloat("sampleNum", 7.0f);
#endif
}

void BlurSprite::setBlurRadius(float radius)
{
    blur_radius_ = radius;
    getGLProgramState()->setUniformFloat("blurRadius", blur_radius_);
}

void BlurSprite::setBlurSampleNum(float num)
{
    blur_sample_num_ = num;
    getGLProgramState()->setUniformFloat("sampleNum", blur_sample_num_);
}

} // namespace gamer