all: build run


build:
	
	g++ -I ./include/ -o ./lib/DosyaOkuyucu.o -c ./src/DosyaOkuyucu.cpp
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirListesiDugum.o -c ./src/SatirListesiDugum.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesiDugum.o -c ./src/YoneticiListesiDugum.cpp

	g++ -I ./include/ -o ./bin/main  ./lib/DosyaOkuyucu.o ./lib/SatirListesi.o ./lib/SatirListesiDugum.o ./lib/YoneticiListesi.o  ./lib/YoneticiListesiDugum.o   ./src/main.cpp

run:
	./bin/main