# Cub3D

Cub3D is a **42 School** project that involves creating a basic 3D game using **raycasting**. Inspired by Wolfenstein 3D, this project provides an introduction to **graphics rendering**, **game mechanics**, and **player movement** using the **MLX (MLX42) library** in C.

## Features

- **Raycasting engine** for rendering a simple 3D environment
- **Minimap display** for navigation
- **Player movement** using `W`, `A`, `S`, `D` keys
- **Mouse-controlled camera movement** for a better first-person experience
- **Collision detection** to prevent walking through walls
- **Basic texture mapping** for walls and floor
- **Simple event handling** for keyboard and mouse input

## Installation

```sh
git clone https://github.com/DijkmanJ/Cub3D.git cub3d
cd cub3d
make
```

## Usage

Run the game by executing:
```sh
./cub3d map.cub
```

## Controls

- `W` / `S` - Move forward / backward
- `A` / `D` - Strafe left / right
- **Mouse movement** - Rotate camera left / right
- `ESC` - Exit the game

## Requirements

- **GNU Make**
- **GCC Compiler**
- **MLX42 Library**
- **Linux**

## Project Guidelines

This project follows the **42 School** rules:
- No use of external game engines.
- Restricted use of global variables.
- Efficient memory management to prevent leaks.

## Contributing

Feel free to fork and submit pull requests. Contributions are welcome!

## License

This project is licensed under the **MIT License**.


