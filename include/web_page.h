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
    // Вставьте здесь весь JavaScript код для игры
  </script>
</body>

</html>
)=====";

#endif
