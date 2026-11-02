//Biblioteka obslugi LCD przez I2C
#include <Adafruit_LiquidCrystal.h>
//Utworzenie obiektu wyswietlacza pod adresem I2C = 0
Adafruit_LiquidCrystal lcd_1(0);
// Utworzenie tekstu ktory bedzie wyswietlany
String tekst = " ZAPRASZAMY NA KURS HISZPANSKIEGO ";

// Zmienna przechowujaca czas od ostatniego przesuniecia 
//( milisekundy od startu programu)
unsigned long poprzedniCzas = 0;
// Czestotliwosc przewijania(co ile ms tekst przesunie sie o 1) 
const unsigned long interwal = 400;


void setup() {
  // Inicjalizacja wyswietlacza 16 kol i 2 wiersze
  lcd_1.begin(16, 2);

 //Ustawienie miejsca poczatku 1szego tekstu 
  lcd_1.setCursor(0, 0);
  // Gorny - przewijany tekst
  lcd_1.print(tekst);

  //Ustawienie miejsca poczatku 2giego tekstu 
  lcd_1.setCursor(0, 1);
  // Dolny napis na srodku
  lcd_1.print(" POLECANY PRZEZ BIZONA ");
}

void loop() {
  // Pobranie czasu jaki minal od uruchomienia arduino
  unsigned long aktualnyCzas = millis();

  // Przewijanie gornego wiersza co interwal ms 
  if (aktualnyCzas - poprzedniCzas >= interwal) {
    poprzedniCzas = aktualnyCzas;

    // Przesuwamy wyświetlany obszar w lewo (tekst jedzie od prawej do lewej)
    lcd_1.scrollDisplayLeft();

  
  }

    
  
}

// Petla loop() wraca duzo razy a gdy minie mniej niz 'interwal' ms, warunek if nie spelni sie ,nic sie nie zmieni.

