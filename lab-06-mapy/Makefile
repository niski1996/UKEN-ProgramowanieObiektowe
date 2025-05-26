# Generator plikow makefile #
# Krzysztof Siminski, 2022  #
#############################

# STALE:
kompilator=g++
standard=-std=c++20

# Update these paths to match your Google Test installation
includeGoogleTest=-I/usr/local/include
linkGoogleTest=-L/usr/local/lib -lgtest -lgtest_main -lpthread

optRelease=-O3
optDebug=-g

errors=-pedantic-errors

release=
debug=-g

rownoleglosc=

release_folder=_release
debug_folder=_debug

#############################

.PHONY : clean $(debug_folder) $(release_folder)

release : $(release_folder) $(release_folder)/main
	./$(release_folder)/main

debug : $(debug_folder) $(debug_folder)/main
	./$(debug_folder)/main

test : $(debug_folder) $(debug_folder)/test
	./$(debug_folder)/test

$(release_folder) : 
	mkdir -p $(release_folder)
$(debug_folder) : 
	mkdir -p $(debug_folder)

$(release_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/funkcje.o : funkcje.cpp
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(release_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -c -o $@ $^
$(debug_folder)/funkcje_test.o : funkcje_test.cpp
	$(kompilator) $(standard) $(includeGoogleTest) $(debug) $(optDebug) $(rownoleglosc) $(errors) -c -o $@ $^

$(release_folder)/main : $(release_folder)/funkcje.o $(release_folder)/main.o 
	$(kompilator) $(standard) $(release) $(optRelease) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/main : $(debug_folder)/funkcje.o $(debug_folder)/main.o 
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^

$(debug_folder)/test : $(debug_folder)/funkcje.o $(debug_folder)/funkcje_test.o
	$(kompilator) $(standard) $(debug) $(optDebug) $(rownoleglosc) $(errors) -o $@ $^ $(linkGoogleTest)

clean : 
	if [ -d $(debug_folder)      ] ; then rm -r $(debug_folder)   ; fi
	if [ -d $(release_folder)    ] ; then rm -r $(release_folder) ; fi