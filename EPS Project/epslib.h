//1801042626 Derviş Ali Duman

typedef struct Point2D{		//Point struct
	double x,y;
	int ignore;
	struct Point2D *next;	//like linked list
}Point2D;

typedef struct{
	double red,green,blue;	//RGB Colors
}Color;

typedef struct Figure{
	double width,height;
	double resolution,thickness;
	Color color;
	Point2D *pointt;		//Represents all points used for figure
	struct Figure *next;	//like linked list (linked figure)
}Figure;

typedef struct Tree{
	double data;
	struct Tree *right,*left;
}Tree;

Figure *start_figure(double width, double height);

void set_thickness_resolution(Figure *fig, double thickness, double resolution);
void set_color(Figure * fig,Color c);
void point_inserter(Point2D *head, double x, double y);
void draw_fx(Figure * fig, double f(double x),double start_x, double end_x,double step_size);
void draw_polyline(Figure *fig, Point2D * poly_line, int n);
void draw_ellipse(Figure* fig,Point2D * center,Point2D * width_height);
void draw_polygon(Figure* fig,Point2D * poly_line);
void append_figures(Figure *fig1, Figure *fig2);
void draw_tree_line(Figure * fig,double start_x, double end_x,double step_size);
void draw_tree_circle(Figure* fig,Point2D * center);
void draw_binary_tree(Figure* fig, Tree * root, Point2D *center);
void scale_figure(Figure *fig, double scale_x, double scale_y);
void resize_figure(Figure *fig,Point2D *start_roi, Point2D *end_roi);
void export_eps(Figure * fig, char * file_name);