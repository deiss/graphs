# project configuration
LIB_GLUT_LINUX = -lGL -lGLU -lglut
LIB_GLUT_MAC   = -framework OpenGL -framework GLUT
CC             = g++
CC_FLAGS       = -Wall -Wno-deprecated-declarations -std=c++11
EXEC           = graphs

# project structure
BUILD_DIR = build
BIN_DIR   = bin
SRC_DIR   = src
MODULES   = ./ components constants graph graph_representation rendering cross_platform
SRC_DIRS  = $(addprefix $(SRC_DIR)/, $(MODULES))

# libs and headers subfolders lookup
INCLUDE = -I$(SRC_DIR)
SRC     = $(foreach sdir, $(SRC_DIRS), $(wildcard $(sdir)/*.cpp))
OBJ     = $(foreach sdir, $(SRC_DIRS), $(patsubst $(sdir)/%.cpp, $(BUILD_DIR)/%.o, $(wildcard $(sdir)/*.cpp)))

# sourcefile subfolders lookup
VPATH = $(SRC_DIRS)

# entry point
default:
	@echo "You need to specify the system you are building on. Possibilities:"
	@echo "  'make linux'"
	@echo "  'make mac'"

linux: lib_linux make_dir $(BIN_DIR)/$(EXEC)

mac: lib_mac make_dir $(BIN_DIR)/$(EXEC)

lib_linux:
	$(eval LD_FLAGS = $(LIB_GLUT_LINUX))

lib_mac:
	$(eval LD_FLAGS = $(LIB_GLUT_MAC))

make_dir:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(BIN_DIR)

# create binary
$(BIN_DIR)/$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LD_FLAGS)

# objects
$(BUILD_DIR)/main.o: main.cpp Window.hpp Graph.hpp Vertex.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/Edge.o: Edge.cpp Edge.hpp Constants.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/Vertex.o: Vertex.cpp Vertex.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/Constants.o: Constants.cpp Constants.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/algorithms.o: algorithms.cpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/algorithms_handlers.o: algorithms_handlers.cpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/Graph.o: Graph.cpp Constants.hpp Graph.hpp GraphRepresentation.hpp GraphRepresentationAdjacencyMatrix.hpp Vertex.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/graphic.o: graphic.cpp GLUT.hpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/random.o: random.cpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/GraphRepresentation.o: GraphRepresentation.cpp GraphRepresentation.hpp Vertex.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/GraphRepresentationAdjacencyMatrix.o: GraphRepresentationAdjacencyMatrix.cpp GraphRepresentationAdjacencyMatrix.hpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

$(BUILD_DIR)/Window.o: Window.cpp GLUT.hpp Graph.hpp
	$(CC) $(INCLUDE) $(CC_FLAGS) -o $@ -c $<

clean:
	@rm -f  $(BUILD_DIR)/*.o
	@rm -rf $(BUILD_DIR)
