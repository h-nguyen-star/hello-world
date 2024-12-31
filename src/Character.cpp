#include "Character.h"

Character::Character(sf::Texture& texture) : m_sprite(texture)
{

}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(m_sprite, states);
}

void Character::move(float x)
{
   m_position.x += x;
   m_sprite.setPosition(m_position);
}

void Character::setTexture(sf::Texture texture)
{
    // Assign the new texture
    m_texture = texture;
}

void Character::setTextureRect(const sf::IntRect& rect)
{
    m_textureRect = rect;
}


const sf::IntRect& Character::getTextureRect() const
{
    return m_textureRect;
}


const sf::Texture Character::getTexture() const
{
    return m_texture;
}