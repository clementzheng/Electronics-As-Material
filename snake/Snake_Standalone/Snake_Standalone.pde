int gridSize = 30;
int w = 35;
int h = 20;

color snakeColor = color(0, 0, 0); // R, G, B; 0-255
color appleColor = color(220, 0, 0); // R, G, B; 0-255
color backgroundColor = color(200, 200, 200); // R, G, B; 0-255

float minSpeedInterval = 25; // LOWER = FASTER
float maxSpeedInterval = 200; // HIGHER = SLOWER
float initialSpeedInterval = 90;

Snake snake;

PVector apple;

void setup() {
  surface.setSize(gridSize*w, gridSize*h);
  snake = new Snake(10, float(round(w/2)), float(round(h/2)), initialSpeedInterval);
  newApple();
}

void draw() {
  fill(backgroundColor);
  noStroke();
  rect(0, 0, width, height);

  fill(appleColor);
  noStroke();
  ellipse(apple.x*gridSize + gridSize/2, apple.y*gridSize + gridSize/2, gridSize/1.2, gridSize/1.2);

  snake.update(apple);
}

void resetGame() {
  if (snake.dead) {
    snake = new Snake(10, float(round(w/2)), float(round(h/2)), initialSpeedInterval);
    newApple();
  }
}

void newApple() {
  boolean checkSnake = false;
  while (!checkSnake) {
    apple = new PVector(floor(random(w)), floor(random(h)));
    int counter = 0;
    for (int i=0; i<snake.size; i++) {
      if (snake.body[i].x == apple.x && snake.body[i].y == apple.y) {
      } else {
        counter++;
      }
    }
    if (counter == snake.size) {
      checkSnake = true;
    }
  }
}

class Snake {

  int size;
  int[] dir;
  PVector[] body;
  float speedInterval;
  int timestamp = 0;

  boolean moving = false;
  boolean dead = false;

  boolean command = false;

  Snake(int _size, float x, float y, float _speedInterval) {
    size = _size;
    speedInterval = _speedInterval;
    body = new PVector[size];
    dir = new int[size];

    float posX = x;
    float posY = y;

    for (int i=0; i<size; i++) {
      body[i] = new PVector(posX - i, posY);
      dir[i] = 1;
    }
  }

  void update(PVector a) {
    if (moving && !dead) {
      if (millis() - timestamp > speedInterval) {
        timestamp = millis();

        boolean ate = false;
        if (body[0].x == a.x && body[0].y == a.y) {
          ate = true;
        }

        if (ate) {
          size++;
          body = (PVector[])expand(body, size);
          dir = (int[])expand(dir, size);
          body[size-1] = new PVector(body[size-2].x, body[size-2].y);
          dir[size-1] = 0;
          newApple();
          // SERIAL_PORT.write('E');
        }

        for (int i=0; i<size; i++) {
          switch(dir[i]) {
          case 1:
            body[i] = new PVector(body[i].x+1, body[i].y);
            break;
          case 2:
            body[i] = new PVector(body[i].x, body[i].y+1);
            break;
          case 3:
            body[i] = new PVector(body[i].x-1, body[i].y);
            break;
          case 4:
            body[i] = new PVector(body[i].x, body[i].y-1);
            break;
          }
        }

        for (int i=size-1; i>0; i--) {
          dir[i] = dir[i-1];
        }

        command = false;
      }
    }

    if (body[0].x < 0 || body[0].x >= w || body[0].y < 0 || body[0].y >= h) {
      moving = false;
      dead = true;
      // SERIAL_PORT.write('D');
    }

    for (int i=size-1; i>0; i--) {
      if (body[i].x == body[0].x && body[i].y == body[0].y) {
        moving = false;
        dead = true;
        // SERIAL_PORT.write('D');
        break;
      }
    }

    for (int i=0; i<size; i++) {
      fill(snakeColor);
      if (dead && (millis()/250)%2 == 0) {
        fill(backgroundColor);
      }
      noStroke();
      rect(body[i].x*gridSize, body[i].y*gridSize, gridSize, gridSize);
    }
  }
}

void moveRight() {
  snake.moving = true;
  if (snake.dir[0] % 2 == 0 && !snake.command && !snake.dead) {
    snake.dir[0] = 1;
    snake.command = true;
  }
}

void moveDown() {
  snake.moving = true;
  if (snake.dir[0] % 2 == 1 && !snake.command && !snake.dead) {
    snake.dir[0] = 2;
    snake.command = true;
  }
}

void moveLeft() {
  snake.moving = true;
  if (snake.dir[0] % 2 == 0 && !snake.command && !snake.dead) {
    snake.dir[0] = 3;
    snake.command = true;
  }
}

void moveUp() {
  snake.moving = true;
  if (snake.dir[0] % 2 == 1 && !snake.command && !snake.dead) {
    snake.dir[0] = 4;
    snake.command = true;
  }
}

void speedUp() {
  snake.speedInterval = snake.speedInterval * 0.9;
  snake.speedInterval = snake.speedInterval < minSpeedInterval ? minSpeedInterval : snake.speedInterval;
}

void speedDown() {
  snake.speedInterval = snake.speedInterval * 1.1;
  snake.speedInterval = snake.speedInterval > maxSpeedInterval ? maxSpeedInterval : snake.speedInterval;
}

void keyPressed() {
  if (key == 'w' || key == 'W') {
    moveUp();
  }
  if (key == 'a' || key == 'A') {
    moveLeft();
  }
  if (key == 's' || key == 'S') {
    moveDown();
  }
  if (key == 'd' || key == 'D') {
    moveRight();
  }
  if (key == 'r' || key == 'R') {
    resetGame();
  }
  if (key == 'p' || key == 'P') {
    speedUp();
  }
  if (key == 'o' || key == 'O') {
    speedDown();
  }
}

