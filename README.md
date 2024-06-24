# README.md

## Project Title: so_long

### Description

In this project, I've created a basic 2D game where the objective is to navigate through a map, collect items, and reach an exit. The controls are simple, using WASD or arrow keys for movement.

### Key Features

- **Gameplay**: Collect all items on the map and find the exit. The game keeps track of your moves and displays them in the terminal.
- **Graphics**: Uses the MiniLibX library for window management and displaying images. The game window behaves smoothly even when minimized or changed.
- **Map System**: Maps are described in `.ber` files, containing walls, collectibles, and the player's start and exit positions. The game checks for valid paths and configurations.
- **Controls**: Use W, A, S, D or ZQSD/arrows to move. The game prevents movement into walls.

## What is the MLX?
The MiniLibX, or MLX, is a framework built by Olivier Crouzet on top of X11, a window system developed back in 1984! The MLX is a beginner-friendly C API to interact with the X11 system behind it. Let's look at some of the functions you might be using.

 -  `mlx_init` : Initialises the MLX library. Must be called before using any other functions.
 -  `mlx_new_window`: Creates a new window instance.
 -  `mlx_hook`: Registers events.
 -  `mlx_loop`: Loops over the MLX pointer, triggering each hook in order of registration.
 -  `mlx_xpm_file_to_image`: Converts an XPM file to an MLX image pointer.
 -  `mlx_put_image_to_window`: Puts your image to the screen at the given coordinates.
 -  `mlx_destroy_image`: Frees the image.
 -  `mlx_destroy_window`: Frees the window instance.
 -  `mlx_destroy_display`: Frees MLX.

### How to Play

1. Run the game with a `.ber` map file as an argument.
2. Navigate the map using the specified keys.
3. Collect items and reach the exit.

### Bonus Features

While not required, adding features like enemy patrols, sprite animations, or displaying the movement count on-screen can earn extra points.

### Some Resources
- [42Docs by Harm Smits](https://harm-smits.github.io/42docs/libs/minilibx)
- [Xquartz on Homebrew](https://formulae.brew.sh/cask/xquartz)
- [Full X11 Manual by Christophe Tronche](https://tronche.com/gui/x/xlib/)

Enjoy playing the game!
