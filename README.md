# 🌌 Gravity Simulation

A lightweight 2D physics simulation built with C++ and raylib. This project visualizes gravitational acceleration, velocity tracking, and boundary collision resolution by allowing users to spawn objects into a simulated environment.

## 🚀 Features

- **Interactive Spawning:** Use your mouse to dynamically spawn new circular objects anywhere on the screen.
- **2D Physics Engine:** Simulates constant downward gravitational acceleration applied to objects based on their mass.
- **Boundary Collisions:** Features precise collision detection and resolution with screen boundaries (floor, left wall, and right wall).
- **Energy Loss (Damping):** Objects simulate realistic bouncing by losing energy (50% velocity reduction) upon hitting the floor.
- **Customizable Properties:** Define the mass and radius of your objects via terminal input upon launching the program.

## 🛠️ Built With

- **[C++](https://isocpp.org/)** - Core programming language
- **[raylib](https://www.raylib.com/)** - A simple and easy-to-use library to enjoy videogames programming (Hardware accelerated graphics).

## ⚙️ Installation & Requirements

To run this project, you will need a C++ compiler (like `g++`) and the **raylib** library installed on your system.

1. **Clone the repository:**
   ```bash
   git clone https://github.com/MingoBingo/Gravity-Simulation.git
   cd Gravity-Simulation
   ```

2. **Install raylib:**
   * **Windows:** Download the installer from the [raylib website](https://www.raylib.com/).
   * **Linux:** `sudo apt install libraylib-dev`
   * **macOS:** `brew install raylib`

3. **Compile the code:**
   *(Example using g++ on Linux/macOS)*
   ```bash
   g++ main.cpp circle.cpp -o gravity_sim -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
   ```

## 🎮 Usage & Controls

1. Run the executable:
   ```bash
   ./gravity_sim
   ```
2. **Terminal Prompt:** The program will immediately wait for two floating-point inputs. Enter the **mass** and **radius** for your objects separated by a space (e.g., `5.0 20.0`), then press **Enter**.
3. **In-App Controls:**

| Input | Action |
| :--- | :--- |
| **Left Mouse Click** | Spawn a new object at the cursor's location |

## 📐 How It Works

The simulation runs at a locked **60 FPS**. Every frame, the engine iterates through a `std::vector` of `Circle` objects and updates their state:
1. **Gravity Application:** The Y-velocity is increased based on the object's mass and a global `gravitationalAttraction` constant.
2. **Movement:** X and Y positions are updated by adding the current velocity vector.
3. **Collision Resolution:** If an object penetrates a boundary, it is snapped back inside the screen bounds. If it hits the floor, its Y-velocity is inverted and halved (`* -0.5f`) to simulate the damping effect of a bounce.

---
**Author:** [MingoBingo](https://github.com/MingoBingo)
> *Note: This README was generated with the assistance of AI.*
