#ifndef WEB_PAGE_H
#define WEB_PAGE_H

const char* webPage = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
  <title>Snake Game</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
  <style>
    canvas {
      border: 1px solid #ddd;
    }

    h2 {
      margin-top: 20px;
    }

    body {
      background-color: #f8f9fa;
    }
  </style>
</head>

<body class="container">
  <div class="row">
    <div class="col-md-6 offset-md-3">
      <h2>Счет: <span id="score" class="badge badge-success">0</span></h2>
      <h2>Максимальный счет: <span id="maxScore" class="badge badge-info">0</span></h2>
      <canvas id="gameCanvas" width="400" height="400"></canvas>
    </div>
  </div>

  <script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.10.2/dist/umd/popper.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

  <script>
const canvas = document.getElementById("gameCanvas");
    const ctx = canvas.getContext("2d");

    const blockSize = 20;
    let snake = [{ x: 10, y: 10 }];
    let food = { x: 15, y: 15 };
    let direction = "right";
    let score = 0;
    let maxScore = 0;
    let acceleration = 1;
    let obstacles = [];
    let obstacleFrequency = 15;

    function draw() {
      ctx.clearRect(0, 0, canvas.width, canvas.height);

      // Рисуем змею
      ctx.fillStyle = "#28a745"; // Зеленый цвет Bootstrap
      snake.forEach(segment => {
        ctx.fillRect(segment.x * blockSize, segment.y * blockSize, blockSize, blockSize);
      });

      // Рисуем еду
      ctx.fillStyle = "#dc3545"; // Красный цвет Bootstrap
      ctx.fillRect(food.x * blockSize, food.y * blockSize, blockSize, blockSize);

      // Рисуем препятствия
      ctx.fillStyle = "#ffc107"; // Желтый цвет Bootstrap для препятствий
      obstacles.forEach(obstacle => {
        ctx.fillRect(obstacle.x * blockSize, obstacle.y * blockSize, blockSize, blockSize);
      });
    }

    function move() {
      let head = { x: snake[0].x, y: snake[0].y };

      switch (direction) {
        case "up":
          head.y--;
          break;
        case "down":
          head.y++;
          break;
        case "left":
          head.x--;
          break;
        case "right":
          head.x++;
          break;
      }

      if (head.x < 0 || head.x >= canvas.width / blockSize || head.y < 0 || head.y >= canvas.height / blockSize) {
        handleGameOver();
        return;
      }

      if (checkCollision(head, snake.slice(1)) || checkCollision(head, obstacles)) {
        handleGameOver();
        return;
      }

      if (head.x === food.x && head.y === food.y) {
        score++;
        if (score % 10 === 0) {
          acceleration += 0.1;
        }

        updateScore();
        snake.unshift(food);

        // Генерируем новую еду
        generateFood();

        // Генерируем препятствия каждые 15 очков
        if (score % obstacleFrequency === 0) {
          generateObstacle();
        }
      } else {
        snake.pop();
        snake.unshift(head);
      }

      draw();
    }

    function handleGameOver() {
      console.log("Game Over!");
      if (score > maxScore) {
        maxScore = score;
        updateMaxScore();
      }
      resetGame();
    }

    function generateFood() {
      food = {
        x: Math.floor(Math.random() * (canvas.width / blockSize)),
        y: Math.floor(Math.random() * (canvas.height / blockSize))
      };

      while (checkCollision(food, snake) || checkCollision(food, obstacles)) {
        food = {
          x: Math.floor(Math.random() * (canvas.width / blockSize)),
          y: Math.floor(Math.random() * (canvas.height / blockSize))
        };
      }
    }

    function generateObstacle() {
      let obstacle = {
        x: Math.floor(Math.random() * (canvas.width / blockSize)),
        y: Math.floor(Math.random() * (canvas.height / blockSize))
      };

      while (checkCollision(obstacle, snake) || checkCollision(obstacle, obstacles) || checkCollision(obstacle, [food])) {
        obstacle = {
          x: Math.floor(Math.random() * (canvas.width / blockSize)),
          y: Math.floor(Math.random() * (canvas.height / blockSize))
        };
      }

      obstacles.push(obstacle);
    }

    function checkCollision(obj, array) {
      return array.some(segment => segment.x === obj.x && segment.y === obj.y);
    }

    function updateScore() {
      document.getElementById("score").innerText = score;
    }

    function updateMaxScore() {
      document.getElementById("maxScore").innerText = maxScore;
    }

    function resetGame() {
      score = 0;
      acceleration = 1;
      snake = [{ x: 10, y: 10 }];
      direction = "right";
      obstacles = [];
      generateFood();
      updateScore();
      draw();
    }

    window.addEventListener("keydown", function (event) {
      switch (event.key) {
        case "ArrowUp":
          if (direction !== "down") {
            direction = "up";
          }
          break;
        case "ArrowDown":
          if (direction !== "up") {
            direction = "down";
          }
          break;
        case "ArrowLeft":
          if (direction !== "right") {
            direction = "left";
          }
          break;
        case "ArrowRight":
          if (direction !== "left") {
            direction = "right";
          }
          break;
      }
    });

    resetGame();
    setInterval(move, 200 / acceleration);
  </script>
</body>

</html>
)=====";

#endif
