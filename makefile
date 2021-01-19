########################
### MAKEFILE GENERAL ###
########################


### === Options === ###

# nom de l'executable
TITRE = executable

# source1.cpp source2.cpp source3.cpp ...
SOURCES = utilities.cpp

# compilateur
CXX = g++



### === Vars === ###

.DEFAULT_GOAL := $(TITRE)

OBJECTS = $(SOURCES:.cpp=.o)

CXXFLAGS  +=
LDFLAGS +=

$(OBJECTS) : %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

CLEAN_OBJECTS = $(OBJECTS)
TARGETS = 



### === Build === ###

LISTE_SOURCES = main.cpp
LISTE_OBJECTS = $(LISTE_SOURCES:.cpp=.o)

$(TITRE) : $(LISTE_OBJECTS) $(OBJECTS) $(HEADERS)
	$(CXX) $(LISTE_OBJECTS) $(OBJECTS) -o $@ $(LDFLAGS)
	
$(LISTE_OBJECTS): %.o : %.cpp
	$(CXX) -MMD $(CXXFLAGS) -c $< -o $@

all : $(TITRE)
TARGETS += main
CLEAN_OBJECTS += $(LISTE_OBJECTS)



### === Cleanup === ###

DEPS = $(CLEAN_OBJECTS:.o=.d)

clean:
	@rm -f $(DEPS) $(TARGETS) $(CLEAN_OBJECTS)

-include $(DEPS)
