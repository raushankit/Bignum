COMPILER = g++
STD = -std=c++17
CPP = $(COMPILER) $(STD)
FLAGS = -O5 -Wall -W
RM  = rm -fr
EXEC = a.out

SRCDIR = src
MAINDIR = main
CRDIR = createdir
OBJDIR = build
SOURCEDIR = ./$(SRCDIR)/$(MAINDIR)

_SOURCES := $(shell find $(SOURCEDIR) -name '*.cpp')

SOURCES := $(patsubst ./%.cpp, %.o, $(_SOURCES))

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES))

all: $(OBJECTS) compile touch

$(OBJDIR)/%.o: %.cpp | $(CRDIR)/$(OBJDIR)
					 $(CPP) $(FLAGS) $(INCLUDES) -c $< -o $(OBJDIR)/$(notdir $@)
$(CRDIR)/%:
					 mkdir -p $*
run: | all
					 ./$(EXEC)			 
clean:  
					 $(RM) $(OBJDIR) $(EXEC)
compile: 
					 $(CPP) $(FLAGS) $(addprefix $(OBJDIR)/, $(notdir $(OBJECTS))) -o $(EXEC) 
touch:
					 @echo " "
					 @echo "Compilation done successfully..................."
					 @echo " "
					