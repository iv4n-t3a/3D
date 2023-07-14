CXX := g++
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system


render: main.cpp math.h
	$(CXX) main.cpp -o render $(LDFLAGS)

clean:
	rm -f render

.PHONY: clean
