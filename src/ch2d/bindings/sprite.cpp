#include <ch2d/LuaInterface.hpp>

namespace ch2d
{
	unsigned int LuaInterface::sprite_create(void)
	{
		return mSpriteHandler.create();
	}

	bool LuaInterface::sprite_draw(unsigned int id)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(id);

		mRenderWindow.draw(*sprite);

		return true;
	}

	bool LuaInterface::sprite_remove(unsigned int id)
	{
		return mSpriteHandler.remove(id);
	}

	bool LuaInterface::sprite_setPosition(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(id);

		if(nullptr == sprite)
		{
			return false;
		}

		sprite->setPosition(sf::Vector2f(std::floor(x), std::floor(y)));

		return true;
	}

	bool LuaInterface::sprite_setOrigin(unsigned int id, LUA_NUMBER x, LUA_NUMBER y)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(id);

		if(nullptr == sprite)
		{
			return false;
		}

		sprite->setOrigin(std::floor(x), std::floor(y));

		return true;
	}

	bool LuaInterface::sprite_setRotation(unsigned int id, LUA_NUMBER rotation)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(id);

		if(nullptr == sprite)
		{
			return false;
		}

		sprite->setRotation(rotation);

		return true;
	}

	void LuaInterface::sprite_setTexture(unsigned int spriteId, unsigned int textureId)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(spriteId);

		std::shared_ptr<sf::Texture> texture = mTextureHandler.get(textureId);

		sprite->setTexture(*texture);
	}

	void LuaInterface::sprite_setTextureRect(unsigned int id, LUA_NUMBER x, LUA_NUMBER y, LUA_NUMBER width, LUA_NUMBER height)
	{
		std::shared_ptr<sf::Sprite> sprite = mSpriteHandler.get(id);

		sprite->setTextureRect(sf::IntRect(x, y, width, height));
	}
}