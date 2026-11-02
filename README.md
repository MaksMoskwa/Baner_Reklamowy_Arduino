📟 Przewijany tekst na wyświetlaczu LCD 16x2 (Arduino C++)
📌 Opis projektu

Projekt polega na wyświetlaniu dwóch komunikatów na wyświetlaczu LCD 16x2 z wykorzystaniem komunikacji I2C oraz mikrokontrolera Arduino.

W górnym wierszu wyświetlany jest tekst „ZAPRASZAMY NA KURS HISZPAŃSKIEGO”, który automatycznie przesuwa się od prawej do lewej strony ekranu.

W dolnym wierszu znajduje się stały napis „POLECANY PRZEZ BIZONA”, który nie zmienia swojego położenia.

Przewijanie tekstu odbywa się cyklicznie, co 400 milisekund.

🛠️ Wykorzystane elementy
Arduino (np. Arduino Uno)
Wyświetlacz LCD 16x2 z modułem I2C
Przewody połączeniowe
Biblioteka Adafruit_LiquidCrystal.h
⚙️ Zasada działania programu

Program składa się z dwóch głównych funkcji:

1. Funkcja setup()

Wykonuje się tylko raz po uruchomieniu Arduino.

Inicjalizuje wyświetlacz LCD o wymiarach 16 kolumn i 2 wierszy.
Wyświetla w górnym wierszu tekst przeznaczony do przewijania.
Wyświetla w dolnym wierszu stały komunikat.
2. Funkcja loop()

Wykonuje się wielokrotnie podczas pracy Arduino.

Pobiera aktualny czas działania programu za pomocą funkcji millis().
Sprawdza, czy od ostatniego przesunięcia minęło 400 ms.
Jeśli tak, przesuwa zawartość wyświetlacza o jedną pozycję w lewo.
Aktualizuje czas ostatniego przesunięcia.

Dzięki temu tekst przesuwa się płynnie bez użycia funkcji delay().

💻 Najważniejsze zmienne i funkcje
Element	Opis
tekst	Przechowuje treść przewijanego komunikatu.
poprzedniCzas	Zapamiętuje czas ostatniego przesunięcia tekstu.
interwal	Określa częstotliwość przewijania – 400 ms.
millis()	Zwraca czas w milisekundach od uruchomienia Arduino.
scrollDisplayLeft()	Przesuwa zawartość wyświetlacza w lewo.
setCursor()	Ustawia pozycję kursora na wyświetlaczu.
print()	Wyświetla tekst na ekranie.
⏱️ Dlaczego program nie wykorzystuje delay()?

Zastosowanie funkcji millis() pozwala kontrolować czas przewijania bez zatrzymywania działania programu.

Funkcja loop() wykonuje się wielokrotnie, ale tekst przesuwa się dopiero wtedy, gdy upłynie określony interwał czasowy.

Dzięki temu Arduino może wykonywać również inne zadania w trakcie przewijania tekstu.

🔧 Możliwości modyfikacji

Program można łatwo dostosować do własnych potrzeb:

Zmiana tekstu: wystarczy zmodyfikować wartość zmiennej tekst.
Zmiana szybkości przewijania: należy zmienić wartość interwal.
Zmiana dolnego komunikatu: wystarczy edytować tekst w drugim poleceniu lcd_1.print().
Zmiana kierunku przewijania: można zastosować funkcję scrollDisplayRight() zamiast scrollDisplayLeft().
🎯 Cel projektu

Celem projektu jest poznanie podstaw programowania Arduino w języku C++, obsługi wyświetlacza LCD za pomocą komunikacji I2C oraz wykorzystania funkcji millis() do realizacji czasowego sterowania bez blokowania programu.

Projekt może być wykorzystany jako elektroniczny baner informacyjny, wyświetlacz reklamowy lub tablica z komunikatami.
