#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include "web_page.h"

const char *ssid = "your-ssid";
const char *password = "your-password";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Подключение к WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");

  // Обработка запросов к корневому URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", webPage);
  });

  // Здесь вы также можете обработать другие URL, если это необходимо

  // Запуск веб-сервера
  server.begin();
}

void loop() {
  // Ваш основной код здесь
}