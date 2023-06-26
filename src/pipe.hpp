#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>

namespace fb
{
    class pipe
    {
    private:
        // pipe texture
        sf::Texture p;
        // pipe sprite
        sf::Sprite ps;

    //////////////////////////////////////////////////////////////////////////////////////////  
    public:
        explicit pipe(str path , int distance_x = 0 , int distance_y = 0){
            p.create(52, 320);
            if(!p.loadFromFile(path)){
                std::cout << "failed to load pipe\n";
            }
            ps.setTexture(p);
            ps.setPosition(sf::Vector2f((WIDTH - 52)+ distance_x  ,(HEIGHT - 320)+distance_y ));
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        static void create_bottom_pipes(pipe* arr[], str path ) {
            for (size_t i = 0; i < pipes_count; i++)
            {
                arr[i] = new pipe(path, distance_x , distance_y);
                distance_x += 200;
                distance_y = rand()%100;
            }
            distance_x = 0;
        }

        //////////////////////////////////////////////////////////////////////////////////////////
        
        static void create_upper_pipes(pipe* arr[], str fpath){
            for (size_t i = 0; i < pipes_count; i++)
            {
               distance_y = -(HEIGHT - 320) - rand() % 100; 
               arr[i] = new pipe(fpath, distance_x , distance_y);
               distance_x += 200;
            } 
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        static void draw_pipes(pipe* arr[], sf::RenderWindow window) {
            for (size_t i = 0; i < pipes_count; i++)
            {
               window.draw(arr[i]->get_sprite());
            }
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        static void animate_pipes(pipe* arr[]) {
            for (size_t i = 0; i < pipes_count; i++) {
                arr[i]->set_position(
                sf::Vector2f(arr[i]->get_sprite().getGlobalBounds().left - 1,
                arr[i]->get_sprite().getGlobalBounds().top)
                );
            }
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        sf::Sprite get_sprite(){
            return this->ps;
        }

        //////////////////////////////////////////////////////////////////////////////////////////

        sf::FloatRect get_position(){
            return ps.getGlobalBounds();
        }       
        //////////////////////////////////////////////////////////////////////////////////////////

        void set_position(sf::Vector2f vec){
            return this->ps.setPosition(vec);
        }

        //////////////////////////////////////////////////////////////////////////////////////////
        
        static bool hover(sf::Sprite s , sf::Vector2f mouse_coordinates){
            return s.getGlobalBounds().contains(mouse_coordinates);
        }

        //////////////////////////////////////////////////////////////////////////////////////////

};

} // namespace fb


