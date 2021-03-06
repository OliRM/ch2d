// ch2d
#include <ch2d/System.hpp>

namespace ch2d
{
    unsigned int System::sprite_create(void)
    {
        unsigned int id = 0;

        std::shared_ptr<sf::Drawable> sprite = std::make_shared<sf::Sprite>();

        id = mDrawableHandler.add(sprite);

        return id;
    }

    bool System::sprite_remove(unsigned int id)
    {
        return mDrawableHandler.remove(id);
    }

    bool System::sprite_setPosition(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return false;
        }

        sprite->setPosition(sf::Vector2f(std::floor(x), std::floor(y)));

        return true;
    }

    bool System::sprite_setOrigin(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return false;
        }

        sprite->setOrigin(std::floor(x), std::floor(y));

        return true;
    }

    bool System::sprite_setRotation(unsigned int id, LUA_NUMBER rotation)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return false;
        }

        sprite->setRotation(rotation);

        return true;
    }

    bool System::sprite_setScale(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return false;
        }

        sprite->setScale(x, y);

        return true;
    }

    /*bool System::sprite_setTexture(unsigned int spriteId, unsigned int textureId)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(spriteId)).get());

        auto texture = static_cast<sf::Texture*>((mDrawableHandler.get(textureId)).get());

        if(nullptr == sprite || nullptr == texture)
        {
            return false;
        }

        sprite->setTexture(*texture);

        return true;
    }*/

    bool System::sprite_setTextureRect(unsigned int id, LUA_NUMBER top, LUA_NUMBER left, LUA_NUMBER width, LUA_NUMBER height)
    {
        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return false;
        }

        sprite->setTextureRect(sf::IntRect(top, left, width, height));

        return true;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::sprite_getPosition(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return data;
        }

        auto position = sprite->getPosition();

        data = std::make_tuple(position.x, position.y);

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::sprite_getOrigin(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return data;
        }

        auto origin = sprite->getOrigin();

        data = std::make_tuple(origin.x, origin.y);

        return data;
    }

    LUA_NUMBER System::sprite_getRotation(unsigned int id)
    {
        LUA_NUMBER data {0.f};

        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return data;
        }

        auto rotation = sprite->getRotation();

        data = rotation;

        return data;
    }

    std::tuple<LUA_NUMBER, LUA_NUMBER> System::sprite_getScale(unsigned int id)
    {
        std::tuple<LUA_NUMBER, LUA_NUMBER> data {0.f, 0.f};

        auto sprite = static_cast<sf::Sprite*>((mDrawableHandler.get(id)).get());

        if(nullptr == sprite)
        {
            return data;
        }

        auto scale = sprite->getScale();

        data = std::make_tuple(scale.x, scale.y);

        return data;
    }
}
