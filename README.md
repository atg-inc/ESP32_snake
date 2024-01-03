# ESP32_snake

Игра змейка одна из самых популярных игр на телефоне Nokia. Данный проект представляет из себя Web версию, запускаемую из браузера по WIFI соединению.

## Окружение

Для разработки используется Platform.io и VS Code. Для запуска проекта на Arduino IDE понадобятся некоторые изменения, в частности, необходимо переименовать main.cpp.

Разработка ведётся с использованием платы ESP32 - MH ET LIVE ESP32DevKIT

Используется платформа Espressif 32 6.5.0

## Библиотеки

В проекте используются следующие сторонние библиотеки, которые необходимо установить самостоятельно:

1. ESP Async WebServer (ESPAsyncWebServer-esphome by ESPHome Team 3.1.0)

## Настройка

Для запуска необходимо настроить WIFI соединение. Для этого необходимо переименовать файл _credentials..h в credentials..h, открыть этот файл и прописать в нём ssid (название вашей WIFI сети) и password (пароль от вашего WIFI).

> ВАЖНО! Тестовая плата поддерживает WIFI только 2.4Ghz, поэтому необходимо указывать данные именно этой сети.