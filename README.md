# So Long - 42 Common core project
## A basic computer graphics project, a 2D GAME!


## The rules
* Must use Minilibix (Mandatory!)
* 
* Allowed functions:
    - Open, close, read, write, malloc, free, perror, strerror, exit
    - All functions of the math library 
    - All functions of the MiniLibX
    - ft_printf and any equivalent YOU coded
* Game:
    - Take as parameter a map description file ending with the .ber extension
    - The goal is to collect every collectable present on the map, then escape choosing the shortest possible route.
    - The W, A, S, and D keys must be used to move the main character the 4 directions: up, down, left, right.
    - Has to display the image in a window and the management of your window must remain smooth
    - ESC must close the window and quit the program in a clean way, as well as clicking on the cross on the window’s frame
    - The map must be validated under specific rules

### Bonus part:
* Make the player lose when they touch an enemy patrol.
* Add some sprite animation.
* Display the movement count directly on screen instead of writing it in the shell.

## Learning Experience

* Window management
* Event handling
* Colors, textures, sprites, sprite sheets, tiles, tilesets
* Understand useful game algorithms like creating random movements, collision check

## How to use
1. Clone the repository
2. To compile:
    * mandatory part type: make
    * bonus part type: make bonus

3. To execute the game:
    * ./so_long [map_path] (ex: ./so_long maps/test.ber)
    * ./so_long_bonus [map_path] (ex: ./so_long maps/testbonus.ber)
4. PLAY!
