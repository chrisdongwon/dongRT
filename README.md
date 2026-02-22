*This project has been created as part of the 42 curriculum by cwon, hnithyan.

# miniRT

## Description

**miniRT** is a minimal ray tracer written in C, developed as part of the 42 curriculum.  
The goal of the project is to implement a basic ray tracing engine capable of rendering simple 3D scenes described in a `.rt` configuration file.

The program simulates light behavior by casting rays from a virtual camera into a 3D scene and computing pixel colors based on object intersections and lighting models.

### Core Features

- Ray–object intersection (sphere, plane, cylinder)
- Ambient and point lights
- Diffuse lighting (Lambertian reflection)
- Hard shadows
- Camera positioning and orientation
- Scene parsing from `.rt` file
- Rendering using MiniLibX
- Proper memory management and clean exit

---

## Instructions

### Install MiniLibX

miniRT depends on **MiniLibX**, the graphical library provided by 42.

Unzip `minilibx-linux.tgz` and install it first:

```bash
tar -xzf minilibx-linux.tgz
cd minilibx-linux
make
```

This will generate the `libmlx.a` static library.

If needed on Ubuntu/Debian, install required dependencies:

```bash
sudo apt install gcc make xorg libxext-dev libbsd-dev
```

After building MiniLibX, return to the miniRT root directory:

```bash
cd ..
```

---

### Compile miniRT

```bash
make
```

Available rules:

```bash
make        # Compile mandatory project
make clean  # Remove object files
make fclean # Remove objects and executable
make re     # Recompile
make bonus  # Compile bonus project
```

---

### Run the Program

```bash
./miniRT[_bonus] scene.rt
```

A rendering window will open displaying the scene.

---

## Scene Format Overview

The scene must be described in a `.rt` file.  
Each line represents one element of the scene.

Rules:
- Global element must appear exactly once (e.g., `A`, `C`, `L`)
- Values are space-separated.
- Vectors use comma-separated format: `x,y,z`
- Colors use comma-separated RGB format: `R,G,B`
- Orientation vectors must be normalized.

---

### Global Elements

#### A — Ambient Lighting

```
A <ratio> <R,G,B>
```

- `<ratio>`: Ambient lighting ratio in range `[0.0, 1.0]`
- `<R,G,B>`: Color values in range `[0,255]`

Example:
```
A 0.2 255,255,255
```

---

#### C — Camera

```
C <x,y,z> <nx,ny,nz> <FOV>
```

- `<x,y,z>`: Camera position in 3D space
- `<nx,ny,nz>`: Normalized orientation vector
- `<FOV>`: Field of view in degrees `[0,180]`

Example:
```
C 0,0,0 0,0,1 70
```

---

#### L — Light Source

```
L <x,y,z> <brightness> <R,G,B>
```

- `<x,y,z>`: Light position
- `<brightness>`: Light brightness ratio `[0.0,1.0]`
- `<R,G,B>`: Light color `[0,255]`

Example:
```
L 10,10,10 0.7 255,255,255
```

---

### Scene Objects

Objects may appear multiple times in the file.

---

#### sp — Sphere

```
sp <x,y,z> <diameter> <R,G,B>
```

- `<x,y,z>`: Center of the sphere
- `<diameter>`: Diameter (positive float)
- `<R,G,B>`: Object color

Example:
```
sp 0,0,20 5 255,0,0
```

---

#### pl — Plane

```
pl <x,y,z> <nx,ny,nz> <R,G,B>
```

- `<x,y,z>`: A point on the plane
- `<nx,ny,nz>`: Normalized normal vector
- `<R,G,B>`: Object color

Example:
```
pl 0,-5,0 0,1,0 255,255,255
```

---

#### cy — Cylinder

```
cy <x,y,z> <nx,ny,nz> <diameter> <height> <R,G,B>
```

- `<x,y,z>`: Center of cylinder
- `<nx,ny,nz>`: Normalized orientation vector
- `<diameter>`: Cylinder diameter (positive float)
- `<height>`: Cylinder height (positive float)
- `<R,G,B>`: Object color

Example:
```
cy 5,0,20 0,1,0 4 10 0,0,255
```

---

### Notes on Validity

- All numeric values must be valid floats or integers.
- Orientation vectors must have length 1 within a tolerance of ±1e-3.
- Colors must be within `[0,255]`.
- Ratios must be within `[0.0,1.0]`.
- The program should return an error if the scene file is malformed.

---

### Complete Example Scene: Mandatory

```
A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,10,10 0.7 255,255,255
sp 0,0,20 5 255,0,0
pl 0,-5,0 0,1,0 255,255,255
cy 5,0,20 0,1,0 4 10 0,0,255
```

---

## Bonus Features Overview

### Colored and Multi-Spot Lights

```
S <x,y,z> <brightness> <R,G,B>
```

- `<x,y,z>`: Spotlight position  
- `<brightness>`: Light intensity ratio `[0.0, 1.0]`  
- `<R,G,B>`: Light color `[0,255]`  

`S` represents a colored spotlight with the following default behavior:

- Default cone angle: 30°  
- The spotlight automatically faces the geometric center of the scene objects  
- No direction or cutoff angle needs to be specified in the `.rt` file  
- Illumination is applied only to surfaces inside the spotlight cone
- Multiple declarations allowed

---

#### Example

```
L 10,10,10 0.5 255,255,255
S -5,8,5 0.7 255,200,200
S 5,10,-5 0.6 200,200,255
```

---

### Specular Reflection (Phong Model)

All objects, by default, will be rendered with specular reflection in the bonus project. 

---

### Checkerboard Pattern

All plane objects, by default, will be rendered with checkerboard pattern in the bonus project. The checkerboard is composed of the surface color and the inverted surface color.

---

### Paraboloid (Second-Degree Object)

Identifier: `pb`

```
pb <x,y,z> <nx,ny,nz> <k> <height> <R,G,B>
```

- `<x,y,z>`: Vertex of paraboloid  
- `<nx,ny,nz>`: Normalized axis direction  
- `<k>`: Curvature coefficient (positive float)  
- `<height>`: Finite height along the axis  
- `<R,G,B>`: Object color  

Example:
```
pb 5,0,20 0,1,0 0.5 10 200,100,50
```

---

### Bump Mapping

All sphere objects, by default, will be rendered with checkerboard pattern in the bonus project.

---

### Complete Minimal Bonus Scene Example

```
A 0.2 255,255,255
C 0,0,0 0,0,1 70
L 10,10,10 0.5 255,255,255
S -5,8,5 0.7 255,200,200
S 5,10,-5 0.6 200,200,255
sp 0,0,20 5 255,0,0
pl 0,-5,0 0,1,0 255,255,255
pb 5,0,20 0,1,0 0.5 10 200,100,50
```

---

## Resources

- *Ray Tracing in One Weekend* — https://raytracing.github.io/books/RayTracingInOneWeekend.html
- Scratchapixel — https://www.scratchapixel.com  
- PBRT (Physically Based Rendering) - https://pbr-book.org/

---

## Use of AI

AI tools were used for:

- Clarifying mathematical concepts (ray intersections, vector projections)
- Debugging segmentation faults and memory issues
- Reviewing architecture ideas
- Improving documentation clarity

All implementation and testing were performed manually to ensure complete understanding of the ray tracing process.
