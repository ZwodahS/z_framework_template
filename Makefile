# framework common files, always required
vpath %.cpp z_framework/zf_common/
# framework inputs
vpath %.cpp z_framework/zf_inputs/
# framework sfml code. also required.
vpath %.cpp z_framework/zf_sfml/
# framework sfml animation code.
vpath %.cpp z_framework/zf_sfml/animations
# framework for hud
vpath %.cpp z_framework/zf_hud/
# game code.
vpath %.cpp game/
# game screen code
vpath %.cpp game/screens/
vpath %.o obj/

WARNING= -Wextra -Wno-switch -Wno-sign-compare -Wno-missing-braces -Wno-unused-parameter
OPTIMIZE= -fno-exceptions
BIN=binaryname
BINFDR=bin/
CXX=clang++ ${WARNING} -std=c++11
SFML=-framework sfml-graphics -framework sfml-window -framework sfml-system -framework sfml-network
OBJDIR=obj

game = $(shell cat FileList)
gameobjs = $(patsubst %,$(OBJDIR)/%,$(game:.cpp=.o))

main=obj/main.o

all: $(BIN)

$(BIN) : $(main) $(zf_commonobjs) $(zf_sfmlobjs) $(zf_sfmlsubobjs) $(zf_platformerobjs) $(zf_networkobjs) $(zf_networksubobjs) $(gameobjs) FileList
	$(CXX) -o $(BIN) $(OBJDIR)/* $(SFML)

$(OBJDIR)/%.o : %.cpp
	$(CXX) -c -o $@ $^

obj/main.o : main.cpp
	$(CXX) -c -o $@ $^

clean:
	rm obj/*.o
	rm $(BIN)

remake:
	make clean
	make all

debug:
	@echo $(zf_sfml)

.PHONY: clean remake debug
