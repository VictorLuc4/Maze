# Maze
This project allow you to create perfect and imperfect maze.

## Install
Run `make` then `make clean` at the root of the repository to build everything.

## Usage
`./generator X Y [perfect | imperfect]`

It creates a maze.txt file that contain the generated maze.  
Walls are represented as `X`and path as `*`.

## Examples
### Imperfect maze 

`./generator 10 10 perfect`

```text
*********X
*XXX*XXX*X
***X*X***X
*XXX*XXXXX
***X*****X
*XXXXX*XXX
*****X***X
*XXX*XXXXX
***X*****X
XXXXXXXX**
```

### Imperfect maze 

`./generator 10 10 imperfect`

```text
*********X
***X*X*X**
*****X****
*X**X*X**X
*******X**
*X*X*X*X*X
**********
*X***X*X*X
***X******
X*X*X*X***
```