CXX = clang++
SDL = -framework SDL2 -framework SDL2_image
SDLLIBS = -Wl,-Bstatic 'sdl-config --static-libs' -Wl,-Bdynamic
# If your compiler is a bit older you may need to change -std=c++11 to -std=c++0x
CXXFLAGS = -Wall -c -std=c++11
LDFLAGS = $(SDL)
SOURCES = main.cpp Game.cpp TextureManager.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXE = game


all: $(SOURCES) $(EXE)

$(EXE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm *.o && rm $(EXE)
