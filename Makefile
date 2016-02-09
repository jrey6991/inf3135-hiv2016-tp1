FILENAME = tp1
EXEC = tp1

$(EXEC): $(FILENAME).o
	gcc -o $(EXEC) $(FILENAME).o

$(FILENAME).o: $(FILENAME).c
	gcc -c $(FILENAME).c

clean:
	rm -f $(EXEC) $(FILENAME).o

database:
	curl http://download.geonames.org/export/dump/countryInfo.txt -o "country.txt"
	curl -o cities.zip http://download.geonames.org/export/dump/cities15000.zip
	unzip cities.zip
