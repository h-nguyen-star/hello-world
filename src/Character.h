#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <iostream>

/*
This character template was pulled from Tadidadou from this stack overflow post and was modified.
 https://stackoverflow.com/questions/60548077/how-to-use-a-manager-class-to-manage-characters-and-their-animations-in-c-usin
*/

const std::string PATH = "C:\\Users\\Haison\\game\\hello-world\\src\\textures\\";

class Character : public sf::Drawable {

    public:
        Character(sf::Texture& texture);
        
        void setPosition(sf::Vector2f pos) { m_position = pos; };
        void setTexture(sf::Texture texture);
        void setTextureRect(const sf::IntRect& rect);
        void move(float x);
        const sf::IntRect& getTextureRect() const;
        const sf::Texture getTexture() const;

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        std::string name;
        sf::Vector2f m_position;
        sf::Texture m_texture;
        sf::IntRect m_textureRect;
        sf::Sprite m_sprite;
};