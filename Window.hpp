#ifndef Window_hpp
#define Window_hpp

class Graph;

class Window {

    public :
    
        Window();
        ~Window();

        int  add(const Graph*);
        void hide(int);
        void init();
        void launch(int)                        const;
 static void draw();
 static void keyboard(unsigned char, int, int);
 static void reshape(int, int);
        void replaceGraph(const Graph*, const Graph*);
    
    private :
    
 static std::vector<const Graph*>* graphs;
 
  const int width;
  const int height;

};

#endif